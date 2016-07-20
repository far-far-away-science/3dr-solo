#include <test/test.h>
#include <test/trace_uart.h>
#include <signals/signals.h>
#include <st_link/st_link.h>
#include <system_clock/system_clock.h>

#include <stm32l0xx_hal.h>

int main(void)
{
#ifdef TEST
    HAL_Init();
    configSystemClock();
    stLinkInit();
    traceUartInit();

    EXECUTE_TESTS();

    traceUartDeInit();

    for (;;)
    {
    }
#else
    HAL_Init();
    configSystemClock();
    initializeSignals();
    stLinkInit();

    signalInitialized(true);

    for (;;)
    {
    }
#endif
}
