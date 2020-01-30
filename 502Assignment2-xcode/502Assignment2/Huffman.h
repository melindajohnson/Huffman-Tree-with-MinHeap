
/*
----------------------------------------------------------------------------------------------------------------
HUFFMAN.H
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

#ifndef Huffman_h
#define Huffman_h
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "Heap.h"
static const int NUM_CHAR = 26;  //total numbers of characters
class Huffman
{

public:
	/**
	//-------------------------- Default constructor for class Huffman ------------------------------------//
	Preconditions: None
	Postconditions : The rootPtr of the Huffman Tree is initialized to a nullptr
	**/
	Huffman();

	/**
	//-------------------------- Copy constructor for class Huffman ------------------------------------//
	Preconditions: The rootPtr points to an empty Huffman tree or one containing a number of nodes in each of its left and right Subtree
	 Postconditions: The rootPtr point to a copy of the Huffman tree containing new copies of its left and right subtree in a different memory location
	**/
	Huffman(const Huffman& obj1);

	/**
	//-------------------------- Parametric constructor for class Huffman ------------------------------------//
	This constructor takes the frequency of each letter from 'a' to 'z' provided in the array counts.
	It then constructs the Huffman tree and computes the code for each character.
	Preconditions : None
	Postconditions : Huffman tree is created using the Heap class.
	Code for each letter in the counts array is constructed as a stringand stored in an array called codeBook
	**/
	Huffman(const int counts[NUM_CHAR]);
	/**
	 //--------------------------getWord method  ------------------------------------//
	 This methods takes in a word to encode. All letters in the word are converted to the appropriate bit strings. Non-letters may be ignored.
	 Preconditions: obj1.rootPtr must point to a Huffman tree with child nodes
	 Postconditions: Outputs a bit string corresponding to the input string and its code translation
	 */
	std::string getWord(const std::string in);
	/**
	 //--------------------------Overloaded output operator <<  ------------------------------------//
	 Outputs the letter-to-code translation table with one letter per line (in alphabetical order)
	 followed by a space and the binary encoding from the Huffman algorithm
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
		char c;  //lower case letter in the huffman tree
		unsigned frequency = 0;  //count of occurence of a character c
		struct Node* left = nullptr; //pointer to Left Child
		struct Node* right = nullptr; //pointer to Right Child

		/**
		//-------------------------- Overloaded lesser than operator <------------------------------------//
		Determines if the Nodes frequency on the left hand side is lesser than the Node frequency on right hand side
		Preconditions:frequency and 0.frequency are two unsigned int belonging to two Node this and o
		Postconditions: boolean true if the left hand side frequency is lesser than the frequency on right hand side
		@return boolean true if left is smaller than right
		*/
		bool operator<(const Node& o);

		/**
		//-------------------------- Overloaded greater than operator >------------------------------------//
		Determines if the Nodes frequency on the left hand side is greater than the Node frequency on right hand side
		Preconditions : frequency and 0.frequency are two unsigned int belonging to two Node this and o
		Postconditions : boolean true if the left hand side frequency is greater than the frequency on right hand side
		@return boolean true if left is greater than right
		**/
		bool operator>(const Node& o);

		/**
		  //-------------------------- Overloaded equal to operator == ------------------------------------//
		  Determines if the Nodes frequency on the left hand side is equal to than the Node frequency on right hand side
		  Preconditions : frequency and 0.frequency are two unsigned int belonging to two Node this and o
		  Postconditions : boolean true if the left hand side frequency is equal to than the frequency on right hand side
		  @return boolean true if left is greater than right
		 **/
		bool operator==(const Node& o);
	};

	Node* rootPtr; //pointer to the root Node of the Huffman tree
	std::string codeBook[NUM_CHAR]; //array of Strings to hold the code for each character

	//-------------------------- Private Helper methods  -------------------------------------------//

/**
//--------------------------Clear method ------------------------------------//
Preconditions: The subTreePtr points to a nullPtr  or a Node with left and right subtrees
Postconditions: The subtree pointers and its left and right subtrees are deallocated and frees the memory
*/
	void clear(Node* subTreePtr);

	/**
	 //--------------------------huffmanMaker method ------------------------------------//
	 Preconditions: A heap object is created with data
	 Postconditions: A huffman tree is constructed
	 */
	void huffmanMaker(Heap<Node>& h1);

	/**
	 //--------------------------codeMaker method ------------------------------------//
	 Preconditions:A huffman tree is created with the heap class
	 Postconditions: A codeBook is created using the Huffman tree
	 */
	void codeMaker(Node* root, std::string code);

	/*
	 //-------------------------- Deep Copy Helper method ------------------------------------//
	 Preconditions: The subTreePtr points to a nullPtr  or a Node with left and right subtrees
	 Postconditions: The newTreePtr point to a copy of the parametric new Object containing new copies of its left and right subtree
	 @return Node pointing to a new copy of the subTreePtr and its child nodes
	 */
	Node* deepCopy(Node* subTreePtr);
};
#endif
