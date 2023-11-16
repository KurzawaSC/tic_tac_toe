#include <iostream>
#include <conio.h>
#include <string>
#include <typeinfo>

using namespace std;

void game_field(char field[]);
void round(char *field, int player, string name);
bool check(char field[], int player, string name);
void start();
char restart();
int who_starts(string player1, string player2);
string enter_name();