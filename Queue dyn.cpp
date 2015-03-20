template<class ItemType>
QueType<ItemType>::QueType()         // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been 
//       dynamically allocated.
{
    maxQue = MAX_ITEMS + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
}

template<class ItemType>
QueType<ItemType>::QueType(int max)	
// Paramaterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been 
//       dynamically allocated.
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new ItemType[maxQue];
}

template<class ItemType>
QueType<ItemType>::~QueType()	// Class destructor
{
    delete [] items;
}

template<class ItemType>
void QueType<ItemType>::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    front = maxQue - 1;
    rear = maxQue - 1;
}

template<class ItemType>
bool QueType<ItemType>::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return (rear == front);
}

template<class ItemType>
bool QueType<ItemType>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return ((rear + 1) % maxQue == front);
}

template<class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
// Post: newItem is at the rear of the queue.
{
    rear = (rear + 1) % maxQue;
    items[rear] = newItem;
}

template<class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
// Post: The front of the queue has been removed and a copy returned in item.
{
    front = (front + 1) % maxQue;
    item = items[front];
}
