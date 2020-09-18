/*
 * tournament.c
 *
 *  Created on: 17.09.2020
 *      Author: Fromm
 */

#include "tournament.h"
#include <stdlib.h>
#include <stdio.h>


#define TOURNAMENT_MINSIZE	1
#define TOURNAMENT_MAXSIZE	10
#define TOURNAMENT_DEFAULTSIZE	10

#define TOURNAMENT_BOARDROWS	3
#define TOURNAMENT_BOARDCOLUMNS	4
#define TOURNAMENT_BOARDTYPE	CHESS

RC_t tournament_create(tournament_t * const me, unsigned short no_boards)
{
	//Step 1 - are the parameters ok

		if (me == NULL)
		{
			//Dummy user provided null pointer as parameter
			return RC_ERROR_WRONGPARAM;
		}

		if (no_boards >= TOURNAMENT_MINSIZE && no_boards <= TOURNAMENT_MAXSIZE)
		{
			me->no_boards = no_boards;
		}
		else
		{
			printf("Wrong no_boards value. Take %d as default.\n", TOURNAMENT_DEFAULTSIZE);
			me->no_boards = TOURNAMENT_DEFAULTSIZE;
		}


		//STep 2 - Lets claculate any derived value
		//Important: use the corrected me attributes
		me->boards = (board_t*)malloc(me->no_boards * sizeof(board_t));

		if (me->boards == NULL)
		{
			return RC_ERROR_NOMEMORY;
		}

		//Step 3 - initialise allocated memory
		for (unsigned short i = 0; i < me->no_boards; i++)
		{
			board_create(&(me->boards[i]), TOURNAMENT_BOARDROWS, TOURNAMENT_BOARDCOLUMNS, TOURNAMENT_BOARDTYPE);
		}

		return RC_OK;

}

RC_t tournament_print(tournament_t const * const me)
{
	//Ommitted error handling

	printf("Tournamnet having %d boards: \n\n",me->no_boards);

	for (unsigned short i = 0; i < me->no_boards; i++)
	{
		printf("Board %d:\n", i+1);
		board_print(&me->boards[i]);
	}

	return RC_OK;
}


RC_t tournament_playBoard(tournament_t * const me, unsigned short board_id, unsigned short row, unsigned short column, char stone)
{
	//No errorhandling

	return board_set(&me->boards[board_id], row, column, stone);


}
