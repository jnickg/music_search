#include <cstdlib>
#include <ostream>

/* LIST (LINEAR LINKED LIST)
List.h
jnickg (jnickg83@gmail.com)
Created 17 Oct 2013

See description below

THIS IS A TEMPLATE CLASS WHICH REQUIRES AN
IMPORT OF A CPP FILE, AT THE END OF THIS
DEFINITION

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

	Any type T for List needs to have:
	operator= implemented

*/
template <class T> class List
{
public:
	List(void);
	List(char* n);
	~List(void);
	
	// Creates a new node and makes item its data; prepends it to the List
	int add_to_head(T & item);
	// Creates a new node and makes item its data; appends it to the List
	int add_to_end(T & item);
	// Removes the last node in the List
	int remove_last();
	// Removes the first node in the List
	int remove_first();
	// Returns the node at the beginning of the List
	int get_head(T & data);
	// Returns the final node in the List
	int get_last(T & data);
	
	// Returns 1 if it resets its iterator to the head of the List; 0 if head points to NULL
	int it_init();
	// Returns 1 if it advanced to the next node; 0 if the next node pointed to NULL
	int it_adv();
	// Returns the node to which the iterator currently points
	int it_cur(T & data);
	// Returns 1 if item comes after the iterator; 0 if they are equal; -1 if it comes before
	int it_comp(T & item);
	std::ostream& print(std::ostream& out) const;

	// Checks if this list is the one being looked for
	bool isname(char* n);
	// Returns the current node count
	int get_count();
	// Forces a re-count of nodes and returns that; does not reset node count
	int fget_count();

	List& operator=(const & List right);
private:
	node<T>* head; // The head
	node<T>* last; // The last
	node<T>* cur; // The iterator 
	int count; // The number of nodes
	char* name; // The name of the list (used for assignment 3)

	// Used to force a recount of count
	int fget_count(node<T>* strt);
	// Defined in List.cpp ????
	friend std::ostream& operator<<(std::ostream& out, const List* const list);
};

#include "List.cpp"

}} // end namespace

