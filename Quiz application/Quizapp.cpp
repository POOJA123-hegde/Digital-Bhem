#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct User {
    string username;
    string password;
    int score;
};

struct Question {
    string question;
    string options[4];
    int correctOption; // The correct answer index (0-3)
};

vector<User> users;
vector<Question> questionBank;

void registerUser();
bool loginUser();
void loadQuestions();
void startQuiz(User &user);
void showLeaderboard();

int main() {
    int choice;
    loadQuestions();  // Load questions into memory

    while (true) {
        cout << "\nQuiz Application\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Take Quiz\n";
        cout << "4. Show Leaderboard\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    cout << "Logged in successfully!" << endl;
                }
                break;
            case 3:
                if (users.size() > 0) {
                    User &loggedInUser = users[0];  // Simplified: take first user as logged in
                    startQuiz(loggedInUser);
                } else {
                    cout << "Please login first!" << endl;
                }
                break;
            case 4:
                showLeaderboard();
                break;
            case 5:
                cout << "Thank you for using the quiz application!" << endl;
                return 0;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
}

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Simple check for existing username
    for (const auto &user : users) {
        if (user.username == username) {
            cout << "Username already exists!" << endl;
            return;
        }
    }

    // Add new user
    User newUser = {username, password, 0};
    users.push_back(newUser);
    cout << "Registration successful!" << endl;
}

bool loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (auto &user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    cout << "Invalid username or password!" << endl;
    return false;
}

void loadQuestions() {
    questionBank.push_back({"What is the capital of France?", {"1) London", "2) Paris", "3) Berlin", "4) Madrid"}, 2});
    questionBank.push_back({"Which language is used for web development?", {"1) C++", "2) Java", "3) JavaScript", "4) Python"}, 3});
    questionBank.push_back({"What is 2 + 2?", {"1) 3", "2) 4", "3) 5", "4) 6"}, 2});
}

void startQuiz(User &user) {
    int score = 0;
    cout << "Starting the quiz..." << endl;

    for (int i = 0; i < questionBank.size(); ++i) {
        Question q = questionBank[i];
        cout << "\n" << q.question << endl;
        for (const auto &option : q.options) {
            cout << option << endl;
        }

        int answer;
        cout << "Enter the number of your answer: ";
        cin >> answer;

        if (answer - 1 == q.correctOption) {
            score++;
        }
    }

    user.score = score;
    cout << "Quiz completed!" << endl;
    cout << "Your Score: " << score << "/" << questionBank.size() << endl;
}

void showLeaderboard() {
    if (users.empty()) {
        cout << "No users registered yet!" << endl;
        return;
    }

    cout << "\nLeaderboard:" << endl;
    for (const auto &user : users) {
        cout << user.username << " - Score: " << user.score << endl;
    }
}
