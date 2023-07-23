using namespace std;
#include <iostream>
class Queue
{
private:
	struct node
	{
		int item;
		node* next;
	};
	node* rear;
	node* head;
	int count;
public:
	Queue()
	{
		rear = NULL;
		head = NULL;
		count = 0;
	}
	bool isEmpty()
	{
		return count == 0;
	}
	void enQueue(int Element)
	{
		if (isEmpty())
		{
			head = new node;
			head->item = Element;
			head->next = NULL;
			rear = head;
			count++;
		}
		else
		{
			node* newNode = new node;
			newNode->item = Element;
			newNode->next = NULL;
			rear->next = newNode;
			rear = newNode;
			count++;
		}
	}
	void deQueue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty...\n";
		}
		else if (count == 1)
		{
			head = NULL;
			rear = NULL;
		}
		else
		{
			node* temp = new node;
			temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
			count--;
		}
	}
	int getHead()
	{
		if (isEmpty())cout << "Queue is Empty...\n";
		else
		return head->item;
	}
	int getRear()
	{
		if (isEmpty())cout << "Queue is Empty...\n";
		else
		return rear->item;
	}
	void CQueue()
	{
		if (isEmpty()) cout << "Queue is Empty...\n";
		else 
		{
			node* tmp;
			while (head != NULL)
			{
				tmp = head;
				head = head->next;
				delete tmp;
			}
			rear = NULL;
			count = 0;
		}
	}
	int search(int num)
	{
		node* temp;
		int index = 0 , reg = 0;
		if (isEmpty()) cout << "Queue is Empty...\n";
		else
		{
			temp = head;
			while (temp != NULL)
			{
				if (temp->item == num)
				{
					index++;
					reg = index;
					return index;
				}
				else
				{
					temp = temp->next;
					index++;
				}
				
			}
			if (reg == 0) return 0;
		}
	}
	void Display()
	{
		node* sec = head;
		while (sec != NULL)
		{
			cout << "| " << sec->item << " |\n";
			sec = sec->next;
		}
	}
};
int main()
{
	Queue q;
	q.enQueue(100);
	q.enQueue(200);
	q.enQueue(300);
	q.enQueue(400);
	q.enQueue(500);
	//q.deQueue();
	//q.CQueue();
	q.Display();
	return 0;
}