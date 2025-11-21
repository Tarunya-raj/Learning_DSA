#include  <iostream>
#include <functional>
using namespace std;
class Node {
	private: 
		Node* prev;
		int value;
		Node* next;
public:
	Node(int value = 0,Node* prev=NULL, Node* next= NULL)
	{
		this->next = next;
		this->value = value;		
		this->prev = prev;
	}

	Node* getNextAddress()
	{
		return this->next;
	}
	Node* getPrevAddress()
	{
		return this->prev;
	}
	int getValue()
	{
		return this->value;
	}
	void setPreviousNode(Node * prevPtr)
	{
		this->prev = prevPtr;
	}
	void setNextNode(Node* nextPtr)
	{
		this->next = nextPtr;

	}
	void setValue(int value)
	{
		this->value = value;
	}

};
class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int NodeIndex = -1;
public:
	DoublyLinkedList()
	{
		this->head = NULL;
		this->tail = NULL;

	}
	Node* createNewNode(int value,Node* prev=NULL, Node* next=NULL)
	{
		NodeIndex++;
		return new Node(value, prev, next);


	}
	void insertAtHead(int value)
	{
		head = createNewNode(value, NULL, head);
		if (NodeIndex == 0)
			tail = head;

	}
	void insertAtTail(int value)
	{
		if (tail == NULL && NodeIndex == -1)
			insertAtHead(value);
		else
		{
			Node* newNodeAddress = createNewNode(value, tail, NULL);
			tail->setNextNode(newNodeAddress);			
			tail = newNodeAddress;
		}
	}
	void insertAtIndex(int index, int value)
	{
		if (index > NodeIndex + 1)
			return;
		if (index == 0)
		{
			insertAtHead(value);
			return;

		}
		if (index == NodeIndex + 1)
		{
			insertAtTail(value);
			return;
		}
		Node* temp = head->getNextAddress();
		for (int currentNode = 1; currentNode <= NodeIndex; currentNode++)
		{
			if (currentNode == index)
			{
				Node* newNodeAddress = createNewNode(value, temp->getPrevAddress(), temp);
				temp->getPrevAddress()->setNextNode(newNodeAddress);
				temp->setPreviousNode(newNodeAddress);
				return;
			}
			temp = temp->getNextAddress();

		}

	}
	void display()
	{
		// Reccusive lambda funcion LATER

		std::function<void(Node*)> printNextNodeValue;

		printNextNodeValue = [&](Node* node) {
			if (node == NULL) {
				std::cout << "NULL\n";
				return;
			}

			std::cout << node->getValue() << " -> ";
			printNextNodeValue(node->getNextAddress());
			};

		printNextNodeValue(head);





	}
};
int main()
{
	DoublyLinkedList* dll = new DoublyLinkedList();
	dll->insertAtHead(10);
	dll->insertAtHead(20);
	dll->insertAtTail(30);
	dll->insertAtTail(40);
	dll->insertAtTail(50);
	dll->insertAtTail(60);
	dll->insertAtIndex(5,70);
	dll->insertAtIndex(7,90);
	dll->insertAtIndex(8,91);
	dll->insertAtIndex(9,92);
	dll->display();

}