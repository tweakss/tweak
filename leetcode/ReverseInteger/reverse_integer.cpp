#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int reverse(int x);

int main()
{
    int num = 0;
    int after = 0;

    cin >> num;
    cout << "num: " << num << endl;
    
    after = reverse(num);
    cout << "After reverse: " << after << endl;
    
    return 0;
}

int reverse(int x)
{
    int powOfTen = -1;
    long int sum = 0;
    long int temp_x = x;
    bool isNeg = false;

    cout << "In reverse, x is " << x << endl;
    if(temp_x < 0)
    {
        isNeg = true;
        temp_x = temp_x*-1;
    }

    //Get the powOfTen of x
    for(int i = temp_x; i > 0; i /= 10)
    {
        powOfTen++;
        cout << "powOfTen++: " << powOfTen << endl;
        
    }
    cout << endl;
    cout << "powOfTen: " << powOfTen << endl;

    //Use the powOfTen of x to calculate sum
    //cout << "--- Calculate sum ---" << endl;
    for(int i = temp_x; i > 0; i /= 10)
    {
        cout << i % 10 << "\t";
        sum += (i % 10)*pow(10, powOfTen);
        cout << "sum: " << sum << "\t";
        powOfTen--;
        cout << "powOfTen: " << powOfTen << endl;
    }

    //If negative
    if(isNeg)
    {
        sum = sum*-1;
        cout << "sum*-1: " << sum << endl;
    }
    cout << "return sum: " << sum << endl;

    //Check for overflow
    if((sum >= pow(-2, 31)) && (sum <= pow(2, 31)-1))
    {
        cout << "if between -2^31 and 2^31 - 1, return sum" << endl;
        return sum;
    }
    else
    {
        cout << "else, return 0" << endl;
        return 0;
    }
        

    
}