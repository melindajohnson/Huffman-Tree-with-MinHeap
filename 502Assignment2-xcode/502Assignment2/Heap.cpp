
#include "Heap.h"
/**
 //-------------------------- Default constructor for class Heap ------------------------------------//
 Preconditions: None
 Postconditions: The rootPtr of the Searchtree is initialized to a nullptr
 */
template <typename Comparable>
Heap<Comparable>::Heap(){
   this->numElements = 0; // Heap is initially empty
  // this->items = ; // Empty vector
}

/**
 //-------------------------- Copy constructor for class Heap ------------------------------------//
 Preconditions: The rootPtr points to a SearchTree containing a number of nodes in each of its left and right Subtree
 Postconditions: The rootPtr point to a new node, but the node contains the given data item and pointers to copies of the given subtrees.
 */
template <typename Comparable>
Heap<Comparable>::Heap(const Heap& tree){
   items = tree.items;
   numElements = tree.numElements;
}

/**
 //-------------------------- Destructor  for class Heap ------------------------------------//
 Preconditions:  The rootPtr points to a SearchTree containing a number of nodes in each of its left and right Subtree to a memory on the heap
 Postconditions: deallocate the elements stored in the Heap class
 */
template <typename Comparable>
Heap<Comparable>::~Heap(){
   
}

/**
 //-------------------------- Overloaded assignment operator =  ------------------------------------//
 Preconditions:
 Postconditions:
 @returnetw
 */
template <typename Comparable>
Heap<Comparable> Heap<Comparable>::operator=(const Heap<Comparable>& right){
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
 Preconditions:
 Postconditions:
 */
template <typename Comparable>
Heap<Comparable>::Heap(Comparable** array, int count){
   for(int i=0; i<array->size(); i++){
      insert(array[i]);
   }
   heapify();
}

 // These methods should assume that the Comparables being stored have their own appropriate constructors/operators/destructor defined. However, to simplify matters, you should only copy/deallocate Nodes that have pointers in the Heap (not their children). We will not use the Heap in such a way that a partial Huffman tree is copied or deallocated while in the Heap. Remember that the first element in the heap is a dummy/duplicate to simplify the implementation of various methods. This has implications for the above operations.
