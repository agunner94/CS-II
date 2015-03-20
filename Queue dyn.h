// Dynamically allocated array version

const int MAX_ITEMS = 5;

template<class ItemType>
class QueType
{
public: 
    QueType();
    // Class constructor.

	QueType(int max);
    // Parameterized class constructor.

	~QueType();
    // Class destructor.

	void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.

	bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)

	bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)

	void Enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the queue.
    // Pre:  Queue is not full.
    // Post: newItem is at the rear of the queue.

	void Dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it in item.
    // Pre:  Queue is not empty.
    // Post: Front element has been removed from the queue.
    //       item is a copy of the removed element.

private:
    int front;
    int rear;
    ItemType* items;
    int maxQue;
};

#include "Queue dyn.cpp"
















