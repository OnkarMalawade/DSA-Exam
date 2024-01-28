#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

int getRandomMultipleOfTwo(int lowerLimit, int upperLimit) {
    srand(static_cast<unsigned int>(time(NULL)));

    int randomNum = lowerLimit + rand() % (upperLimit - lowerLimit + 1);
    int multipleOfTwo = randomNum + (randomNum % 2 == 0 ? 0 : 1);

    return multipleOfTwo;
}

int main() {
    int result = getRandomMultipleOfTwo(2, 100);
    cout << "\nWelcome to Programmer Magic With Onkar!!!";
    cout << "\nTo Start Magic Press 1:";
    int p;
    cin >> p;
    if(p == 1){
    	while(p == 1){
    	string str;
    	cout << "\nWelcome to Onkar's mind reading World:";
    	cout << "\nPlease Enter your Name:";
    	cin >> str;
    	getch();
    	cout << "\nHello " <<str<<" are you Ready!!!!";
    	getch();
    	cout<<"\nLet's Start the Game: ";
    	cout << "\nGuess the Number in Mind";
    	getch();
    	cout << "\nMake double the Number in your Mind";
    	getch();
    	cout << "\nAdd the given "<< result <<" in Number";
    	getch();
    	cout << "\nMake Half the Number in your Mind";
    	getch();
    	cout << "\nRemove the Number in your Mind that you Guessed When Game started";
    	getch();
    	cout << "\nSpeak Loudly in side your Mind...";
    	getch();
    	cout << "\nTake Long Breath!!!";
    	getch();
    	cout << "\n"<<str<<" your Number is " << (result/2) << " Am I right? or Am I Right?";
    	getch();
    	cout << "\n"<<str<<" want to again Start Magic!!! Press 1 Otherwise \nCome Out Of Magic World!!!";
    	cin>>p;
    	result = getRandomMultipleOfTwo(2, 100);
		}
	}
    return 0;
}

