#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void read_set_and_target(vector<int>& set, int& target)
{
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error while opening the file." << endl;
    }
    
    string line;
    getline(file, line);
    stringstream intstream(line);

    intstream >> target;

    int number;
    while (getline(file, line)) {
        stringstream intstream(line);
        intstream >> number;
        set.push_back(number);
    }

    file.close();
}

bool orderingCriteria(const int &a, const int &b) { return a > b; }

bool subsetSum(const vector<int>& set, int target)
{
    for (int number : set) {
        if (target - number >= 0) {
            target -= number;
            cout << "Number added into subset: " << number << endl;
        }
    }
    return target == 0;
}

int main()
{
    vector<int> set = {};
    int target;

    // Read number set from input.txt where first line is target and
    // following ones are integer numbers.
    read_set_and_target(set, target);

    sort(set.begin(), set.end(), orderingCriteria);
    bool targetFound = subsetSum(set, target);

    if (targetFound) {
        cout << "Target found!" << endl;
    }

    return 0;
}
