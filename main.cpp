#include<bits/stdc++.h>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int current_player;

void drawBoard(){
    cout<<"\n "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"-----------\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"-----------\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n\n";
}

bool placeMarker(int slot){
    int row=(slot-1)/3;
    int col=(slot-1)%3;

    if(board[row][col]!='X' && board[row][col]!='x' && board[row][col]!='O' && board[row][col]!='o'){ 
        board[row][col]=current_marker;
        return (true);
    }

    else
        return (false);
}

int winner(){

    for(int i=0; i<3; i++){
        //checking rows
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2])
            return current_player;
        //checking col
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i])
            return current_player;
    }

    //checking main-diagonal
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
        return current_player;

    //checking cross-diagonal
    if(board[0][2]==board[1][1] && board[2][0]==board[1][1])
        return current_player;
    
    return (0);//nobody won
}

void swap_player_and_marker(){
    if(current_marker=='X')
        current_marker='O';
    else if(current_marker=='x')
        current_marker='o';
    else if(current_marker=='O')
        current_marker='X';
    else if(current_marker=='o')
        current_marker='x';

    if(current_player==1)
        current_player=2;
    else
        current_player=1;
}

void game(){
    char marker_p1;
    cout<<"Player one, choose your marker : ";
    cin>>marker_p1;

    current_marker=marker_p1;
    current_player=1;

    drawBoard();
    int player_won;
    for(int i=0; i<9; i++){
        int slot;
        cout<<"It's player "<<current_player<<"'s ("<<current_marker<<") turn. Enter your slot : ";
        cin>>slot;

        while(slot<1 || slot>9){
            cout<<"That slot is invalid. Try another slot!\n";
            cout<<"It's player "<<current_player<<"'s ("<<current_marker<<") turn. Enter your slot : ";
            cin>>slot;    
        }

        if(slot>=1 && slot<=9){
            while(placeMarker(slot)==false){
                cout<<"That slot is occupied. Try another slot!\n";
                cout<<"It's player "<<current_player<<"'s ("<<current_marker<<") turn. Enter your slot : ";
                cin>>slot;
                while(slot<1 || slot>9){
                    cout<<"That slot is invalid. Try another slot!\n";
                    cout<<"It's player "<<current_player<<"'s ("<<current_marker<<") turn. Enter your slot : ";
                    cin>>slot;    
                }
            }
        }

        player_won=winner();
        drawBoard();
        if(player_won==1){
            cout<<"\nPlayer one won! Congratulations!";
            break;
        }

        else if(player_won==2){
            cout<<"\nPlayer two won! Congratulations!";
            break;
        }

        swap_player_and_marker();
    }

    if(player_won==0)
        cout<<"\nThat's a tie!";

}

int main(){

    game();

    return (0);
}