//Sean O'Connor and Jeffery Martin
#include <iostream>
#include <list>
using namespace std;
list<int> bookNumbers;
list<int> bookSizes;
list<int> bookAlreadyOn;
int currentSize = 0;
void remove (int bookNum){
  list<int>::iterator it1=bookSizes.begin();
  list<int>::iterator it2;
  for(it2=bookNumbers.begin();it2!=bookNumbers.end();it2++){
    if(*it2==bookNum){
      it2=bookNumbers.erase(it2);
      currentSize=currentSize-*it1;
      it1=bookSizes.erase(it1);
      break;
    }
    it1++;
  }
}

void add(int bookNum,int bookSize, int shelfWidth){
  currentSize=currentSize+bookSize;
  while(currentSize>shelfWidth){
    currentSize=currentSize-bookSizes.front();
    bookSizes.pop_front();
    bookNumbers.pop_front();
  }
  bookSizes.push_back(bookSize);
  bookNumbers.push_back(bookNum);
}

void print(){

  while (!bookNumbers.empty()) {
    cout << bookNumbers.back() << " ";
    bookNumbers.pop_back();
    bookSizes.pop_back();
  }
  currentSize = 0;
  cout << endl;
}

int main (){
  int numTimes=0;
  while (true){
    int shelfWidth;
    cin>>shelfWidth;
    numTimes++;
    if (shelfWidth==-1){
      break;
    }
    else{
      while (true){
        string in;
        cin>>in;
        if (in=="E"){
          cout<<"PROBLEM "<<numTimes<<": "<<endl;
          print();
          break;
        }
        else{
          int bookNum;
          cin>>bookNum;
          if (in=="R"){
            remove(bookNum);
          }
          else if(in=="A"){
            int bookSize;
            cin>>bookSize;
            add(bookNum, bookSize, shelfWidth);
          }
        }
      }
    }
  }
  return 0;
}
