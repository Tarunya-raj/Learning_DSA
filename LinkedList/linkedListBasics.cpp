#include <iostream>
using namespace std;

struct node{
    int value;
    struct node* next; // self referential structure

};
int main()
{
    struct node n1,n2,n3,n4;
    struct node* arrAddress[]= {&n1, &n2, &n3,&n4};

    n1.value=10;
    n1.next=&n2;
    n2.value= 12;
    n2.next=&n3;
    n3.value=20;
    n3.next=NULL;
    n4={200,&n3};
    struct node arrCopy[]={n1,n2,n3,n4}; // arrar has copy of nodes n1,n2,n3.
    struct node *ptr= &n1;
    cout<< ptr->value <<"\t"<< ptr->next<<endl;
    cout << n1.value <<"\t"<< n1.next<<"\t"<<&n1<<endl;
    cout << arrCopy[0].value <<"\t"<< arrCopy[0].next<<"\t"<<arrCopy<<endl;
    for(auto node: arrCopy)
    {
        cout<< node.value<<"\t"<<node.next<<endl;
    }
    for(auto node: arrAddress)
    {
        cout<< node->value <<"\t"<< node->next<<endl;
    }


}