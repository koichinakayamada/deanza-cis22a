/*********************************************************************
 * Name: Koichi Nakayamada
 * Project: week8 - classAndObject
 * Editor(s) used: VSCode
 * Compiler(s) used: G++
 * Description: 1. Define the class named "SimplePay" that manages working hour info:
- the number of working hours (integer)
- the hourly pay rate (double)
It must have at least the following methods:
- "toString" method to return pay information as a string in the format
HOURS(<hours>) PAY-RATE(<pay-rate>) PAY-AMOUNT(<pay-total>)
For example,
HOURS(40) PAY-RATE($10) PAY-AMOUNT($400)
or
HOURS(60) PAY-RATE($10) PAY-AMOUNT($700)
Please note that any working hour that is more than 40 hours will be using overtime payrate
(payrate * 1.5).
- "payMore" method to compare with another SimplePay object and return true if the total pay
is more than the other object.  Hint: the method signature:  bool payMore(SimplePay &otherPay)

2. Write the main function to create 2 SimplePay objects to test your class.  You can assign values to hours and pay rate directly (there is no need to get the user input).  Then, compare the pay amount by utilizing "payMore" method.

3. You can place all of your code in one CPP file to make it easy to test.
 **********************************************************************/

#include <iostream>
#include <sstream> // For string stream

#include <iostream>
#include <sstream>

/********************************************************************
 * Class: SimplePay
 * Description: Manages working hour info including the number of working hours and the hourly pay rate.
 *******************************************************************/
class SimplePay
{
private:
    int hours;      // Number of working hours
    double payRate; // Hourly pay rate

public:
    /********************************************************************
     * Constructor: SimplePay
     * Description: Initializes a SimplePay object with given hours and pay rate.
     * Parameters:
     *  h (IN): Number of working hours
     *  rate (IN): Hourly pay rate
     *******************************************************************/
    SimplePay(int h, double rate) : hours(h), payRate(rate) {}

    /********************************************************************
     * Function: toString
     * Description: Returns a string representing the pay information.
     * Parameters: NONE
     * Return: A string in the format "HOURS(<hours>) PAY-RATE($<pay-rate>) PAY-AMOUNT($<pay-total>)".
     *******************************************************************/
    std::string toString() const
    {
        std::stringstream ss;
        double totalPay = hours <= 40 ? hours * payRate : 40 * payRate + (hours - 40) * payRate * 1.5;
        ss << "HOURS(" << hours << ") PAY-RATE($" << payRate << ") PAY-AMOUNT($" << totalPay << ")";
        return ss.str();
    }

    /*******************************************************************
     * Function: payMore
     * Description: Compares the total pay of this object with another SimplePay object.
     * Parameters:
     *  otherPay (IN): The other SimplePay object to compare against.
     * Return: True if this object's total pay is more than the other object's, false otherwise.
     *******************************************************************/
    bool payMore(const SimplePay &otherPay) const
    {
        double myTotalPay = hours <= 40 ? hours * payRate : 40 * payRate + (hours - 40) * payRate * 1.5;
        double otherTotalPay = otherPay.hours <= 40 ? otherPay.hours * otherPay.payRate : 40 * otherPay.payRate + (otherPay.hours - 40) * otherPay.payRate * 1.5;
        return myTotalPay > otherTotalPay;
    }
};

/*********************************************************************
 * Function: Main
 **********************************************************************/
int main()
{
    // Create SimplePay objects
    SimplePay employee1(40, 10); // 40 hours at $10/hr
    SimplePay employee2(60, 10); // 60 hours at $10/hr, including overtime

    // Show pay information for both employees
    std::cout << "Employee 1: " << employee1.toString() << std::endl;
    std::cout << "Employee 2: " << employee2.toString() << std::endl;

    // Compare their pay
    if (employee1.payMore(employee2))
    {
        std::cout << "Employee 1 earns more than Employee 2." << std::endl;
    }
    else
    {
        std::cout << "Employee 2 earns more or the same as Employee 1." << std::endl;
    }

    return 0;
}
