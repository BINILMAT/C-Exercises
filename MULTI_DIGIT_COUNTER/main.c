// Standard (system) header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
// Add more header files as required

#include "Mod_N_Counter.h"
#include "Multicounter.h"



int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);

	int maxcount=0,i=0,num_digits=0,overflow=0;
	printf("Welcome to MultiDigit-Counter creation program \n");

	//Mod_N_Counter_t my_counter = {0};

	Multi_counter_t my_multi_counter = {0};


	printf("Enter the number of digits required for counter \n");
	scanf("%d",&num_digits);


	printf("Enter the type of counter \n");
	scanf("%d",&maxcount);


	configure_Multicounter(&my_multi_counter,num_digits,maxcount);


		for(i=0; i < 300; i++)
		{
		print_Multicounter(&my_multi_counter);
		overflow=increment_Multicounter(&my_multi_counter);
		if(overflow==1)
		{
			printf("\n !!! Overflow Occurred ,Resetting the counter \n");
		}

		printf("\n");
		}





	return 0;


}
