#include <stm32l053xx.h>
#include <stm32l0xx_hal.h>

#include "mxconstants.h"

#include "test/trace_uart.h"
#include "signals/signals_impl.h"

void HAL_MspInit(void)
{
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void HAL_UART_MspInit(UART_HandleTypeDef* pUart)
{
    if (pUart->Instance == TRACE_UART)
    {
        traceUartMspInit(pUart);
    }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* pUart)
{
    if (pUart->Instance == TRACE_UART)
    {
        traceUartMspDeInit(pUart);
    }
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* pTimer)
{
    if (pTimer->Instance == SIGNAL_TIMER)
    {
        initializeSignalsTimer(pTimer);
    }
}
