/*
 * Multicounter.c
 *
 *  Created on: 17-Sep-2020
 *      Author: binil
 */

#include "Multicounter.h"
#include <stdlib.h>
#include <stdio.h>

int configure_Multicounter(Multi_counter_t* const me,unsigned int digits_num,unsigned int maxcount)
{
	int i=0,maxcount_correct=0;

	if((maxcount == 2) ||(maxcount == 8) ||(maxcount == 10) ||(maxcount == 16))
	{
		maxcount_correct=1;
	}

	if((digits_num==0) || (maxcount_correct==0))
	{
		return 0;
	}

	//Store the (number of digits used or number of counters required ) in the structure
	me->digits_number=digits_num;

	//Allocate memory for all the counters
	me->Mod_N_Counter=(Mod_N_Counter_t*)malloc(me->digits_number*sizeof(Mod_N_Counter_t));

	//Initialize/assign the allocated memory for all counters
	for(i=0;i<me->digits_number;i++)
	{
		configure_counter(&(me->Mod_N_Counter[i]),maxcount);
	}

	return 1;

}


int increment_Multicounter(Multi_counter_t* const me)
{
	int overflow=0;
	for(unsigned int i=0;i<me->digits_number;i++)
	{
		overflow=increment_counter(&(me->Mod_N_Counter[i]));
		if(overflow == 0)
		{
			return 0;
		}
	}
	return 1;

}




void print_Multicounter(const Multi_counter_t* const me)
{


//		for(unsigned int i=0;i<me->digits_number;i++)
//			{
//			print_counter(&(me->Mod_N_Counter[i]));
//			}

	for(int i=me->digits_number-1;i>=0;i--)
		{
		print_counter(&(me->Mod_N_Counter[i]));
		}

}
