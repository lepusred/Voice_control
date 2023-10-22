#include "lcd.h"
extern I2C_HandleTypeDef hi2c1;
uint8_t buf[1]={0};
uint8_t portlcd=0;
void I2C_WriteByte(uint8_t bt)
{
	buf[0]=bt;
	HAL_I2C_Master_Transmit (&hi2c1, (uint16_t) 0x4E, buf, 1, 1000);
}

__STATIC_INLINE void DelayMicro(__IO uint32_t micros)

{

           micros *=(SystemCoreClock / 1000000) / 5;

}
void sendhalfbyte(uint8_t dt) 
{
	dt<<=4;
	e1;
	DelayMicro(50);
	I2C_WriteByte(portlcd|dt);
	e0;
	DelayMicro(50);
}
void sendbyte(uint8_t dt) {
	rs0;
	uint8_t c=0;
	c=dt>>4;
	sendhalfbyte(c);
	sendhalfbyte(dt);
}
void LCD_Data(uint8_t dt) {
	rs1;
	uint8_t c=dt>>4;
	sendhalfbyte(c);
	sendhalfbyte(dt);
}
void LCD_Ini() {
	HAL_Delay(40);
	rs0;
  sendhalfbyte(0x03);
  HAL_Delay(5);
  sendhalfbyte(0x03);
  DelayMicro(100);
  sendhalfbyte(0x03);
  HAL_Delay(1);
  sendhalfbyte(0x02);
  HAL_Delay(1);
  sendbyte(0x28); 
	HAL_Delay(1);
  sendbyte(0x0C); 
  HAL_Delay(1);
  sendbyte(0x6); 
  HAL_Delay(1);
	sendbyte(0x2); 
  HAL_Delay(1);
	sendbyte(0x1); 
  HAL_Delay(2);
	led1;
	rw0;
}
void LCD_Clear()
{
	sendbyte(0x01);
	HAL_Delay(2);
}
void LCD_SendChar(char ch)
{
	LCD_Data((uint8_t)ch);
	DelayMicro(15);
}
void LCD_SendString(char* st)
{
	uint16_t i=0;
	while (st[i]!=0)
	{
		LCD_Data(st[i]);
		DelayMicro(15);
		i++;
	}
}
void LCD_SetPos(uint8_t x, uint8_t y)
{
	switch(y)
	{
		case 0: sendbyte(x|0x80); break;
	  case 1: sendbyte(0x40+x|0x80); break;
	}
}

