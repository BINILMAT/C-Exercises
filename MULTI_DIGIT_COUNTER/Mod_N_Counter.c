/*
 * Mod_N_Counter.c
 *
 *  Created on: 17-Sep-2020
 *      Author: binil
 */



#include <stdio.h>
#include "Mod_N_Counter.h"
int COUNTER_NAME=0;


void configure_counter(Mod_N_Counter_t* const me,unsigned int max_count)
{
	me->max_count_value=max_count;
	me->current_count_value=0;
	me->overflow=0;

}


int increment_counter(Mod_N_Counter_t* const me)
{

	me->current_count_value=me->current_count_value+1;
	if(me->current_count_value==me->max_count_value)
	{
		//printf("\n\n!!! Overflow Occured, Resetting the counter to 0 \n");
		me->overflow=me->overflow+1;
		me->current_count_value=0;
		return 1;
	}

	return 0;


}


void print_counter(Mod_N_Counter_t* const me)
{
//	if(COUNTER_NAME == 0)
//	{
//		printf("Modulo %d Counter \n",me->max_count_value);
//		printf("\nCurrent counter value = %d  \n",me->current_count_value);
//		COUNTER_NAME=1;
//	}
//	else
//	{
		switch (me->current_count_value)
		{

		case 10:printf("A");break;
		case 11:printf("B");break;
		case 12:printf("C");break;
		case 13:printf("D");break;
		case 14:printf("E");break;
		case 15:printf("F");break;
		default:printf("%d",me->current_count_value);break;

		}

//	}

}
