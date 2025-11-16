#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int  largestElement(vector<int> *);
void bruteForcesortArray(vector<int> *);

void selectionSort(vector<int> *);
int main()
{
    // largest element in array
    vector<int> input {10,20,2,8,99,0,56,2,3,9,12,0,43,9,8,43,10};
    //vector<int> input {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int largestElement_= largestElement(&input);
    //largestElement // function name == funciton address
    cout <<"\n"<< largestElement_<< endl;
    for(int vectori=0; vectori<input.size(); vectori++)
    {
        cout << input.at(vectori)<< '\t';
    }

}
void bruteForcesortArray(vector<int > *input)
{
    for(int i=0; i<input->size(); i++)
    {
        //for(int j=1;j<input->size(); j++) // j = i+1 (to compare the current i with each later index) rather than always from 1
        for (int j=i+1; j<input->size(); j++)
        {
           // if(input[i]>input[j])
           if(input->at(i)> input->at(j))
             {
                //swap
                int temp = input->at(i);
                input->at(i)= input->at(j);
                input->at(j)=temp;
                //std::swap(input->at(i),input->at(j));
             }

        }

    }
}

void selectionSort(vector<int>* nums) {
        for(int i=0; i<(nums->size()-1); i++)
        {
            int smallestElementIndex= -1, smallestValue=nums->at(i);
            for(int j=i+1; j<nums->size(); j++)
            {
                if(smallestValue> nums->at(j))
                {
                    smallestElementIndex= j;
                    smallestValue=nums->at(j);
                }
            }
            if(smallestElementIndex !=-1)
                std::swap(nums->at(i),nums->at(smallestElementIndex));
        }

    }



void bubbleSort(vector<int>& input)
{
    for(int parseCount=1 ; parseCount<(input.size()-1); parseCount++)
    {
        bool swapElements= false;
        cout << parseCount;
        for(int i =0 ; i<(input.size()-1); i++)
        {
            if(input.at(i)>input.at(i+1))
            {
                swap(input.at(i),input.at(i+1)); //largest element shifted to right
                swapElements= true;
            }
    
        }
        if(swapElements== false)
            break;
    }
}

void insertionSort(vector<int> & input)
{
    for(int i=0 ; i<input.size()-1; i++)
    {
        int correctIndex=-1;
        for(int j=i+1; j>0; j--)
        {
            if(input.at(j)< input.at(j-1))
            {
                //correctIndex= 
            }
                //swap(input.at(j),input.at(j-1)); //dont swap each time find the proper position then swap
            else
                break;

        }
    }

}

std::vector<int> countingSort(vector<int> & input)
{
    int k= *max_element(std::begin(input),std::begin(input));
    int arr[k]={0};
    vector<int> sortedArray;
    sortedArray.reserve(input.size());
    for(int i=0; i<input.size();i++)
    {

        arr[input[i]]+=1;
    }
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if(arr[i]!=0)
        {
           sortedArray.push_back(i); 
           arr[i]-=1;
        }

    }
    return sortedArray;

}
    

int largestElement(vector<int> *input)
{

    int largestElement;
    //selectionSort(input); // O(n2 complexity)
    // insertionSort(*input);
    return input->at(input->size()-1);
    // sort the vector ascending then get the last element this will be the largest.

}