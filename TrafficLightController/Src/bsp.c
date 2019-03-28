#include "bsp.h"
#include "timer.h"
int x = 0;
// exported global variables
volatile int Button_Status = 0;

/** @brief  Initialize I/O for lamps
    @retval None
*/
void BSP_Init(void)
{
}

/** @brief  Change lamps to GREEN
    @retval None
*/
void Signal_Pass(void)
{
    printf("x=%d\n",x);
	WALK_OFF();
	if(x == CONSTANT){
	int i;
	for(i=0;i<3;i++){
  WALK_ON();
	Delay(10);
	WALK_OFF();
	Delay(10);
	x = 0;
	}
}

	printf ("Dont Walk Bro!!\n");
	DONT_WALK_ON();
	Delay(20);
	RED_OFF();
	Delay(5);
	GREEN_ON();	
}

/** @brief  Change lamps to RED
    @retval None
*/
void Signal_Block(void)
{
	GREEN_OFF();
		Delay(5);
		YELLOW_ON();
		Delay(10);
		YELLOW_OFF();
		Delay(5);
    RED_ON();
		Delay(20);
		DONT_WALK_OFF();
		Delay(5);
		
		WALK_ON();
		int Walktime = Walk_selected();
		Delay(Walktime);
		
		x = CONSTANT;
}

/** @brief  Flash YELLOW lamp
    @retval None
*/
void Signal_Flash(void)
{
	RED_OFF();
	GREEN_OFF();
	WALK_OFF();
	DONT_WALK_OFF();
	YELLOW_OFF();
	YELLOW_ON();
	Delay(5);
	YELLOW_OFF();
	Delay(5);
}
