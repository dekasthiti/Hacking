#include <iostream>


using namespace std;

class Person {

public: 
    Person(){}
	Person(int myEntry) : entry(myEntry) { status = -1; }
	void setStatus(int myStatus)
	{
		status = myStatus;
	}
private:
	int entry; // 1 or 0 -> convert from char 'x' or 'o'
	int status; // win:1, loss:0, can't tell: -1
};

class TicTacToeBoard {

public: 
	TicTacToeBoard()
	{
		for (int i = 0; i < 3; i++) // To Do: Make this a generic nxn board
		{
			for (int j = 0; j < 3; j++)
			{
				Tiles[i][j] = -1;
			}
		}
	}
	
	// Methods for adding players
	void addPlayers(Person p1)
	{
		// playerNumber is 1 based. To do: Find a way to have a running count
		players[playerCount++] = p1; //assignment
	}

	int hasWon(int **boardTiles);

	int** getTiles();

private:
	int Tiles[3][3]; // To Do: Make this a generic nxn board
	int status;
	static int playerCount;
	Person players[2];
};

int TicTacToeBoard::hasWon(int **boardTiles)
{
	int status = -1; // unknown

	// Check horizontal rows
	for (int i = 0; i < 3; i++)
	{
		if ((boardTiles[i][0] == boardTiles[i][1]) && (boardTiles[i][1] == boardTiles[i][2]))
		{
			status = 1; // someone has won
			// To think: Players need to be static members?
			if (boardTiles[i][0] == 0) // To Do: check with char 'o'
			{
				this->players[0].setStatus(1); // To Do: Player's status is not accessible directly. Make getters and setters
			}
			else
			{
				this->players[1].setStatus(1);
			}
		}
	}

	// If rows don't tell the status, check vertical columns
	if (status == -1)
	{
		for (int j = 0; j < 3; j++)  // have number of rows and columns configurable
		{
			if ((boardTiles[0][j] == boardTiles[1][j]) && (boardTiles[1][j] == boardTiles[2][j]))
			{
				status = 1; // someone has won
				if (boardTiles[0][j] == 0)
				{
					this->players[0].setStatus(1);
				}
				else
				{
					this->players[1].setStatus(1);
				}
			}

		}
	}

	// If rows and columns don't tell the status, check the diagonals
	if (status == -1)
	{
		if (((boardTiles[0][0] == boardTiles[1][1]) && (boardTiles[1][1] == boardTiles[2][2])) ||
			((boardTiles[0][2] == boardTiles[1][1]) && (boardTiles[1][1] == boardTiles[2][0])))
		{
			status = 1; // someone has won

			if (boardTiles[1][1]== 0)
			{
				this->players[0].setStatus(1);
			}
			else
			{
				this->players[1].setStatus(1);
			}
		}
	}

	return status; 
}

int** TicTacToeBoard::getTiles()
{
	return (int**)(Tiles);
}

int main_TicTacToe()
{
	TicTacToeBoard *board = new TicTacToeBoard();

	Person player1(0); // Find a way to accept 'o'
	Person player2(1);

	board->addPlayers(player1);
	board->addPlayers(player2);

	// To Do: Run a few moves, or set tiles to a random value

	if (board->hasWon(board->getTiles()) == 1)
	{
		// if(board->getStatus(board->player[0]) == 1)
				// cout<< "Player 1 has won!"
		// else
		//		// cout << "Player 2 has won!"
	}


	
}
