/* TicTacToe game
Author: Talent Yolanda Ndlovu
Date: 13 Aug 2024*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    
   string init_board[3][3]={{"   1 ","    2","    3"},{"    4","   5 ","    6"},{"   7 ", "    8", "    9"}};
    int player_input;
    string empty[3][3];
    int num_fails=0;
    int box_pos;
    string winner;
    string Players[]={"  X ","   O"};
    bool prev_turn=1;
    bool Player_turn=0;
    bool Full=0;
    int temp;
    bool winner_found=0;
    int Num_plays=0;
    
    for(int l=0;l<=2;l++){
        for(int p=0;p<=2;p++){
            empty[l][p]=init_board[l][p];
        }
    }

    for (int i=0; i<=2;i++){
cout<<init_board[i][0]<<"|"<<init_board[i][1]<<"|"<<init_board[i][2]<<"|"<<endl;
cout<<"----------------"<<endl;
    }

    while (Full==0){
    cout<<"Player"<<(Player_turn ==0 ? "1":"2");
    cout<<endl;
    cout<<"Pick a box from (1-9)";
    cin>>player_input;
    if (player_input>0 && player_input<10){
    
    box_pos=player_input%3;
    if (box_pos==0){
box_pos=3;
    }
            if (player_input<4){
                if(init_board[0][box_pos-1]==empty[0][box_pos-1]){
                init_board[0][box_pos-1]=Players[Player_turn];
                }
                else if(init_board[0][box_pos-1]!=empty[0][box_pos-1]){
                    cout<<"CAN YOU NOT SEE THAT THE BOX IS OCCUPPIED?"<<endl;
                    num_fails=num_fails+1;
                
                }
            }
            else if(player_input>3 && player_input<7){
                if (init_board[1][box_pos-1]==empty[1][box_pos-1]){
                    init_board[1][box_pos-1]=Players[Player_turn];
                }
                else if(init_board[1][box_pos-1]!=empty[1][box_pos-1]){
                    cout<<"STOP WASTING OUR TIME AND PICK ANOTHER ONE!!"<<endl;
                    num_fails=num_fails+1;
                    
                }
            }
            else if (player_input>6 && player_input<10){
                if (init_board[2][box_pos-1]==empty[2][box_pos-1]){
                    init_board[2][box_pos-1]=Players[Player_turn];
                }
                else if(init_board[2][box_pos-1]!=empty[2][box_pos-1]){
                    cout<<"ARE YOU BLIND? THAT BOX IS ALREADY OCCUPPIED"<<endl;
                    num_fails=num_fails+1;
                    
                }
            }
             system("clear");
            for (int i=0; i<=2;i++){
             cout<<init_board[i][0]<<"|"<<init_board[i][1]<<"|"<<init_board[i][2]<<"|"<<endl;
             cout<<"----------------"<<endl;
           }
           
            
            temp=Player_turn;
            Player_turn=prev_turn;
            prev_turn=temp;

             for(int a=0; a<=2;a++){
        for(int b=0;b<=2;b++){
            if(init_board[a][b]!=empty[a][b]){
                Num_plays=Num_plays+1;
            }
        }
             }
             for (int n=0; n<=2;n++){
                if(init_board[n][0]==init_board[n][1]&&init_board[n][0]==init_board[n][2]){ //checking horizontal state
                    winner=init_board[n][0];
                    winner_found=1;
                    cout<<"GAME OVER!!"<<endl;
                    cout<<"Winner, Player "<<(winner==Players[0]? "1. Better luck next time Player 2": "2. Better luck next time Player 1")<<endl;
                break;
                }
             }
             for (int n=0; n<=2;n++){
                if(init_board[0][n]==init_board[1][n]&&init_board[0][n]==init_board[2][n]){ //checking vertical state
                    winner=init_board[0][n];
                    winner_found=1;
                    cout<<"GAME OVER!!"<<endl;
                    cout<<"Winner, Player "<<(winner==Players[0]? "1. Better luck next time Player 2": "2. Better luck next time Player 1")<<endl;
                break;
                }
             }
            
                if((init_board[0][0]==init_board[1][1]&&init_board[0][0]==init_board[2][2])|| (init_board[0][2]==init_board[1][1]&& init_board[0][2]==init_board[2][0])){ //checking horizontal state
                    winner=init_board[1][1];
                    winner_found=1;
                    cout<<"GAME OVER!!"<<endl;
                    cout<<"Winner, Player "<<(winner==Players[0]? "1. Better luck next time Player 2": "2. Better luck next time Player 1")<<endl;
                break;
                }
             
             if(winner_found==1){
                break;
             }
        if(Num_plays==9){
                Full=1;
            }
        else{
            Num_plays=0;
        }
    }
          else{
            cout<<"ENTER A VALID NUMBER YOU BANANA!!"<<endl;
          }  
     }
     
}


   
 
