
#include "Huffman.h"

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
   
   Node* array[NUM_CHAR];
   for(int i=0; i<=NUM_CHAR; i++){
      array[i] = new Node();
      array[i]->c = i + 97;
      array[i]->frequency = counts[i];
   }
   Heap<Node> h1(array,NUM_CHAR);
   huffmanMaker(h1);
   
   for(int i=0; i<NUM_CHAR; i++){
      
   }
   

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
   return in;
}
/**
 //--------------------------Overloaded output operator <<  ------------------------------------//
 Outputs the letter-to-code translation table with one letter per line (in alphabetical order) followed by a space and the binary encoding from the Huffman algorithm using inorder traversal of the  tree.
 Preconditions: obj1.rootPtr must point to a Huffman tree with child nodes
 Postconditions: Outputs the letter-to-code translation table in alphabetical order
 */
std::ostream& operator<<(std::ostream& out, const Huffman& obj1){
   return out;
}
/**
 //-------------------------- Destructor  for class Huffman Tree ------------------------------------//
 Preconditions:  The rootPtr points to a Huffman Tree containing a number of nodes in each of its left and right Subtree to a memory on the heap
 Postconditions: The rootptr and all subsequent pointers in the tree are deallocated
 */
Huffman:: ~Huffman(){
   
}

/**
 //--------------------------huffmanMaker method ------------------------------------//
 Preconditions:
 Postconditions:
 */
void Huffman::huffmanMaker(Heap<Node>& h1) {
   Node* tempRootNode = nullptr ;
   while(h1.size() > 1){
     Node* first = h1.deleteMin();
     Node* second = h1.deleteMin();
      tempRootNode = new Node;
      tempRootNode->frequency = first->frequency + second->frequency;
      tempRootNode->left = first;
      tempRootNode->right = second;
      h1.insert(tempRootNode);
     //
   }
   
   rootPtr = h1.deleteMin();
   delete tempRootNode;
}

/**
 //--------------------------codeMaker method ------------------------------------//
 Preconditions:
 Postconditions:
 */
std::string Huffman::codeMaker(Node* root, std::string code){
      // Assign 0 to left edge and recur
   if (root->left) {
      code = code + "0";
      codeMaker(root->left, code);
   }
   
      // Assign 1 to right edge and recur
   if (root->right) {
      code = code + "1";
      codeMaker(root->right, code);
   }
   return code;
}

//int Huffman::isLeaf(Node* root)
//{
//   return !(root->left) && !(root->right);
//}
