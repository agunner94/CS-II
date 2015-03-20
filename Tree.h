#include <fstream>

template<class ItemType>
struct TreeNode;

template<class ItemType>
class TreeType
{
public: 	
  TreeType();                 // constructor
  TreeType(const TreeType<ItemType>& originalTree); // copy constructor
  ~TreeType();             	// destructor

  void MakeEmpty();
  // Function:  Sets tree to an empty state.
  // Post: tree is empty.

  bool IsEmpty() const;          
  // Function: Determines whether the tree is empty.
  // Pre:  tree has been initialized.
  // Post: Function value = (tree is empty)

  bool IsFull() const;          
  // Function: Determines whether the tree is full.
  // Pre:  tree has been initialized.
  // Post: Function value = (tree is full)

  int NumberOfNodes() const;
  // Function: Counts the number of nodes in the tree.
  // Pre:  tree has been initialized.
  // Post: Function value = (number of nodes)

  void RetrieveItem(ItemType& item, bool& found);
  // Retrieves tree element whose key matches item's key (if present).
  // Pre:  Key member of item is initialized.
  // Post: If there is an element someItem whose key matches 
  //       item's key, then found = true and item is a copy 
  //       of someItem; otherwise found = false and item is unchanged. 
  //       Tree is unchanged.

  void InsertItem(ItemType item);
  // Adds item to tree.
  // Pre:  Tree is not full.
  //       item is not in tree. 
  // Post: item is in tree.

  void DeleteItem(ItemType item);
  // Deletes the element whose key matches item's key.
  // Pre:  Key member of item is initialized.
  //       One and only one element in tree has a key matching
  //       item's key.
  // Post: No element in tree has a key matching item's key.

  void PrintTree(std::ostream& out) const;
  // Function: Prints elements of the tree in order (e.g., from smallest to largest).
  // Pre:  tree has been initialized.
  // Post: tree is unchanged.

  void operator= (const TreeType<ItemType>& originalTree);
  // overloaded assignment

private:
  TreeNode<ItemType>* root;
};

template<class ItemType>
struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

#include "tree.cpp"
