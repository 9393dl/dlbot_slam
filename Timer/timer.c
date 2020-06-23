#include "timer.h"
#include "led.h"

//ͨ�ö�ʱ���жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!

//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void PWM_Init(u16 arr,u16 psc,u16 ccr1,u16 ccr2)
{		 					 
	//�˲������ֶ��޸�IO������
	RCC->APB1ENR|=1<<1;       //TIM3ʱ��ʹ��
	RCC->APB2ENR|=1<<2;      //ʹ��GPIOA


	GPIOA->CRL&=0X00FFFFFF;//PA7 PA6���
	GPIOA->CRL|=0XBB000000;//���ù������ 	  
	GPIOA->ODR|=0<<7;//PA7����
	GPIOA->ODR|=0<<6;


	TIM3->ARR=arr-1;//�趨�������Զ���װֵ 
	TIM3->PSC=psc;//Ԥ��Ƶ������Ƶ
	
	TIM3->CCMR1|=7<<12;  //CH2 PWM2ģʽ		 
	TIM3->CCMR1|=1<<11; //CH2Ԥװ��ʹ��
	TIM3->CCMR1|=7<<4;   //CH1 ʹ��
 	TIM3->CCMR1|=1<<3;   //CH1Ԥװ��ʹ��
		   
	TIM3->CR1&=0<<4;     //���ϼ���ģʽ
	TIM3->CCER|=1<<4;   //OC2 ���ʹ��	
	TIM3->CCER|=1<<0;   // OC1 ���ʹ��
	
	TIM3->BDTR|=1<<15;  //����OC��OCN��

	TIM3->CCR1=ccr1; //�趨ռ�ձ�
    TIM3->CCR2=ccr2; 
    TIM3->EGR|=1<<0;    //���³�ʼ��������	

	TIM3->CR1=0x8000;   //ARPEʹ�� 
	TIM3->CR1|=0x01;    //ʹ�ܶ�ʱ��3 		



  
}
 	 
















