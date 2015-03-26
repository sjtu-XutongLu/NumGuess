// File name: guessNumGame

// This cpp is a game. Enter 3 different number which between
// 0 and 9, till guess the right number and queue.

// By sjtu-XutongLu
// 2015-3-25

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){

	// Initialize the random seed
	srand(time(NULL));

	// definition and initialize
	const int TIME = 7;
	int a(0), b(0), c(0);
	int winTime(0),allTime(0);
	int input_a(0), input_b(0), input_c(0); 
	int counter_A(0), counter_B(0);
	bool mainFlag(true), lowerFlag(true);
	char ch;

	char input_ch_a, input_ch_b, input_ch_c;

	// main loop
	while (1){
		cout<<"需要玩游戏吗（Y/N）？";
		// check whether the main loop continue or not, check exception 
		while(1){
			cin>>ch;
			if(ch == 'n' || ch == 'N') {mainFlag = false;break;}
			else if (ch == 'y' || ch == 'Y') break;
			else continue;
		}

		// quit and print
		if(!mainFlag){cout<<"你一共玩了"<<allTime<<"局，赢了"<<winTime<<"局，输了"<<allTime-winTime<<"局";break;}

		// count 
		allTime += 1;

		// random number
		do {
			a = rand() % 10;
			b = rand() % 10;
			c = rand() % 10;
		} while (b == a || c == a || c == b);

		// guess for 7 times
		for (int i = 0; i < TIME; ++i){
			cout<<"请输入你猜测的数字:"<<endl;

			do {
				cin>>input_ch_a>>input_ch_b>>input_ch_c;
				cin.sync();
				if (lowerFlag = !(input_ch_a <= '9' && input_ch_a >= '0' && input_ch_b >= '0' 
					&& input_ch_b <= '9' && input_ch_c >= '0' && input_ch_c <= '9')){
						cout<<"请输入0~9的数字: \n";}
			} while (lowerFlag);

			input_a = input_ch_a - '0';
			input_b = input_ch_b - '0';
			input_c = input_ch_c - '0';

			// count and print
			counter_A = (a == input_a) + (b == input_b) + (c == input_c);
	
			counter_B = (a == input_b) + (a == input_c) + (b == input_a) 
				+ (b == input_c) + (c == input_a) + (c == input_b);

			cout<<counter_A<<'A'<<counter_B<<'B';
			// check if you win
			if (counter_A == 3){
				winTime += 1;
				cout<<"恭喜，你猜对了";
				break;
			}
			// check if you lose
			if (i == 6){
				cout<<"很遗憾，你没有在规定次数内猜对。答案是 "<<a<<b<<c<<endl;
			}
		}
	}
	// pause
	system("pause");
	return 0;
}