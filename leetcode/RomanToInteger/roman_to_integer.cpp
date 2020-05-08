#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int romanToInt(string input);

int main()
{
    string romanNums = "";
    int result = 0;
    
    cin >> romanNums;
    cout << "romanNums: " << romanNums << endl;
    result = romanToInt(romanNums);
    cout << "After romanToInt, result: " << result << endl;

    
    return 0;
}

int romanToInt(string input)
{
    cout << "In romanToInt, input: " << input << endl;
    //cout << input[0] << endl; //There is a null character at the end for string
    int conversion  = 0;

    cout << "For looping the string: " << endl;
    for(int i = 0; i < input.length(); i++)
    {
        cout << input[i];
        if(input[i] == 'I')
        {
            if(input[i+1] == 'V')
            {
                conversion += 4;
                i += 1;
            }
            else if(input[i+1] == 'X')
            {
                conversion += 9;
                i += 1;
            }
            else
            {
                conversion += 1;
            }
                
            
        }
        else if(input[i] == 'V')
        {
            conversion += 5;
        }
        else if(input[i] == 'X')
        {
            if(input[i+1] == 'L')
            {
                conversion += 40;
                i += 1;
            }
            else if(input[i+1] == 'C')
            {
                conversion += 90;
                i += 1;
            }
            else
            {
                conversion += 10;
            }
            
        }
        else if(input[i] == 'L')
        {
            conversion += 50;
        }
        else if(input[i] == 'C')
        {
            if(input[i+1] == 'D')
            {
                conversion += 400;
                i += 1;
            }
            else if(input[i+1] == 'M')
            {
                conversion += 900;
                i += 1;
            }
            else
            {
                conversion += 100;
            }
            
        }
        else if(input[i] == 'D')
        {
            conversion += 500;
        }
        else if(input[i] == 'M')
        {
            conversion += 1000;
        }
        else
        {
            cout << "No valid roman numural to convert" << endl;
        }
        cout << " converted to: " << conversion << endl;
        
    }
    cout << endl << "Final conversion: " << conversion << endl;

    //cout << "romanNums: " << romanNums["D"] << endl;

    return conversion;
}