#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;

class Player {
private:
	char c;
	bool win;



public:
	Player(char c) {
		if (c == 'X' || c == 'O')
			this->c = c;
		this->win = false;
	}

	char GetChar() {
		return this->c;
	}
	bool isWinning() {
		return win;
	}
	void setWinning(bool w) {
		this->win = w;
	}
	int AI(Game* G) {
		G->grid;
	}
	
};


class Game {
	friend Player;
	
private:
	
	char grid[9] = { '1','2','3','4','5','6','7','8','9' };
	//                0   1   2   3   4   5   6   7   8
	int X = int('X');
	int O = int('O');
	Player player1 = Player('X');
	Player player2 = Player('O');
	bool isGameRunning = true;
	int counter;
	


public:
	string whoWon = "draw";
	
	Game() {

	}

	void DrawGrid() {
		system("cls");
		for (int i=0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << " " << grid[j+3*i] << " |";
			}
			cout << endl << "------------"<<endl;
		}
	}
	void KeyBoardHit(Player* p) {
		if (_kbhit) {
			int CurrentIndex = (_getch() - '0');
			if (grid[CurrentIndex - 1] != 'X' && grid[CurrentIndex - 1] != 'O') {
				grid[CurrentIndex - 1] = p->GetChar();
				
			}
			else {
				cout << "can't do that action" << endl;
				//isGameRunning = false;
				this->counter--;

			}

				

		}
	}
	bool WinningConditions() {
		for (int i = 0; i < 3; i++) {
			if (grid[3 * i] == 'X' && grid[3 * i + 1] == 'X' && grid[3 * i + 2] == 'X' || grid[i] == 'X' && grid[i + 3] == 'X' && grid[i + 6] == 'X' || grid[0] == 'X' && grid[4]=='X' &&grid[8] == 'X' || grid[2] == 'X' && grid[4] =='X' && grid[6] == 'X') {
				whoWon = "Player 1 Wins!";
				return true;
			}
			else if (grid[3 * i] == 'O' && grid[3 * i + 1] == 'O' && grid[3 * i + 2] == 'O' || grid[i] == 'O' && grid[i + 3] == 'O' && grid[i + 6] == 'O' || grid[0] == 'O' && grid[4] == 'O' && grid[8] == 'O' || grid[2] == 'O' && grid[4] == 'O' && grid[6] == 'O') {
				whoWon = "Player 2 Wins!";
				return true;
			}
			else {
				return false;
			}
		}
	}

	void Run() {
		for ( counter = 0; isGameRunning;counter++) {

			this->DrawGrid();
			if (counter % 2 == 0)
				this->KeyBoardHit(&player1);
			else
				this->KeyBoardHit(&player2);
			if (counter >= 8 || WinningConditions()) break;
		}

	}


};





int main() {
	Game g = Game();
	g.Run();
	system("cls");
	cout << g.whoWon << endl;


	return 0;
}

