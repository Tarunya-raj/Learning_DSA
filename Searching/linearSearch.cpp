#include <iostream>
#include <vector>
using namespace std;
int search(std::vector<int>& array, int key)
{
    for(int i=0 ; i<array.size();i++ ) 
    {
       if(array.at(i)== key)
         return i;
       else 
        continue; 
    }  
    return -1;
}
int main()
{
    std::vector<int> arr={4,9,2,3,6,3,9,1,0,4,4,67};
    int index=-1;
    index= search(arr, 4);
    cout << index;
}
