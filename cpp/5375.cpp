#include <iostream>
#include <string>

using namespace std;

string buffer;

int get_int() {
  getline(cin, buffer);
  return stoi(buffer);
}

int main() {
  int N = get_int();
  
  string pos_sequence = "",
         neg_sequence = "";
         
  for (int i = 0; i < N; i++) {
    string seq_item = to_string(i + 1);
    
    int a = get_int();
    
    if (a < 0) {
      if (neg_sequence == "") {
        if (pos_sequence != "") neg_sequence = pos_sequence + " ";
        neg_sequence += seq_item;
      }
      else {
        pos_sequence = neg_sequence;
        pos_sequence += " " + seq_item;
        
        neg_sequence = "";
      }
    }
    else if (a > 0) {
      if (pos_sequence != "") pos_sequence += " ";
      pos_sequence += seq_item;
    }
  }
  
  cout << pos_sequence << endl;
}
