#include <iostream>
using namespace std;
class LinkedList{

    private:
        int value;
        LinkedList* next;
    public:
        LinkedList(int value=-1, LinkedList* next=NULL)
        {
            this->next=next;
            this->value=value;
        }
        void insertFirst(int value, LinkedList*(&head))
        {
            head=new LinkedList(value, head);
        }
        void insertLast(int value, LinkedList* (&head))
        {   
            LinkedList *temp=head;
            while(temp!= NULL)
            {
                if(temp->getNextNodeAddress()==NULL)
                {
                    LinkedList *newNode=new LinkedList(value,NULL);
                    temp->updateNextNode(newNode);
                    break;
                }
                temp= temp->getNextNodeAddress();
            }
        }
        LinkedList* getNextNodeAddress(){
            return this->next;

        }
        void updateNextNode(LinkedList *(&nextAdd))
        {
            this->next=nextAdd;

        }
        void display(LinkedList *(&head))        
        {
            LinkedList *temp= head;
            while(temp!=NULL)
            {
                cout<< temp->value<<" -> ";
                temp= temp->getNextNodeAddress();

            }
            cout <<"END";

        }
        void insertAtindex(int value, LinkedList* (&head), int index)
        {
            LinkedList * temp= head;
             for(int i=0 ; i<=index; i++)
                {
                    if(index== 0)
                    {
                        this->insertFirst(value,head);
                        break;
                    }
                    if(temp!= NULL&& i==index-1)
                    {                    
                        LinkedList* newNode= new LinkedList(value, temp->getNextNodeAddress());
                        (*temp).updateNextNode(newNode);
                        break;                        
                           
                    }
                    else if (temp==NULL )
                    {
                        return;
                    }
                    if(index==i)
                    {
                        temp->insertLast(value,temp);
                        break;
                    }
                    temp=temp->getNextNodeAddress();
                }
            

        }


};
int main()
{
    LinkedList *head= NULL;
    //head->insertFirst(10,head);
    head->insertFirst(15,head);
    head->insertFirst(20,head);
    head->insertLast(30,head);
    head->insertLast(40,head);
    head->insertAtindex(122,head,2);
    head->insertAtindex(23,head,4);
    head->insertAtindex(32,head,0);
    head->insertAtindex(43,head,0);
    
    head->insertAtindex(32,head,20);
    //head->insertAtindex(343,head,10);

    (*head).display(head);


}