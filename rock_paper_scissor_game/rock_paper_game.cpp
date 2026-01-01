#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

void game_rules()
{
    cout << "Rock-Paper-Scissors Game Rules:" << endl;
    cout << "1. Rock crushes Scissors" << endl;
    cout << "2. Scissors cuts Paper" << endl;
    cout << "3. Paper covers Rock" << endl;
    cout << "4. If both players choose the same, it's a tie!" << endl;
}

int game_winner(string p1_choice, string p2_choice)
{
    if (p1_choice == p2_choice)
    {
        return 0;
    }
    if (p1_choice == "rock")
    {
        if (p2_choice == "scissors")
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else if (p1_choice == "paper")
    {
        if (p2_choice == "rock")
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else if (p1_choice == "scissors")
    {
        if (p2_choice == "paper")
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    return 0;
}

void game()
{

    string player1, player2;
    cout << "Enter name of player 1: ";
    getline(cin, player1);
    cout << "Enter name of player 2: ";
    getline(cin, player2);

    string choices[3] = {"rock", "paper", "scissors"};
    string p1_choice, p2_choice;
    int num;

    cout << player1 << ", enter your choice (rock/paper/scissors): ";
    cin >> num;

    if (num < 0 || num > 2)
    {
        cout << "Invalid choice! Please choose 0, 1, or 2." << endl;
        return;
    }

    p1_choice = choices[num];

    cout << "Wait for player 2 to enter choice..." << endl;
    Sleep(4000);
    srand(time(0));
    int rand_num = rand() % 3 + 1;
    p2_choice = choices[rand_num - 1];
    cout << "player 2 has chosen: " << p2_choice << endl;

    int result = game_winner(p1_choice, p2_choice);
    if (result == 0)
    {
        cout << "It's a tie!" << endl;
        cout << "Play Again!" << endl;
    }
    else if (result == 1)
    {
        cout << player1 << " wins!" << endl;
    }
    else
    {
        cout << player2 << " wins!" << endl;
    }
}

int main()
{
    game_rules();
    cout << "-----------------------------" << endl;
    cout << "-----------------------------" << endl;
    cout << "Choose 0 for rock, 1 for paper, 2 for scissors" << endl;
    cout << "Let's Start the Game!" << endl;
    game();
    return 0;
}