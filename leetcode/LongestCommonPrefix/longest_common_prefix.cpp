#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string longestCommonPrefix(vector<string>& strs);

int main()
{
    vector<string> arrOfStrings = {"flower","flow","flight", "fliter", "flick"};
    
    string s = "";
    cout << "string s: empty" << s << endl;
    s += "a";
    cout << "s += a: " << s << endl;
    s += "b";
    cout << "s += b: " << s << endl;
    
    s = longestCommonPrefix(arrOfStrings);
    cout << "Longest common prefix: " << s << endl;
    
    return 0;
}

string longestCommonPrefix(vector<string>& strs)
{
    unordered_map<string, int> common_strs;
    string matched_chars = "";
    
    if(strs.empty())
    {
        cout << "strs is empty" << endl;
        return "";
    }
        

    int element = 0;
    for(int i = 0; i < strs.size(); i++)
    {
        cout << "Size of strs: " << strs.size() << endl;
        cout << "At index: " << i << endl;

        element = i;
        //If there is more than 1 string, stay on the element and compare the element with the other elements
        if(strs.size() > 1)
        {
            for(int k = i+1; k < strs.size(); k++)
            {
                cout << "About to compare: " << strs[element] << " with " << strs[k] << endl;
                for(int j = 0; j < strs[element].size(); j++)
                {
                    
                    if((strs[element])[j] == (strs[k])[j]) 
                    {
                        matched_chars += (strs[k])[j];
                        cout << "matched_chars: " << matched_chars << endl;
                        
                        //If the string is already in the map...
                        if(common_strs.find(matched_chars) != common_strs.end())
                        {
                            cout << matched_chars << " occured" << endl;
                            common_strs[matched_chars]++; 
                        }
                        
                    }
                    else
                    {
                        cout << "No more consecutive matches, breaking current loop" << endl;
                        break;
                    }
                    
                }
                //If the string is not in the map...
                if((common_strs.find(matched_chars) == common_strs.end()) && (matched_chars != ""))
                {
                    common_strs.insert({matched_chars, 1});
                }
                
                matched_chars = "";
            }


        }
        else if(strs.size() == 1)
        {
            matched_chars = strs[0];
            common_strs.insert({matched_chars, 1});
        }

        cout << "Iterating the map, after completing a set of comparison" << endl;
        for(auto iter = common_strs.begin(); iter != common_strs.end(); ++iter)
        {
            cout << iter->first << " occured " << iter->second << " times" << endl;
        } 
        cout << endl;
        
        
    }
    int highest_occurrence = 0;
    cout << "After all sets of comparisons, the common longest prefix is: ";
    for(auto iter = common_strs.begin(); iter != common_strs.end(); ++iter)
    {
        if(iter->second > highest_occurrence)
        {
            highest_occurrence = iter->second;
            matched_chars = iter->first;
        }
             
    }
    cout << matched_chars << " occured " << highest_occurrence << " times";
    cout << endl;
    
    
    return matched_chars;
}