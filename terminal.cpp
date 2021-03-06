#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

string login() {
    string loginDir = "logins.txt";
    fstream logins(loginDir);
    string username;
    string password;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    string line, T;
    while (getline (logins, line)) {
        int divider = line.find(",");
        string user = line.substr(0, divider);
        string pass = line.substr(divider+1, line.length());
        if ((username == user)&&(password == pass)) {
            return user;
        }
    }
    return "";
}

int handleInput(string input, string path) {
    int divider = input.find(" ");
    string opcode = input.substr(0, divider);
    string operand = input.substr(divider+1, input.length());
    if (opcode == "run") {
        const char * c = operand.c_str();
        system(c);
    }
}

int main() {
    bool running = true;
    string userInput;
    string path = "T:/home/";
    string current_user = "";

    while (running) {
        if (current_user == "") {
            current_user = login();
            if (current_user == "") {
                continue;
            }
        }
        cout << path+current_user+"$ ";
        cin >> userInput;
        cout << "\n";
        if (userInput == "end") {running = false;}
        if (userInput == "logout") {current_user = "";}
        handleInput(userInput, path);

    }
}