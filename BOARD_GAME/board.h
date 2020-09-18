/*
 * board.h
 *
 *  Created on: 17.09.2020
 *      Author: Fromm
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "global.h"

typedef enum {CHESS = 0, TICTACTOE, FOURINAROW} game_t;

typedef struct {
	unsigned short no_rows;
	unsigned short no_columns;

	char* boardarray;

	game_t gametype;

}board_t;

RC_t board_create(board_t * const me, unsigned short no_rows, unsigned short no_columns, game_t typeOfGame);

RC_t board_print(board_t const * const me);

RC_t board_set(board_t * const me, unsigned short row, unsigned short column, char stone);

RC_t board_destroy(board_t * const me);

#endif /* BOARD_H_ */
