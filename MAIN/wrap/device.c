/*
 * Copyright (C) 2019-2020 Zach Lee.
 *
 * Licensed under the MIT License, you may not use this file except in
 * compliance with the License.
 *
 * MIT License:
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * ----------------------------------------------------------------------
 *
 * $Date:        11. August 2019
 * $Revision:    V0.0.0
 *
 * Project:      CMSIS-DAP Examples STM32F103
 * Title:        device.c CMSIS-DAP Wrap module for STM32
 *
 *---------------------------------------------------------------------------*/
#include "cmsis_compiler.h"
#include "cmsis_os2.h"
#include "rl_usb.h"
#include "device.h"

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;        /* For some extension in the future */
UART_HandleTypeDef huart1;
extern PCD_HandleTypeDef hpcd_USB_FS; /* It's defined in usbd_conf.c */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART1_UART_Init(void);

/**
  * @brief  The hardware initialize routine. Derived from the source code
  *         which was generated with STM32CubeMX.
  * @param  None
  * @retval None
  */
void DEVICE_Init(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */


  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  MX_USB_DEVICE_Init();

  /* USER CODE BEGIN 2 */
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  /**
    * On Cortex-M7 core there is a LAR register in DWT domain.
    * Any time we need to setup DWT registers, we MUST write
    * 0xC5ACCE55 into LAR first. LAR means Lock Access Register.
    */
  DWT->CYCCNT = 0;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
  /* USER CODE END 2 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_CONNECTED_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : LED_CONNECTED_Pin */
  GPIO_InitStruct.Pin = LED_CONNECTED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * All codes listed above are generated with STM32CubeMX.
  * I add some stub routines below to support the DAP module.
  */

/**
  * Replace CMSIS RTOS api
  */
static volatile int osFlags;  /* Use "volatile" to prevent GCC optimizing the code. */

void osKernelInitialize(void)
{
  osFlags = 0;
  return;
}
osThreadId_t osThreadNew(void (*func)(void *), void * n, void * ctx)
{
  (void)n;

  (*func)(ctx);
  return 0;
}
int osThreadFlagsWait(int mask, int b, int c)
{
  (void)b;
	(void)c;

  int ret;

  while((osFlags&mask) == 0)
  {
    ;
  }
  ret = osFlags; osFlags &= ~mask;
  return ret;
}
void osThreadFlagsSet(int tid, int f)
{
  (void)tid;

  osFlags |= f;
  return;
}

/**
  * Replace USB Middleware of Keil MDK
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/**
  * @brief  I use USB Middleware from STMicro. The func "MX_USB_DEVICE_Init"
  *         is used to initialize the USB device peripheral.
  * @param  n: Unused
  */
void USBD_Initialize(int n)
{
  (void)n;

  /**
    * I inserted the call of USBD_HID0_Initialize/USBD_HID0_Uninitialize
    * into usbd_custom_hid_if.c. Please refer:
    *
    * line 179  @ usbd_custom_hid_if.c
    * line 191  @ usbd_custom_hid_if.c
    */
  /* USBD_HID0_Initialize(); */
  return;
}
void USBD_Connect(int n)
{
  (void)n;

  return;
}
int USBD_Configured(int n)
{
  (void)n;

  return (hUsbDeviceFS.dev_state == USBD_STATE_CONFIGURED ? 1:0);
}

/**
  * @brief  This routine is used to send a REPORT to the host.
  * @param  a: Unused
  * @param  b: Unused
  * @param  report: Data sent to host
  * @param  len: Data length, usually to be "DAP_PACKET_SIZE"
  */
void USBD_HID_GetReportTrigger(int a, int b, void * report, int len)
{
  (void)a;
  (void)b;

  if (USBD_OK != USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len))
  {
    ;
  }
  return;
}

extern bool USBD_HID0_SetReport (uint8_t rtype, uint8_t req, uint8_t rid, const uint8_t *buf, int32_t len);
/**
  * @brief  This is a bridge routine to connect the USB Middleware and the DAP module.
  *
  *         When a OUTPUT REPORT from the host is got by USB peripheral, a interface func
  *         "CUSTOM_HID_OutEvent_FS" will be invoked by USB Middleware. I did a tiny
  *         modification for the interface func to call USBD_OutEvent. Please refer:
  *
  *         line 99   @ usbd_customhid.h
  *         line 160  @ usbd_custom_hid_if.c
  *         line 206  @ usbd_custom_hid_if.c
  */
void USBD_OutEvent(void)
{
  USBD_CUSTOM_HID_HandleTypeDef *hhid = (USBD_CUSTOM_HID_HandleTypeDef *)hUsbDeviceFS.pClassData;
  USBD_HID0_SetReport(HID_REPORT_OUTPUT, 0, 0, hhid->Report_buf, USBD_CUSTOMHID_OUTREPORT_BUF_SIZE);
}

extern int32_t USBD_HID0_GetReport (uint8_t rtype, uint8_t req, uint8_t rid, uint8_t *buf);
/**
  * @brief  This is a bredge routine to connect the USB Middleware and the DAP module.
  *
  *         After we use "USBD_HID_GetReportTrigger" to send a INPUT REPORT to the host,
  *         an interrupt will be generated by USB peripheral when the host responses an ACK.
  *         The func "USBD_CUSTOM_HID_DataIn" of usbd_customhid.c will be invoked. I added a
  *         new interface func into the structure "USBD_CUSTOM_HID_ItfTypeDef" and inserted
  *         a func call into "USBD_CUSTOM_HID_DataIn". Then this bridge func "USBD_InEvent"
  *         could be invoked by the USB Middleware. Please refer:
  *
  *         line 101  @ usbd_customhid.h
  *         line 218  @ usbd_custom_hid_if.c
  *         line 634  @ usbd_customhid.c
  */
void USBD_InEvent(void)
{
  int32_t len;

  USBD_CUSTOM_HID_HandleTypeDef *hhid = (USBD_CUSTOM_HID_HandleTypeDef *)hUsbDeviceFS.pClassData;
  if ((len=USBD_HID0_GetReport(HID_REPORT_INPUT, USBD_HID_REQ_EP_INT, 0, hhid->Report_buf)) > 0)
  {
    USBD_HID_GetReportTrigger(0, 0, hhid->Report_buf, len);
  }
}
