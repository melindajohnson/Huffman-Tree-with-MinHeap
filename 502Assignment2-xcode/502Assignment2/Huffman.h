

#ifndef Huffman_h
#define Huffman_h
#include <string>
#include <stdio.h>
#include "Heap.h"
static const int NUM_CHAR = 26;  //total numbers of characters
class Huffman
{

public:
   
   /**
    //-------------------------- Parametric constructor for class Huffman ------------------------------------//
    This constructor takes the frequency for each letter from 'a' to 'z' provided in the array counts. It then construct the Huffman tree and compute the code for each character.
    Preconditions: None
    Postconditions: Huffman tree is created using the Heap class. Code for each letter in the counts array is constructed as a string and stored in an array called codeBook
    */
   Huffman(int counts[NUM_CHAR]);
   /**
    //--------------------------getWord method  ------------------------------------//
    This methods takes in a word to encode. All letters in the word are converted to the appropriate bit strings. Non-letters may be ignored.
    Preconditions: obj1.rootPtr must point to a Huffman tree with child nodes
    Postconditions: Outputs a bit string corresponding to the input string and its code translation
    */
   std::string getWord(std::string in);
   /**
    //--------------------------Overloaded output operator <<  ------------------------------------//
    Outputs the letter-to-code translation table with one letter per line (in alphabetical order) followed by a space and the binary encoding from the Huffman algorithm using inorder traversal of the  tree.
    Preconditions: obj1.rootPtr must point to a Huffman tree with child nodes
    Postconditions: Outputs the letter-to-code translation table in alphabetical order
    */
   friend std::ostream& operator<<(std::ostream& out, const Huffman& obj1);
   /**
    //-------------------------- Destructor  for class Huffman Tree ------------------------------------//
    Preconditions:  The rootPtr points to a Huffman Tree containing a number of nodes in each of its left and right Subtree to a memory on the heap
    Postconditions: The rootptr and all subsequent pointers in the tree are deallocated
    */
   virtual ~Huffman();
   
private:
   
   struct Node
   {
      char c = NULL;  //lower case letter in the huffman tree
      unsigned frequency = 0 ;  //count of occurence of a character c
      struct Node* left = nullptr;
      struct Node* right = nullptr;
      bool operator<(const Node &o);
      bool operator>(const Node &o);
      bool operator==(const Node &o);
   };
   
   Node* rootPtr; //pointer to the root Node of the Huffman tree
   int codeBook[NUM_CHAR];
   
      //-------------------------- Private Helper methods  -------------------------------------------
   /**
    //--------------------------Inorder traversal method  ------------------------------------//
    Preconditions: The subTreePtr points to a Huffman containing a number of nodes in each of its left and right Subtree
    Postconditions: Prints the contents of the Huffman Tree i.e the character c and its code contained in each node in alphabetical order
    */
   void inorderTraversal(std::ostream& output, const Node* subTreePtr) const;
   
   /**
    //--------------------------Clear method ------------------------------------//
    Preconditions: The subTreePtr points to a nullPtr  or a Node with left and right subtrees
    Postconditions: The subtree pointers and its left and right subtrees are deallocated and frees the memory
    */
   void clear(Node* subTreePtr);
   
   /**
    //--------------------------huffmanMaker method ------------------------------------//
    Preconditions:
    Postconditions:
    */
   void huffmanMaker(Heap<Node>& h1);
   
   /**
    //--------------------------codeMaker method ------------------------------------//
    Preconditions:
    Postconditions:
    */
   std::string codeMaker(Node* root, std::string code );
   /**
    //--------------------------wordCodeMaker method ------------------------------------//
    Preconditions:
    Postconditions:
    */
   std::string wordCodeMaker(std::string in);
   
   int isLeaf(Node* root);
   
};
#endif
