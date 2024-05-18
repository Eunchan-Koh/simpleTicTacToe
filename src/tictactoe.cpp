//============================================================================
// Name        : tictactoe.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool gameOver = false;
string endLine = "Winner is: Player";
string CheckLine(string arr[][3]);
void Displayer(string marks[][3]);
int main() {
	//player one goes first
	//then player two
	//shows the empty tictactoe field first
	//how to interact? using number
	//check nubmber pad for correct location
	bool gotInput = false;
	string marks[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			marks[i][j] = "";
		}

	}
	int number1;
	int number2;
	string winner = "";

	bool playerOneTurn = false;
//	bool correctInputs = false;

	int totalTurn = 0;
	while(!gameOver){
		system("cls");
		totalTurn++;
		playerOneTurn = !playerOneTurn;
//		while(!correctInputs){
		point1:
			Displayer(marks);
			cout << "enter row alphabet(capital) to put in the mark!" << endl;
			char tempRow;
			while(!gotInput){
				if(cin >> tempRow){
					number1 = (int)tempRow;
					if(number1 > 67 || number1 < 65){
						cout << "Sorry, please Choose from one of the followings:" << endl;
						cout << " A, B, C" << endl;
					}else{
						gotInput = true;
						number1 -=65;
					}

				}
			}
			gotInput = false;
			cout << "enter column number to put in the mark!" << endl;
			while(!gotInput){
				if(cin >> number2){
					if(number2 > 2 || number2 < 0){
						cout << "Sorry, please Choose from one of the followings:" << endl;
						cout << " 0, 1, 2" << endl;
					}else{
						gotInput = true;
					}

				}
			}
			gotInput = false;
			if(marks[number1][number2]==""){
//				correctInputs = true;
			}else{
				cout << "cannot mark on there - " << marks[number1][number2] << " is already there!" << endl;
				goto point1;
			}
//		}



		if(playerOneTurn){
			marks[number1][number2] = "x";
		}else{
			marks[number1][number2] = "o";
		}
		if(totalTurn>=4){
			winner = CheckLine(marks);
		}
		if(winner != ""){
			gameOver = true;
		}
	}
	cout << "winner is: " << winner << "!"<<endl;
	Displayer(marks);



	return 0;
}
void Displayer(string marks[][3]){
	cout <<"	0	1	2" << endl;

	cout <<"  -------------------------" << endl;
	cout <<"A |" << marks[0][0]<<"	  |" << marks[0][1]<<"	  |" << marks[0][2]<<"	  |" << endl;
	cout <<"  -------------------------" << endl;
	cout <<"B |" << marks[1][0]<<" 	  |" << marks[1][1]<<"	  |" << marks[1][2]<<"	  |" << endl;
	cout <<"  -------------------------" << endl;
	cout <<"C |" << marks[2][0]<<"	  |" << marks[2][1]<<"	  |" << marks[2][2]<<"	  |" << endl;
	cout <<"  -------------------------" << endl;
}
string CheckLine(string arr[][3]){
//	cout << "arr is:" << arr[0][0] << endl;
	string first = "";
	bool gameOver = false;
	string winner = "";
	//vertical check
	for(int i = 0; i < 3; i++){
		if(gameOver)break;
		if(arr[0][i] != "" && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]){
			gameOver = true;
			winner = arr[0][i];
		}
	}
	//horizontal check
	for(int i = 0; i < 3; i++){
		if(gameOver)break;
		if(arr[i][0] != "" && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
			gameOver = true;
			winner = arr[i][0];
		}
	}
	//diagonal check

	if(gameOver)return winner;
	if(arr[0][0] != "" && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){
		gameOver = true;
		winner = arr[0][0];
	}
	if(gameOver)return winner;
	if(arr[2][0] != "" && arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2]){
		gameOver = true;
		winner = arr[2][0];
	}


	return winner;
}


