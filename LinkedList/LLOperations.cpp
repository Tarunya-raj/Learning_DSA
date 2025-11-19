#include <iostream>
using namespace std;

class LinkedList{
    private:
        int value=0;
        LinkedList *next=NULL;
    public:
        LinkedList* getNextNode()
        {
        return this->next;
        };
        int getValue()
        {
        return this->value;
        }
        LinkedList(int value)
        {
            this->value=value;

        }
        void updateValue(int value)
        {
            this->value= value;
        }
        void updateNextNode(LinkedList *nodeptr)
        {
            this->next = nodeptr;
        }
        LinkedList(int value, LinkedList *address)
        {
            this->value= value;
            this->next= address; 

        }
        void display(LinkedList *head)
        {
            LinkedList *temp= head;
            while(temp != NULL)
            {
                cout <<temp->getValue()<<"->";
                temp= temp->getNextNode();

            }
            cout<<"NULL";
            //while(temp!= NULL && temp->getNextNode()!= NULL); // last node will not be printed
            

        }
 };

int main()
{
    //here each node has a corresponding pointer in stack associated with it. This can be avoided.
    LinkedList *n1 = new LinkedList(10,NULL);
    LinkedList *n2 = new LinkedList(20,NULL);
    LinkedList *n3 = new LinkedList(30,NULL);
    //n1->updateNextNode(n2); 
    (*n1).updateNextNode(n2);
    (*n2).updateNextNode(n3);
    (*n1).display(n1);
    cout <<endl;
    (*n2).display(n1);
    cout <<endl;
    (*n3).display(n1);

}

/*

new LinkedList(20, NULL)

Address 0x2000:
+-----------------------+
| value = 20            |
| next  = NULL          |
+-----------------------+

n2 =new LinkedList(20,NULL);

STACK                          HEAP
+------+           +-----------------------+
| n2   | ------->  | Node @ 0x2000        |
|      |           | value = 20            |
|      |           | next  = NULL          |
+------+           +-----------------------+


*/