#include <iostream>
#include <vector>
#include <string>


using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main()
{
   vector<int> array{2,7,11,15};

   twoSum(array, 9);

   return 0;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int>indices;

    
    for(int i = 0; i < nums.size() - 1; i++)
    {
        //cout << "At " << nums[i] << " ,going right" << endl;
        for(int goRight = i + 1; goRight < nums.size(); goRight++)
        {
            if(nums[i] + nums[goRight] == target)
            {
                indices.push_back(i);
                indices.push_back(goRight);
                cout << "push_back index: " << i << " " << goRight << endl; 
            }   
        }
            
    }

    return indices;
}