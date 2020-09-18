

// We will implement a tournament simulation
// A tournament consts of different board_games
// Every boardgame will consists of different fields, which have different stones placed on them

#include <stdio.h>

#include "board.h"
#include "tournament.h"

int main (void)
{

	board_t myBoard = {0};

	board_create(&myBoard,3, 4, TICTACTOE);

	board_print(&myBoard);

	board_set(&myBoard,1,2,'x');

	board_print(&myBoard);

	board_destroy(&myBoard);

	///

	printf("Tournament\n");

	tournament_t myTournament = {0};
	tournament_create(&myTournament,5);

	tournament_print(&myTournament);

	tournament_playBoard(&myTournament, 1, 1, 2, 'x');
	tournament_print(&myTournament);

	return 0;
}
