#include "QueueOfStrings.hpp"

// enqueue, front, then add stuff to constructor along way, destruct along the way to allocate memory,
// copy/assignment operator last

QueueOfStrings::QueueOfStrings() : front1{nullptr}
{
}



// Be sure to do a "deep copy" -- if I 
// make a copy and modify one, it should not affect the other. 
QueueOfStrings::QueueOfStrings(const QueueOfStrings & st)
{
	// If orginal is empty, nothing to copy
	if (st.front1 == nullptr)
	{
		return;
	}
	// Initialize original Node and the new copy Node. Also intialize the first string value
	Node * org = st.front1;	
	Node * copy = new Node(org -> value);
	// Set the copy as the front
	front1 = copy;
	// Loop through each node after the first string value and copy it
	while (org -> next != nullptr)
	{
		org = org -> next;
		enqueue(org -> value);
	}
}

QueueOfStrings & QueueOfStrings::operator=(const QueueOfStrings & st)
{
	// Check if the objects are equal. If not, remove all elements and deep copy
	if (this != & st)
	{
		// Loop through all Nodes and delete them
		while (!isEmpty())
		{
			dequeue();
		}

		// Deep copy
		Node * tmp = st.front1;
		while (tmp != nullptr)
		{
			enqueue(tmp -> value);
			tmp = tmp -> next;
		}
	}
	return *this;
}

QueueOfStrings::~QueueOfStrings() 
{
	// Goes through each Node in QueueofStrings object and deletes it
	while (front1 != nullptr)
	{
		Node * tmp = front1;
		front1 = front1->next;
		delete tmp;
	}
}


size_t QueueOfStrings::size() const noexcept
{
	// Initialize size counter and Node pointer holder
	size_t counter = 0;
	Node * tmp = front1;
	// Loop through every Node and count it
	while (tmp != nullptr)
	{
		counter ++;
		tmp = tmp -> next;
	}
	return counter;
}


bool QueueOfStrings::isEmpty() const noexcept
{
	// If there is no Nodes, return true. Else return false.
	if (front1 == nullptr)
	{
		return true;
	}
	return false;
}

void QueueOfStrings::enqueue(const std::string & elem)
{
	// Check if Node pointer is null. If so, create a new Node with elem. Else, Add the new Node.
	if (nullptr == front1)
	{
		Node * tmp{front1};
		front1 = new Node(elem);
		front1 -> next = tmp;
		return;
	}
	Node * tmp{front1};
	while (tmp -> next != nullptr)
	{
		tmp = tmp -> next;
	}
	tmp -> next = new Node(elem);
}


std::string & QueueOfStrings::front()
{
	// Check if QueueOfStrings is empty. If so, throw exception. If not, return front value
	if (isEmpty())
	{
		throw QueueEmptyException{"Queue is Empty"};
	}
	return front1 -> value;
}

const std::string & QueueOfStrings::front() const
{
	// Check if QueueOfStrings is empty. If so, throw exception. If not, return front value
	if (isEmpty())
	{
		throw QueueEmptyException{"Queue is Empty"};
	}
	return front1 -> value;
}


// does not return anything.  Just removes. 
void QueueOfStrings::dequeue()
{
	// First check if the Queue is empty
	if (isEmpty())
	{
		throw QueueEmptyException("Queue is Empty.");
	}
	// Move the Node pointer to the next one and delete the current Node
	Node * tmp = front1;
	front1 = front1 -> next;
	delete tmp;
}


