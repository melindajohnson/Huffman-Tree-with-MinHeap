   //--------------------------------------------------------------------
   // HEAP.H
   // Declaration and definition of the template Heap class
   // Author: Olson (borrowing from a previous edition of Carrano/Henry)
   //--------------------------------------------------------------------
   // Heap class:
   //   Implements a priority queue with the following methods:
   //      insert, deleteMin, findMin, heapify
   //  The heap is stored in a vector (see the CSS 502 lecture notes)
   //  Assumptions:
   //    Can only store data for which operator< exists
   //    (hence the Comparable type variable)
   //--------------------------------------------------------------------

#include <vector>
using namespace std;

template <typename Comparable>
class Heap {
public:
     
   /**
    //-------------------------- Default constructor for class Heap ------------------------------------//
    Preconditions: None
    Postconditions: The rootPtr of the Searchtree is initialized to a nullptr
    */
   Heap(){
      this->numElements = 0; // Heap is initially empty
                             // this->items = ; // Empty vector
   }
   
   /**
    //-------------------------- Copy constructor for class Heap ------------------------------------//
    Preconditions:
    Postconditions:
    */
   Heap(const Heap& tree){
      items = tree.items;
      numElements = tree.numElements;
   }
   
   /**
    //-------------------------- Destructor  for class Heap ------------------------------------//
    Preconditions:  
    Postconditions: deallocate the elements stored in the Heap class
    */
   virtual ~Heap(){
      items.clear();
      numElements = 0;
   }  //You are allowed to assume that it only has single nodes stored in it (don't have to recursively deallocate trees of nodes).
   
   /**
    //-------------------------- Overloaded assignment operator =  ------------------------------------//
    Preconditions: The right.rootPtr points to a SearchTree containing a number of nodes
    Postconditions: *this is assigned the same values in the tree as right in a different memory location
    @return SearchTree which is a deep copy of the object right
    */
   Heap operator= (const Heap& right){
      if (this != &right) {
         items.clear();
         items = right.items;
         numElements = right.numElements;
      }
      return *this;
   }
   
   /**
    //-------------------------- Parametric constructor for class Heap ------------------------------------//
    Constructor that takes an array of Comparables and constructs a Heap using the (supplied) heapify method.
    Preconditions: The rootPtr points to a SearchTree containing a number of nodes in each of its left and right Subtree
    Postconditions: The rootPtr point to a new node, but the node contains the given data item and pointers to copies of the given subtrees.
    */
   Heap(Comparable** array, int count){
      for(int i=0; i< count; i++){
         insert(array[i]);
      }
      
      heapify();
   }//
  // These methods should assume that the Comparables being stored have their own appropriate constructors/operators/destructor defined. However, to simplify matters, you should only copy/deallocate Nodes that have pointers in the Heap (not their children). We will not use the Heap in such a way that a partial Huffman tree is copied or deallocated while in the Heap. Remember that the first element in the heap is a dummy/duplicate to simplify the implementation of various methods. This has implications for the above operations.
   
   
   /**
    //--------------------------insert - adds a single item to the heap  ------------------------------------//
    Preconditions: the initial heap has sufficient memory allocated and satisfies the heap order property
    Postconditions: inserts the item into the queue, such that a new heap is created containing the union of the elements
    */
   void insert(Comparable *c) {
      if (c == NULL) return;
      
         // Add item in position 0 (dummy position) to prevent percolating up from root
      if (items.size() < 1)
         items.push_back(c);
      else
         items[0] = c;
      
         // Ensure we have enough space
      numElements++;
      while ((int) items.size() <= numElements)
         items.push_back(nullptr);
      
         // Percolate up
      int position = numElements;
      while (*c < *items[position / 2]) {
         items[position] = items[position / 2];
         position = position / 2;
      }
      items[position] = c;
   }
   
   /**
    //--------------------------findMin - returns a const pointer to the minimum value in the heap  ------------------------------------//
    Preconditions: items[0] exists if numElements is larger than zero
    Postconditions:Returns nullptr if the heap is empty, otherwise returns  the item at the root of the heap (presumably the minimum priority).
    */
   const Comparable * findMin() const {
      if (numElements <= 0) return nullptr;
      else return items[1];
   }
   
   /**
    //--------------------------deleteMin - delete the minimum and return a pointer to it ------------------------------------//
    Preconditions:items[0] exists if numElements is larger than zero
    Postconditions: Returns nullptr if the heap is empty, otherwise returns  the item at the root of the heap (presumably the minimum priority). That element is deleted from the heap and the heap order property is  restored.
    */
   Comparable * deleteMin() {
      if (numElements == 0) return nullptr;
      
         // Give memory back to user
      Comparable *toReturn = items[1];
      items[1] = items[numElements];
      numElements--;
      
      percolateDown(1);
      return toReturn;
   }
   
   /**
    //--------------------------heapify - modifies any set of data into a heap ------------------------------------//
    Preconditions:items has been allocated space for numElements pointers
    Postconditions:The items stored form a heap
    */
   void heapify() {
      for (int i = numElements / 2; i > 0; i--)
         percolateDown(i);
   }
   
     
   /**
    //-------------------------size ------------------------------------//
    Preconditions: none
    Postconditions:returns the size of the heap
    */
   int size() const {
      return numElements;
   }
   
   /**
    //-------------------------isEmpty ------------------------------------//
    Preconditions: none
    Postconditions: returns whether the heap is empty (zero elements)
    */
   int isEmpty() const {
      return numElements == 0;
   }
   
private:
   
   /**
    //-------------------------percolateDown - used to restore the heap order property after deleteMin ------------------------------------//
    Preconditions: Both subtrees of the root are heaps
    Postconditions: Restores the heap order property to shifting the root down until it reaches an appropriate node
    */
   void percolateDown(int position) {
      int child = position * 2;
      if (child > numElements) return;
      if (child != numElements && *items[child] > *items[child + 1]) child++;
      if (*items[child] < *items[position]) {
         swap(items[child], items[position]);
         percolateDown(child);
      }
   }
   
   int numElements = 0;         // Number of elements in the heap
   vector <Comparable *> items;   // The elements in the heap
};


