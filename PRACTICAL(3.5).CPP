#include <iostream>
#include <cstring>
using namespace std;
int Super_Digit(int n)
{
    if (n < 10)
        return n;
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return Super_Digit(sum);
}
int Super_Digit_Of_Concatenated_Number(const string &n, int k)
{
    int Initial_Sum = 0;
    for (char digit : n)
        Initial_Sum += digit - '0';
    int Total_Sum = Initial_Sum * k;
    return Super_Digit(Total_Sum);
}
int main()
{
    string n;
    int k;
    cout << endl
         << "Enter the string representation of the number (n) : ";
    cin >> n;
    cout << endl
         << "Enter the number of repetition (k) : ";
    cin >> k;
    int result = Super_Digit_Of_Concatenated_Number(n, k);
    cout << endl
         << "The super digit is : " << result<<endl;
    cout<<"SHREEJAY_24CE117";
    return 0;
}
