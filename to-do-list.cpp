#include <iostream>
#include <string>
using namespace std;

class Task
{
private:
	int number;
	string objective;
	bool status;
public:
	Task()
	{
		number = 0;
		objective = ' ';
		status = false;
	}
	Task(int ID)
	{
		number = ID;
		cout << "Enter Task: ";
		getline(cin , objective);
		status = false;
	}
	Task(Task& t)
	{
		number = t.number;
		objective = t.objective;
		status = t.status;
	}
	void UpdateStatus()
	{
		status = true;
	}
	void UpdateNumber(int id)
	{
		number = id;
	}
	int GetNumber()
	{
		return number;
	}
	friend ostream& operator << (ostream& out, Task& t)
	{
		out << t.number << ". " << t.objective << "\t\t";
		if (t.status)
		{
			out << "Completed";
		}
		else
		{
			out << "Pending";
		}
		return out;
	}
	bool operator == (int id)
	{
		if (number == id)
		{
			return true;
		}
		return false;
	}
};

class List
{
private:
	class Node
	{
	public:
		Task data;
		Node* next;
		Node(Task& t)
		{
			data = t;
			next = NULL;
		}
	};
	Node* head;
	Node* tail;
	int size;
public:
	List()
	{
		head = tail = NULL;
		size = 0;
	}
	Task* InputTask()
	{
		Task* taskptr = new Task(++size);
		return taskptr;
	}
	void AddTask()
	{
		Task* taskptr = InputTask();
		Node* newNode = new Node(*taskptr);
		if (tail == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}
	void ViewTasks()
	{
		Node* ptr = head;
		while (ptr != NULL)
		{
			cout << ptr->data << endl;
			ptr = ptr->next;
		}
	}
	Task* Search(int id)
	{
		Node* ptr = head;
		Task* taskptr = NULL;
		while (ptr != NULL)
		{
			if (ptr->data == id)
			{
				taskptr = &(ptr->data);
				break;
			}
			ptr = ptr->next;
		}
		return taskptr;
	}
	void MarkTaskAsComplete(int id)
	{
		Task* ptr = Search(id);
		if (ptr != 0)
		{
			ptr->UpdateStatus();
		}
	}
	void RemoveTask(int id)
	{
		Node* ptr = head;
		Node* prevptr = NULL;
		while (ptr != NULL)
		{
			if (ptr->data == id)
			{
				if (ptr == head)
				{
					DeleteAtStart();
					UpdateList(head);
				}
				else if (ptr == tail)
				{
					prevptr->next = NULL;
					delete ptr;
					tail = prevptr;
					UpdateList(tail);
				}
				else
				{
					prevptr->next = ptr->next;
					ptr->next = NULL;
					delete ptr;
					UpdateList(prevptr->next);
				}
				size--;
				break;
			}
			else
			{
				prevptr = ptr;
				ptr = ptr->next;
			}
		}
	}
	void DeleteAtStart()
	{
		if (head != NULL)
		{
			if (head == tail)
			{
				delete head;
				head = tail = NULL;
			}
			else
			{
				Node* ptr = head->next;
				head->next = NULL;
				delete head;
				head = ptr;
			}
		}
	}
	void DeleteAll()
	{
		while (head != NULL)
		{
			DeleteAtStart();
		}
		size = 0;
	}
	void UpdateList(Node* n)
	{
		int newnumber = n->data.GetNumber() - 1;
		while (n != NULL)
		{
			n->data.UpdateNumber(newnumber++);
			n = n->next;
		}

	}
	~List()
	{
		DeleteAll();
	}
};

int main()
{
	List ToDoList;
	ToDoList.AddTask();
	ToDoList.AddTask();
	ToDoList.AddTask();
	ToDoList.AddTask();
	ToDoList.AddTask();
	ToDoList.ViewTasks();
	ToDoList.MarkTaskAsComplete(3);
	ToDoList.RemoveTask(2);
	ToDoList.RemoveTask(5);
	ToDoList.AddTask();
	ToDoList.MarkTaskAsComplete(4);
	ToDoList.ViewTasks();
	system("pause");
	return 0;
}
