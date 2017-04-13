#include <iostream>
#include <string>

/* The dirtiest piece of code I've hammered out so far~ */

using namespace std;

int scores[3] = { 0, 0, 0 };
string names[3] = { "", "", "" };

void advanceTable(int index, int score, string name) {
  if (names[index] != name && index > 0)
    advanceTable(index - 1, scores[index], names[index]);
  
  scores[index] = score;
  names[index] = name;
}

int main() {
  string in;

  getline(cin, in);
  int n = stoi(in);
  
  for (int i = 0; i < n; i++) {
    getline(cin, in);

    int space = in.find(" ");

    int score = stoi(in.substr(0, space));
    string name = in.substr(space + 1);
    
    for (int i = 2; i >= 0; i--)
      if (score > scores[i]) {
        advanceTable(i, score, name);
        break;
      }  
  }

  for (int rank = 1; rank <= 3; rank++)
    cout << "#" << rank << ": " << names[3 - rank] << " (" << scores[3 - rank] << ")" << endl;
}

