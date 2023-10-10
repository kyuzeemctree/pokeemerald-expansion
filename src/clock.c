#include "global.h"
#include "event_data.h"
#include "rtc.h"
#include "time_events.h"
#include "field_specials.h"
#include "lottery_corner.h"
#include "dewford_trend.h"
#include "tv.h"
#include "field_weather.h"
#include "berry.h"
#include "main.h"
#include "overworld.h"
#include "wallclock.h"

static void ReturnFromStartWallClock(void)
{
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void StartWallClock(void)
{
    SetMainCallback2(CB2_StartWallClock);
    gMain.savedCallback = ReturnFromStartWallClock;
}
