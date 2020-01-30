
/*
----------------------------------------------------------------------------------------------------------------
HUFFMAN.cpp
Declaration of the Huffman class
 Author: Melinda Stannah Stanley Jothiraj
Student number- 1978413
--------------------------------------------------------------------
Huffman class : Implements a Huffman tree with the help of the Heap class
A Node rootPtr that points to the root of the tree
A string array codeBook that holds the code of all the alphabets

Struct Node : The Node holds a character c and a unsigned int frequency
Node left points to the left child and
Node right points to the right child

Includes additional features :
-- allows output of the alphabets and its code using operator << overloading method
-- The class contains the HuffmanMaker method to help build the tree
-- The class contains the codeMaker method to build the codebook
-- The class contains a copy constructor which creates a deep copy of the tree

Assumptions :
--RootPtr is initialized to nullPtr and frequnecy of all Nodes are initialized to zero
--The Huffman tree can only be constructed using the Heap class and its methods.

------------------------------------------------------------------------------------------------------------------
*/

#include "Huffman.h"

/**
 //-------------------------- Overloaded lesser than operator <------------------------------------//
 Determines if the Nodes frequency on the left hand side is lesser than the Node frequency on right hand side
 Preconditions:frequency and 0.frequency are two unsigned int belonging to two Node this and o
 Postconditions: boolean true if the left hand side frequency is lesser than the frequency on right hand side
 @return boolean true if left is smaller than right
 */
bool Huffman::Node::operator<(const Node& o) {
	return (frequency < o.frequency);
}
/**
//-------------------------- Overloaded greater than operator >------------------------------------//
Determines if the Nodes frequency on the left hand side is greater than the Node frequency on right hand side
Preconditions : frequency and 0.frequency are two unsigned int belonging to two Node this and o
Postconditions : boolean true if the left hand side frequency is greater than the frequency on right hand side
@return boolean true if left is greater than right
**/
bool Huffman::Node::operator>(const Node& o) {
	return (frequency > o.frequency);
}
/**
//-------------------------- Overloaded equal to operator == ------------------------------------//
Determines if the Nodes frequency on the left hand side is equal to than the Node frequency on right hand side
Preconditions : frequency and 0.frequency are two unsigned int belonging to two Node this and o
Postconditions : boolean true if the left hand side frequency is equal to than the frequency on right hand side
@return boolean true if left is greater than right
**/
bool Huffman::Node::operator==(const Node& o) {
	return (frequency == o.frequency);
}

/**
//-------------------------- Default constructor for class Huffman ------------------------------------//
Preconditions: None
Postconditions : The rootPtr of the Huffman Tree is initialized to a nullptr
**/
Huffman::Huffman() {
	rootPtr = nullptr;
}
/**
/**
//-------------------------- Copy constructor for class Huffman ------------------------------------//
Preconditions: The rootPtr points to an empty Huffman tree or one containing a number of nodes in each of its left and right Subtree
 Postconditions: The rootPtr point to a copy of the Huffman tree containing new copies of its left and right subtree in a different memory location
**/
Huffman::Huffman(const Huffman& obj1) {
	rootPtr = deepCopy(obj1.rootPtr); //helper method that makes a deep copy of the Huffman tree
	//copy data in codeBook
	for (int i = 0; i < NUM_CHAR; i++) {
		codeBook[i] = obj1.codeBook[i];
	}
}
/**
 //-------------------------- Parametric constructor for class Huffman ------------------------------------//
 This constructor takes the frequency of each letter from 'a' to 'z' provided in the array counts.
 It then constructs the Huffman tree and computes the code for each character.
 Preconditions: None
 Postconditions: Huffman tree is created using the Heap class. 
 Code for each letter in the counts array is constructed as a string and stored in an array called codeBook
 **/
Huffman::Huffman(const int counts[NUM_CHAR]) {

    //A Node array to hold all individual node with character c and frequency corresponding to the input array
	Node* array[NUM_CHAR];
	for (int i = 0; i < NUM_CHAR; i++) {
		Node* currentNode = new Node();
		currentNode->c = i + 97;
		currentNode->frequency = counts[i];
		array[i] = currentNode;
	}
	//heap object is created and the newly created Node array is sent in as a parameter to create a MinHeap 
	Heap<Node> h1(array, NUM_CHAR);//New heap is created
	huffmanMaker(h1);//A huffman tree is constructed using Heap class
	std::string s = "";
	codeMaker(rootPtr, s);//Code for each letter is constructed
}
/**
 //--------------------------getWord method  ------------------------------------//
 This methods takes in a word to encode. All letters in the word are converted to the appropriate bit strings. Non-letters may be ignored.
 Preconditions: A Huffman tree must be created and a codebook must be constructed
 Postconditions: Outputs a bit string corresponding to the input string and its code translation
 */
std::string Huffman::getWord(const std::string in) {
	//Create an vector of integers to hold the index value corresponding to the char in the string
	std::vector<int> indexValues;
	//Store the index value corresponding to the char in the string in the array indexValues
	for (char const& c : in) {
		indexValues.push_back(c - 97);
	}
	std::string code; //string to hold the output code of the input string
	//Loop through indexValues array and concatenate its corresponding code to the string code only if its an lowercase alphabet
	for (int j = 0; j < indexValues.size(); j++) {
		if (indexValues[j] < 25 && indexValues[j] > 0) {
			code = code + codeBook[indexValues[j]];
		}
	}
	return code;
}
/**
 //--------------------------Overloaded output operator <<  ------------------------------------//
 Outputs the letter-to-code translation table with one letter per line (in alphabetical order)
 followed by a space and the binary encoding from the Huffman algorithm 
 Preconditions: obj1.rootPtr must point to a Huffman tree with child nodes
 Postconditions: Outputs the letter-to-code translation table in alphabetical order
 */
std::ostream& operator<<(std::ostream& out, const Huffman& obj1) {
	for (int i = 0; i < NUM_CHAR; i++) {
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
Huffman:: ~Huffman() {
	clear(rootPtr);
}
//-------------------------- Private Helper methods  -------------------------------------------//
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

/**
 //--------------------------huffmanMaker method ------------------------------------//
 Preconditions: A heap object is created with data
 Postconditions: A huffman tree is constructed
 */
void Huffman::huffmanMaker(Heap<Node>& h1) {
	while (h1.size() > 1) {
		Node* first = h1.deleteMin(); 
		Node* second = h1.deleteMin();
		Node* tempRootNode = new Node; //create a new parent node
		//set the frequency of the parent node to the sum of the frequency of its child nodes
		tempRootNode->frequency = first->frequency + second->frequency; 
		tempRootNode->left = first; //set the parents left child
		tempRootNode->right = second;  //set the parents right child
		h1.insert(tempRootNode); //insert the newly created tree inside the heap while maintaining the heap order
	}
	rootPtr = h1.deleteMin(); //set rootPtr to the last remaining element in the heap which is a huffman tree
}

/**
 //--------------------------codeMaker method ------------------------------------//
 Preconditions:A huffman tree is created with the heap class
 Postconditions: A codeBook is created using the Huffman tree
 */
void Huffman::codeMaker(Node* root, string code) {

	if (root == nullptr) {
		return;
	}
	if (root->left != nullptr) codeMaker(root->left, code + "0");  //recusive call to left 
	if (root->right != nullptr) codeMaker(root->right, code + "1");  //recusive call to right 
	else {
		//check the character that the node contains and convert it into an int to store the code in its appropriate location in the codeBook array
		int i = root->c - 97;
		codeBook[i] = code;
	}
}
/*
 //-------------------------- Deep Copy Helper method ------------------------------------//
 Preconditions: The subTreePtr points to a nullPtr  or a Node with left and right subtrees
 Postconditions: The newTreePtr point to a copy of the parametric new Object containing new copies of its left and right subtree 
 @return Node pointing to a new copy of the subTreePtr and its child nodes
 */
Huffman::Node* Huffman::deepCopy(Node* subTreePtr) {


	Node* newTreePtr = nullptr;
	// Copy tree nodes during a preorder traversal
	if (subTreePtr != nullptr) {
		newTreePtr = new Node; //Create a new Node
		newTreePtr->c = subTreePtr->c;
		newTreePtr->frequency = subTreePtr->frequency;
		newTreePtr->left = deepCopy(subTreePtr->left);
		newTreePtr->right = deepCopy(subTreePtr->right);
	}
	return newTreePtr;
}
