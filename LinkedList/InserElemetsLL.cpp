#include <iostream>
using namespace std;
class LinkedList{
    private:
     int value=0;
     LinkedList *next=NULL;

     public:
    LinkedList(int value, LinkedList *nextNodeAddress)
    {
        this->value=value;
        this->next= nextNodeAddress;

    }
    void updateNextNodeAddress(LinkedList *nextAddress)
    {
        this->next= nextAddress;

    }
    //function call by pointer
    void insertFirst(int value, LinkedList *(*headptr))
    {
        *headptr = new LinkedList(value, *headptr); // new list having value and pointing to the first elemet ie: head


    }
    void insertLast(int value, LinkedList*(*headPtr)){
        LinkedList *temp= *headPtr;
        while(temp!= NULL)
        {
            if(temp->getNextNodeAddress()==NULL)
            {
                temp->updateNextNodeAddress(new LinkedList(value, NULL));
                break;
            }
            //updating temp
            temp= temp->getNextNodeAddress();

        }


    }
    LinkedList* getNextNodeAddress()
    {
        return this->next;

    }
    int getValue()
    {
        return this->value;
    }
    /*
    
        [STACK: main]
        head ──► NULL        ← main head is STILL NULL

        [STACK: insertFirst]
        head ──► 0x1000      ← ONLY LOCAL head changed

        [HEAP]
        0x1000: [value=10 | next=NULL]


        These two head variables are NOT the same.


    */
    //void displayList(LinkedList *head)// call by value rather than call by refrence or pointer 
    void displayList(LinkedList *head)
    {
        LinkedList *temp= head;
        while(temp!= NULL)
        {
            cout << (*temp).getValue()<<" -> ";
            temp= temp->getNextNodeAddress();
        
        }
        cout <<"END";

    }

};

int main()
{
    LinkedList *head=NULL;
   // LinkedList *head =new LinkedList(100,NULL);
    // calling a method on null pointer will lead to crash
    //if(head != NULL)
    {
         head->insertFirst(10,&head);
        head->insertFirst(20,&head);
        head->insertFirst(30,&head);
        head->insertLast(200,&head);
        head->displayList(head);

    }
   


}