#pragma once


double Queue::GetTotalOfShares() {
   double toReturn = 0;
   for (int i = 0; i < size; i++) {
      toReturn += p[i].GetSharePrice();
   }
   return toReturn;
}

void Queue::IncreaseSize() {
   Share *temp = new Share[currentSize + 10];

   for (int i = 0; i < currentSize; i++) {
      *temp = *p;
      p++;
      temp++;
   }
   for (int i = 0; i < currentSize; i++) {
      p--;
      temp--;
   }
   delete[] p;
   p = temp;
   currentSize += 10;
}

void Queue::Push(Share n) {
   if (last > currentSize - 5)
      IncreaseSize();
   p[last] = n;
   last++;
   size++;
}
