#include <iostream>
using  namespace std;
#include <vector>
void bubbleSortReccursive(std::vector<int> & arr, int lastElement)
{
    if(lastElement<0)
        return;
    for(int i=0; i<lastElement-1; i++)
    {
        if(arr.at(i)>arr.at(i+1))
            std::swap(arr.at(i),arr.at(i+1));
        else 
            continue;
    }
    bubbleSortReccursive(arr, lastElement-1);
}

void bubbleSortItterative(std::vector<int> & arr)
{
    for(int i=0; i<arr.size()-1; i++)
    {
        for(int j=i; j<arr.size()-1;j++)
        {
            if(arr[j]>arr[j+1])
                std::swap(arr[j],arr[j+1]);
            else 
                continue;

        }
    }

}
int main ()
{
    std::vector<int> arr= {0,12,1,56,2,8,4,23,8,9,11,34};
    //bubbleSortReccursive(arr, arr.size());
    bubbleSortItterative(arr);
    for(int i: arr)
        cout<<i<<"\t";
}