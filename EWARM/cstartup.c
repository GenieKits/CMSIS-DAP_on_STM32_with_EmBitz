#include "stm32f1xx_it.h"

typedef void( handler_t )( void );
typedef union { handler_t * handler; void * ptr; } intvec_elem;

#pragma language=extended
#pragma segment="CSTACK"

void __iar_program_start( void );

typedef struct
{
  intvec_elem _sfe_CSTACK;
  intvec_elem _program_start;
  
  intvec_elem _NMI_Handler               ; //NMI Handler
  intvec_elem _HardFault_Handler         ; //Hard Fault Handler
  intvec_elem _MemManage_Handler         ; //MPU Fault Handler
  intvec_elem _BusFault_Handler          ; //Bus Fault Handler
  intvec_elem _UsageFault_Handler        ; //Usage Fault Handler
  intvec_elem _Reserved1                 ; //Reserved
  intvec_elem _Reserved2                 ; //Reserved
  intvec_elem _Reserved3                 ; //Reserved
  intvec_elem _Reserved4                 ; //Reserved
  intvec_elem _SVC_Handler               ; //SVCall Handler
  intvec_elem _DebugMon_Handler          ; //Debug Monitor Handler
  intvec_elem _Reserved5                 ; //Reserved
  intvec_elem _PendSV_Handler            ; //PendSV Handler
  intvec_elem _SysTick_Handler           ; //SysTick Handler

  intvec_elem _WWDG_IRQHandler           ; //Window Watchdog
  intvec_elem _PVD_IRQHandler            ; //PVD through EXTI Line detect
  intvec_elem _TAMPER_IRQHandler         ; //Tamper
  intvec_elem _RTC_IRQHandler            ; //RTC
  intvec_elem _FLASH_IRQHandler          ; //Flash
  intvec_elem _RCC_IRQHandler            ; //RCC
  intvec_elem _EXTI0_IRQHandler          ; //EXTI Line 0
  intvec_elem _EXTI1_IRQHandler          ; //EXTI Line 1
  intvec_elem _EXTI2_IRQHandler          ; //EXTI Line 2
  intvec_elem _EXTI3_IRQHandler          ; //EXTI Line 3
  intvec_elem _EXTI4_IRQHandler          ; //EXTI Line 4
  intvec_elem _DMA1_Channel1_IRQHandler  ; //DMA1 Channel 1
  intvec_elem _DMA1_Channel2_IRQHandler  ; //DMA1 Channel 2
  intvec_elem _DMA1_Channel3_IRQHandler  ; //DMA1 Channel 3
  intvec_elem _DMA1_Channel4_IRQHandler  ; //DMA1 Channel 4
  intvec_elem _DMA1_Channel5_IRQHandler  ; //DMA1 Channel 5
  intvec_elem _DMA1_Channel6_IRQHandler  ; //DMA1 Channel 6
  intvec_elem _DMA1_Channel7_IRQHandler  ; //DMA1 Channel 7
  intvec_elem _ADC1_2_IRQHandler         ; //ADC1 & ADC2
  intvec_elem _USB_HP_CAN1_TX_IRQHandler ; //USB High Priority or CAN1 TX
  intvec_elem _USB_LP_CAN1_RX0_IRQHandler; //USB Low  Priority or CAN1 RX0
  intvec_elem _CAN1_RX1_IRQHandler       ; //CAN1 RX1
  intvec_elem _CAN1_SCE_IRQHandler       ; //CAN1 SCE
  intvec_elem _EXTI9_5_IRQHandler        ; //EXTI Line 9..5
  intvec_elem _TIM1_BRK_IRQHandler       ; //TIM1 Break
  intvec_elem _TIM1_UP_IRQHandler        ; //TIM1 Update
  intvec_elem _TIM1_TRG_COM_IRQHandler   ; //TIM1 Trigger and Commutation
  intvec_elem _TIM1_CC_IRQHandler        ; //TIM1 Capture Compare
  intvec_elem _TIM2_IRQHandler           ; //TIM2
  intvec_elem _TIM3_IRQHandler           ; //TIM3
  intvec_elem _TIM4_IRQHandler           ; //TIM4
  intvec_elem _I2C1_EV_IRQHandler        ; //I2C1 Event
  intvec_elem _I2C1_ER_IRQHandler        ; //I2C1 Error
  intvec_elem _I2C2_EV_IRQHandler        ; //I2C2 Event
  intvec_elem _I2C2_ER_IRQHandler        ; //I2C2 Error
  intvec_elem _SPI1_IRQHandler           ; //SPI1
  intvec_elem _SPI2_IRQHandler           ; //SPI2
  intvec_elem _USART1_IRQHandler         ; //USART1
  intvec_elem _USART2_IRQHandler         ; //USART2
  intvec_elem _USART3_IRQHandler         ; //USART3
  intvec_elem _EXTI15_10_IRQHandler      ; //EXTI Line 15..10
  intvec_elem _RTCAlarm_IRQHandler       ; //RTC Alarm through EXTI Line
  intvec_elem _USBWakeUp_IRQHandler      ; //USB Wakeup from suspend
}vector_table_t;


const vector_table_t __vector_table @ ".intvec" =
{
  ._sfe_CSTACK.ptr              = __sfe( "CSTACK" ) ,
  ._program_start               = __iar_program_start,
  ._NMI_Handler                 = NMI_Handler,
  ._HardFault_Handler           = HardFault_Handler,
  
  ._MemManage_Handler           = MemManage_Handler,  
  ._BusFault_Handler            = BusFault_Handler,   
  ._UsageFault_Handler          = UsageFault_Handler,
  ._UsageFault_Handler          = UsageFault_Handler, 
  ._SVC_Handler                 = SVC_Handler,        
  ._DebugMon_Handler            = DebugMon_Handler,   
  ._PendSV_Handler              = PendSV_Handler,     
  ._SysTick_Handler             = SysTick_Handler,    
  ._USB_LP_CAN1_RX0_IRQHandler  = USB_LP_CAN1_RX0_IRQHandler,
  ._SPI1_IRQHandler             = SPI1_IRQHandler,
  ._USART1_IRQHandler           = USART1_IRQHandler,
};
