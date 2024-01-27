//************************* Efficient Learning World *********************************
#include<iostream>
#include<cstring>
#include<cstdlib>			// rand()
#include<conio.h>
#include<windows.h>
using namespace std;
int inputuser();
int winner(string,string);
void display();
int main()
{

string     name;
cout<<"Enter your name	:	";
getline(cin,name);
cout<<endl;
char input;
int score=0;
do
{
	system("cls");
	display();
	score=score+inputuser();
	cout<<"\n\nWould you like to play again   y/n   : ";
    cin>>input;
	cout<<endl;	
}while(input!='n');
for(int i=0;i<name.size();i++)
{
	cout<<name[i];
	Sleep(100);
}
cout<<"\nYour score is 	:	"<<score<<endl;
cout<<"\n\n********************************************************************************************\n\n"<<endl;
}


int inputuser()
{
	int input;
	string yinput;
cout<<"1) Rock"<<endl;
cout<<"2) Paper"<<endl;
cout<<"3) Scissor"<<endl;
label1:
cout<<"\nEnter your input		:		";
cin>>input;
cout<<endl;	
if(input==1)
{
	yinput="Rock";
}
else if(input==2)
{
	yinput="Paper";
}
else if(input==3)
{
	yinput="Scissor";
}
else
{
	cout<<"invalid input		"<<endl;
	goto label1;
}
int computerinput=rand()%3 + 1;	
string cinput;
if(computerinput==1)
{
	cinput="Rock";
}
else if(computerinput==2)
{
	cinput="Paper";
}
else if(computerinput==3)
{
	cinput="Scissor";
}
cout<<"Computer choose			:		"<<cinput<<endl;
int output=winner(yinput,cinput);
if(output==1)
{
	cout<<"\nYou win...	";
	return 1;
}
else if(output==0)
{
	cout<<"\nSorry  ! Computer won"<<endl;
	return 0;
}
else if(output==-1)
{
	cout<<"Game Draw			"<<endl;
	return 0;
}
}
int winner(string yinput,string cinput)
{
	if(cinput=="Rock")
	{
		if(yinput=="Rock")
		{
			return -1;
		}
		else if(yinput=="Scissor")
		{
			return  0;
		}
		else if(yinput=="Paper")
		{
			return 1;
		}
	}
	if(cinput=="Scissor")
	{
		if(yinput=="Rock")
		{
			return 1;
		}
		else if(yinput=="Scissor")
		{
			return  -1;
		}
		else if(yinput=="Paper")
		{
			return 0;
		}
	}
	if(cinput=="Paper")
	{
		if(yinput=="Rock")
		{
			return 0;
		}
		else if(yinput=="Scissor")
		{
			return  1;
		}
		else if(yinput=="Paper")
		{
			return -1;
		}
	}
}
void display()
{
	cout<<"********************************************************************************************\n\n"<<endl;
cout<<"________________________________Rock, Scissor ,Paper Game_________________________________\n\n"<<endl;
	cout<<endl;
	cout<<"\t Game rules : "<<endl;
	cout<<"\t ->Rock crushes the scissor"<<endl;
	cout<<"\t ->Scissor cuts the paper"<<endl;
	cout<<"\t ->Paper covers the rock"<<endl;
	cout<<endl;
}
