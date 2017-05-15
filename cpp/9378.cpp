#define DIST 6
#define UNSET 1001

#include <iostream>
#include <string>

using namespace std;

string buffer;

int get_int() {
  getline(cin, buffer);
  return stoi(buffer);
}

int main() {
  int min_even = UNSET,
      min_abs = UNSET,
      min_product = UNSET;
  
  int N = get_int();
  
  int queue[DIST];
  for (int i = 0; i < DIST; i++) queue[i] = get_int();
  
  for (int i = 0; i < (N - DIST); i++) {
    int popped = queue[0];
    for (int q = 1; q < DIST; q++) queue[q - 1] = queue[q];
    
    if (popped % 2 == 0 && popped < min_even)
      min_even = popped;
    else if (popped < min_abs)
      min_abs = popped;
    
    int current = get_int();
    queue[6] = current;
    
    if (min_even != UNSET
        && (min_even * current) < min_product)
      min_product = (min_even * current);

    if (min_abs != UNSET
        && (min_abs * current) % 2 == 0
        && (min_abs * current) < min_product)
      min_product = (min_abs * current);
  }
  
  if (min_product != UNSET) cout << min_product << endl;
  else cout << "-1" << endl;
}
