#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {

  int n = 10;

  int second_last = 1;
  int last = 1;

  cout << second_last << endl << last << endl;

  for(int i=1; i<=10; i++) {
    int next = second_last + last;
    cout << next << endl;
    last = next;
    second_last = last;
  }

  return 0;
}
