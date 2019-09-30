#line 1 "init.cpp"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f3xx.h"













































 



 



 
    




 extern "C" {

   


 



 

#line 96 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f3xx.h"
   


 





 
   




 
#line 120 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f3xx.h"
                                             


 



 

#line 1 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"









































 



 



 





 extern "C" {




 



 








 
   


 




 
typedef enum
{
 
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      
 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMP_STAMP_IRQn             = 2,       
  RTC_WKUP_IRQn               = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_TSC_IRQn              = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Channel1_IRQn          = 11,      
  DMA1_Channel2_IRQn          = 12,      
  DMA1_Channel3_IRQn          = 13,      
  DMA1_Channel4_IRQn          = 14,      
  DMA1_Channel5_IRQn          = 15,      
  DMA1_Channel6_IRQn          = 16,      
  DMA1_Channel7_IRQn          = 17,      
  ADC1_IRQn                   = 18,      
  CAN_TX_IRQn                 = 19,      
  CAN_RX0_IRQn                = 20,      
  CAN_RX1_IRQn                = 21,      
  CAN_SCE_IRQn                = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM15_IRQn                  = 24,      
  TIM16_IRQn                  = 25,      
  TIM17_IRQn                  = 26,      
  TIM18_DAC2_IRQn             = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTC_Alarm_IRQn              = 41,      
  CEC_IRQn                    = 42,      
  TIM12_IRQn                  = 43,      
  TIM13_IRQn                  = 44,      
  TIM14_IRQn                  = 45,      
  TIM5_IRQn                   = 50,      
  SPI3_IRQn                   = 51,      
  TIM6_DAC1_IRQn              = 54,      
  TIM7_IRQn                   = 55,      
  DMA2_Channel1_IRQn          = 56,      
  DMA2_Channel2_IRQn          = 57,      
  DMA2_Channel3_IRQn          = 58,      
  DMA2_Channel4_IRQn          = 59,      
  DMA2_Channel5_IRQn          = 60,      
  SDADC1_IRQn                 = 61,      
  SDADC2_IRQn                 = 62,      
  SDADC3_IRQn                 = 63,      
  COMP_IRQn                   = 64,      
  USB_HP_IRQn                 = 74,      
  USB_LP_IRQn                 = 75,      
  USBWakeUp_IRQn              = 76,      
  TIM19_IRQn                  = 78,      
  FPU_IRQn                    = 81       
} IRQn_Type;



 

#line 1 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\core_cm4.h"
 




 
















 










#line 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"
     












      namespace std {

          extern "C" {








 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;


#line 247 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"

#line 266 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdint.h"


         }   
      }   





      using ::std::int8_t;
      using ::std::int16_t;
      using ::std::int32_t;
      using ::std::int64_t;
      using ::std::uint8_t;
      using ::std::uint16_t;
      using ::std::uint32_t;
      using ::std::uint64_t;
      using ::std::int_least8_t;
      using ::std::int_least16_t;
      using ::std::int_least32_t;
      using ::std::int_least64_t;
      using ::std::uint_least8_t;
      using ::std::uint_least16_t;
      using ::std::uint_least32_t;
      using ::std::uint_least64_t;
      using ::std::int_fast8_t;
      using ::std::int_fast16_t;
      using ::std::int_fast32_t;
      using ::std::int_fast64_t;
      using ::std::uint_fast8_t;
      using ::std::uint_fast16_t;
      using ::std::uint_fast32_t;
      using ::std::uint_fast64_t;
      using ::std::intptr_t;
      using ::std::uintptr_t;
      using ::std::intmax_t;
      using ::std::uintmax_t;








 
#line 35 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\core_cm4.h"


 extern "C" {














 




 



 

 









 
#line 85 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\core_cm4.h"

#line 159 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\core_cm4.h"

#line 1 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\cmsis_compiler.h"
 




 
















 




#line 29 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\cmsis_compiler.h"



 
#line 1 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\cmsis_armcc.h"
 




 
















 









 












   
   


 
#line 78 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\cmsis_armcc.h"


 



 





 
 






 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}









 







 







 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}






 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xFFU);
}







 
static __inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  register uint32_t __regBasePriMax      __asm("basepri_max");
  __regBasePriMax = (basePri & 0xFFU);
}






 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}






 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1U);
}











 
static __inline uint32_t __get_FPSCR(void)
{


  register uint32_t __regfpscr         __asm("fpscr");
  return(__regfpscr);



}






 
static __inline void __set_FPSCR(uint32_t fpscr)
{


  register uint32_t __regfpscr         __asm("fpscr");
  __regfpscr = (fpscr);

}





 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}








 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 
#line 510 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\cmsis_armcc.h"







 











 












 












 














 














 














 










 









 









 









 

__attribute__((section(".rrx_text"))) static __inline __asm uint32_t __RRX(uint32_t value)
{
  rrx r0, r0
  bx lr
}








 








 








 








 








 








 





   


 



 



#line 777 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\cmsis_armcc.h"











 


#line 35 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\cmsis_compiler.h"




 
#line 208 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\cmsis_compiler.h"




#line 161 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\core_cm4.h"



}










 extern "C" {


 
#line 205 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\core_cm4.h"

 






 
#line 221 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\core_cm4.h"

 




 













 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:16;               
    uint32_t GE:4;                        
    uint32_t _reserved1:7;                
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 





















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:1;                
    uint32_t ICI_IT_1:6;                  
    uint32_t GE:4;                        
    uint32_t _reserved1:4;                
    uint32_t T:1;                         
    uint32_t ICI_IT_2:2;                  
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 

































 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t FPCA:1;                      
    uint32_t _reserved0:29;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 









 







 



 
typedef struct
{
  volatile uint32_t ISER[8U];                
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];                
        uint32_t RSERVED1[24U];
  volatile uint32_t ISPR[8U];                
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];                
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];                
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];                
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                    
}  NVIC_Type;

 



 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
  volatile uint32_t VTOR;                    
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
  volatile uint8_t  SHP[12U];                
  volatile uint32_t SHCSR;                   
  volatile uint32_t CFSR;                    
  volatile uint32_t HFSR;                    
  volatile uint32_t DFSR;                    
  volatile uint32_t MMFAR;                   
  volatile uint32_t BFAR;                    
  volatile uint32_t AFSR;                    
  volatile const  uint32_t PFR[2U];                 
  volatile const  uint32_t DFR;                     
  volatile const  uint32_t ADR;                     
  volatile const  uint32_t MMFR[4U];                
  volatile const  uint32_t ISAR[5U];                
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                   
} SCB_Type;

 















 






























 



 





















 









 


















 










































 









 


















 





















 


















 









 















 







 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const  uint32_t ICTR;                    
  volatile uint32_t ACTLR;                   
} SCnSCB_Type;

 



 















 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 







 



 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                  
    volatile  uint16_t   u16;                 
    volatile  uint32_t   u32;                 
  }  PORT [32U];                          
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;                     
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;                     
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;                     
        uint32_t RESERVED3[29U];
  volatile  uint32_t IWR;                     
  volatile const  uint32_t IRR;                     
  volatile uint32_t IMCR;                    
        uint32_t RESERVED4[43U];
  volatile  uint32_t LAR;                     
  volatile const  uint32_t LSR;                     
        uint32_t RESERVED5[6U];
  volatile const  uint32_t PID4;                    
  volatile const  uint32_t PID5;                    
  volatile const  uint32_t PID6;                    
  volatile const  uint32_t PID7;                    
  volatile const  uint32_t PID0;                    
  volatile const  uint32_t PID1;                    
  volatile const  uint32_t PID2;                    
  volatile const  uint32_t PID3;                    
  volatile const  uint32_t CID0;                    
  volatile const  uint32_t CID1;                    
  volatile const  uint32_t CID2;                    
  volatile const  uint32_t CID3;                    
} ITM_Type;

 



 



























 



 



 



 









   







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t CYCCNT;                  
  volatile uint32_t CPICNT;                  
  volatile uint32_t EXCCNT;                  
  volatile uint32_t SLEEPCNT;                
  volatile uint32_t LSUCNT;                  
  volatile uint32_t FOLDCNT;                 
  volatile const  uint32_t PCSR;                    
  volatile uint32_t COMP0;                   
  volatile uint32_t MASK0;                   
  volatile uint32_t FUNCTION0;               
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;                   
  volatile uint32_t MASK1;                   
  volatile uint32_t FUNCTION1;               
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;                   
  volatile uint32_t MASK2;                   
  volatile uint32_t FUNCTION2;               
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;                   
  volatile uint32_t MASK3;                   
  volatile uint32_t FUNCTION3;               
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   







 



 
typedef struct
{
  volatile uint32_t SSPSR;                   
  volatile uint32_t CSPSR;                   
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;                    
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;                    
        uint32_t RESERVED2[131U];
  volatile const  uint32_t FFSR;                    
  volatile uint32_t FFCR;                    
  volatile const  uint32_t FSCR;                    
        uint32_t RESERVED3[759U];
  volatile const  uint32_t TRIGGER;                 
  volatile const  uint32_t FIFO0;                   
  volatile const  uint32_t ITATBCTR2;               
        uint32_t RESERVED4[1U];
  volatile const  uint32_t ITATBCTR0;               
  volatile const  uint32_t FIFO1;                   
  volatile uint32_t ITCTRL;                  
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;                
  volatile uint32_t CLAIMCLR;                
        uint32_t RESERVED7[8U];
  volatile const  uint32_t DEVID;                   
  volatile const  uint32_t DEVTYPE;                 
} TPI_Type;

 



 



 












 






 



 





















 



 





















 



 



 


















 






   








 



 
typedef struct
{
  volatile const  uint32_t TYPE;                    
  volatile uint32_t CTRL;                    
  volatile uint32_t RNR;                     
  volatile uint32_t RBAR;                    
  volatile uint32_t RASR;                    
  volatile uint32_t RBAR_A1;                 
  volatile uint32_t RASR_A1;                 
  volatile uint32_t RBAR_A2;                 
  volatile uint32_t RASR_A2;                 
  volatile uint32_t RBAR_A3;                 
  volatile uint32_t RASR_A3;                 
} MPU_Type;

 









 









 



 









 






























 








 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile uint32_t FPCCR;                   
  volatile uint32_t FPCAR;                   
  volatile uint32_t FPDSCR;                  
  volatile const  uint32_t MVFR0;                   
  volatile const  uint32_t MVFR1;                   
} FPU_Type;

 



























 



 












 
























 












 







 



 
typedef struct
{
  volatile uint32_t DHCSR;                   
  volatile  uint32_t DCRSR;                   
  volatile uint32_t DCRDR;                   
  volatile uint32_t DEMCR;                   
} CoreDebug_Type;

 




































 






 







































 







 






 







 


 







 

 
#line 1552 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\core_cm4.h"

#line 1561 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\core_cm4.h"









 










 


 



 





 

#line 1609 "C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\5.0.0\\CMSIS\\Include\\core_cm4.h"


















 
static __inline void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);              

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));  
  reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U)                      );               
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}






 
static __inline uint32_t __NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}







 
static __inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}







 
static __inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)(int32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetActive(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)(int32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}










 
static __inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               = (uint8_t)((priority << (8U - 4)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4)) & (uint32_t)0xFFUL);
  }
}










 
static __inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)(int32_t)IRQn)]               >> (8U - 4)));
  }
  else
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)(int32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4)));
  }
}












 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4)) ? (uint32_t)(4) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}












 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4)) ? (uint32_t)(4) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}










 
static __inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
    uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
    vectors[(int32_t)IRQn + 16] = vector;
}









 
static __inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
    uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
    return vectors[(int32_t)IRQn + 16];
}





 
static __inline void NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = (uint32_t)((0x5FAUL << 16U)    |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U)    );          
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 


 





 








 
static __inline uint32_t SCB_GetFPUType(void)
{
  uint32_t mvfr0;

  mvfr0 = ((FPU_Type *) ((0xE000E000UL) + 0x0F30UL) )->MVFR0;
  if      ((mvfr0 & ((0xFUL << 4U) | (0xFUL << 8U))) == 0x020U)
  {
    return 1U;            
  }
  else
  {
    return 0U;            
  }
}


 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 4) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 



 





 

extern volatile int32_t ITM_RxBuffer;                               










 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&       
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL               ) != 0UL)   )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __nop();
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}







 
static __inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;                            

  if (ITM_RxBuffer != ((int32_t)0x5AA55AA5U))
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ((int32_t)0x5AA55AA5U);        
  }

  return (ch);
}







 
static __inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == ((int32_t)0x5AA55AA5U))
  {
    return (0);                               
  }
  else
  {
    return (1);                               
  }
}

 





}




#line 167 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"
#line 1 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\system_stm32f3xx.h"



































  



 



   
  


 




 extern "C" {




 



 




 
  






 
extern uint32_t SystemCoreClock;           




 



 



 



 



 



 
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


 


}






 
  


   
 
#line 168 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"
#line 169 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"



 



 

typedef struct
{
  volatile uint32_t SR;     
  volatile uint32_t CR1;    
  volatile uint32_t CR2;    
  volatile uint32_t SMPR1;  
  volatile uint32_t SMPR2;  
  volatile uint32_t JOFR1;  
  volatile uint32_t JOFR2;  
  volatile uint32_t JOFR3;  
  volatile uint32_t JOFR4;  
  volatile uint32_t HTR;    
  volatile uint32_t LTR;    
  volatile uint32_t SQR1;   
  volatile uint32_t SQR2;   
  volatile uint32_t SQR3;   
  volatile uint32_t JSQR;   
  volatile uint32_t JDR1;   
  volatile uint32_t JDR2;   
  volatile uint32_t JDR3;   
  volatile uint32_t JDR4;   
  volatile uint32_t DR;     
} ADC_TypeDef;




 
typedef struct
{
  volatile uint32_t TIR;   
  volatile uint32_t TDTR;  
  volatile uint32_t TDLR;  
  volatile uint32_t TDHR;  
} CAN_TxMailBox_TypeDef;



 
typedef struct
{
  volatile uint32_t RIR;   
  volatile uint32_t RDTR;  
  volatile uint32_t RDLR;  
  volatile uint32_t RDHR;  
} CAN_FIFOMailBox_TypeDef;



 
typedef struct
{
  volatile uint32_t FR1;  
  volatile uint32_t FR2;  
} CAN_FilterRegister_TypeDef;



 
typedef struct
{
  volatile uint32_t              MCR;                  
  volatile uint32_t              MSR;                  
  volatile uint32_t              TSR;                  
  volatile uint32_t              RF0R;                 
  volatile uint32_t              RF1R;                 
  volatile uint32_t              IER;                  
  volatile uint32_t              ESR;                  
  volatile uint32_t              BTR;                  
  uint32_t                   RESERVED0[88];        
  CAN_TxMailBox_TypeDef      sTxMailBox[3];        
  CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];      
  uint32_t                   RESERVED1[12];        
  volatile uint32_t              FMR;                  
  volatile uint32_t              FM1R;                 
  uint32_t                   RESERVED2;            
  volatile uint32_t              FS1R;                 
  uint32_t                   RESERVED3;            
  volatile uint32_t              FFA1R;                
  uint32_t                   RESERVED4;            
  volatile uint32_t              FA1R;                 
  uint32_t                   RESERVED5[8];         
  CAN_FilterRegister_TypeDef sFilterRegister[28];  
} CAN_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;            
  volatile uint32_t CFGR;          
  volatile uint32_t TXDR;          
  volatile uint32_t RXDR;          
  volatile uint32_t ISR;           
  volatile uint32_t IER;           
}CEC_TypeDef;



 

typedef struct
{
  volatile uint32_t CSR;     
} COMP1_2_TypeDef;

typedef struct
{
  volatile uint16_t CSR;     
} COMP_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;           
  volatile uint8_t  IDR;          
  uint8_t       RESERVED0;    
  uint16_t      RESERVED1;    
  volatile uint32_t CR;           
  uint32_t      RESERVED2;    
  volatile uint32_t INIT;         
  volatile uint32_t POL;          
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;        
  volatile uint32_t SWTRIGR;   
  volatile uint32_t DHR12R1;   
  volatile uint32_t DHR12L1;   
  volatile uint32_t DHR8R1;    
  volatile uint32_t DHR12R2;   
  volatile uint32_t DHR12L2;   
  volatile uint32_t DHR8R2;    
  volatile uint32_t DHR12RD;   
  volatile uint32_t DHR12LD;   
  volatile uint32_t DHR8RD;    
  volatile uint32_t DOR1;      
  volatile uint32_t DOR2;      
  volatile uint32_t SR;        
} DAC_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;   
  volatile uint32_t CR;       
  volatile uint32_t APB1FZ;   
  volatile uint32_t APB2FZ;   
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CCR;           
  volatile uint32_t CNDTR;         
  volatile uint32_t CPAR;          
  volatile uint32_t CMAR;          
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;           
  volatile uint32_t IFCR;          
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t IMR;           
  volatile uint32_t EMR;           
  volatile uint32_t RTSR;          
  volatile uint32_t FTSR;          
  volatile uint32_t SWIER;         
  volatile uint32_t PR;            
}EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;           
  volatile uint32_t KEYR;          
  volatile uint32_t OPTKEYR;       
  volatile uint32_t SR;            
  volatile uint32_t CR;            
  volatile uint32_t AR;            
  uint32_t      RESERVED;      
  volatile uint32_t OBR;           
  volatile uint32_t WRPR;          

} FLASH_TypeDef;



 
typedef struct
{
  volatile uint16_t RDP;           
  volatile uint16_t USER;          
  uint16_t RESERVED0;          
  uint16_t RESERVED1;          
  volatile uint16_t WRP0;          
  volatile uint16_t WRP1;          
  volatile uint16_t WRP2;          
  volatile uint16_t WRP3;          
} OB_TypeDef;



 

typedef struct
{
  volatile uint32_t MODER;         
  volatile uint32_t OTYPER;        
  volatile uint32_t OSPEEDR;       
  volatile uint32_t PUPDR;         
  volatile uint32_t IDR;           
  volatile uint32_t ODR;           
  volatile uint16_t BSRRL;         
  volatile uint16_t BSRRH;         
  volatile uint32_t LCKR;          
  volatile uint32_t AFR[2];        
  volatile uint32_t BRR;           
}GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t CFGR1;        
       uint32_t RESERVED;     
  volatile uint32_t EXTICR[4];    
  volatile uint32_t CFGR2;        
} SYSCFG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;       
  volatile uint32_t CR2;       
  volatile uint32_t OAR1;      
  volatile uint32_t OAR2;      
  volatile uint32_t TIMINGR;   
  volatile uint32_t TIMEOUTR;  
  volatile uint32_t ISR;       
  volatile uint32_t ICR;       
  volatile uint32_t PECR;      
  volatile uint32_t RXDR;      
  volatile uint32_t TXDR;      
}I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;    
  volatile uint32_t PR;    
  volatile uint32_t RLR;   
  volatile uint32_t SR;    
  volatile uint32_t WINR;  
} IWDG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CSR;   
} PWR_TypeDef;



 
typedef struct
{
  volatile uint32_t CR;          
  volatile uint32_t CFGR;        
  volatile uint32_t CIR;         
  volatile uint32_t APB2RSTR;    
  volatile uint32_t APB1RSTR;    
  volatile uint32_t AHBENR;      
  volatile uint32_t APB2ENR;     
  volatile uint32_t APB1ENR;     
  volatile uint32_t BDCR;        
  volatile uint32_t CSR;         
  volatile uint32_t AHBRSTR;     
  volatile uint32_t CFGR2;       
  volatile uint32_t CFGR3;       
} RCC_TypeDef;



 

typedef struct
{
  volatile uint32_t TR;          
  volatile uint32_t DR;          
  volatile uint32_t CR;          
  volatile uint32_t ISR;         
  volatile uint32_t PRER;        
  volatile uint32_t WUTR;        
  uint32_t RESERVED0;        
  volatile uint32_t ALRMAR;      
  volatile uint32_t ALRMBR;      
  volatile uint32_t WPR;         
  volatile uint32_t SSR;         
  volatile uint32_t SHIFTR;      
  volatile uint32_t TSTR;        
  volatile uint32_t TSDR;        
  volatile uint32_t TSSSR;       
  volatile uint32_t CALR;        
  volatile uint32_t TAFCR;       
  volatile uint32_t ALRMASSR;    
  volatile uint32_t ALRMBSSR;    
  uint32_t RESERVED7;        
  volatile uint32_t BKP0R;       
  volatile uint32_t BKP1R;       
  volatile uint32_t BKP2R;       
  volatile uint32_t BKP3R;       
  volatile uint32_t BKP4R;       
  volatile uint32_t BKP5R;       
  volatile uint32_t BKP6R;       
  volatile uint32_t BKP7R;       
  volatile uint32_t BKP8R;       
  volatile uint32_t BKP9R;       
  volatile uint32_t BKP10R;      
  volatile uint32_t BKP11R;      
  volatile uint32_t BKP12R;      
  volatile uint32_t BKP13R;      
  volatile uint32_t BKP14R;      
  volatile uint32_t BKP15R;      
  volatile uint32_t BKP16R;      
  volatile uint32_t BKP17R;      
  volatile uint32_t BKP18R;      
  volatile uint32_t BKP19R;      
  volatile uint32_t BKP20R;      
  volatile uint32_t BKP21R;      
  volatile uint32_t BKP22R;      
  volatile uint32_t BKP23R;      
  volatile uint32_t BKP24R;      
  volatile uint32_t BKP25R;      
  volatile uint32_t BKP26R;      
  volatile uint32_t BKP27R;      
  volatile uint32_t BKP28R;      
  volatile uint32_t BKP29R;      
  volatile uint32_t BKP30R;      
  volatile uint32_t BKP31R;      
} RTC_TypeDef;




 

typedef struct
{
  volatile uint32_t CR1;           
  volatile uint32_t CR2;           
  volatile uint32_t ISR;           
  volatile uint32_t CLRISR;        
  volatile uint32_t RESERVED0;     
  volatile uint32_t JCHGR;         
  volatile uint32_t RESERVED1;     
  volatile uint32_t RESERVED2;     
  volatile uint32_t CONF0R;        
  volatile uint32_t CONF1R;        
  volatile uint32_t CONF2R;        
  volatile uint32_t RESERVED3[5];  
  volatile uint32_t CONFCHR1;      
  volatile uint32_t CONFCHR2;      
  volatile uint32_t RESERVED4[6];  
  volatile uint32_t JDATAR;        
  volatile uint32_t RDATAR;        
  volatile uint32_t RESERVED5[2];  
  volatile uint32_t JDATA12R;      
  volatile uint32_t RDATA12R;      
  volatile uint32_t JDATA13R;      
  volatile uint32_t RDATA13R;      
} SDADC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;       
  volatile uint32_t CR2;       
  volatile uint32_t SR;        
  volatile uint32_t DR;        
  volatile uint32_t CRCPR;     
  volatile uint32_t RXCRCR;    
  volatile uint32_t TXCRCR;    
  volatile uint32_t I2SCFGR;   
  volatile uint32_t I2SPR;     
} SPI_TypeDef;



 
typedef struct
{
  volatile uint32_t CR1;          
  volatile uint32_t CR2;          
  volatile uint32_t SMCR;         
  volatile uint32_t DIER;         
  volatile uint32_t SR;           
  volatile uint32_t EGR;          
  volatile uint32_t CCMR1;        
  volatile uint32_t CCMR2;        
  volatile uint32_t CCER;         
  volatile uint32_t CNT;          
  volatile uint32_t PSC;          
  volatile uint32_t ARR;          
  volatile uint32_t RCR;          
  volatile uint32_t CCR1;         
  volatile uint32_t CCR2;         
  volatile uint32_t CCR3;         
  volatile uint32_t CCR4;         
  volatile uint32_t BDTR;         
  volatile uint32_t DCR;          
  volatile uint32_t DMAR;         
  volatile uint32_t OR;           
} TIM_TypeDef;



 
typedef struct
{
  volatile uint32_t CR;             
  volatile uint32_t IER;            
  volatile uint32_t ICR;            
  volatile uint32_t ISR;            
  volatile uint32_t IOHCR;          
  uint32_t      RESERVED1;      
  volatile uint32_t IOASCR;         
  uint32_t      RESERVED2;      
  volatile uint32_t IOSCR;          
  uint32_t      RESERVED3;      
  volatile uint32_t IOCCR;          
  uint32_t      RESERVED4;      
  volatile uint32_t IOGCSR;         
  volatile uint32_t IOGXCR[8];      
} TSC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;     
  volatile uint32_t CR2;     
  volatile uint32_t CR3;     
  volatile uint32_t BRR;     
  volatile uint32_t GTPR;    
  volatile uint32_t RTOR;    
  volatile uint32_t RQR;     
  volatile uint32_t ISR;     
  volatile uint32_t ICR;     
  volatile uint16_t RDR;     
  uint16_t  RESERVED1;   
  volatile uint16_t TDR;     
  uint16_t  RESERVED2;   
} USART_TypeDef;



 
  
typedef struct
{
  volatile uint16_t EP0R;              
  volatile uint16_t RESERVED0;             
  volatile uint16_t EP1R;             
  volatile uint16_t RESERVED1;               
  volatile uint16_t EP2R;             
  volatile uint16_t RESERVED2;               
  volatile uint16_t EP3R;              
  volatile uint16_t RESERVED3;               
  volatile uint16_t EP4R;             
  volatile uint16_t RESERVED4;               
  volatile uint16_t EP5R;             
  volatile uint16_t RESERVED5;               
  volatile uint16_t EP6R;             
  volatile uint16_t RESERVED6;               
  volatile uint16_t EP7R;             
  volatile uint16_t RESERVED7[17];         
  volatile uint16_t CNTR;             
  volatile uint16_t RESERVED8;               
  volatile uint16_t ISTR;             
  volatile uint16_t RESERVED9;               
  volatile uint16_t FNR;              
  volatile uint16_t RESERVEDA;               
  volatile uint16_t DADDR;            
  volatile uint16_t RESERVEDB;               
  volatile uint16_t BTABLE;           
  volatile uint16_t RESERVEDC;               
} USB_TypeDef;



 
typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CFR;   
  volatile uint32_t SR;    
} WWDG_TypeDef;



 









 





 
#line 767 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 782 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 803 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 811 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"




 



 
#line 887 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"


 



 

  

 

 
 
 

 
 
 
 
 

 






 
#line 937 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 958 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 996 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1038 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 


 


 


 


 
#line 1087 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1125 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1163 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1192 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 


 


 


 
 
 
 
 

 
 
#line 1235 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"
 
#line 1255 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"
 
#line 1275 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
 
 
 
 
 
#line 1291 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1302 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1320 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"











 





 





 
#line 1358 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 












 
#line 1388 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
 






 




 





 





 






 




 





 





 






 




 





 





 





 




 





 





 





 




 





 





 
 


 
#line 1528 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1545 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1562 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1579 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1613 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1647 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1681 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1715 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1749 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1783 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1817 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1851 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1885 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1919 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1953 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 1987 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2021 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2055 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2089 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2123 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2157 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2191 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2225 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2259 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2293 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2327 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2361 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2395 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2429 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2463 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2497 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2531 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
 
 
 
 
 


 


 
#line 2552 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 
 
 
 
 
 











































 



 


 


 


 


 


 


 



 



 



 


 


 



 
 
 
 
 
 



 









 
#line 2688 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 





 
 
 
 
 
 
#line 2729 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2759 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2769 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"















 


 


 


 
 
 
 
 
 
#line 2828 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2859 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2890 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2921 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2952 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 2983 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
 
 
 
 
 








 





 





 





 
#line 3028 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 




#line 3045 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 

 



 



 



 



 



 


 
 
 
 
 
 
#line 3128 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3146 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3196 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3246 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3264 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3282 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3316 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3335 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3345 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3355 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3373 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
 
 
 
 
 
#line 3401 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3414 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 




 




 






 






 
#line 3457 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3468 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 



 
 
 
 
 
 


 





 


 




 


 
 
 
 
 

 




 
#line 3525 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 
#line 3546 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3561 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
 
 
 
 
 











 
#line 3588 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"






 









 
 
 
 
 
 



#line 3619 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

#line 3629 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

#line 3636 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
 








 








 






#line 3672 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 











 











 

















 






#line 3737 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 





 





#line 3757 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3765 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

#line 3783 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3802 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3815 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3840 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3854 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3867 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3892 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 













 








 
#line 3928 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 3937 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
 






#line 3962 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 









































 
 
 
 
 
 
#line 4038 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4068 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4095 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4114 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 



 


 
#line 4163 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4205 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 



 
#line 4244 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4264 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 
#line 4282 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4304 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4312 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4320 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 
 
 
 
 

 
#line 4443 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4469 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4481 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 




 
#line 4498 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4511 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4524 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4537 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4547 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 
#line 4558 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 



 



 



 



 
 
 
 
 
 
#line 4601 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4619 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4636 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 


 


 
#line 4664 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 




 
 
 
 
 
 
#line 4699 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 







 
#line 4715 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"



 
#line 4725 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"



 
#line 4735 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"



 






 







 
#line 4760 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"



 








 
#line 4779 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"



 
#line 4789 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 







 








 
#line 4814 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"



 
#line 4824 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"



 






 







 







 







 








 






 





 
 
 
 
 
 

















 









#line 4921 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 



























 
#line 4966 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4980 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 4990 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 




























 





















 




























 





















 
#line 5109 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 


 


 


 


 


 


 
#line 5144 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"





#line 5155 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5163 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

#line 5170 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 




 




 
 
 
 
 
 



















#line 5217 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"













 



 



 



 
#line 5275 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5309 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5343 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5377 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5395 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 
 
 
 
 
 
#line 5436 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5460 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5486 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 



 




 



 






 
#line 5530 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5544 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 
 
 
 
 






 
#line 5573 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

#line 5582 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5597 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 






 



 
#line 5618 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"
  
#line 5629 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 

                                                                                
#line 5639 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"
                                                                 

                                                                                
#line 5649 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"
                                                                                
#line 5657 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
 
 
 
 
 
#line 5672 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"



 
#line 5684 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"







 




 

 

 



 

 


 


 


 



 


 


 


 


    
#line 5739 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5753 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5761 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 



 




 


 


 




 



 




 
#line 5807 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5821 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5831 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5839 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5847 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"
    
 

 
#line 5859 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5867 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5875 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5885 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5895 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5903 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5911 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 
#line 5922 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5934 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 5944 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 




 
#line 5960 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 





 
#line 6018 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 6029 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 6037 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 





 
#line 6057 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 


 
#line 6077 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 6091 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 


 




 


 




 




 



                                      
 



                                      
 



                                          
 




 




 




 




 




 




 


 




 


 
 
 
 
  
 
 

 

#line 6187 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"

 
#line 6197 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f373xc.h"


}






 

  

 

 
#line 145 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f3xx.h"
#line 160 "C:\\Keil_v5\\ARM\\PACK\\Keil\\STM32F3xx_DFP\\1.3.0\\Device\\Include\\stm32f3xx.h"



 



  
typedef enum 
{
  RESET = 0, 
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum 
{
  DISABLE = 0, 
  ENABLE = !DISABLE
} FunctionalState;


typedef enum 
{
  ERROR = 0, 
  SUCCESS = !ERROR
} ErrorStatus;



 




 
























 



}





 



 
  



 
#line 2 "init.cpp"
#line 1 "init.h"



void init_RCC(void);

#line 3 "init.cpp"

void init_RCC(void)
{
	
}
