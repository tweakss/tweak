#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val);

int main()
{
    vector<int> arr = {0,1,2,2,3,0,4,2};

    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int length = removeElement(arr, 2);
    cout << "Length after removeElement: " << length << endl;
    cout << "After removeElement, arr is: ";
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

int removeElement(vector<int>& nums, int val)
{
    int newIndex = 0;

    if(nums.empty())
    {
        return 0;
    }

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != val)
        {
            nums[newIndex] = nums[i];
            newIndex++; 
        }
    }
    
    
    return newIndex;
}