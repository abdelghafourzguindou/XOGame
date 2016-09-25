#include <iostream>
#include <stdlib.h>
#include <iomanip>

#define cls   system("cls")
#define pause system("PAUSE")

using namespace std;

void print_xoGame(char xoGame[3][3]) {
    for(int i=0; i<3; i++) {
            cout << "\n" << setw(45) << "|-----------|" << endl;
            cout << setw(34);
            for(int j=0; j<3; j++) {
                cout << "| " << xoGame[i][j]<<" ";
                if(j == 2)cout<<"|";
            }
        }
        cout << "\n" << setw(45) << "|-----------|" << endl;
}

void playXO(char xoGame[3][3], char gamer, char gamerChoice, bool *play) {
    *play = false;
    for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    if( xoGame[i][j] == gamerChoice
                        && xoGame[i][j] != gamer
                        && xoGame[i][j] != gamer) {
                            xoGame[i][j] = gamer;
                            *play = true;
                    }
                }
        }
}

bool winner(char xoGame[3][3], char gamer) {

    if(    xoGame[0][2] == gamer
        && xoGame[1][1] == gamer
        && xoGame[2][0] == gamer) return true;

    int k = 0;

    for(int i=0; i<3; i++) if(xoGame[i][i] == gamer) ++k;
    if(k == 3) return true;
    else k = 0;

    for(int i=0; i<3; i++) {

        for(int j=0; j<3; j++) if(xoGame[i][j] == gamer) ++k;
        if(k == 3) return true;
        else k = 0;

        for(int j=0; j<3; j++) if(xoGame[j][i] == gamer) ++k;
        if(k == 3) return true;
        else k = 0;

    }
    return false;
}

void caseEror() {
    cls;
    cout <<"\n\n"<< "Case EROR (play again)\n\n" << endl;
    pause;
}

/*
void Pprint_xoGame(char xoGame[6][6]) {
    for(int i=0; i<6; i++) {
            cout << "\n|-----------------------|" << endl;
            for(int j=0; j<6; j++) {
                cout << "| " << xoGame[i][j]<<" ";
                if(j == 5)cout<<"|";
            }
        }
        cout << "\n|-----------------------|" << endl;
}
*/

int main()
{
    string gamer1, gamer2;
    char gamerChoice;

    /*
    char xoGame[6][6] = {
                            {'0', '1', '2', '3', '4', '5'},
                            {'6', '7', '8', '9', 'A', 'B'},
                            {'C', 'D', 'E', 'F', 'I', 'J'},
                            {'K', 'L', 'M', 'N', 'O', 'P'},
                            {'Q', 'R', 'S', 'T', 'V', 'W'},
                            {'X', 'Y', 'Z', '&', '@', '#'},
                        };
    Pprint_xoGame(xoGame);
    */
    char xoGame[3][3] = {
                            {'1', '2', '3'},
                            {'4', '5', '6'},
                            {'7', '8', '9'}
                        };

    cout << "Scan name of gamer 1 : "; cin >> gamer1;
    cout << "Scan name o  gamer 2 : "; cin >> gamer2;

    while(!winner(xoGame, 'X') || !winner(xoGame, 'O')) {

        startGamer1 :
        cls; print_xoGame(xoGame);
        cout << "\n" << gamer1 << " [with X] choice your case : "; cin >> gamerChoice;
        bool play;
        playXO(xoGame, 'X', gamerChoice, &play);
        if(!play) {
            caseEror();
            goto startGamer1;
        }
        cls; print_xoGame(xoGame);
        if(winner(xoGame, 'X')) {
            cout << "\n" << gamer1 << " [with X] you are the winner" << endl;
            break;
        }

        else {
        startGamer2 :
        cls; print_xoGame(xoGame);
        cout << "\n" << gamer2 << " [with O] choice your case : "; cin >> gamerChoice;
        playXO(xoGame, 'O', gamerChoice, &play);
        if(!play) {
            caseEror();
            goto startGamer2;
        }
        cls; print_xoGame(xoGame);
        if(winner(xoGame, 'O')) {
            cout << "\n" << gamer2 << " [with O] you are the winner" << endl;
            break;
        }
        else continue;
        }

    }

    return 0;
}
