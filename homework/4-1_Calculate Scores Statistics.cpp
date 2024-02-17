/*********************************************************************
* Name: Koichi Nakayamada
* Project: Calculate Scores Statistics
* Editor(s) used: Xcode
* Compiler(s) used: Xcode
* Description: Write a program to ask the user to enter 5 scores (double) and calculate the following statistics: average score, the maximum score, the minimum sore by using a function named scoreStats.  This function returns the average score.  The other stats are returned by using pass-by-reference parameters.  Here's the function prototype:
 
 double scoreStats (double scores[], double &maxScore, double &minScore)

  

 The main function gets the input scores from the user and store them in the scores array and calls scoreStats() to calculate the statistics.  Then  the main function prints the results.
* This program manages courses taken by a student.
**********************************************************************/
#include <iostream>
using namespace std;

// Function prototype adjusted to requirements
double scoreStats(double scores[], double &maxScore, double &minScore);

int main() {
    const int SIZE = 5; // Number of scores is fixed
    double scores[SIZE]; // Array to store the scores
    double maxScore, minScore, average; // Variables to store the statistics
    
    // Ask the user to enter 5 scores
    cout << "Please enter 5 scores (Please put space to separate the numbers): ";
    for (int i = 0; i < SIZE; i++) {
        cin >> scores[i];
    }
    
    // Calculate the statistics
    average = scoreStats(scores, maxScore, minScore);
    
    // Print the results
    cout << "Average score: " << average << endl;
    cout << "Maximum score: " << maxScore << endl;
    cout << "Minimum score: " << minScore << endl;
    
    return 0;
}

// Function to calculate the average, maximum, and minimum scores
// Adjusted to not take size as a parameter, assuming fixed size of 5
double scoreStats(double scores[], double &maxScore, double &minScore) {
    const int SIZE = 5; // Fixed size for the array
    double sum = 0; // Initialize sum of scores
    maxScore = scores[0]; // Assume first score is the max
    minScore = scores[0]; // Assume first score is the min

    // Loop through scores to update sum, maxScore, and minScore
    for (int i = 0; i < SIZE; i++) {
        sum += scores[i]; // Add current score to sum
        if (scores[i] > maxScore) maxScore = scores[i]; // Update maxScore if current score is greater
        if (scores[i] < minScore) minScore = scores[i]; // Update minScore if current score is lesser
    }

    return sum / SIZE; // Return the average score
}
