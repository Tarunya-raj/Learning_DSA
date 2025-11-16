#include <iostream>
using namespace std;
void print1_n(int n)
{
    if(n==0)
         {
        cout<<"Enter number greater than 1 "<<endl;

    };
    if(n>1)
    {
        print1_n(n-1);
        cout<< n<<"\t";

    }
    else 
        cout<<1<<"\t";

    return;
    
};
void printn_1(int n)
{
    if(n==0)
    {
        cout<<"Enter number greater than 1 "<<endl;

    }
    if(n>1)
    {
        cout<<n<<"\t";
        printn_1(n-1);
    }
    else
        cout<<1<<"\t";

    return;

}
int pow(int n, int power)
{
    if(n==0)
        return 0;
    
    if(power==0)
        return 1;
    if(n>0&& power>0)
    {
        return pow(n, power-1)*n;
    }
};

int sumofNterms(int n)
{
    if(n<2)
        return n;
    else 
        return n+sumofNterms(n-1);
    

}
    
int fact(int n)
{
    if(n<2)
        return n;
    else 
        return n*fact(n-1);

}

void reverseNumber(int n)
{
    int quotient= n/10;
    int remainder= n%10;
    if(n<10)
        cout<<n;
    else{
        
    cout<< remainder;
    reverseNumber(quotient);
    }
    // if(remainder==0&& quotient ==0)
    //     return;
    
}

int main()
{
    //print1_n(15);
    //printn_1(15);
    //cout<<pow(2,10);
    //cout<< sumofNterms(11);
    //cout <<fact(11);
    reverseNumber(-976);

}