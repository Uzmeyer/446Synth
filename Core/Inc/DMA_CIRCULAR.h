#include "stm32f4xx_hal.h"
#include "dma.h"

void USART_IrqHandler (UART_HandleTypeDef *huart, DMA_HandleTypeDef *hdma);

void DMA_IrqHandler (DMA_HandleTypeDef *hdma);


