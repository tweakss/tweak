#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(int x);

int main()
{
    int input;

    cin >> input;
    cout << "input: " << input << endl;
    bool testPalindrome = isPalindrome(input);

    cout << "testPalindrome: " << testPalindrome << endl;

    return 0;
}

bool isPalindrome(int x)
{
    int powOfTen = -1;
    long int sum = 0;


    //Get the powOfTen of x
    for(int i = x; i > 0; i /= 10)
    {
        powOfTen++;
        //cout << "powOfTen++: " << powOfTen << endl;
        
    }
    // cout << endl;
    // cout << "powOfTen: " << powOfTen << endl;

    //Use the powOfTen of x to calculate sum
    // cout << "--- Calculate sum ---" << endl;
    for(int i = x; i > 0; i /= 10)
    {
        // cout << i % 10 << "\t";
        sum += (i % 10)*pow(10, powOfTen);
        // cout << "sum: " << sum << "\t";
        powOfTen--;
        // cout << "powOfTen: " << powOfTen << endl;
    }


    if(sum == x)
        return 1;
    else
    {
        return 0;
    }
    
    
        
}