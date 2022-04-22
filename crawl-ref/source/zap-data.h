/**
 * @file
 * @brief Zap definitions. See zap_info struct in beam.cc.
**/

/*
struct zap_info
{
    zap_type ztype;
    const char* name;
    int player_power_cap;
    dam_deducer* player_damage;
    tohit_deducer* player_tohit;       // Enchantments have power modifier here
    dam_deducer* monster_damage;
    tohit_deducer* monster_tohit;      // Enchantments have power modifier here
    colour_t colour;
    bool is_enchantment;
    beam_type flavour;
    dungeon_char_type glyph;
    bool always_obvious;
    bool can_beam;
    bool is_explosion;
    int hit_loudness;
}
*/

/// Boilerplate monster hex.
static zap_info _mon_hex_zap(zap_type ztype, beam_type beam,
                             int player_pow_cap = 100,
                             colour_t colour = BLACK)
{
    return {
        ztype,
        "",
        player_pow_cap,
        nullptr,
        nullptr,
        nullptr,
        new tohit_calculator<0, 1, 3>, // ENCH_POW_FACTOR
        colour,
        true,
        beam,
        NUM_DCHAR_TYPES,
        false,
        false,
        false,
        0
    };
}

/// Wand Hex Zap
static zap_info _wand_hex_zap(zap_type ztype, beam_type beam,
                              int player_pow_cap = 100,
                              colour_t colour = BLACK)
{
    return {
        ztype,
        "",
        player_pow_cap,
        nullptr,
        new tohit_calculator<10, 4, 1>,
        nullptr,
        new tohit_calculator<10, 4, 1>, // ENCH_POW_FACTOR
        colour,
        true,
        beam,
        NUM_DCHAR_TYPES,
        false,
        false,
        false,
        0
    };
}

static const zap_info zap_data[] =
{

{
    ZAP_THROW_FLAME,
    "puff of flame",
    50,
    new dicedef_calculator<2, 4, 1, 10>,
    new tohit_calculator<12, 1, 5>,
    new dicedef_calculator<3, 5, 1, 40>,
    new tohit_calculator<35, 1, 10>,
    RED,
    false,
    BEAM_FIRE,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    2
},

{
    ZAP_WAND_FLAME,
    "puff of flame",
    200,
    new dicedef_calculator<2, 2, 1, 3>,
    new tohit_calculator<13, 1, 1>,
    new dicedef_calculator<2, 2, 1, 3>,
    new tohit_calculator<13, 1, 1>,
    RED,
    false,
    BEAM_FIRE,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    3
},

{
    ZAP_WAND_ENSNARE,
    "stream of webbing",
    200,
    new dicedef_calculator<1, 1, 1, 8>,
    new tohit_calculator<6, 4, 3>,
    new dicedef_calculator<1, 1, 1, 8>,
    new tohit_calculator<6, 4, 3>,
    WHITE,
    false,
    BEAM_ENSNARE,
    DCHAR_FIRED_MISSILE,
    true,
    false,
    false,
    0
},

{
    ZAP_THROW_FROST,
    "puff of frost",
    50,
    new dicedef_calculator<2, 4, 1, 10>,
    new tohit_calculator<12, 1, 5>,
    new dicedef_calculator<3, 5, 1, 40>,
    new tohit_calculator<33, 1, 10>,
    WHITE,
    false,
    BEAM_COLD,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    2
},

{
    ZAP_SLOW,
    "",
    100,
    nullptr,
    new tohit_calculator<0, 3, 2>,
    nullptr,
    new tohit_calculator<0, 1, 3>,
    BLACK,
    true,
    BEAM_SLOW,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_MEPHITIC,
    "stinking cloud",
    100,
    nullptr,
    new tohit_calculator<AUTOMATIC_HIT>,
    nullptr,
    nullptr,
    GREEN,
    false,
    BEAM_MEPHITIC,
    DCHAR_FIRED_ZAP,
    true,
    false,
    true,
    0 // Noise comes from explosion
},

{
    ZAP_HASTE,
    "",
    200,
    nullptr,
    new tohit_calculator<3, 1, 8>,
    nullptr,
    new tohit_calculator<10, 1, 5>,
    BLACK,
    true,
    BEAM_HASTE,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_WAND_HASTING,
    "",
    200,
    nullptr,
    new tohit_calculator<3, 1, 1>,
    nullptr,
    new tohit_calculator<3, 1, 1>,
    BLACK,
    true,
    BEAM_HASTE,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_MAGIC_DART,
    "magic dart",
    25,
    new dicedef_calculator<1, 3, 1, 5>,
    new tohit_calculator<AUTOMATIC_HIT>,
    new dicedef_calculator<3, 4, 1, 100>,
    new tohit_calculator<AUTOMATIC_HIT>,
    LIGHTMAGENTA,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    1
},

{
    ZAP_BOLT_OF_FIRE,
    "bolt of fire",
    200,
    new calcdice_calculator<6, 18, 2, 3>,
    new tohit_calculator<20, 1, 10>,
    new dicedef_calculator<3, 8, 1, 11>,
    new tohit_calculator<32, 1, 10>,
    RED,
    false,
    BEAM_FIRE,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    6
},

{
    ZAP_FROST_BURST,
    "shard of frozen ooze",
    60,
    new calcdice_calculator<3, 10, 1, 6>,
    new tohit_calculator<18, 2, 3>,
    new calcdice_calculator<3, 10, 1, 6>,
    new tohit_calculator<18, 2, 3>,
    LIGHTCYAN,
    false,
    BEAM_ICE,
    DCHAR_FIRED_MISSILE,
    true,
    false,
    false,
    6
},

{
    ZAP_FROST_BURST_EXPLOSION,
    "frozen ooze fragments",
    60,
    new calcdice_calculator<3, 3, 1, 9>,
    new tohit_calculator<AUTOMATIC_HIT>,
    new calcdice_calculator<3, 3, 1, 9>,
    new tohit_calculator<AUTOMATIC_HIT>,
    LIGHTCYAN,
    false,
    BEAM_ICY_SHARDS,
    DCHAR_FIRED_MISSILE,
    true,
    false,
    true,
    6
},

{
    ZAP_BOLT_OF_COLD,
    "bolt of cold",
    200,
    new calcdice_calculator<6, 18, 2, 3>,
    new tohit_calculator<20, 1, 10>,
    new dicedef_calculator<3, 8, 1, 11>,
    new tohit_calculator<32, 1, 10>,
    WHITE,
    false,
    BEAM_COLD,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    6
},

{ // Used by phial of floods
    ZAP_PRIMAL_WAVE,
    "torrent of water",
    200,
    new calcdice_calculator<4, 14, 3, 5>,
    new tohit_calculator<20, 1, 10>,
    // Water attack is weaker than the pure elemental damage attacks, but also
    // less resistible.
    new dicedef_calculator<3, 6, 1, 12>,
    // Huge wave of water is hard to dodge.
    new tohit_calculator<33, 1, 10>,
    LIGHTBLUE,
    false,
    BEAM_WATER,
    DCHAR_WAVY,
    true,
    false,
    false,
    6
},

{ 
    ZAP_CORROSIVE_WAVE,
    "deluge of slime",
    200,
    new calcdice_calculator<4, 10, 1, 3>,
    new tohit_calculator<15, 3, 2>,
    new calcdice_calculator<4, 10, 1, 3>,
    new tohit_calculator<15, 3, 2>,
    LIGHTGREEN,
    false,
    BEAM_ACID_WAVE,
    DCHAR_WAVY,
    true,
    false,
    false,
    6
},

{ 
    ZAP_SLIMEBOLT,
    "torrent of ooze",
    200,
    new calcdice_calculator<3, 8, 1, 4>,
    new tohit_calculator<18, 2, 3>,
    new calcdice_calculator<3, 8, 1, 4>,
    new tohit_calculator<18, 2, 3>,
    LIGHTGREEN,
    false,
    BEAM_ACID_WAVE,
    DCHAR_WAVY,
    true,
    true,
    false,
    4
},

_mon_hex_zap(ZAP_CONFUSE, BEAM_CONFUSION),

{
    ZAP_TUKIMAS_DANCE,
    "",
    100,
    nullptr,
    new tohit_calculator<0, 3, 2>,
    nullptr,
    nullptr,
    BLACK,
    true,
    BEAM_TUKIMAS_DANCE,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_CIGOTUVI,
    "",
    200,
    nullptr,
    new tohit_calculator<0, 1, 1>,
    nullptr,
    nullptr,
    BLACK,
    true,
    BEAM_CIGOTUVI,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_SNAKES_TO_STICKS,
    "",
    100,
    nullptr,
    new tohit_calculator<0, 1, 4>,
    nullptr,
    nullptr,
    BLACK,
    true,
    BEAM_SNAKES_TO_STICKS,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_INVISIBILITY,
    "",
    100,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    BLACK,
    true,
    BEAM_INVISIBILITY,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_DIG,
    "",
    200,
    new calcdice_calculator<1, 0, 1, 1>,
    nullptr,
    new calcdice_calculator<1, 50, 1, 1>,
    nullptr,
    BLACK,
    true,
    BEAM_DIGGING,
    NUM_DCHAR_TYPES,
    false,
    true,
    false,
    4
},

{
    ZAP_FIREBALL,
    "fireball",
    200,
    new calcdice_calculator<3, 10, 1, 2>,
    new tohit_calculator<40>,
    new dicedef_calculator<3, 7, 1, 10>,
    new tohit_calculator<40>,
    RED,
    false,
    BEAM_FIRE,
    DCHAR_FIRED_ZAP,
    false,
    false,
    true,
    0 // Noise comes from explosion
},

{
    ZAP_GHOSTLY_FIREBALL,
    "ghostly fireball",
    200,
    new calcdice_calculator<3, 8, 1, 2>,
    new tohit_calculator<40>,
    new dicedef_calculator<3, 6, 1, 13>,
    new tohit_calculator<40>,
    CYAN,
    false,
    BEAM_DRAIN,
    DCHAR_FIRED_ZAP,
    false,
    false,
    true,
    0 // Noise comes from explosion
},

{
    ZAP_MALIGN_OFFERING,
    "malignant energy",
    200,
    new calcdice_calculator<2, 5, 1, 2>,
    new tohit_calculator<AUTOMATIC_HIT>,
    new dicedef_calculator<2, 11, 1, 13>,
    new tohit_calculator<AUTOMATIC_HIT>,
    RED,
    true,
    BEAM_MALIGN_OFFERING,
    DCHAR_FIRED_ZAP,
    false,
    false,
    false,
    0
},

{
    ZAP_CHAOS_ERUPTION,
    "eruption",
    200,
    new calcdice_calculator<3, 5, 2, 3>,
    new tohit_calculator<40>,
    new dicedef_calculator<3, 4, 1, 10>,
    new tohit_calculator<40>,
    RED,
    false,
    BEAM_LAVA,
    DCHAR_FIRED_ZAP,
    false,
    false,
    true,
    0 // Noise comes from explosion
},

{
    ZAP_CHAOS_ICEFALL,
    "icy stalactite",
    200,
    new calcdice_calculator<4, 8, 1, 3>,
    new tohit_calculator<40>,
    new dicedef_calculator<4, 5, 1, 10>,
    new tohit_calculator<40>,
    WHITE,
    false,
    BEAM_FREEZE,
    DCHAR_FIRED_ZAP,
    false,
    false,
    true,
    0 // Noise comes from explosion
},


{
    ZAP_CHAOS_STALACTITE,
    "stalactite",
    200,
    new calcdice_calculator<3, 8, 2, 3>,
    new tohit_calculator<40>,
    new dicedef_calculator<3, 5, 1, 8>,
    new tohit_calculator<40>,
    BROWN,
    false,
    BEAM_FRAG,
    DCHAR_FIRED_ZAP,
    false,
    false,
    true,
    0 // Noise comes from explosion
},

{
    ZAP_TELEPORT_OTHER,
    "",
    100,
    nullptr,
    new tohit_calculator<0, 3, 2>,
    nullptr,
    new tohit_calculator<0, 1, 3>,
    BLACK,
    true,
    BEAM_TELEPORT,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_LIGHTNING_BOLT,
    "bolt of lightning",
    200,
    new calcdice_calculator<1, 11, 3, 5>,
    new tohit_calculator<7, 1, 8>,
    new dicedef_calculator<3, 10, 1, 17>,
    new tohit_calculator<14, 1, 8>,
    LIGHTCYAN,
    false,
    BEAM_ELECTRICITY,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    5 // XXX: Maybe louder?
},

_mon_hex_zap(ZAP_POLYMORPH, BEAM_POLYMORPH),
_wand_hex_zap(ZAP_WAND_POLYMORPH, BEAM_POLYMORPH),

{
    ZAP_VENOM_BOLT,
    "bolt of poison",
    200,
    new calcdice_calculator<4, 16, 3, 5>,
    new tohit_calculator<14, 1, 10>,
    new dicedef_calculator<3, 6, 1, 13>,
    new tohit_calculator<21, 1, 10>,
    LIGHTGREEN,
    false,
    BEAM_POISON,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    5 // XXX: Quieter because it's poison?
},

{
    ZAP_BOLT_OF_DRAINING,
    "bolt of negative energy",
    200,
    new calcdice_calculator<4, 15, 3, 5>,
    new tohit_calculator<16, 1, 10>,
    new dicedef_calculator<3, 9, 1, 13>,
    new tohit_calculator<16, 1, 30>,
    DARKGREY,
    false,
    BEAM_DRAIN,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    0 // Draining is soundless
},

{
    ZAP_LEHUDIBS_CRYSTAL_SPEAR,      // was splinters
    "crystal spear",
    200,
    new calcdice_calculator<10, 26, 5, 4>,
    new tohit_calculator<10, 1, 5>,
    new dicedef_calculator<3, 18, 1, 8>,
    new tohit_calculator<21, 1, 6>,
    WHITE,
    false,
    BEAM_CRYSTAL_SPEAR,
    DCHAR_FIRED_MISSILE,
    true,
    true,
    false,
    7
},

_wand_hex_zap(ZAP_ENSLAVEMENT, BEAM_ENSLAVE),

{
    ZAP_PAIN,
    "",
    100,
    new dicedef_calculator<1, 4, 1, 5>,
    new tohit_calculator<0, 7, 2>,
    new dicedef_calculator<1, 7, 1, 20>,
    new tohit_calculator<0, 1, 3>,
    BLACK,
    true,
    BEAM_PAIN,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    1 // XXX: Should this be soundless?
},

{
    ZAP_STICKY_FLAME,
    "sticky flame",
    100,
    new dicedef_calculator<2, 3, 1, 12>,
    new tohit_calculator<AUTOMATIC_HIT>,
    new dicedef_calculator<3, 3, 1, 50>,
    new tohit_calculator<AUTOMATIC_HIT>,
    RED,
    false,
    BEAM_FIRE,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    1
},

{
    ZAP_WAND_HEALING,
    "healing mist",
    200,
    new dicedef_calculator<3, 2, 1, 2>,
    new tohit_calculator<AUTOMATIC_HIT>,
    new dicedef_calculator<3, 2, 1, 2>,
    new tohit_calculator<AUTOMATIC_HIT>,
    ETC_HOLY,
    false,
    BEAM_WAND_HEALING,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    6
},

{
    ZAP_STICKY_FLAME_RANGE,
    "sticky flame",
    100,
    new dicedef_calculator<2, 3, 1, 12>,
    new tohit_calculator<AUTOMATIC_HIT>,
    new dicedef_calculator<3, 3, 1, 50>,
    new tohit_calculator<23, 1, 5>,
    RED,
    false,
    BEAM_FIRE,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    1
},

{
    ZAP_DISPEL_UNDEAD,
    "",
    100,
    new calcdice_calculator<3, 20, 3, 4>,
    new tohit_calculator<0, 3, 2>,
    new dicedef_calculator<3, 6, 1, 10>,
    new tohit_calculator<AUTOMATIC_HIT>,
    BLACK,
    true,
    BEAM_DISPEL_UNDEAD,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

_mon_hex_zap(ZAP_BANISHMENT, BEAM_BANISH, 150),

{
    ZAP_STING,
    "sting",
    25,
    new dicedef_calculator<1, 3, 1, 5>,
    new tohit_calculator<AUTOMATIC_HIT>,
    new dicedef_calculator<1, 6, 1, 25>,
    new tohit_calculator<AUTOMATIC_HIT>,
    GREEN,
    false,
    BEAM_POISON,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    0
},

{
    ZAP_DAMNATION,
    "hellfire",
    200,
    new calcdice_calculator<3, 8, 3, 5>,
    new tohit_calculator<30, 1, 10>,
    nullptr,
    nullptr,
    LIGHTRED,
    false,
    BEAM_DAMNATION,
    DCHAR_FIRED_ZAP,
    true,
    false,
    true,
    9 // XXX: Even louder because it's hellish?
},

{
    ZAP_IRON_SHOT,
    "iron shot",
    200,
    new calcdice_calculator<9, 15, 3, 4>,
    new tohit_calculator<14, 1, 5>,
    new dicedef_calculator<3, 8, 1, 9>,
    new tohit_calculator<20, 1, 5>,
    LIGHTCYAN,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_MISSILE,
    true,
    false,
    false,
    6
},

{
    ZAP_SILVER_SHOT,
    "silver shot",
    200,
    new calcdice_calculator<9, 15, 3, 4>,
    new tohit_calculator<11, 1, 5>,
    new dicedef_calculator<3, 6, 1, 9>,
    new tohit_calculator<30, 1, 10>,
    ETC_SILVER,
    false,
    BEAM_SILVER,
    DCHAR_FIRED_MISSILE,
    true,
    false,
    false,
    7,
},

{
    ZAP_STONE_ARROW,
    "stone arrow",
    50,
    new dicedef_calculator<3, 5, 1, 8>,
    new tohit_calculator<11, 1, 5>,
    new dicedef_calculator<3, 5, 1, 10>,
    new tohit_calculator<21, 1, 5>,
    LIGHTGREY,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_MISSILE,
    true,
    false,
    false,
    3
},

{
    ZAP_SHOCK,
    "zap",
    25,
    new dicedef_calculator<1, 3, 1, 4>,
    new tohit_calculator<4, 1, 4>,
    new dicedef_calculator<1, 8, 1, 20>,
    new tohit_calculator<17, 1, 5>,
    LIGHTCYAN,
    false,
    BEAM_ELECTRICITY,             // beams & reflects
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    1 // XXX: maybe electricity should be louder?
},

{
    ZAP_ORB_OF_ELECTRICITY,
    "orb of electricity",
    200,
    new calcdice_calculator<0, 13, 4, 5>,
    new tohit_calculator<40>,
    new dicedef_calculator<3, 7, 1, 9>,
    new tohit_calculator<40>,
    LIGHTBLUE,
    false,
    BEAM_ELECTRICITY,
    DCHAR_FIRED_ZAP,
    true,
    false,
    true,
    6 // XXX: maybe electricity should be louder?
},

{
    ZAP_SPIT_POISON,
    "splash of poison",
    50,
    new dicedef_calculator<1, 4, 1, 2>,
    new tohit_calculator<7, 1, 3>,
    nullptr,
    nullptr,
    GREEN,
    false,
    BEAM_POISON,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    1
},

{
    ZAP_DEBUGGING_RAY,
    "debugging ray",
    10000,
    new dicedef_calculator<AUTOMATIC_HIT, 1, 0, 1>,
    new tohit_calculator<AUTOMATIC_HIT>,
    nullptr,
    nullptr,
    WHITE,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_DEBUG,
    false,
    false,
    false,
    0
},

// XXX: How loud should breath be?
// Breaths scale off of level x 1 normally and level x 2 in dragon form so practical cap is 54.
{
    ZAP_BREATHE_FIRE,
    "fiery breath",
    200,
    new dicedef_calculator<3, 4, 1, 3>,
    new tohit_calculator<12, 1, 3>,
    nullptr,
    nullptr,
    RED,
    false,
    BEAM_FIRE,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    7
},

{
    ZAP_BREATHE_MAGMA,
    "lava breath",
    200,
    new dicedef_calculator<3, 3, 1, 3>,
    new tohit_calculator<12, 1, 3>,
    nullptr,
    nullptr,
    RED,
    false,
    BEAM_LAVA,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    7
},

{
    ZAP_BREATHE_MAGMA_II,
    "magma breath",
    200,
    new dicedef_calculator<3, 5, 1, 3>,
    new tohit_calculator<15, 1, 3>,
    nullptr,
    nullptr,
    RED,
    false,
    BEAM_LAVA,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    7
},

{
    ZAP_BREATHE_TRIPLE,
    "freezing flame",
    200,
    new dicedef_calculator<4, 4, 1, 3>,
    new tohit_calculator<12, 1, 3>,
    nullptr,
    nullptr,
    ETC_CRYSTAL,
    false,
    BEAM_PARADOXICAL,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    7
},

{
    ZAP_BREATHE_LIGHTNING,
    "lightning breath",
    200,
    new dicedef_calculator<3, 2, 1, 3>,
    new tohit_calculator<AUTOMATIC_HIT>,
    nullptr,
    nullptr,
    CYAN,
    false,
    BEAM_ELECTRICITY,
    DCHAR_FIRED_ZAP,
    true,
    true,
    true,
    15
},

{
    ZAP_BREATHE_CHAOS,
    "seething chaos breath",
    200,
    new dicedef_calculator<3, 4, 1, 3>,
    new tohit_calculator<12, 1, 3>,
    nullptr,
    nullptr,
    ETC_JEWEL,
    false,
    BEAM_CHAOTIC,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    7,
},

{
    ZAP_BREATHE_FROST,
    "freezing breath",
    200,
    new dicedef_calculator<3, 4, 1, 3>,
    new tohit_calculator<12, 1, 3>,
    nullptr,
    nullptr,
    WHITE,
    false,
    BEAM_COLD,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    6
},

{
    ZAP_BREATHE_ACID,
    "glob of acid",
    200,
    new dicedef_calculator<4, 4, 1, 3>,
    new tohit_calculator<14, 1, 3>,
    nullptr,
    nullptr,
    YELLOW,
    false,
    BEAM_ACID,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    6
},

{
    ZAP_BREATHE_HOLY_FLAMES,
    "blast of cleansing flame",
    200,
    new dicedef_calculator<4, 4, 1, 3>,
    new tohit_calculator<14, 1, 3>,
    nullptr,
    nullptr,
    ETC_HOLY,
    false,
    BEAM_HOLY,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    7
},

{
    ZAP_BREATHE_RADIATION,
    "blast of magical radiation",
    200,
    new dicedef_calculator<4, 4, 1, 3>,
    new tohit_calculator<16, 1, 3>,
    nullptr,
    nullptr,
    ETC_MUTAGENIC,
    false,
    BEAM_IRRADIATE,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    3
},

{
    ZAP_BREATHE_DRAIN,
    "bolt of negative energy",
    200,
    new dicedef_calculator<3, 4, 1, 3>,
    new tohit_calculator<12, 1, 3>,
    nullptr,
    nullptr,
    DARKGREY,
    false,
    BEAM_DRAIN,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    0  // Draining is silent.
},

{
    ZAP_BREATHE_BLOOD,
    "wave of vampiric fog",
    200,
    new dicedef_calculator<3, 4, 1, 3>,
    new tohit_calculator<AUTOMATIC_HIT>,
    nullptr,
    nullptr,
    RED,
    false,
    BEAM_BLOOD,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    0  // Draining is silent.
},

{
    ZAP_BREATHE_SPECTRAL,
    "blast of ghostly flames",
    200,
    new dicedef_calculator<3, 4, 1, 3>,
    new tohit_calculator<12, 1, 3>,
    nullptr,
    nullptr,
    LIGHTBLUE,
    false,
    BEAM_DRAIN,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    20
},

{
    ZAP_BREATHE_POISON,
    "poison gas",
    200,
    new dicedef_calculator<3, 2, 1, 6>,
    new tohit_calculator<9, 1, 3>,
    nullptr,
    nullptr,
    GREEN,
    false,
    BEAM_POISON,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    0 // Explosion does the noise.
},

{
    ZAP_BREATHE_MIASMA,
    "foul miasma",
    200,
    new dicedef_calculator<2, 2, 1, 6>,
    new tohit_calculator<9, 1, 3>,
    nullptr,
    nullptr,
    MAGENTA,
    false,
    BEAM_MIASMA,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    7 // Explosion does the noise.
},

{
    ZAP_BREATHE_ROT,
    "vicious blight",
    200,
    new dicedef_calculator<2, 2, 1, 6>,
    new tohit_calculator<9, 1, 3>,
    nullptr,
    nullptr,
    LIGHTGREEN,
    false,
    BEAM_ROT,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    7 // Explosion does the noise.
},

{
    ZAP_BREATHE_BUTTERFLY,
    "fairy dust",
    200,
    new dicedef_calculator<5, 4, 1, 3>,
    new tohit_calculator<AUTOMATIC_HIT>,
    nullptr,
    nullptr,
    LIGHTRED,
    false,
    BEAM_BUTTERFLY,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    2
},

{
    ZAP_BREATHE_BONE,
    "spray of bone shards",
    200,
    new dicedef_calculator<2, 6, 1, 3>,
    new tohit_calculator<4, 2, 3>,
    new dicedef_calculator<2, 10, 1, 24>,
    new tohit_calculator<14, 1, 6>,
    WHITE,
    false,
    BEAM_FRAG,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    7
},

{
    ZAP_BREATHE_SILVER,
    "spray of silver splinters",
    200,
    new dicedef_calculator<2, 5, 1, 3>,
    new tohit_calculator<4, 2, 3>,
    new dicedef_calculator<2, 10, 1, 24>,
    new tohit_calculator<14, 1, 6>,
    LIGHTGREY,
    false,
    BEAM_SILVER_FRAG,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    7
},

{
    ZAP_BREATHE_METAL,
    "spray of metal splinters",
    200,
    new dicedef_calculator<2, 6, 1, 3>,
    new tohit_calculator<4, 2, 3>,
    nullptr,
    nullptr,
    DARKGREY,
    false,
    BEAM_FRAG,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    7
},

{
    ZAP_BREATHE_POWER,
    "bolt of dispelling energy",
    50,
    new dicedef_calculator<3, 3, 1, 3>,
    new tohit_calculator<11, 1, 3>,
    nullptr,
    nullptr,
    BLUE,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    6
},

{
    ZAP_AGONY,
    "agony",
    200,
    nullptr,
    new tohit_calculator<0, 5, 1>,
    nullptr,
    new tohit_calculator<0, 1, 3>,
    BLACK,
    true,
    BEAM_AGONY,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_DISINTEGRATE,
    "",
    100,
    new calcdice_calculator<3, 2, 1, 1>,
    new tohit_calculator<0, 4, 1>,
    new calcdice_calculator<3, 2, 1, 1>,
    new tohit_calculator<0, 4, 1>,
    BLACK,
    true,
    BEAM_DISINTEGRATION,
    NUM_DCHAR_TYPES,
    false,
    true,
    false,
    6
},

{
    ZAP_BREATHE_STEAM,
    "ball of steam",
    200,
    new dicedef_calculator<3, 4, 1, 5>,
    new tohit_calculator<15, 1, 5>,
    new dicedef_calculator<3, 7, 1, 15>,
    new tohit_calculator<25, 1, 10>,
    LIGHTGREY,
    false,
    BEAM_STEAM,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    0 // Explosion does the noise.
},

{
    ZAP_BREATHE_FOG,
    "fog cloud",
    200,
    new dicedef_calculator<3, 4, 1, 3>,
    new tohit_calculator<15, 1, 5>,
    nullptr,
    nullptr,
    MAGENTA,
    false,
    BEAM_FOG,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    2,
},

{
    ZAP_THROW_ICICLE,
    "shard of ice",
    100,
    new calcdice_calculator<3, 10, 1, 2>,
    new tohit_calculator<11, 1, 7>,
    new dicedef_calculator<3, 8, 1, 11>,
    new tohit_calculator<19, 1, 12>,
    WHITE,
    false,
    BEAM_ICE,
    DCHAR_FIRED_MISSILE,
    false,
    false,
    false,
    4
},

{
    ZAP_CASCADE,
    "icicle",
    200,
    new calcdice_calculator<3, 8, 3, 8>,
    new tohit_calculator<11, 1, 7>,
    new dicedef_calculator<3, 8, 1, 11>,
    new tohit_calculator<19, 1, 12>,
    WHITE,
    false,
    BEAM_ICE,
    DCHAR_FIRED_MISSILE,
    false,
    false,
    false,
    12
},

{
    ZAP_CASCADE_II,
    "icy fragments",
    200,
    new calcdice_calculator<5, 4, 1, 4>,
    new tohit_calculator<40>,
    new dicedef_calculator<5, 6, 1, 22>,
    new tohit_calculator<40>,
    WHITE,
    false,
    BEAM_FREEZE,
    DCHAR_FIRED_MISSILE,
    false,
    false,
    true,
    0
},

{
    ZAP_MAGIC_CANDLE,
    "magic candle",
    100,
    new calcdice_calculator<1, 1, 1, 1>, 
    new tohit_calculator<9, 1, 6>,
    new calcdice_calculator<1, 1, 1, 1>,
    new tohit_calculator<19, 1, 11>,
    BLUE,
    false,
    BEAM_MAGIC_CANDLE,
    DCHAR_FIRED_ZAP,
    false,
    false,
    false,
    0
},

// player spellpower is capped to 50 in spl-zap.cc:spell_zap_power.
_mon_hex_zap(ZAP_HIBERNATION, BEAM_HIBERNATION),

{
    ZAP_FLAME_TONGUE,
    "flame tongue",
    25,
    new dicedef_calculator<1, 8, 1, 4>,
    new tohit_calculator<11, 1, 3>,
    new dicedef_calculator<3, 3, 1, 12>,
    new tohit_calculator<7, 1, 3>,
    RED,
    false,
    BEAM_FIRE,
    DCHAR_FIRED_BOLT,
    true,
    false,
    false,
    1
},

{
    ZAP_SANDBLAST,
    "blast of sand",
    50,
    new dicedef_calculator<2, 4, 1, 3>,
    new tohit_calculator<13, 1, 5>,
    new dicedef_calculator<3, 5, 1, 40>,
    new tohit_calculator<20, 1, 5>,
    BROWN,
    false,
    BEAM_FRAG,
    DCHAR_FIRED_BOLT,
    true,
    false,
    false,
    2 // XXX: Sound 2 for level one spell?
},

{
    ZAP_BOLT_OF_MAGMA,
    "bolt of magma",
    200,
    new calcdice_calculator<4, 16, 2, 3>,
    new tohit_calculator<8, 1, 10>,
    new dicedef_calculator<3, 8, 1, 11>,
    new tohit_calculator<17, 1, 10>,
    RED,
    false,
    BEAM_LAVA,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    5
},

{
    ZAP_DASH,
    "unstable dash",
    200,
    new calcdice_calculator<5, 11, 2, 3>,
    new tohit_calculator<4, 1, 10>,
    new dicedef_calculator<5, 12, 1, 11>,
    new tohit_calculator<17, 1, 10>,
    RED,
    false,
    BEAM_LAVA,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    8
},

{
    ZAP_POISON_ARROW,
    "poison arrow",
    200,
    new calcdice_calculator<4, 15, 1, 1>,
    new tohit_calculator<9, 1, 7>,
    new dicedef_calculator<3, 7, 1, 12>,
    new tohit_calculator<20, 1, 10>,
    LIGHTGREEN,
    false,
    BEAM_POISON_ARROW,             // extra damage
    DCHAR_FIRED_MISSILE,
    true,
    false,
    false,
    6 // XXX: Less noise because it's poison?
},

_mon_hex_zap(ZAP_PETRIFY, BEAM_PETRIFY),
_mon_hex_zap(ZAP_PORKALATOR, BEAM_PORKALATOR, 100, RED),
_mon_hex_zap(ZAP_SLEEP, BEAM_SLEEP),

{
    ZAP_IOOD,
    "",
    200,
    nullptr,
    new tohit_calculator<AUTOMATIC_HIT>,
    nullptr,
    nullptr,
    WHITE,
    false,
    BEAM_DEVASTATION,
    NUM_DCHAR_TYPES, // no dchar, to get bolt.glyph == 0,
                     // hence invisible
    true,
    true,
    false,
    0
},

{
    ZAP_BREATHE_MEPHITIC,
    "blast of choking fumes",
    50,
    new dicedef_calculator<3, 2, 1, 6>,
    new tohit_calculator<12, 1, 3>,
    nullptr,
    nullptr,
    GREEN,
    false,
    BEAM_MEPHITIC,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    0
},

{
    ZAP_INNER_FLAME,
    "",
    100,
    nullptr,
    new tohit_calculator<0, 3, 1>,
    nullptr,
    nullptr,
    BLACK,
    true,
    BEAM_INNER_FLAME,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_BLINDING_SPRAY,
    "spray of blinding venom",
    50,
    new calcdice_calculator<2, 6, 1, 4>,
    new tohit_calculator<12, 1, 5>,
    new dicedef_calculator<3, 5, 1, 17>,
    new tohit_calculator<16, 1, 5>,
    LIGHTMAGENTA,
    false,
    BEAM_POISON,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    3
},

{
    ZAP_FORCE_LANCE,
    "lance of force",
    200,
    new dicedef_calculator<2, 6, 1, 6>,
    new tohit_calculator<10, 1, 5>,
    new dicedef_calculator<3, 6, 1, 15>,
    new tohit_calculator<20, 1, 10>,
    CYAN,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_MISSILE,
    true,
    false,
    false,
    5
},

{
    ZAP_SEARING_RAY_I,
    "searing ray",
    50,
    new dicedef_calculator<2, 3, 1, 13>,
    new tohit_calculator<10, 2, 5>,
    nullptr,
    nullptr,
    MAGENTA,
    false,
    BEAM_LAVA,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    2
},

{
    ZAP_SEARING_RAY_II,
    "searing ray",
    50,
    new dicedef_calculator<3, 3, 1, 12>,
    new tohit_calculator<11, 2, 5>,
    nullptr,
    nullptr,
    LIGHTMAGENTA,
    false,
    BEAM_LAVA,
    DCHAR_FIRED_ZAP,
    true,
    false,
    false,
    2
},

{
    ZAP_SEARING_RAY_III,
    "searing ray",
    50,
    new dicedef_calculator<4, 3, 1, 12>,
    new tohit_calculator<12, 2, 5>,
    nullptr,
    nullptr,
    WHITE,
    false,
    BEAM_LAVA,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    2
},

{
    ZAP_CRYSTAL_BOLT,
    "crystal bolt",
    200,
    new calcdice_calculator<6, 18, 2, 3>,
    new tohit_calculator<10, 1, 10>,
    nullptr,
    nullptr,
    GREEN,
    false,
    BEAM_CRYSTAL,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    6
},

{
    ZAP_QUICKSILVER_BOLT,
    "bolt of dispelling energy",
    200,
    new calcdice_calculator<6, 15, 2, 3>,
    new tohit_calculator<10, 1, 10>,
    new dicedef_calculator<3, 20, 0, 1>,
    new tohit_calculator<16, 1, 10>,
    ETC_RANDOM,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    6
},

{
    ZAP_CORROSIVE_BOLT,
    "bolt of acid",
    200,
    new calcdice_calculator<4, 11, 3, 5>,
    new tohit_calculator<10, 1, 10>,
    new dicedef_calculator<3, 9, 1, 17>,
    new tohit_calculator<17, 1, 10>,
    YELLOW,
    false,
    BEAM_ACID,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    6
},

{
    ZAP_WAND_ACID,
    "bolt of acid",
    200,
    new calcdice_calculator<3, 2, 1, 1>,
    new tohit_calculator<12, 5, 3>,
    new dicedef_calculator<3, 2, 1, 1>,
    new tohit_calculator<12, 5, 3>,
    YELLOW,
    false,
    BEAM_ACID,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    6
},

{
    ZAP_RANDOM_BOLT_TRACER,
    "random bolt tracer",
    200,
    new dicedef_calculator<AUTOMATIC_HIT, 1, 0, 1>,
    new tohit_calculator<AUTOMATIC_HIT>,
    nullptr,
    nullptr,
    WHITE,
    false,
    BEAM_BOUNCY_TRACER,
    DCHAR_FIRED_DEBUG,
    true,
    true,
    false,
    0
},

{
    ZAP_SCATTERSHOT,
    "burst of metal fragments",
    200,
    new calcdice_calculator<2, 2, 2, 3>,
    new tohit_calculator<4, 1, 1>,
    new calcdice_calculator<2, 2, 2, 3>,
    new tohit_calculator<4, 1, 1>,
    CYAN,
    false,
    BEAM_FRAG,
    DCHAR_FIRED_BOLT,
    true,
    false,
    false,
    6
},

{
    ZAP_UNRAVELLING,
    "unravelling",
    200,
    nullptr,
    new tohit_calculator<0, 1, 1>,
    nullptr,
    nullptr,
    ETC_MUTAGENIC,
    true,
    BEAM_UNRAVELLING,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0 // dubious
},

{
    ZAP_ICEBLAST,
    "iceblast",
    200,
    new calcdice_calculator<3, 2, 1, 1>,
    new tohit_calculator<40>,
    new dicedef_calculator<3, 2, 1, 1>,
    new tohit_calculator<40>,
    WHITE,
    false,
    BEAM_FREEZE,
    DCHAR_FIRED_MISSILE,
    false,
    false,
    true,
    0 // Noise comes from explosion
},

{
    ZAP_BREATHE_DART,
    "dart",
    200,
    new dicedef_calculator<2, 2, 1, 1>,
    new tohit_calculator<12, 1, 2>,
    new dicedef_calculator<2, 4, 1, 25>,
    new tohit_calculator<14, 1, 10>,
    CYAN,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_MISSILE,
    true,
    false,
    false,
    1
},

{
    ZAP_BLINKBOLT,
    "living lightning",
    200,
    nullptr,
    nullptr,
    new dicedef_calculator<2, 10, 1, 17>,
    new tohit_calculator<16, 1, 10>,
    LIGHTCYAN,
    false,
    BEAM_ELECTRICITY,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    0
},

{
    ZAP_FREEZING_BLAST,
    "freezing blast",
    200,
    nullptr,
    nullptr,
    new dicedef_calculator<2, 9, 1, 11>,
    new tohit_calculator<17, 1, 10>,
    WHITE,
    false,
    BEAM_COLD,
    DCHAR_FIRED_ZAP,
    true,
    true,
    false,
    0
},

{
    ZAP_HARPOON_SHOT,
    "harpoon shot",
    50,
    nullptr,
    nullptr,
    new dicedef_calculator<2, 7, 1, 20>,
    new tohit_calculator<17, 1, 10>,
    CYAN,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_MISSILE,
    true,
    false,
    false,
    1
},

_mon_hex_zap(ZAP_DIMENSION_ANCHOR, BEAM_DIMENSION_ANCHOR),
_mon_hex_zap(ZAP_VULNERABILITY, BEAM_VULNERABILITY),
_mon_hex_zap(ZAP_SENTINEL_MARK, BEAM_SENTINEL_MARK),
_mon_hex_zap(ZAP_VIRULENCE, BEAM_VIRULENCE),
_mon_hex_zap(ZAP_SAP_MAGIC, BEAM_SAP_MAGIC),
_mon_hex_zap(ZAP_DRAIN_MAGIC, BEAM_DRAIN_MAGIC),

{
    ZAP_FORCE_LASSO,
    "lasso of force",
    200,
    new dicedef_calculator<2, 6, 1, 6>,
    new tohit_calculator<12, 1, 5>,
    new dicedef_calculator<3, 6, 1, 15>,
    new tohit_calculator<20, 1, 10>,
    ETC_WARP,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_ZAP,
    false,
    false,
    false,
    0
},

{
    ZAP_FIRE_STORM,
    "great blast of fire",
    200,
    new calcdice_calculator<8, 5, 1, 1>,
    new tohit_calculator<40>,
    new calcdice_calculator<8, 5, 1, 1>,
    new tohit_calculator<40>,
    RED,
    false,
    BEAM_LAVA, // partially unaffected by rF
    DCHAR_FIRED_ZAP,
    false,
    false,
    true,
    0 // handled by explosion
},

{
    ZAP_MALMUTATE,
    "malmutate",
    200,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    ETC_MUTAGENIC,
    true,
    BEAM_MALMUTATE,
    NUM_DCHAR_TYPES,
    false,
    false,
    false,
    0
},

{
    ZAP_VILE_CLUTCH,
    "",
    200,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    GREEN,
    true,
    BEAM_VILE_CLUTCH,
    DCHAR_FIRED_BURST,
    true,
    false,
    true,
    0 // handled by explosion
},

{
    ZAP_REFRIGERATE,
    "refrigeration",
    200,
    new calcdice_calculator<4, 20, 4, 10>,
    new tohit_calculator<40>,
    new calcdice_calculator<4, 20, 4, 10>,
    new tohit_calculator<40>,
    LIGHTCYAN,
    false,
    BEAM_COLD,
    NUM_DCHAR_TYPES,
    true,
    false,
    false,
    0 // No additional effect noise.
},

{
    ZAP_DRAIN_LIFE,
    "drain life",
    200,
    new calcdice_calculator<1, 10, 1, 1>,
    new tohit_calculator<40>,
    new calcdice_calculator<1, 10, 1, 1>,
    new tohit_calculator<40>,
    DARKGREY,
    false,
    BEAM_NEG,
    NUM_DCHAR_TYPES,
    true,
    false,
    false,
    0 // No additional effect noise.
},

{
    ZAP_SONIC_WAVE,
    "sonic wave",
    200,
    new calcdice_calculator<2, 5, 1, 5>,
    new tohit_calculator<40>,
    new calcdice_calculator<2, 5, 1, 5>,
    new tohit_calculator<40>,
    YELLOW,
    false,
    BEAM_MMISSILE,
    NUM_DCHAR_TYPES,
    true,
    false,
    false,
    0 // No additional effect noise.
},

// Used only by CYAN's empowered breath
{
    ZAP_EMPOWERED_BREATH,
    "wind blast",
    200,
    new calcdice_calculator<2, 4, 1, 6>,
    new tohit_calculator<40>,
    new calcdice_calculator<2, 4, 1, 6>,
    new tohit_calculator<40>,
    CYAN,
    false,
    BEAM_MMISSILE,
    NUM_DCHAR_TYPES,
    true,
    false,
    false,
    2
},

{
    ZAP_THROW_PIE,
    "klown pie",
    200,
    nullptr,
    nullptr,
    new dicedef_calculator<3, 20, 0, 1>,
    new tohit_calculator<22, 1, 10>,
    BROWN,
    false,
    BEAM_MMISSILE,
    DCHAR_FIRED_MISSILE,
    true,
    false,
    false,
    6
},

{
    ZAP_FOXFIRE,
    "foxfire",
    50,
    new dicedef_calculator<1, 4, 1, 5>,
    new tohit_calculator<AUTOMATIC_HIT>,
    new dicedef_calculator<3, 3, 1, 12>,
    new tohit_calculator<AUTOMATIC_HIT>,
    RED,
    false,
    BEAM_FIRE,
    DCHAR_FIRED_BOLT,
    true,
    false,
    false,
    1
},

{
    ZAP_CHAOSFIRE,
    "ephemeral spirit",
    50,
    new dicedef_calculator<1, 4, 1, 5>,
    new tohit_calculator<AUTOMATIC_HIT>,
    new dicedef_calculator<3, 3, 1, 12>,
    new tohit_calculator<AUTOMATIC_HIT>,
    ETC_JEWEL,
    false,
    BEAM_CHAOTIC,
    DCHAR_FIRED_BOLT,
    true,
    false,
    false,
    1
},

};
