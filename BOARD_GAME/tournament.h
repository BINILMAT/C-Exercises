/*
 * tournament.h
 *
 *  Created on: 17.09.2020
 *      Author: Fromm
 */

#ifndef TOURNAMENT_H_
#define TOURNAMENT_H_

#include "board.h"
#include "global.h"

typedef struct
{
	board_t* boards;
	unsigned short no_boards;
}tournament_t;

RC_t tournament_create(tournament_t * const me, unsigned short no_boards);

RC_t tournament_print(tournament_t const * const me);

RC_t tournament_playBoard(tournament_t * const me, unsigned short board_id, unsigned short row, unsigned short column, char stone);


#endif /* TOURNAMENT_H_ */
