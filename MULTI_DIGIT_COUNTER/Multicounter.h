/*
 * Multicounter.h
 *
 *  Created on: 17-Sep-2020
 *      Author: binil
 */

#ifndef MULTICOUNTER_H_
#define MULTICOUNTER_H_

#include "Mod_N_Counter.h"

typedef struct Multi_counter
{
	Mod_N_Counter_t* Mod_N_Counter;
	int digits_number;

}Multi_counter_t;

int configure_Multicounter(Multi_counter_t* const me,unsigned int digits_num,unsigned int maxcount);

int increment_Multicounter(Multi_counter_t* const me);

void print_Multicounter(const Multi_counter_t* const me);

#endif /* MULTICOUNTER_H_ */
