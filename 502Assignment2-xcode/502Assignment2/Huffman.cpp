
#include "Huffman.h"
#include <iostream>
#include <sstream>

bool Huffman::Node::operator<(const Node &o){
   return (frequency < o.frequency);
}
bool Huffman::Node::operator>(const Node &o){
   return (frequency > o.frequency);
}
bool Huffman::Node::operator==(const Node &o){
   return (frequency == o.frequency);
}

/**
 //-------------------------- Parametric constructor for class Huffman ------------------------------------//
 This constructor takes the frequency for each letter from 'a' to 'z' provided in the array counts. It then construct the Huffman tree and compute the code for each character.
 Preconditions: None
 Postconditions: Huffman tree is created using the Heap class. Code for each letter in the counts array is constructed as a string and stored in an array called codeBook
 */
Huffman::Huffman(int counts[NUM_CHAR]){
   
   Node** array = new Node*[NUM_CHAR];
   for(int i=0; i< NUM_CHAR; i++){
      Node* currentNode = new Node();
      currentNode->c = i + 97;
      currentNode->frequency = counts[i];
      array[i] = currentNode;
      // delete currentNode;
   }
 
   Heap<Node> h1(array,NUM_CHAR);
   huffmanMaker(h1);
   
   std::string s = "";
   codeMaker(rootPtr, s);
}
/**
 //--------------------------getWord method  ------------------------------------//
 This methods takes in a word to encode. All letters in the word are converted to the appropriate bit strings. Non-letters may be ignored.
 Preconditions: obj1.rootPtr must point to a Huffman tree with child nodes and the codeBook must be created with codes for each char
 Postconditions: Outputs a bit string corresponding to the input string and its code translation
 */
std::string Huffman::getWord(std::string in){
      //Create an array of integers to hold the index value corresponding to the char in the string
   int indexValues[in.length()];
   int i=0;
      //Store the index value corresponding to the char in the string in the array indexValues
   for (char const &c: in) {
      indexValues[i] = c-97;
      i++;
   }
   std::string code; //string to hold the code of the input string
   //Loop through indexValues array and concatenate its corresponding code to the string code
   for(int j=0; j<in.length(); j++){
      code = code + codeBook[indexValues[j]];
   }
   return code;
}
/**
 //--------------------------Overloaded output operator <<  ------------------------------------//
 Outputs the letter-to-code translation table with one letter per line (in alphabetical order) followed by a space and the binary encoding from the Huffman algorithm using inorder traversal of the  tree.
 Preconditions: obj1.rootPtr must point to a Huffman tree with child nodes
 Postconditions: Outputs the letter-to-code translation table in alphabetical order
 */
std::ostream& operator<<(std::ostream& out, const Huffman& obj1){
   for(int i=0; i<NUM_CHAR; i++){
      char c = i + 97;
      out << c << ": " << obj1.codeBook[i] << "\n";
   }
   return out;
}
/**
 //-------------------------- Destructor  for class Huffman Tree ------------------------------------//
 Preconditions:  The rootPtr points to a Huffman Tree containing a number of nodes in each of its left and right Subtree to a memory on the heap
 Postconditions: The rootptr and all subsequent pointers in the tree are deallocated
 */
Huffman:: ~Huffman(){
   clear(rootPtr);
}

/**
 //--------------------------huffmanMaker method ------------------------------------//
 Preconditions:
 Postconditions:
 */
void Huffman::huffmanMaker(Heap<Node>& h1) {
   while(h1.size() > 1){
      Node* first = h1.deleteMin();
      Node* second = h1.deleteMin();
      Node* tempRootNode = new Node;
      tempRootNode->frequency = first->frequency + second->frequency;
      tempRootNode->left = first;
      tempRootNode->right = second;
      h1.insert(tempRootNode);
      // delete tempRootNode;
   }
   
   rootPtr = h1.deleteMin();
}

/**
 //--------------------------codeMaker method ------------------------------------//
 Preconditions:
 Postconditions:
 */
void Huffman::codeMaker(Node* root, string code){
   
   if(root == nullptr){
      return;
   }
   if(root->left!=nullptr) codeMaker(root->left, code + "0");
   if(root->right!=nullptr) codeMaker(root->right, code + "1");
   else{
      int i = root->c - 97;
      codeBook[i] = code;
   }
}

/**
 //--------------------------Clear method ------------------------------------//
 Preconditions: The subTreePtr points to a nullPtr  or a Node with left and right subtrees
 Postconditions: The subtree pointers and its left and right subtrees are deallocated and frees the memory
 **/
void Huffman::clear(Node* subTreePtr) {
   if (subTreePtr != nullptr)
   {
      clear(subTreePtr->left); //recusively call left subtree
      
      clear(subTreePtr->right); //recusrively calls the right subtree
      
     // delete subTreePtr->c;
      delete subTreePtr;
     // subTreePtr = nullptr;
      
   }
}
