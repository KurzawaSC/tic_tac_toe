/*
        This is a "Tic tac toe" game as console application
    - written by Kurzawa :)

*/

#include "headers.h"

int main()
{
    string player1, player2;
    int choice;

    start();

    cout << "Enter first player's name and press enter: ";
    player1 = enter_name();
    cout << "Enter second player's name and press enter: ";
    player2 = enter_name();

    int firstMove, secondMove;
    firstMove = who_starts(player1, player2);
    if (firstMove == 1)
    {
        secondMove = 2;
    }
    else
    {
        string tmp = player1;
        player1 = player2;
        player2 = tmp;
        secondMove = 1;
    }

    do
    {

        char field[] = {'1', '2', '3',
                        '4', '5', '6',
                        '7', '8', '9'};

        while (true)
        {
            game_field(field);
            round(field, firstMove, player1);
            if (check(field, firstMove, player1))
            {
                break;
            }
            game_field(field);
            round(field, secondMove, player2);
            if (check(field, secondMove, player2))
            {
                break;
            }
        }
        choice = restart();

    } while (choice == 'Y');

    return 0;
}
