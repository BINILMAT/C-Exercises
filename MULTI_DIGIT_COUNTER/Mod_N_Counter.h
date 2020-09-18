/*
 * Mod_N_Counter.h
 *
 *  Created on: 17-Sep-2020
 *      Author: binil
 */

#ifndef MOD_N_COUNTER_H_
#define MOD_N_COUNTER_H_

typedef struct
{
	unsigned int max_count_value;
	unsigned int current_count_value;
	unsigned int overflow;



}Mod_N_Counter_t;


void configure_counter(Mod_N_Counter_t* const me,unsigned int max_count);
int increment_counter(Mod_N_Counter_t* const me);
void print_counter(Mod_N_Counter_t* const me);



#endif /* MOD_N_COUNTER_H_ */
