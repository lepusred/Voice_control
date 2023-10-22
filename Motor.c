#include "Motor.h"

////////////////////////////////////////////////////////
void SM_1()
{
	IN1_SET;
	IN2_RESET;
	IN3_RESET;
	IN4_RESET;
	HAL_Delay(2);
}
void SM_2()
{
	IN1_RESET;
	IN2_RESET;
	IN3_RESET;
	IN4_SET;
	HAL_Delay(2);
}
void SM_3()
{
	IN1_RESET;
	IN2_RESET;
	IN3_SET;
	IN4_RESET;
	HAL_Delay(2);
}
void SM_4()
{
	IN1_RESET;
	IN2_SET;
	IN3_RESET;
	IN4_RESET;
	HAL_Delay(2);
}
void SM_Forward()
{
	//SM_1();
	//SM_2();
	//SM_3();
	//SM_4();
	IN11_RESET;
	IN21_RESET;
	IN31_RESET;
	IN41_RESET;
}

void SM_Back()
{
	SM_4();
	SM_3();
	SM_2();
	SM_1();
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
void SM_11()
{
	IN11_SET;
	IN21_RESET;
	IN31_RESET;
	IN41_RESET;
	HAL_Delay(2);
}
void SM_21()
{
	IN11_RESET;
	IN21_RESET;
	IN31_RESET;
	IN41_SET;
	HAL_Delay(2);
}
void SM_31()
{
	IN11_RESET;
	IN21_RESET;
	IN31_SET;
	IN41_RESET;
	HAL_Delay(2);
}
void SM_41()
{
	IN11_RESET;
	IN21_SET;
	IN31_RESET;
	IN41_RESET;
	HAL_Delay(2);
}


void SM_Back1()
{
	SM_11();
	SM_21();
	SM_31();
	SM_41();
}

void SM_Forward1()
{
	//SM_41();
	//SM_31();
	//SM_21();
	//SM_11();
	IN11_SET;
	IN21_SET;
	IN31_SET;
	IN41_SET;
}



