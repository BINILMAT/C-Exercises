/*
 * board.c
 *
 *  Created on: 17.09.2020
 *      Author: Fromm
 */

#include "board.h"
#include <stdlib.h>
#include <stdio.h>

#define BOARD_MAXSIZE		50
#define BOARD_MINSIZE		1
#define BOARD_DEFAULTSIZE 	3
#define BOARD_INVALIDPOS	-1

const char* board_gameNames[] = {
		"Chess", "TicTacToe", "4 in a row"
};

static unsigned short board_calcIndex(board_t const * const me, unsigned short row, unsigned short column);


RC_t board_create(board_t * const me, unsigned short no_rows, unsigned short no_columns, game_t typeOfGame)
{


	//Step 1 - are the parameters ok

	if (me == NULL)
	{
		//Dummy user provided null pointer as parameter

		return RC_ERROR_WRONGPARAM;
	}

	if (no_rows >= BOARD_MINSIZE && no_rows <= BOARD_MAXSIZE)
	{
		me->no_rows = no_rows;
	}
	else
	{
		printf("Wrong no_rows value. Take %d as default. \n", BOARD_DEFAULTSIZE);
		me->no_rows = BOARD_DEFAULTSIZE;
	}

	if (no_columns >= BOARD_MINSIZE && no_columns <= BOARD_MAXSIZE)
	{
		me->no_columns = no_columns;
	}
	else
	{
		printf("Wrong no_columns value. Take %d as default.\n", BOARD_DEFAULTSIZE);
		me->no_columns = BOARD_DEFAULTSIZE;
	}

	me->gametype = typeOfGame;

	//STep 2 - Lets claculate any derived value
	//Important: use the corrected me attributes
	me->boardarray = (char*)malloc(me->no_columns * me->no_rows * sizeof(char));

	if (me->boardarray == NULL)
	{
		return RC_ERROR_NOMEMORY;
	}

	//STep 3 - initialise allocated memory
	for (unsigned short i = 0; i < me->no_rows * me->no_columns; i++)
	{
		me->boardarray[i] = '.';
	}

	return RC_OK;
}

RC_t board_print(board_t const * const me)
{
	if (me == NULL)
	{
		//Dummy user provided null pointer as parameter
		return RC_ERROR_WRONGPARAM;
	}

	if (me->boardarray == NULL)
	{
		return RC_ERROR_NOMEMORY;
	}


	printf("Board of the type %d (%s)\n", me->gametype, board_gameNames[me->gametype]);

	//All ok, now let's do the real job
	for (unsigned short r = 0; r < me->no_rows; r++)
	{
		for (unsigned short c = 0; c < me->no_columns; c++)
		{
			int index = board_calcIndex(me,r,c);

			if (index == BOARD_INVALIDPOS)
			{
				return RC_ERROR_OUTOFRANGE;
			}

			printf("%c ", me->boardarray[index]);
		}
		printf("\n");
	}

	printf("\n");

	return RC_OK;

}

RC_t board_set(board_t * const me, unsigned short row, unsigned short column, char stone)
{
	if (me == NULL)
	{
		//Dummy user provided null pointer as parameter
		return RC_ERROR_WRONGPARAM;
	}

	if (me->boardarray == NULL)
	{
		return RC_ERROR_NOMEMORY;
	}

	int index = board_calcIndex(me, row, column);

	if (index == BOARD_INVALIDPOS)
	{
		return RC_ERROR_OUTOFRANGE;
	}

	me->boardarray[index] = stone;


	return RC_OK;
}

RC_t board_destroy(board_t * const me)
{
	if (me == NULL)
	{
		//Dummy user provided null pointer as parameter
		return RC_ERROR_WRONGPARAM;
	}

	if (me->boardarray != NULL)
	{
		free(me->boardarray);
		me->boardarray = 0;
	}

	return RC_OK;

}

static unsigned short board_calcIndex(board_t const * const me, unsigned short row, unsigned short column)
{
	if (me == NULL)
	{
		//Dummy user provided null pointer as parameter
		return BOARD_INVALIDPOS;
	}

	if (row >= me->no_rows || column >= me->no_columns)
	{
		return BOARD_INVALIDPOS;
	}

	return row * me->no_columns + column;

}
