#pragma once
/*
File Included: ClassHeader.h

Class Provided: Share

   Public Member Variables:
      
      double sharePrice;
         holds the price for this specific Share

   Public Member Functions:

      Share();
         PreCondition: none
         PostCondition: default constructor, sets sharePrice to 0.

      Share(double n);
         PreCondition: n is a double
         PostCondition: sharePrice set to n

Class Provided: Queue

   Private Member Variables:

      Item *p;
         used to point to a dynamic array of type Share

      int startSize = 5;
         the size that the dynamic array "p" starts at

      int currentSize = 5;
         the current size of the dynamic array "p", increments by 10 when needed

      int size = 0;
         keeps track of how many elements we have in our dynamic array

      int first = 0;
         keeps track of which element is first in line

      int last = 0;
         keeps track of which element is last in line

   Public Member Functions:

      Queue()
         PreCondition: none
         PostCondition: default constructor, starts p dynamic array with size "startSize"

      void Push(Share n)
         PreCondition: n passed in is of the correct data type
         PostCondition: n added to the back of the queue

      void Pop()
         PreCondition: an element exists in our Queue
         PostCondition: the front element is removed from the queue

      Share& Front()
         PreCondition: an element exists in our queue
         PostCondition: returns a reference to the Share at the front of the queue

      void IncreaseSize()
         PreCondition: variable last is greater than currentSize - 5, meaning we need to make more space
         PostCondition: currentSize incremented by 10, values in our queue copied over to a 10 space larger Share array, old array dynamically deleted

      double GetTotalOfShares();
         PreCondition: none
         PostCondition: returns the summation of all share prices we have in stock 

      int GetAmountOfShares()
         PreCondition: none
         PostCondition: returns how many elements are in our queue

*/

class Share {
public:
   double sharePrice;
   Share() {
      sharePrice = 0;
   }
   Share(double n) {
      sharePrice = n;
   }
   double GetSharePrice() { return sharePrice; }
};

class Queue {
private:
   Share *p;
   int startSize = 5, currentSize = 5, size = 0;
   int first = 0, last = 0;
public:

   Queue() { p = new Share[startSize]; }

   void Push(Share n);

   void Pop() { first++; size--; }

   Share& Front() { return p[first]; }

   void IncreaseSize();

   double GetTotalOfShares();

   int GetAmountOfShares() { return size; }
};
#include "ClassImplementation.h"