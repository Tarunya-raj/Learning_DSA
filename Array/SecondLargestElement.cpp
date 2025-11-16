#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
        int secondLargestElement=-1, largestElement=-1;
        for(int i=0; i<= nums.size();i++)
        {
            if(largestElement<nums[i] )
            {
                secondLargestElement=largestElement;
                largestElement=nums[i];

            }
            else if(secondLargestElement<nums[i] && nums[i] < largestElement)
            {
                secondLargestElement=nums[i];   
            }

        }
        return secondLargestElement;
      
    }
};
int main(){
    Solution findSecondLargestElement=Solution() ;
    std::vector<int> ip= {10, 10,10 ,10};
    int secondLargest= findSecondLargestElement.secondLargestElement(ip);
   
    cout<< "SECOND LARGEST: "<< secondLargest;

}