#include <iostream>
#include <string>
#include <ctime>
#include <unordered_map>
#include <fstream>

using namespace std;

unordered_map<string, int> user_data;
int current_balance = 0;

void game_rules_display()
{
    cout << "Welcome to the Casino Guessing Game!" << endl;
    cout << "-----------------------------------" << endl;
    cout << "----------------------------------" << endl;
    cout << "Rules:" << endl;
    cout << "1. Choose a level: Easy, Medium, or Hard." << endl;
    cout << "2. Each level has a different range of numbers:" << endl;
    cout << "   - Easy: 1 to 10" << endl;
    cout << "   - Medium: 1 to 50" << endl;
    cout << "   - Hard: 1 to 100" << endl;
    cout << "3. If you guess correctly, you win!" << endl;
    cout << "4. If you fail to guess the number in 3 attempts, you lose." << endl;
    cout << "Good luck and have fun!" << endl;
};

void game_mechanics(int max_number, string level, int bet_amount)
{
    cout << "Guess a number between 1 and " << max_number << "." << endl;
    int num;
    cin >> num;

    int random_num = rand() % max_number + 1;

    cout << "Wait a minute ..........." << endl;

    if (num == random_num)
    {
        cout << "Congratulations! You guessed the correct number: " << random_num << endl;
        cout << "You won $" << bet_amount << "!" << endl;
        user_data[level] += bet_amount;
        current_balance += bet_amount;
    }
    else
    {
        cout << "Sorry! The correct number was: " << random_num << endl;
        cout << "You lost your bet of $" << bet_amount << "." << endl;
        user_data[level] -= bet_amount;
        current_balance -= bet_amount;
    }
};

void easy_game_start(int bet_amount)
{
    cout << "You have selected Easy level." << endl;
    string level = "Easy";
    game_mechanics(10, level, bet_amount);
};

void medium_game_start(int bet_amount)
{
    cout << "You have selected Medium level." << endl;
    string level = "Medium";
    game_mechanics(50, level, bet_amount);
};

void hard_game_start(int bet_amount)
{
    cout << "You have selected Hard level." << endl;
    string level = "Hard";
    game_mechanics(100, level, bet_amount);
};

void game_history_save()
{

    ofstream game_file;
    game_file.open("game_history.txt");

    if (!game_file)
    {
        cout << "Error opening file!" << endl;
        exit(1);
    }
    game_file << "-----------------------------------" << endl;
    game_file << "Game History:" << endl;
    for (const auto &entry : user_data)
    {
        game_file << entry.first << " Level Balance: $" << entry.second << endl;
    }
    game_file << "Total Balance: $" << (user_data["Easy"] + user_data["Medium"] + user_data["Hard"]) << endl;
    game_file << "Current Balance: $" << current_balance << endl;
    game_file << "-----------------------------------" << endl;
    game_file.close();
};

int main()
{
    srand(time(0));
    game_rules_display();

    string play_again = "yes";

    while (play_again == "yes")
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Enter 0,1,2 to choose Easy, Medium, Hard level respectively: ";
        int level;
        cin >> level;
        cout << "Your current balance is $" << current_balance << endl;
        cout << "Enter amount to bet: $";
        int bet_amount;
        cin >> bet_amount;

        if (level < 0 || level > 2)
        {
            cout << "Invalid level selected. Please choose again." << endl;
            continue;
        }

        if (bet_amount <= 0)
        {
            cout << "Invalid bet amount. Please enter a positive amount." << endl;
            continue;
        }

        switch (level)
        {
        case 0:
        {
            easy_game_start(bet_amount);
            break;
        }
        case 1:
        {
            medium_game_start(bet_amount);
            break;
        }
        case 2:
        {
            hard_game_start(bet_amount);
            break;
        }
        default:
            break;
        }

        game_history_save();

        cout << "Do you want to continue playing? (yes/no): ";
        cin >> play_again;
    }

    cout << "Thank you for playing!" << endl;

    return 0;
}