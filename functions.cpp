#include "headers.h"

void game_field(char field[])
{
    system("cls");
    cout << "+-+-+-+" << endl;
    cout << "|" << *field << "|" << *(field + 1) << "|" << *(field + 2) << "|" << endl;
    cout << "+-+-+-+" << endl;
    cout << "|" << *(field + 3) << "|" << *(field + 4) << "|" << *(field + 5) << "|" << endl;
    cout << "+-+-+-+" << endl;
    cout << "|" << *(field + 6) << "|" << *(field + 7) << "|" << *(field + 8) << "|" << endl;
    cout << "+-+-+-+" << endl;
}

void round(char *field, int player, string name)
{
    if (player == 1)
        cout << name << "'s move" << endl;
    else if (player == 2)
        cout << name << "'s move" << endl;

    int num;
    char charNum;
    cout << "Enter the field number: ";
    while (true)
    {
        charNum = getch();
        num = charNum - '0';
        if (player == 1 && *(field - 1 + num) != 'O' && *(field - 1 + num) != 'X' && charNum <= '9')
        {
            *(field - 1 + num) = 'O';
            break;
        }
        else if (player == 2 && *(field - 1 + num) != 'O' && *(field - 1 + num) != 'X' && charNum <= '9')
        {
            *(field - 1 + num) = 'X';
            break;
        }
        else if (charNum > '9')
        {
            cout << endl
                 << "You enter wrong field number, try again: ";
            continue;
        }
        else
            cout << "\nThe field is occupied, please try again: ";
    }
}

bool check(char field[], int player, string name)
{
    for (int i = 0, j = 0; i < 9; i++)
    {
        if (*(field + i) == 'X' || *(field + i) == 'O')
        {
            j++;
            if (j == 9)
            {
                cout << "*****DRAW*****" << endl;
                return true;
            }
        }
    }
    if (*field == *(field + 1) && *(field + 1) == *(field + 2) ||
        *(field + 3) == *(field + 4) && *(field + 4) == *(field + 5) ||
        *(field + 6) == *(field + 7) && *(field + 7) == *(field + 8) ||
        *field == *(field + 4) && *(field + 4) == *(field + 8) ||
        *(field + 2) == *(field + 4) && *(field + 4) == *(field + 6) ||
        *field == *(field + 3) && *(field + 3) == *(field + 6) ||
        *(field + 1) == *(field + 4) && *(field + 4) == *(field + 7) ||
        *(field + 2) == *(field + 5) && *(field + 5) == *(field + 8))
    {
        game_field(field);
        cout << "*****Player " << name << " has won!*****" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void start()
{
    system("cls");
    cout << "Hello, press enter to start" << endl;
    while (getch() != 13)
        ;
}

string enter_name()
{
    string name;
    cin >> name;
    cin.ignore();
    return name;
}

char restart()
{
    char choice;
    cout << "Do you want play again? Y/N";
    while (true)
    {
        choice = getch();
        if (choice == 'y' || choice == 'Y')
        {
            return 'Y';
        }
        else if (choice == 'n' || choice == 'N')
        {
            return 'N';
        }
        else
        {
            cout << endl
                 << "Wrong key! Press correct key again: ";
            continue;
        }
    }
}

int who_starts(string player1, string player2)
{
    char choice;
    system("cls");
    cout << "Which player would start?" << endl;
    cout << "1." << player1 << endl;
    cout << "2." << player2 << endl;
    while (true)
    {
        choice = getch();
        if (choice == '1')
        {
            return 1;
        }
        else if (choice == '2')
        {
            return 2;
        }
        else
        {
            cout << endl
                 << "Wrong key! Press correct key again: ";
            continue;
        }
    }
}
