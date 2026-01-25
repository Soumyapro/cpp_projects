#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Login_System
{
private:
    string username;
    string password;

public:
    Login_System(const string &u, const string &p)
    {
        username = u;
        password = p;
    }

    string get_username() const
    {
        return username;
    }

    string get_password() const
    {
        return password;
    }
};

class Register
{
private:
    string file_name;

public:
    Register(const string &f)
    {
        file_name = f;
    };

    void save_credentials(const Login_System &login)
    {
        string username = login.get_username();
        string password = login.get_password();
        string credentials = username + " " + password + "\n";

        ofstream file(file_name, ios::app);
        if (!file.is_open())
        {
            cout << "Error opening file for saving credentials." << endl;
            return;
        }

        file << credentials;
        file.close();
    }
};

class Auth
{
private:
    string file_name;

public:
    Auth(const string &f)
    {
        file_name = f;
    };

    bool verify_credentials(const Login_System &login)
    {
        string username = login.get_username();
        string password = login.get_password();
        string credentials = username + " " + password;

        ifstream file(file_name);
        if (!file.is_open())
        {
            cout << "Error opening file for verifying credentials." << endl;
            return false;
        }
        string line;
        while (getline(file, line))
        {
            if (line == credentials)
            {
                return true;
            }
        }
        file.close();
        return false;
    }
};

int main()
{

    cout << "Welcome to the Login & Registration System" << endl;
    cout << "--------------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
    int choice;
    cin >> choice;

    switch (choice)
    {

    case 1:
    {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        Login_System new_user(username, password);
        Register reg("credentials.txt");
        reg.save_credentials(new_user);
        cout << "Registration Successful!" << endl;
        break;
    }

    case 2:
    {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        Login_System existing_user(username, password);
        Auth auth("credentials.txt");

        if (auth.verify_credentials(existing_user))
        {
            cout << "Login Successful!" << endl;
        }
        else
        {
            cout << "Invalid Username or Password." << endl;
        }
        break;
    }

    case 3:
    {
        cout << "Exiting the system. Goodbye!" << endl;
        break;
    }

    default:
        cout << "Invalid option. Please try again." << endl;
        break;
    }

    return 0;
}