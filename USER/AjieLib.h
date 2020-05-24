#ifndef __AJIELIB_H__
#define __AJIELIB_H__

#include "stm32f10x.h"
#include "stm32f10x_conf.h"

/*===1.GPIO模块===*/
//常用STM32位绑定，方便GPIO的的操作
#define GPIOA_ODR_ADDR (GPIOA_BASE+0x0C)
#define GPIOA_IDR_ADDR (GPIOA_BASE+0x08)
#define GPIOB_ODR_ADDR (GPIOB_BASE+0x0C)
#define GPIOB_IDR_ADDR (GPIOB_BASE+0x08)
#define GPIOC_ODR_ADDR (GPIOC_BASE+0x0C)
#define GPIOC_IDR_ADDR (GPIOC_BASE+0x08)
#define GPIOD_ODR_ADDR (GPIOD_BASE+0x0C)
#define GPIOD_IDR_ADDR (GPIOD_BASE+0x08)
#define GPIOE_ODR_ADDR (GPIOE_BASE+0x0C)
#define GPIOE_IDR_ADDR (GPIOE_BASE+0x08)
#define GPIOF_ODR_ADDR (GPIOF_BASE+0x0C)
#define GPIOF_IDR_ADDR (GPIOF_BASE+0x08)
#define GPIOG_ODR_ADDR (GPIOG_BASE+0x0C)
#define GPIOG_IDR_ADDR (GPIOG_BASE+0x08)
/************************************************
*片上SRAM区：0x2000 0000~0x200f ffff	1M	(n=0-31)
*AliaAddr=0x22000000+((A-0x20000000)*8+n)*4
*片上外设区：0x4000 0000~0x400f ffff	1M	(n=0-31)
*AliaAddr=0x42000000+((A-0x40000000)*8+n)*4
************************************************/
//位绑定公式
#define BitBand(Addr,BitNum) *(volatitle unsigned long *)((Addr&0xF0000000)+0x2000000+((Addr&0xfffff)<<5)+(BitNum<<2))
#define PAout(n) BitBand(GPIOA_ODR_ADDR,n)
#define PAin(n)  BitBand(GPIOA_IDR_ADDR,n)
#define PBout(n) BitBand(GPIOB_ODR_ADDR,n)
#define PBin(n)  BitBand(GPIOB_IDR_ADDR,n)
#define PCout(n) BitBand(GPIOC_ODR_ADDR,n)
#define PCin(n)  BitBand(GPIOC_IDR_ADDR,n)
#define PDout(n) BitBand(GPIOD_ODR_ADDR,n)
#define PDin(n)  BitBand(GPIOD_IDR_ADDR,n)
#define PEout(n) BitBand(GPIOE_ODR_ADDR,n)
#define PEin(n)  BitBand(GPIOE_IDR_ADDR,n)
#define PFout(n) BitBand(GPIOF_ODR_ADDR,n)
#define PFin(n)  BitBand(GPIOF_IDR_ADDR,n)
#define PGout(n) BitBand(GPIOG_ODR_ADDR,n)
#define PGin(n)  BitBand(GPIOG_IDR_ADDR,n)

void GPIOx_Configuration(void);

/*===2.常用的延时函数===*/
void Delay_Init(void);
void Delay_us(u32 nus);
void Delay_ms(u16 nms);

/*===3.RCC模块===*/



/*===4.USART模块===*/
#include "stm32f10x_usart.h"
void USARTx_Configuration(void);

/*===5.NVIC模块===*/


/*===6.ADC模块===*/
/*===6.CAN模块===*/
/*===7.SPI模块===*/
/*===7.看门狗模块===*/
#include "stm32f10x_iwdg.h"
void IWDG_Configuration(u8 prescaler,u16 rlr);



#endif
