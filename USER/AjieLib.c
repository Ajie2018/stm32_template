#include "AjieLib.h"

/*===1.GPIO模块===*/
void GPIOx_Configuration(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
}

/*===2.常用的延时函数===*/
static u8 fac_us=0;		//us延时因子
static u16 fac_ms=0;	//ms延时因子
void Delay_Init(void){
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
	fac_us=SystemCoreClock/8000000;
	fac_ms=(u16)fac_us*1000;
}
void Delay_us(u32 nus){
	u32 temp;
	SysTick->LOAD=nus*fac_us;	//时间加载
	SysTick->VAL=0x00;			//计数器清零
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;	//开始倒计时
	do{
		temp=SysTick->CTRL;
	}while((temp & 0x01) && !(temp & (1<<16)));
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;	//停止倒计时
	SysTick->VAL=0x00;			//计数器清零
}
//SysTick->LOAD为24位寄存器，nms<=0ffffffff*8/SYSCLK
void Delay_ms(u16 nms){//在72M时针下，最大延时nms<=1864
	u32 temp;
	SysTick->LOAD=(u32)nms*fac_ms;	//时间加载
	SysTick->VAL=0x00;			//计数器清零
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;	//开始倒计时
	do{
		temp=SysTick->CTRL;
	}while((temp & 0x01) && !(temp & (1<<16)));
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;	//停止倒计时
	SysTick->VAL=0x00;			//计数器清零
}

/*===3.USART模块===*/
#ifdef MODULE_USART_ON
void USARTx_Configuration(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
}
#endif



/*===7.看门狗模块===*/
void IWDG_Configuration(u8 prescaler,u16 rlr){
	IWDG_WriteAccessCmd(0x5555);
	IWDG_SetPrescaler(0x25);
}

