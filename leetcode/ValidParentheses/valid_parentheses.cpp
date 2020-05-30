#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s);

int main()
{
    string input = "[])"
;
    bool testValid = true;

    testValid = isValid(input);
    if(testValid)
    {
        cout << "valid parentheses" << endl;
    }
    else
    {
        cout << "invalid parentheses" << endl;
    }
    

    
    return 0;
}

bool isValid(string s)
{
    bool valid = true;

    if(s.empty())
    {
        cout <<"Empty string" << endl;
        return valid;
    }

    
    stack<char> prev;
    prev.push(s[0]);
    cout << "Pushed: " << prev.top() << endl;
    for(int i = 1; i < s.size(); i++)
    {
        //prev.push(s[i]);
        
        if((s[i] == '}') && (!prev.empty()))
        {
            if(prev.top() == '{')
            {
                cout << "Matched { } and popping " << prev.top() << endl;
                prev.pop();
                continue;
            }
            
        }
        else if((s[i] == ')') && (!prev.empty()))
        {
            if(prev.top() == '(')
            {
                cout << "Matched ( ) and popping " << prev.top() << endl;
                prev.pop();
                continue;
            }
            
        }
        else if((s[i] == ']') && (!prev.empty()))
        {
            if(prev.top() == '[')
            {
                cout << "Matched [ ] and popping " << prev.top() << endl;
                prev.pop();
                continue;
            }
        }

        prev.push(s[i]);
        cout << "Pushed: " << prev.top() << endl;
        
    }
    
    if(!prev.empty())
    {
        valid = false;
    }

    return valid; //went through all characters and no falses, so true
}