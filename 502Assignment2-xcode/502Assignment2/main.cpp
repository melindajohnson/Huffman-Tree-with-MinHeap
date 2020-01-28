   //------------------------------------------------------------------------
   // HW2.CPP
   // Driver code for testing Huffman class for creating Huffman codes
   // Author:  Clark Olson
   //------------------------------------------------------------------------
   // This code tests all of the basic functionality of the Huffman class
   // for CSS 502 HW 2.  It is not meant to exhaustively test the class.
   //
   // Assumptions:
   //  - none
   //------------------------------------------------------------------------

#include <iostream>
#include "Huffman.h"   // Must define NUM_CHAR to 26
using namespace std;


   //------------------------------------------------------------------------
   // main
   // Preconditions: none
   // Postconditions: tests methods of the Huffman class using randomly
   //               generated character counts
int main() {
      // Create random counts
   int counts[NUM_CHAR];
   for (int i = 0; i < NUM_CHAR; i++) {
      counts[i] = rand() % 1000;
   }
   
      // Construct Huffman codes and display table
   Huffman code(counts);
   cout << code << endl;
   
      // Simple test of encoding words
   cout << "test:  " << code.getWord("test") << endl;
   cout << "least: " << code.getWord("least") << endl;
   cout << endl;
}
