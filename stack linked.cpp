template <class ItemType>
struct NodeType
{
  ItemType info;
  NodeType<ItemType>* next;
};

template<class ItemType>
StackType<ItemType>::StackType()
{
  xTop = NULL;
}

template <class ItemType>
StackType<ItemType>::~StackType()
{
  MakeEmpty();
}

template<class ItemType>
StackType<ItemType>::operator=( const StackType<ItemType>& cstack )
{	
	NodeType<ItemType>* ptr1 ;
	NodeType<ItemType>* ptr2 ;
	if ( cstack.xTop == NULL )
		xTop = NULL ;
	else			    // allocate memory for first node
	{	
		xTop = new NodeType<ItemType> ;
		xTop->info = cstack.xTop->info ;
		ptr1 = cstack.xTop->next ;
		ptr2 = xTop ;
		while ( ptr1 != NULL )	// deep copy other nodes
		{	ptr2->next = new NodeType<ItemType> ;
			ptr2 = ptr2->next ;
			ptr2->info = ptr1->info ;
			ptr1 = ptr1->next ;
		}
		ptr2->next = NULL ;	
	}
}
template<class ItemType>	     // copy constructor
StackType<ItemType>::StackType( const StackType<ItemType>& cstack )
{	
	NodeType<ItemType>* ptr1 ;
	NodeType<ItemType>* ptr2 ;
	if ( cstack.xTop == NULL )
		xTop = NULL ;
	else			    // allocate memory for first node
	{	
		xTop = new NodeType<ItemType> ;
		xTop->info = cstack.xTop->info ;
		ptr1 = cstack.xTop->next ;
		ptr2 = xTop ;
		while ( ptr1 != NULL )	// deep copy other nodes
		{	ptr2->next = new NodeType<ItemType> ;
			ptr2 = ptr2->next ;
			ptr2->info = ptr1->info ;
			ptr1 = ptr1->next ;
		}
		ptr2->next = NULL ;	
	}
}
template <class ItemType>
void StackType<ItemType>::MakeEmpty() 
{
  NodeType<ItemType>* p;
  
  while (xTop != NULL)
  {
    p = xTop;
    xTop = xTop->next;
    delete p;
  }
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
  NodeType<ItemType>* p;
  p = new NodeType<ItemType>;
  if (p == NULL)
    return true;
  else
  {
    delete p;
    return false;
  }
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
  return xTop == NULL;
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
  NodeType<ItemType>* p = new NodeType<ItemType>;
  p->info = newItem;
  p->next = xTop;
  xTop = p;
}

template<class ItemType>
void StackType<ItemType>::Pop(ItemType& item)
{
  NodeType<ItemType>* p = xTop;
  item = xTop->info;
  xTop = xTop->next;
  delete p;
}

template<class ItemType>
ItemType StackType<ItemType>::Top()
{
  return xTop->info;
}
