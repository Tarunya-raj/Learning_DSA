#include <iostream>
using namespace std;
class Node {
private:
    int value;
    Node* next;
public:
    Node(int value, Node* nodePtr)
    {
        this->value = value;
        this->next = nodePtr;

    }
    Node* getNextNodeAddress()
    {
        return this->next;
    }
    int getValue()
    {
        return this->value;
    }
    void updateNodeAddress(Node* nodePtr)
    {
        this->next = nodePtr;

    }
};
class MyLinkedList {
private:
    Node* head = NULL;
    Node* tail = NULL;
    int nodeIndex = -1;
public:
    MyLinkedList() {

    }


    int get(int index) {
        if (index > nodeIndex)
            return -1;

        Node* temp = head;
        for (int currentIndex = 0; currentIndex <= index; currentIndex++)
        {
            if (temp != NULL)
            {
                if (currentIndex == index)
                    return temp->getValue();
                else
                    temp = temp->getNextNodeAddress();
            }
        }
        return -1;

    }

    void addAtHead(int value) {

        head = new Node(value, head);
        nodeIndex++;
        if (nodeIndex == 0)
            tail = head;


    }

    void addAtTail(int val) {

        if (tail != NULL && nodeIndex != 1)
        {
            tail->updateNodeAddress(new Node(val, NULL));
            tail = tail->getNextNodeAddress();
            nodeIndex += 1;
        }
        else
            addAtHead(val);

    }

    void addAtIndex(int index, int value) {
        if (nodeIndex < index)
        {
            return;
        }
        if (index == 0)
        {
            addAtHead(value);
            return;
        }

        Node* temp = head;
        for (int currentIndex = 0; currentIndex < index; currentIndex++)
        {

            if (temp != NULL && index - 1 == currentIndex)
            {
                temp->updateNodeAddress(new Node(value, temp->getNextNodeAddress()));
                nodeIndex++;
                return;
            }
            temp = temp->getNextNodeAddress();

        }

    }

    void deleteAtIndex(int index) {
        if (index > nodeIndex)
            return;

        Node* temp = head;
        for (int currentIndex = 0; currentIndex <= nodeIndex; currentIndex++)
        {
            if (currentIndex == 0 && currentIndex == index)
            {
                head = temp->getNextNodeAddress();
                delete temp;
                temp = NULL;
                nodeIndex--;
                return;
            }
            else if (currentIndex == index - 1)
            {
                Node* nodeToBeDeleted = temp->getNextNodeAddress();
                temp->updateNodeAddress(nodeToBeDeleted->getNextNodeAddress());
                delete nodeToBeDeleted;
                nodeToBeDeleted = NULL;
                nodeIndex--;
                return;

            }


        }


    }

    void display()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->getValue() << " -> ";
            temp = temp->getNextNodeAddress();

        }
        cout << "END" << endl;

    }


};

int main()
{
    MyLinkedList* myLinkedList = new MyLinkedList();
    //{
    //    // Test case 

    //    myLinkedList->addAtHead(7);
    //    myLinkedList->display();
    //    myLinkedList->addAtHead(2);
    //    myLinkedList->display();
    //    myLinkedList->addAtHead(1);
    //    myLinkedList->display();
    //    myLinkedList->addAtIndex(3, 0);
    //    myLinkedList->display();
    //    myLinkedList->deleteAtIndex(2);
    //    myLinkedList->display();
    //    myLinkedList->addAtHead(6);
    //    myLinkedList->display();
    //    myLinkedList->addAtTail(4);
    //    myLinkedList->display();
    //    myLinkedList->addAtTail(4);
    //    myLinkedList->display();
    //    myLinkedList->addAtTail(4);
    //    myLinkedList->display();
    //    cout << myLinkedList->get(4) << endl;
    //    myLinkedList->addAtHead(4);
    //    myLinkedList->addAtIndex(5, 0);
    //    myLinkedList->addAtHead(6);
    //    cout<<myLinkedList->get(9)<<endl;
    //    myLinkedList->display();
    //}


    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->display();
    myLinkedList->addAtIndex(1, 2);    // linked list becomes 1->2->3
    myLinkedList->display();
    cout << myLinkedList->get(1) << endl;              // return 2
    myLinkedList->deleteAtIndex(1);    // now the linked list is 1->3
    cout << myLinkedList->get(1) << endl;              // return 3
    myLinkedList->display();
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */