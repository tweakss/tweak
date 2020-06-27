#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle);

int main()
{
    string haystack = "aakaab";
    string needle = "aab";
    int needle_pos = 0;

    cout << "haystack: ";
    for(int i = 0; i < haystack.size(); i++)
    {
        cout << haystack[i];
    }
    cout << "\tneedle: ";
    for(int i = 0; i < needle.size(); i++)
    {
        cout << needle[i];
    }
    cout << "\n\n";

    needle_pos = strStr(haystack, needle);
    cout << "needle_pos: " << needle_pos << endl; 

    return 0;
}

int strStr(string haystack, string needle)
{
    int needle_at = -1;
    int needleIndex = 0;
    int j = 0;

    if(needle.empty())
    {
        return 0;
    }
    else if(needle.size() > haystack.size())
    {
        return -1;
    }

    for(int i = 0; i < haystack.size(); i++)
    {
        cout << "Beginning of for loop, i: " << i << endl;
        if(haystack[i] == needle[0])
        {
            //needle_at = i;
            j = i;
            if(j+needle.size() > haystack.size())
            {
                cout << "j+needle.size() > haystack.size()... breaking" << endl;
                break;
            }
            
            needle_at = i;
            while((haystack[j] == needle[needleIndex]) && (needleIndex < needle.size()))
            {
                cout << "At haystack " << j << ", " << haystack[j] << " matches needle " << needleIndex << ", " << needle[needleIndex] << endl;
                j++;
                needleIndex++;
            }
            
            if(needleIndex == needle.size())
            {
                return needle_at;
            }
            else
            {
                
                cout << "needleIndex != needle.size()" << endl;
                needleIndex = 0;
                needle_at = -1;
            }
           
        }
    }

    return needle_at;
}