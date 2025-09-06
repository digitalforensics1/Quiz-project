#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int playQuiz();

int main() {
    int finalResult = 0;
    char playAgain;

play: // replay label
    finalResult = playQuiz();
    cout << "Your score is: " << finalResult << endl;

    if (finalResult >= 5) {
        cout << "You are pass" << endl;
    } else {
        cout << "You are fail" << endl;
    }

    cout << "Do you want to play QUIZ again y or n?" << endl;
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        goto play;
    } else {
        cout << "Thank you for playing Quiz!" << endl;
    }
    return 0;
}

int playQuiz() {
    ifstream file("questions.txt");
    if (!file) {
        cerr << "Error: Could not open questions.txt\n";
        return 0;
    }

    string question, option;
    char correctAnswer, userAnswer;
    int score = 0, qCount = 0;

    cout << "------Welcome to Quiz Game------" << endl;
    cout << "-----Please follow the instructions-----" << endl;
    cout << "Step 1 : Quiz contains multiple questions" << endl;
    cout << "Step 2 : You will get 1 mark for each right answer" << endl;
    cout << "Step 3 : There will be no negative marking" << endl;

    cout << "Step 4 : Please select option a, b, c, d" << endl;
    cout << "Step 5 : If you score >=5 , you will pass the quiz" << endl;

    while (getline(file, question)) {
        if (question.empty()) continue; // skip blanks
        cout << "\nQ" << ++qCount << ". " << question << endl;

        // Print options
        for (int i = 0; i < 4; i++) {
            getline(file, option);
            cout << option << endl;
        }

        file >> correctAnswer;  // correct answer
        file.ignore();          // skip newline

        cout << "Your answer (a/b/c/d): ";
        cin >> userAnswer;

        if (tolower(userAnswer) == tolower(correctAnswer)) {
            cout << "✅ Correct!\n";
            score++;
        } else {
            cout << "❌ Wrong! Correct answer was " << correctAnswer << endl;
        }
    }

    file.close();
    return score;
}