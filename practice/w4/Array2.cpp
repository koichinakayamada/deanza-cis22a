#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::getline;
using std::string;

void printScores(int[], int);
// void printScores(int scoresList[], int);
int getMax(int scoreList[], int size, int &maxScore);

int main()
{
  const int CAPACITY = 5;
  int scores [CAPACITY] = {}; // init all to 0
  int i;

  for (i = 0; i < CAPACITY; i++)
  {
    cout << "Enter a score [" << i << "]: ";
    cin >> scores[i];
  }

  // How to pass an array to a function
  printScores(scores, CAPACITY);

  // find the maximum scores and sum of all scores
  /*
  int sum = scores[0];
  int maxScore = scores[0];   // 99
  for (int index = 1; index < CAPACITY; index++) // starting at index 1
  {
    if (maxScore < scores[index])
       maxScore = scores[index];
    sum += scores[index];
  }
  cout << "Sum of scores = " << sum << "\t\t Max score = " << maxScore << endl;

  */
  int sum, maxScore;

  sum = getMax(scores, CAPACITY, maxScore);
  cout << "Sum of scores = " << sum << "\t\t Max score = " << maxScore << endl;
  
  return 0;
}


int getMax(int scoreList[], int size, int &maxScore)
{
  int sum = scoreList[0];
  maxScore = scoreList[0];   // 99
  for (int index = 1; index < size; index++) // starting at index 1
  {
    if (maxScore < scoreList[index])
       maxScore = scoreList[index];
    sum += scoreList[index];
  }

  return sum;
}


void printScores(int scoreArray[], int size)
{
  cout << "Score array contents: " << endl;
  for (int i = 0; i < size; i++)
    cout << "scoreArray[" << i << "] = " << scoreArray[i] << endl;
}
