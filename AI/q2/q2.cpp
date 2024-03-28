#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

void read_set_and_target(vector<int>& set, int& target, string& fileName)
{
    ifstream file("data/" + fileName);
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

bool subsetSum(vector<int>& set, vector<int> subset, int target, int setIndex)
{
    if (setIndex == set.size()) {
        return target==0;
    }

    bool foundNotAdding = subsetSum(set, subset, target, setIndex+1);

    subset.push_back(set[setIndex]);
    bool foundAdding = subsetSum(set, subset, target-set[setIndex], setIndex+1);

    return foundAdding || foundNotAdding;
}

int main()
{

    vector<string> files = {
        "input_0.txt",
        "input_1.txt",
        "input_2.txt",
        "input_3.txt",
        "input_4.txt",
        "input_5.txt",
        "input_6.txt",
        "input_7.txt",
        "input_8.txt",
        "input_9.txt",
    };

    for (string file : files) {
        vector<int> set = {};
        vector<int> subset = {};
        int target;

        cout << "Starting search for file " << file << endl;

        clock_t start = clock();

        read_set_and_target(set, target, file);

        bool targetFound = subsetSum(set, subset, target, 0);

        double duration = (double) (clock() - start) / CLOCKS_PER_SEC;
        
        if (targetFound) {
            cout << "Target found in " << file << endl;
        }

        cout << "Time to search subsets in " << file << ": " << setprecision(2) << duration << endl;

    }

    return 0;
}
