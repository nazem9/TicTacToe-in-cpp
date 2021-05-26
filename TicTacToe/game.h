#pragma once
#include<iostream>
class game
{
private:



public:
	void DrawGrid() {
		for (int i = 1; i <= 9; i++) {
			for (int j =1; j <= 3; j++) {
				std::cout << std::endl;
				std::cout << "_" << i << "_" << "|";
			}
		}
		
	}



};

