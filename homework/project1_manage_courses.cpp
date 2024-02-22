/*********************************************************************
 * Name: Koichi Nakayamada
 * Project: Project 1: Manage Courses
 * Editor(s) used: VSCode
 * Compiler(s) used: g++
 * Description: Receives an e, u, or l input, and accordingly exits the system,
 *displays more classes than the number of units desired by the user, or
 *displays a list of the entire class. The number of units is also displayed in
 *the class display.
 **********************************************************************/

#include <fstream>  // Include for file stream operations
#include <iomanip>  // Include for using setw
#include <iostream> // Include for input and output operations
#include <limits>   // Include for using numeric_limits
#include <sstream>  // Include for string stream operations
#include <string>   // Include for using the string class
#include <vector>   // Include for using the vector container

using namespace std;

/*********************************************************************
* Function: Displays the main menu options to the console.
*
* Parameters: NONE
*
* Return: NONE
**********************************************************************/
void displayMenu() {
  // Prints the main menu options to the console
  cout << "================================================\n";
  cout << " Welcome to My Course Catalog Management System \n";
  cout << "================================================\n";
  cout << "E end Terminate the program\n";
  cout << "L List Show all available courses in the catalog\n";
  cout << "U search units>= number Show all courses in the catalog that have "
       << "the number of units equal or greater than the given number\n";
  cout << "Enter your option: ";
}

/*********************************************************************
* Function: Finds the maximum length of titles in the given list.
*
* Parameters:
*   titles (IN): A constant reference to a vector of strings, where
*                each string represents a course title.
*
* Return: The maximum length among the titles as an integer.
**********************************************************************/
int findMaxTitleLength(const vector<string> &titles) {
  int maxLength = 0;
  for (const string &title : titles) { // Corrected the syntax here
    if (title.length() > maxLength) {
      maxLength = title.length();
    }
  }
  return maxLength;
}

/*********************************************************************
* Function: Displays a list of courses and their corresponding units,
*           aligning the units column based on the maximum title length.
*
* Parameters:
*   units (IN): A constant reference to a vector of integers, where each
*               integer represents the number of units for a course.
*   titles (IN): A constant reference to a vector of strings, where each
*                string represents the title of a course.
*
* Return: NONE
**********************************************************************/
void displayCourses(const vector<int> &units, const vector<string> &titles) {
  int maxTitleLength = findMaxTitleLength(titles);
  cout << "\nCourses Catalog\n";
  // Adjust the setw() for titles to ensure units align
  cout << left << setw(maxTitleLength + 8) << "Title"
       << "Unit\n";
  for (size_t i = 0; i < titles.size(); i++) {
    cout << left << setw(maxTitleLength + 4) << titles[i] << right << setw(5)
         << units[i] << endl;
  }
}

/*********************************************************************
* Function: Displays courses that have at least a specified number of
*           units, aligning the units column based on the maximum title
*           length for readability.
*
* Parameters:
*   units (IN): A constant reference to a vector of integers, where
*               each integer represents the number of units for a course.
*   titles (IN): A constant reference to a vector of strings, where
*                each string represents the title of a course.
*   minUnits (IN): An integer specifying the minimum number of units
*                  a course must have to be included in the display.
*
* Return: NONE
**********************************************************************/
void displayCoursesWithMinUnits(const vector<int> &units,
                                const vector<string> &titles, int minUnits) {
  int maxTitleLength = findMaxTitleLength(titles);
  cout << "\nCourses matching your search:\n";
  cout << left << setw(maxTitleLength + 8) << "Title"
       << "Unit\n";
  for (size_t i = 0; i < units.size(); i++) {
    if (units[i] >= minUnits) {
      cout << left << setw(maxTitleLength + 4) << titles[i] << right << setw(5)
           << units[i] << endl;
    }
  }
}

/*********************************************************************
* Function: Main
**********************************************************************/
int main() {
  // Vectors to store course units and titles
  vector<int> courseUnits;
  vector<string> courseTitles;
  // Attempt to open the file
  ifstream file("courseCatalog.txt");
  string line;

  // Check if the file can be opened
  if (!file) {
    // Error message if the file cannot be found or opened
    cerr << "Error: File not found." << endl;
    return 1; // Exit the program with an error code
  }

  // Read the file line by line
  while (getline(file, line)) {
    stringstream ss(line); // Use stringstream for parsing
    int units;
    string title;
    // Extract units and title from the line
    ss >> units >> ws; // ws consumes any leading whitespace before the title
    getline(ss, title);
    // Store the extracted data
    courseUnits.push_back(units);
    courseTitles.push_back(title);
  }
  // Close the file after reading
  file.close();

  char choice; // User's menu choice
  do {
    displayMenu(); // Show the menu
    cin >> choice; // Read the choice
    cin.ignore(numeric_limits<streamsize>::max(),
               '\n'); // Clear the input buffer

    // Process the choice
    switch (choice) {
    case 'L':
    case 'l':
      // Display all courses
      displayCourses(courseUnits, courseTitles);
      break;
    case 'U':
    case 'u':
      cout << "Enter your search unit: ";
      int minUnits;
      // Check for valid integer input
      while (!(cin >> minUnits)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n'); // Discard the input
        cout << "Invalid input. Please enter a number: ";
      }
      displayCoursesWithMinUnits(courseUnits, courseTitles, minUnits);
      break;

    case 'E':
    case 'e':
      // Exit the program
      cout << "----------------------------------------------------------\n";
      cout << " Thank you for using My Course Catalog Management System. \n";
      cout << "----------------------------------------------------------\n";
      break;
    default:
      // Handle invalid input
      cout << "Invalid option. Try again.\n";
    }
  } while (choice != 'E' &&
           choice != 'e'); // Loop until 'E' or 'e' is entered for exit

  return 0; // Indicate successful completion of the program
}
