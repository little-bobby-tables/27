#include <iostream>
#include <string>

using namespace std;

string buffer;

int get_int(char sep = '\n') {
  getline(cin, buffer, sep);
  return stoi(buffer);
}

int main() {
  int N = get_int();
  
  int sum = 0,
      min_diff = 0;
  
  for (int i = 0; i < N; i++) {
    int a = get_int(' '),
        b = get_int();
        
    if (a > b) sum += a;
    else sum += b;
    
    int diff = abs(a - b);
    if (diff % 3 != 0 && (min_diff == 0 || min_diff > diff)) min_diff = diff;
  }
  
  if (sum % 3 != 0) cout << sum << endl;
  else if (min_diff != 0) cout << (sum - min_diff) << endl;
  else cout << "0" << endl;
}
