#include <iostream>
#include <string>
template <typename T>
class LinkedList
{
	private:
		//template <typename ST>
		struct Node{
			T data;
			struct Node* next;
			private:
				Node(T value):data(value),next(nullptr){}
			public:
				static struct Node* createNode(T value)
				{
					return new Node(value);
				}
		};
		struct Node* head;
	public:
		LinkedList():head(nullptr){}
		void insertFirst(T value)
		{
			if(head==nullptr)
			{
				head=Node::createNode(value);
			}
			else
			{
				struct Node* temp=head;
				head =Node::createNode(value);
				head->next=temp;
			}
		}
		void insertLast(T value)
		{
			if(head==nullptr)
			{
				head=Node::createNode(value);
				return;
			}
			struct Node*  currentNode=head;
			while(currentNode->next!=nullptr)
			{
				currentNode= currentNode->next;
			}
			currentNode->next=Node::createNode(value);
		}
		void insertAtPos(T value, int pos)
		{
			if(pos<0 || pos>count()+1)
				throw std::runtime_error("Enter a valid position to insert node\n");
			if(pos>0)
			{
				Node *previousNode=nullptr, *currentNode=head;
				while((pos--)>1)
				{
					//Node *nextNode= currentNode->next;
					previousNode=currentNode;
					currentNode=currentNode->next;
				}

				Node *newNode= Node::createNode(value);
				newNode->next=currentNode;
				if(previousNode!= nullptr)
					previousNode->next=newNode;
				else
					head= newNode;
			}
		}

		void deleteFirst()
		{
			if(head==nullptr)
				return;
			if(head->next ==nullptr)
			{
				delete head;
				head =nullptr;
				return;

			}
			else
			{	struct Node* temp=head;
				head= head->next;
				delete temp;
			}
			return;
		}

		void deleteEnd()
		{
			if(head==nullptr)
				return;
			struct Node *previousNode=nullptr,*currentNode=head;
			while(currentNode->next!=nullptr)
			{
				previousNode=currentNode;
				currentNode=currentNode->next;
			}
			previousNode->next=nullptr;
			delete currentNode;
		}
		void display()
		{
			struct Node* currentNode=head;
			while(currentNode!=nullptr)
			{

				std::cout<<currentNode->data<<"\t";
				currentNode=currentNode->next;
			}
		}
		void reverse()//Node* head)
		{
			Node* previousAddress=nullptr;
			while(head->next!= nullptr)
			{
				Node *nextAddress=nullptr;
				nextAddress= head->next;
				head->next=previousAddress;
				previousAddress=head;
				head=nextAddress;
			}
			if(head->next ==nullptr&& previousAddress != nullptr)
			{
				head->next=previousAddress;
			}
		}
		void printReverse(Node* currentNode)
		{
			if(currentNode->next!= nullptr)
				printReverse(currentNode->next);
			std::cout<<currentNode->data<<"\t";
		}
		Node* getHead()
		{
			return head;
		
		}
		int count()
		{
			Node *currentNode=head;
			int count=0;
			while(currentNode!= nullptr)
			{
				count++;
				currentNode=currentNode->next;
			}
			return count;
		}


};
int main()
{
	LinkedList<std::string> ll;
	ll.insertAtPos("PostNode" , 1);
	ll.insertFirst("First");

	ll.insertFirst("Second");
	ll.insertFirst("Third");
	ll.insertFirst("Fourth");
	ll.insertLast("Last");
	
	ll.deleteFirst();
	ll.insertLast("Last2");
	ll.insertLast("Last3");
	ll.insertLast("Last4");
	ll.deleteEnd();
	std::cout<<"\n Straight: ";
	ll.display();
	//ll.display();
	std::cout<<"\n Reversed: ";
	ll.reverse();
	ll.insertAtPos("pos3Node", 3);
	ll.display();
	std::cout<<"\n";
	ll.printReverse(ll.getHead());
	return 0;
}

