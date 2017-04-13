#include <iostream>

using namespace std;

int score_per_school[99];
int students_per_school[99];

void print_stats() {
  int max_avg = 0;
  int schools_with_max_avg = 0;

  for (int i = 0; i < 99; i++) {
    if (students_per_school[i] == 0) continue;

    int average = score_per_school[i] / students_per_school[i];

    if (average > max_avg) {
      max_avg = average;
      schools_with_max_avg = 1;
    } else if (average == max_avg)
      schools_with_max_avg++;
  }

  cout << "Max. average per school: " << max_avg << endl;
  
  if (schools_with_max_avg > 1)
    cout << "In " << schools_with_max_avg << " schools" << endl;
}

int main() {
  for (int i = 0; i < 99; i++)
    score_per_school[i] = students_per_school[i] = 0;

  int n;
  cin >> n;

  string buffer;

  for (int i = 0; i < n; i++) {
    getline(cin, buffer, ' '); /* FN */
    getline(cin, buffer, ' '); /* LN */

    getline(cin, buffer, ' '); /* School # */
    int school = stoi(buffer);

    getline(cin, buffer); /* Score */
    int score = stoi(buffer);

    score_per_school[school] += score;
    students_per_school[school]++;
  }

  print_stats();
}

