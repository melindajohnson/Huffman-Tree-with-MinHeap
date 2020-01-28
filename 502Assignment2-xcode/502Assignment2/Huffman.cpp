
#include "Huffman.h"


/**
 //-------------------------- Parametric constructor for class Huffman ------------------------------------//
 This constructor takes the frequency for each letter from 'a' to 'z' provided in the array counts. It then construct the Huffman tree and compute the code for each character.
 Preconditions: None
 Postconditions: Huffman tree is created using the Heap class. Code for each letter in the counts array is constructed as a string and stored in an array called codeBook
 */
Huffman::Huffman(int counts[NUM_CHAR]){
   
   Node* array[NUM_CHAR];
   
   for(int i=0; i<NUM_CHAR; i++){
      array[i]->c = i + '0';
      array[i]->frequency = counts[i];
      
   }
   Heap<Node> h1(array,NUM_CHAR);
   huffmanMaker(h1);
      //It should then construct the code for each letter by traversing the tree and storing a string for each letter (always assign 0 to the lower weight branch and 1 to the higher weight branch).
      //The codebook is an array in the Huffman private data.
   
}
/**
 //--------------------------getWord method  ------------------------------------//
 This methods takes in a word to encode. All letters in the word are converted to the appropriate bit strings. Non-letters may be ignored.
 Preconditions: obj1.rootPtr must point to a Huffman tree with child nodes
 Postconditions: Outputs a bit string corresponding to the input string and its code translation
 */
std::string Huffman::getWord(std::string in){
   
}
/**
 //--------------------------Overloaded output operator <<  ------------------------------------//
 Outputs the letter-to-code translation table with one letter per line (in alphabetical order) followed by a space and the binary encoding from the Huffman algorithm using inorder traversal of the  tree.
 Preconditions: obj1.rootPtr must point to a Huffman tree with child nodes
 Postconditions: Outputs the letter-to-code translation table in alphabetical order
 */
std::ostream& operator<<(std::ostream& out, const Huffman& obj1){
   
}
/**
 //-------------------------- Destructor  for class Huffman Tree ------------------------------------//
 Preconditions:  The rootPtr points to a Huffman Tree containing a number of nodes in each of its left and right Subtree to a memory on the heap
 Postconditions: The rootptr and all subsequent pointers in the tree are deallocated
 */
Huffman:: ~Huffman(){
   
}

void Huffman::huffmanMaker(Heap<Node>& h1) {
   while(h1.size() > 1){
     const Node* first = h1.findMin();
      h1.deleteMin();
     const Node* second = h1.findMin();
      h1.deleteMin();
     Node* tempRootNode = new Node;
      tempRootNode->left = const_cast<Node*>(first);
      tempRootNode->right = const_cast<Node*>(second);
      h1.insert(tempRootNode);
      delete tempRootNode;
   }
   rootPtr = const_cast<Node*>(h1.findMin());
}
