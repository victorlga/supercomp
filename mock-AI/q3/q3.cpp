#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

using namespace std;

struct Job {
    int load;
    Job(int load) : load(load) {}
};

struct Machine {
    int load;
    Machine(int load) : load(load) {}
};

void fillVectors(vector<Machine>& machines, vector<Job>& jobs)
{
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error while opening the file." << endl;
    }
    
    string line;
    getline(file, line);
    stringstream jobStream(line);

    int numberJobs;
    int numberMachines;
    jobStream >> numberJobs >> numberMachines;

    for (int i = 0; i < numberMachines; ++i) {
        machines.push_back(Machine(0));
    }

    int load;

    while (getline(file, line)) {
        stringstream jobStream(line);
        jobStream >> load;
        Job job = Job(load);
        jobs.push_back(job);
    }

    file.close();
}

int findBestMaxMachineLoad(vector<Machine>& machines) {
    if (machines.empty()) {
        return 0;
    }

    auto maxMachineLoadIt = std::max_element(machines.begin(), machines.end(),
        [](const Machine& a, const Machine& b) { return a.load < b.load; });

    return maxMachineLoadIt->load;
}

int exhaustiveSearchBestMaxMachineLoad(vector<Machine>& machines, vector<Job>& jobs, vector<Job>::size_type jobIndex)
{
    if (jobIndex >= jobs.size()) {
        return findBestMaxMachineLoad(machines);
    }

    int bestMaxMachineLoad = numeric_limits<int>::max();

    for (vector<Machine>::size_type i = 0; i < machines.size(); ++i) {
        machines[i].load += jobs[jobIndex].load;
        int maxMachineLoad = exhaustiveSearchBestMaxMachineLoad(machines, jobs, jobIndex + 1);
        machines[i].load -= jobs[jobIndex].load;

        if (maxMachineLoad < bestMaxMachineLoad) {
            bestMaxMachineLoad = maxMachineLoad;
        }
    }


    return bestMaxMachineLoad;
}

void writeOutputFile(vector<Machine>& machines, int& bestMaxMachineLoad)
{
    ofstream file("output.txt");
    if (!file.is_open()) {
        cerr << "Error while opening the file." << endl;
    }

    file << "Final Max Machine Load: " << bestMaxMachineLoad << endl;
    file.close();
}

int main()
{
    vector<Machine> machines;
    vector<Job> jobs;

    fillVectors(machines, jobs);
    int bestMaxMachineLoad = exhaustiveSearchBestMaxMachineLoad(machines, jobs, 0);
    writeOutputFile(machines, bestMaxMachineLoad);

    return 0;
}