#include <iostream>
#include<iomanip>
#include<bits/stdc++.h>
#include <Windows.h>
#include <unistd.h>
#include <time.h>
using namespace std;
//Data

int player1_score = 0;
int player2_score = 0;
string numbers[20] = {"1", "2", "3", "4", "5", "6", "7", "8", "9","10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20"};
string characters[20] = {"A", "A", "B", "B", "C", "C", "D", "D", "E", "E", "F", "F", "G", "G", "H", "H", "I", "I", "J", "J"};
string check_list[20] = {"*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*"};
int sum=0;
string running = "Run";

//shuffle characters
void shuffle (string arr[],int len){
    string temp ;
    int random_index=0;
    for (int i =0; i < len ;i++){


        random_index=rand()%len;
        temp = arr[i];
        arr[i]=arr[random_index];
        arr[random_index] = temp;


    }

}

//swap right characters with stars
void swap_numbers_check(int &number1,int &number2){
 numbers[number1-1] =  check_list[number1-1];

 numbers[number2-1] =  check_list[number2-1];


}
//winner
void winner(){
    if (player1_score > player2_score){
        cout<<("player#1 won")<<endl;
    }

    if (player1_score < player2_score){
        cout<<("player#2 won")<<endl;
    }

    if (player1_score == player2_score){
        cout<<("Draw")<<endl;
        }

}
//game loop
void game_loop(){

    while(sum < 20){
        //print score
        cout<<"p1 turn, p1_score: "<< player1_score<<endl;

        //print numbers
        for(int p1 = 0; p1 < 20; p1++){
            cout<<numbers[p1]<<"  ";
        }


        cout<<endl;


        //take first number from player1
        int number1;
        cout<<"Enter number1:"<<" ";
        cin>>number1;


        //take second number from player2
        int number2;
        cout<<"Enter number2:"<<" ";
        cin>>number2;
        cout<<endl;


        //print values
        cout<<"chosen values"<<endl;
        cout<<characters[number1-1]<<"  "<<characters[number2-1];

        cout<<endl;

        //check for right choose
        if (characters[number1-1]==characters[number2-1]){
                player1_score+=1;
                //add stars

                swap_numbers_check( number1, number2);

                sum+=2;
        }

        //check for end
        if(sum==20){
            running="stop";

        }


        //clear screen
        sleep(2);
        system("cls");

        //print score
        cout << "p2 turn, p2_score: " << player2_score<<endl;

        //print numbers
        for(int p2 = 0; p2 < 20; p2++){
            cout<<numbers[p2]<<"  ";
        }
        cout<<endl;

        //take first number from player2
        cout<<"Enter number1:"<<" ";
        cin>>number1;

        //take second number from player2
        cout<<"Enter number2:"<<" ";
        cin>>number2;
        cout<<endl;



        //print values
        cout<<"chosen values"<<endl;
        cout<<characters[number1-1]<<"  "<<characters[number2-1];

        //check for right choose
        cout<<endl;
        if (characters[number1-1]==characters[number2-1]){
                player2_score+=1;

                swap_numbers_check( number1, number2);

                sum+=2;
        }

        //check for end
        if(sum==20){
            running="stop";
        }

        //clear screen
        sleep(2);
        system("cls");
  }







}


int main(){

cout << "welcome to One line memory game" <<endl;

cout << " By Yousef Abdalla Attia"<<endl;

cout << "FCAI-CU"<<endl;

cout<<"Game Description:"<<endl;

cout<<"Choose two numbers, if their values are equal, you will get a point"<<endl;

cout<<"The most points will win" <<endl;

cout<<endl;

cout<<endl;




//call functions
shuffle(characters,20);

game_loop();

winner();

cout<<"Thanks for trying our game";

}






