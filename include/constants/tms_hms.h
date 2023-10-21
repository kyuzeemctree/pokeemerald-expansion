#ifndef GUARD_CONSTANTS_TMS_HMS_H
#define GUARD_CONSTANTS_TMS_HMS_H
 
#define FOREACH_TM(F) \
    F(PROTECT) \
    F(BULK_UP) \
    F(CALM_MIND) \
    F(ROAR) \
    F(THUNDER_WAVE) \
    F(WILL_O_WISP) \
    F(TOXIC) \
    F(TAUNT) \
    F(REFLECT) \
    F(LIGHT_SCREEN) \
    F(REST) \
    F(SLEEP_TALK) \
    F(SLACK_OFF) \
    F(SPIKES) \
    F(SLAM) \
    F(HYPER_VOICE) \
    F(BRICK_BREAK) \
    F(AURA_SPHERE) \
    F(DUAL_WINGBEAT) \
    F(AIR_SLASH) \
    F(POISON_JAB) \
    F(SLUDGE_BOMB) \
    F(DRILL_RUN) \
    F(EARTH_POWER) \
    F(CHIP_AWAY) \
    F(POWER_GEM) \
    F(X_SCISSOR) \
    F(BUG_BUZZ) \
    F(SHADOW_PUNCH) \
    F(SHADOW_BALL) \
    F(IRON_HEAD) \
    F(FLASH_CANNON) \
    F(FIRE_PUNCH) \
    F(FLAMETHROWER) \
    F(LIQUIDATION) \
    F(WATER_PULSE) \
    F(SEED_BOMB) \
    F(ENERGY_BALL) \
    F(THUNDER_PUNCH) \
    F(THUNDERBOLT) \
    F(ZEN_HEADBUTT) \
    F(PSYCHIC) \
    F(ICE_PUNCH) \
    F(ICE_BEAM) \
    F(DRAGON_CLAW) \
    F(DRAGON_PULSE) \
    F(CRUNCH) \
    F(DARK_PULSE) \
    F(PLAY_ROUGH) \
    F(DAZZLING_GLEAM)

#define FOREACH_HM(F) \
    F(CUT) \
    F(FLY) \
    F(SURF) \
    F(STRENGTH) \
    F(FLASH) \
    F(ROCK_SMASH) \
    F(WATERFALL) \
    F(DIVE)

#define FOREACH_TMHM(F) \
    FOREACH_TM(F) \
    FOREACH_HM(F)

#endif
