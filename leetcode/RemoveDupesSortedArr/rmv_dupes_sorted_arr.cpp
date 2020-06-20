#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums);

int main()
{
    vector<int> sortedArr = {0,1};

    for(int i = 0; i < sortedArr.size(); i++)
    {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    int lengthOf_nums = removeDuplicates(sortedArr);

    cout << "removeDuplicates length: " << lengthOf_nums << endl;

    //removeDuplicates(sortedArr);
    for(int i = 0; i < sortedArr.size(); i++)
    {
        cout << sortedArr[i] << " ";
    }
    cout << endl;


    return 0;
}

int removeDuplicates(vector<int>& nums)
{
    if(nums.empty())
    {
        return 0;
    }
    else if(nums.size() == 1)
    {
        return 1;
    }
    
    int newIndex = 0;
    int duplicates = 0;

    //For any array with more than 1 element
    for(int i = 0; i < nums.size() - 1; i++)
    {
        cout << "At: " << "[" << i << "] " << nums[i] <<  endl; 
        if(nums[i] == nums[i+1])
        {
            duplicates++; 
        }
        else if(nums[i] != nums[i+1])
        {
            newIndex++;
            cout << "newIndex: " << newIndex << ".Putting " << nums[i+1] << " to index " << newIndex << endl;
            nums[newIndex] = nums[i+1];
        }
    }
    cout << "Popping " << duplicates << " times" << endl;
    while(duplicates > 0)
    {
        nums.pop_back();
        duplicates--;
    }


    return nums.size();
}