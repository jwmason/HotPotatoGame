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

}

QueueOfStrings & QueueOfStrings::operator=(const QueueOfStrings & st)
{
	return *this;
}

QueueOfStrings::~QueueOfStrings() 
{
}


size_t QueueOfStrings::size() const noexcept
{
	return 15; // stub, probably not the right answer.
}


bool QueueOfStrings::isEmpty() const noexcept
{
	return false; // stub, probably not the right answer.
}

void QueueOfStrings::enqueue(const std::string & elem)
{
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
	if (isEmpty())
	{
		throw QueueEmptyException{"Queue is Empty"};
	}
	return front1 -> value;
}

const std::string & QueueOfStrings::front() const
{
	if (isEmpty())
	{
		throw QueueEmptyException{"Queue is Empty"};
	}
	return front1 -> value;
}


// does not return anything.  Just removes. 
void QueueOfStrings::dequeue()
{
}


