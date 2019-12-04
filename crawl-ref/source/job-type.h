#pragma once

enum job_type
{
    JOB_FIGHTER,
    JOB_WIZARD,
    JOB_PRIEST,
    JOB_GLADIATOR,
    JOB_NECROMANCER,
#if TAG_MAJOR_VERSION == 34
    JOB_ASSASSIN,
#endif
    JOB_BERSERKER,
    JOB_HUNTER,
#if TAG_MAJOR_VERSION == 34
    JOB_CONJURER,
#endif
    JOB_ENCHANTER,
    JOB_FIRE_ELEMENTALIST,
    JOB_ICE_ELEMENTALIST,
    JOB_SUMMONER,
    JOB_AIR_ELEMENTALIST,
    JOB_EARTH_ELEMENTALIST,
    JOB_SKALD,
    JOB_VENOM_MAGE,
    JOB_CHAOS_KNIGHT,
    JOB_TRANSMUTER,
#if TAG_MAJOR_VERSION == 34
    JOB_HEALER,
    JOB_STALKER,
#endif
    JOB_MONK,
    JOB_WARPER,
    JOB_WANDERER,
    JOB_ARTIFICER,                     //   Greenberg/Bane
    JOB_ARCANE_MARKSMAN,
#if TAG_MAJOR_VERSION == 34
    JOB_DEATH_KNIGHT,
#endif
    JOB_ABYSSAL_KNIGHT,
#if TAG_MAJOR_VERSION == 34
    JOB_JESTER,
#endif
    JOB_NOBLE,
    JOB_XOM,
    JOB_MUMMY,
    JOB_DEMIGOD,
    JOB_DEMONSPAWN,
    NUM_JOBS,                          // always after the last job

    JOB_UNKNOWN = 100,
    JOB_RANDOM,
    JOB_VIABLE,
};
COMPILE_CHECK(NUM_JOBS < JOB_UNKNOWN);
