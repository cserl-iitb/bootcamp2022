#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {

  int a = 45; int b = 22;
  int *p = &a;
  int *q = &b;// b is taken instead of null

  cout << *p << endl;

  p = q;
  cout << *p << endl;
//p = &b;cout << *p << endl; is eliminated
  
  return 0;
}
