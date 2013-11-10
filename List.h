#include <cstdlib>

/* LIST (LINEAR LINKED LIST)
List.h
jnickg (jnickg83@gmail.com)
Created 17 Oct 2013

See description below

THIS IS A TEMPLATE CLASS WHICH REQUIRES FUNCTION
IMPLEMENTATIONS INSIDE THE .h FILE

*/

namespace jnickg { namespace adt {

#ifndef LLSTRUCT
#define LLSTRUCT
template <class T> struct node
{
	T data;
	node<T>* next;
};
#endif // LLSTRUCT

/*	List (Linear Linked List)
	
	A linear linked list is a series of nodes
	which contain pointers to other nodes. Each
	node contains an object of type T, which allows
	this class to be useful in any situation.

	The size of a List is flexible, and sentinel
	nodes track the head and last elements in the
	list. Add and remove operations can be done
	from either side of the list. Iteration is
	possible through an additional sentinel node,
	which can be manipulated through the it_
	functions.

*/
template <class T> class List
{
public:
	List(char* n)
	{
		head = 	NULL;
		head = NULL;
		last = NULL;
		cur = NULL;
		count = 0;
		strcpy(name, n);
	}

	~List()
	{
		// If there is a head
		if(head)
		{
			node<T>* tmp;
			while(head->next)
			{
				// Set tmp to the 'in-between' node
				tmp=head->next;
				// Set head to point over tmp (unless
				// tmp is the 2nd to last one)
				if(tmp->next)
					head->next = tmp->next;
				// Then cull tmp
				delete tmp;
			}
			delete head;
		}
		
	}

	/*
	Head/Last functions
	*/
	
	// Creates a new node and makes item its data; prepends it to the List
	int add_to_head(T & item)
	{
		// Create new node with T
		node<T>* tmp = new node<T>;
		tmp->data = item;
	
		// If no items in list, it's both last and head
		if (NULL==head)
		{
			last = tmp;
			head = tmp;
			cur = tmp;
			tmp->next = NULL;
		}
		// One-item List needs to disconnect head and last
		else if(NULL==head->next)
		{
			tmp->next = head;
			last = head;
			head = tmp;
			last->next = NULL;
		}
		// Otherwise it's just the new head
		else
		{ 
			tmp->next = head;
			head = tmp;
			if(cur == head)
			{
				cur = tmp;
			}
		}

		count++;
		return 1;
	}



	// Creates a new node and makes item its data; appends it to the List
	int add_to_end(T & item)
	{
		// Create new node with T
		node<T>* tmp = new node<T>;
		tmp->data = item;

		// If no items in list, it's both last and head
		if (NULL==head)
		{
			last = tmp;
			head = tmp;
			cur = tmp;
			tmp->next = NULL;
		}
		// One-item List needs to disconnect head and last
		else if(NULL==head->next)
		{
			head->next = tmp;
			last = tmp;
			last->next = NULL:
		}
		// Otherwise it's just the new last
		else
		{ 
			last->next = tmp;
			last = tmp;
			last->next = NULL;
			if(cur == last)
			{
				cur = last;
			}
		}

		count++;
		return 1;	
	}



	// Removes the last node in the List
	int remove_last()
	{
		// Empty List
		if (head == NULL)
			return 0;
		
		// One-item List
		else if (head->next == NULL)
		{
			delete head;
			head = NULL;
			count--;
			return 1;
		}
		
		// Multi-item List
		else {
			remove_last(head->next);
			return 1;
		}
	}



	// Removes the first node in the List
	int remove_first()
	{
		if (head == NULL)
		{
			return 0;
		}
		else
		{
			node<T>* tmp = head;
			head = head->next;
			delete tmp;
			tmp = NULL;

			count--;
			return 1;
		}
	}

	
	
	// Returns the node at the beginning of the List
	int get_head(T & data)
	{
		if(head)
		{
			data = head->data;
			return 1;
		}
		else return 0;
	}

	
	
	// Returns the final node in the List
	int get_last(T & data)
	{
		if(last)
		{
			data = last->data;
			return 1;
		}
		else return 0;
	}

	/*
	Iteration functions
	*/
	
	
	
	// Returns 1 if it resets its iterator to the head of the List; 0 if head points to NULL
	int it_init()
	{
		if(!(head==NULL))
		{
			cur = head;
			return 1;
		}
		else return 0;
	}
	
	
	
	// Returns 1 if it advanced to the next node; 0 if the next node pointed to NULL
	int it_adv()
	{
		if(cur->next == NULL)
			return 0;
		else 
		{
			cur = cur->next;
			return 1;
		}
	}
	
	
	
	// Returns the node to which the iterator currently points
	int it_cur(T & data)
	{
		data = cur->data;
		return 1;
	}
	
	
	
	// Returns 1 if item comes after the iterator; 0 if they are equal; -1 if it comes before
	int it_comp(T & item)
	{
		T c = cur->data;
		if(c < item) return 1;
		else if(c > item) return -1;
		else return 0;
	}

	/*
	Metadata functions
	*/
	
	// Checks if this list is the one being looked for
	bool isname(char* n)
	{
		if(0==strcmp(name, n) return true;
		else return false;
	}
	
	// Returns the current node count
	int get_count()
	{
		return count;
	}

	
	
	// Forces a re-count of nodes and returns that; does not reset node count
	int fget_count()
	{
		return fget_count(head);
	}

private:
	node<T>* head; // The head
	node<T>* last; // The last
	node<T>* cur; // The iterator 
	int count; // The number of nodes
	char* name; // The name of the list (used for assignment 3)
	
	
	
	// Used to force a recount of count
	int fget_count(node<T>* strt)
	{
		if(NULL == strt) return 0;
		return fget_count(strt->next) +1;
	}
};

//#include "List.cpp"

}} // end namespace
