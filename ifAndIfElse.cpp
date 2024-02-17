#include <iostream>
using namespace std;

int main()
{
    int age;
    int score;
    char grade;

    cout << "How old are you?: " << endl;
    cin >> age;

    // If without else
    if (age == 21) 
        cout << "Congratulations! You have just reached drinking age." << endl;

    // If with else
    cout << "if-else statement\n";
    if (age >= 21) {
        cout << "You can drink." << endl;    
    }
    else{
        cout << "You can't drink yet." << endl;
    }

    if (!(age < 21)){
        cout << "You are old enough to drink.\n";
    }    
    else {
        cout << "You are too young.\n";
        cout << "Please come back in " << 21 - age << " Years.\n"; 
    }
    
    // Compound conditions
    if (age > 15 && age <66)// If this statement is true, the left and right hand sides are both true
        cout << "Have a good work day." << endl;
    
    // No comparsion, 0 is false, else is true
    cout << "Enter a score to see if it's true or false.: " << endl;
    cin >> score;
    if (score)// If there is no comparsion like this, 0 should be false, and else is true
        cout << "score: " << score << " is true\n";
    else
        cout << "score: " << score << " is false\n";
    
    // Chained if-else
    cout << "Tell me your score, I'll figure out you grade: " << endl;
    cin >> score;
    if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'F';
    
    cout << "Your grade is: " << grade << endl;
    cout << "\nEnd of program." << endl;
}