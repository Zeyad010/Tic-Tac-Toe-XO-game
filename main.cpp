#include <iostream>

using namespace std;


char Matrix[3][3] = { '1','2','3','4','5','6','7','8','9' };

char Player = 'X';

void printMatrix()
{

    system("cls");

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << Matrix[0][0] << "  |  " << Matrix[0][1] << "  |  " << Matrix[0][2] << endl;

    cout << "_____|_____|_____" << endl;

    cout << "     |     |     " << endl;

    cout << "  " << Matrix[1][0] << "  |  " << Matrix[1][1] << "  |  " << Matrix[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << Matrix[2][0] << "  |  " << Matrix[2][1] << "  |  " << Matrix[2][2] << endl;

    cout << "     |     |     " << endl << endl;



}

void chossePosition()
{
    char position;
    cout << "Choose Your Position - Player (" << Player << ") :" << endl;
    cin >> position;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Matrix[i][j] == position)
            {

                Matrix[i][j] = Player;
            }
        }


    }

    if (Player == 'X')
        Player = 'O';
    else
        Player = 'X';

}

char winner()
{
    int Xc = 0; int Oc = 0;
    int counter = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Matrix[i][j] != 'X' && Matrix[i][j] != 'O') counter++;
            if (Matrix[i][j] == 'X')
                Xc++;
            else if (Matrix[i][j] == 'O')
                Oc++;

            if (Xc == 3 || Oc == 3)
                return Xc > Oc ? 'X' : 'O';
        }
        Xc = 0; Oc = 0;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Matrix[j][i] == 'X')
                Xc++;
            else if (Matrix[j][i] == 'O')
                Oc++;

            if (Xc == 3 || Oc == 3)
                return Xc > Oc ? 'X' : 'O';
        }
        Xc = 0; Oc = 0;
    }

    if (Matrix[0][0] == 'X' && Matrix[1][1] == 'X' && Matrix[2][2] == 'X')
        return 'X';
    else if (Matrix[0][0] == 'O' && Matrix[1][1] == 'O' && Matrix[2][2] == 'O')
        return 'O';
    else if (Matrix[0][2] == 'X' && Matrix[1][1] == 'X' && Matrix[2][0] == 'X')
        return'X';
    else if (Matrix[0][2] == 'X' && Matrix[1][1] == 'X' && Matrix[2][0] == 'X')
        return'O';


    if (counter == 0)
        return'l';





    return '.';
}

int main()
{

    while (winner() == '.')
    {
        printMatrix();
        chossePosition();

    }

    printMatrix();

    if (winner() == 'l')
        cout << "*** NO WINNER ***" << endl;
    else
        cout << "#*** THE WINNER IS :  " << winner() << "  ***#" << endl;

    system("pause");
    return 0;
}
