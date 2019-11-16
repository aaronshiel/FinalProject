#include <iostream>
#include <string>
#include "ClassHeader.h"
using namespace std;

int main() {
   double totalCapitalGain = 0; //used to keep track of how much profit we've made so far

   Queue n = Queue();

   int action = -1; //keeps track of what the user would like to do

   while (action != 0) {
      cout << "What would you like to do?" << endl;
      cout << "1. Buy shares." << endl;
      cout << "2. Sell shares." << endl;
      cout << "3. Total Capital Gain So Far." << endl;
      cout << "0. Quit Program." << endl;
      cin >> action;

      if (action == 1) {
         double howMany = 0, pricePer = 0;
         cout << "How many shares are you buying? ";
         cin >> howMany;
         cout << "How much does each share cost? $";
         cin >> pricePer;
         Share toAdd = Share(pricePer);
         for (int i = 0; i < howMany; i++) {
            n.Push(toAdd); //adds howMany Shares with value of pricePer to the queue
         }

         cout << "Total Shares: " << n.GetAmountOfShares() << endl;
         cout << "Total Shares Value: $" << n.GetTotalOfShares() << endl << endl;
      }

      if (action == 2) {
         double howMany = 0, pricePer = 0;
         cout << "How many shares are you selling? ";
         cin >> howMany;
         cout << "How much are you selling each for? $";
         cin >> pricePer;
         cout << endl;
         double profitMade = 0; //keeps track of profit made from this transaction
         if (howMany > n.GetAmountOfShares()) { //if requesting to sell more shares than we have in stock, we sell what we have left
            howMany = n.GetAmountOfShares();
            cout << "Only " << howMany << " shares left, so we are selling what we have left only." << endl;
            for (int i = 0; i < howMany; i++) {
               profitMade += pricePer - n.Front().GetSharePrice(); //capital gain formula
               totalCapitalGain += pricePer - n.Front().GetSharePrice();
               n.Pop();
            }
         }
         else { //if we have enough shares per requested, sell as many as requested
            for (int i = 0; i < howMany; i++) {
               profitMade += pricePer - n.Front().GetSharePrice();
               totalCapitalGain += pricePer - n.Front().GetSharePrice();
               n.Pop();
            }
         }
         cout << "Profit Made: $" << profitMade << endl;
         cout << "Total Shares Left: " << n.GetAmountOfShares() << endl;
         cout << "Total Shares Value: $" << n.GetTotalOfShares() << endl << endl;
      }

      if (action == 3) {
         cout << "Total Capital Gain: $" << totalCapitalGain << endl;
      }
   }

   system("pause");
   return 0;
}