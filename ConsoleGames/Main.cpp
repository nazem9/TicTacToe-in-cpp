#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
enum eDir {
	STOP = 0,
	LEFT=1,
	UPLEFT=2,
	DOWNLEFT=3,
	RIGHT=4,
	UPRIGHT=5,
	DOWNRIGHT=6
};


class cBall {
private:
	int x, y;
	int OriginalX, OriginalY;
	eDir direction;
public:
	cBall(int PosX, int PosY) {
		OriginalX = PosX;
		OriginalY = PosY;
		x = PosX; y = PosY;
		direction = STOP;

	}
	void Reset() {
		x = OriginalX; y = OriginalY;
		direction = STOP;

	}
	void ChangeDirection(eDir d) {
		direction = d;

	}
	void RandomDirection() {
		direction = (eDir)(rand() % 6 + 1);
	}
	void Move() {
		switch (direction) {
		case STOP:break;
		case LEFT:x--; break;
		case RIGHT:x++; break;
		case UPLEFT:x--; y--; break;
		case DOWNLEFT:x--; y++; break;
		case UPRIGHT:x++; y--; break;
		case DOWNRIGHT:x++; y++; break;
		default:break;

		}
	}
	friend ostream& operator<<(ostream& out, cBall c) {
		out << "ball [" << c.x << "," << c.y << "]" << "[" << c.direction << "]";
		return out;
	}

	inline int Getx() { return x; }
	inline int Gety() { return y; }
	inline eDir GetDirection() { return direction; }

};
class cPaddle {
private:
	int x, y;
	int OriginalX, originalY;
public:
	cPaddle() {
		this->x = this->y = 0;

	}
	cPaddle(int posX, int posY) : cPaddle(){
		this->originalY = posY; this->OriginalX = posX;
		x = posX; y = posY;
	}
	void reset() {
		x = OriginalX; y = originalY;
	}
	inline int Getx() { return x; }
	inline int Gety() { return y; }
	void MoveUp() {
		y--;
	}
	void MoveDown() {
		y++;
	}
	friend ostream& operator<<(ostream& out, cPaddle c) {
		out << "paddle [" << c.x << "," << c.y << "]";
		return out;
	}




};
class cGameManger {
private:
	int width, height;
	int ScoreP1, ScoreP2;
	char Up1, Up2, Down1, Down2;
	bool quit;
	cBall* ball;
	cPaddle* player1, * player2;
public:
	cGameManger(int w, int h) {
		srand(time(NULL));
		quit = false;
		Up1 = 'w'; Up2 = 'i';
		Down1 = 's'; Down2 = 'k';
		ScoreP1 = ScoreP2 = 0;
		width = w; height = h;
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3); // h/2 middle of the screen -3 because the paddle is 4 blocks
		player2 = new cPaddle(w - 2, h / 2 -3);
	}
	~cGameManger(){
		delete ball,player1,player2;

	}
	void ScoreUp(cPaddle* player) {
		if (player == player1)
			ScoreP1++;
		if (player == player2)
			ScoreP2++;
		ball->Reset();
		player1->reset();
		player2->reset();

	}
	void Draw() {
		system("cls");
		for (int i = 0; i < width + 2; i++) {
			cout << "\xB2";
		}
		cout << endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				int ballx = ball->Getx();
				int bally = ball-> Gety();
				int Player1y = player1->Gety();
				int Player2y = player2 -> Gety();
				int Player1x= player1->Getx();
				int Player2x = player2->Getx();
				if (j == 0) {
					cout << "\xB2"; // wall right
				}
				if (ballx == j && bally == i) {
					cout << "O"; // ball
				}
				else if (Player1x == j && Player1y == i) {
					cout << "\xDB"; // paddel player1
				}
				else if (Player1x == j && Player1y +1 == i) {
					cout << "\xDB"; // paddel player1
				}
				else if (Player1x == j && Player1y +2 == i) {
					cout << "\xDB"; // paddel player1
				}
				else if (Player1x == j && Player1y +3 == i) {
					cout << "\xDB"; // paddel player1
				}
				else if (Player2x == j && Player2y == i) {
					cout << "\xDB"; //paddle player2
				}
				else if (Player2x == j && Player2y +1== i) {
					cout << "\xDB"; //paddle player2
				}
				else if (Player2x == j && Player2y +2== i) {
					cout << "\xDB"; //paddle player2
				}
				else if (Player2x == j && Player2y +3== i) {
					cout << "\xDB"; //paddle player2
				}


				else {
					cout << " ";
				}


				if (j == (width - 1)) {
					cout << "\xB2"; // left wall
				}
				
			}
			cout << endl;
		}

		for (int i = 0; i < width + 2; i++) {
			cout << "\xB2";
		}
		cout << endl;
	}
	void Input() {
		ball->Move();

		int ballx = ball->Getx();
		int bally = ball->Gety();
		int Player1y = player1->Gety();
		int Player2y = player2->Gety();
		int Player1x = player1->Getx();
		int Player2x = player2->Getx();

		if (_kbhit()) {
			char currentChar = _getch();
			if (currentChar == Up1 && Player1y > 0)
				player1->MoveUp();
			if (currentChar == Up2 && Player2y > 0)
				player2->MoveUp();
			if (currentChar == Down1 && Player1y < height)
				player1->MoveDown();
			if (currentChar == Down2 && Player2y < height)
				player2->MoveDown();
			if (ball->GetDirection() == STOP)
				ball->RandomDirection();
			if (currentChar == 'q')
				quit = true;
		}

	}
	void Logic() {
		int ballx = ball->Getx();
		int bally = ball->Gety();
		int Player1y = player1->Gety();
		int Player2y = player2->Gety();
		int Player1x = player1->Getx();
		int Player2x = player2->Getx();
		//left paddle
		for (int i = 0; i < 4; i++) {
			if (ballx == Player1x + 1 && bally == Player1y + i) {
				ball->ChangeDirection((eDir)(rand()%3 + 4) );
			}
		}
		//right paddle
		for (int i = 0; i < 4; i++) {
			if (ballx == Player2x -1 && bally == Player2y + i) {
				ball->ChangeDirection((eDir)(rand() % 3 + 1));
			}
		}
		//bottom wall
		if (bally == 0)
			ball->ChangeDirection(ball->GetDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		//top wall
		if (bally == height - 1)
			ball->ChangeDirection(ball->GetDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		//right wall
		if (ballx == width - 1) {
			ScoreUp(player1);
		}
		//left wall

		if (ballx ==0) {
			ScoreUp(player2);
		}

	}
	void Run() {
		while (!quit) {
			Draw();
			Input();
			Logic();

		}
	}
};






int main() {
	cGameManger c(40, 20);
	c.Run();

	return 0;
}