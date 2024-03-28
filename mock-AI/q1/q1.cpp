#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Job {
    int load;

    Job(int load) : load(load) {}
};

struct Machine {
    int load;
    int id;
    vector<Job> jobs;

    Machine(int load, int id, vector<Job> jobs) : load(load), id(id), jobs(jobs) {}
};

void fill_vectors(vector<Machine>& machines, vector<Job>& jobs)
{
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "Error while opening the file." << endl;
    }
    
    string line;
    getline(file, line);
    stringstream jobstream(line);

    int number_jobs;
    int number_machines;
    jobstream >> number_jobs >> number_machines;

    for (int i = 0; i < number_machines; ++i) {
        machines.push_back(Machine(0, i, {}));
    }

    int execution_time;

    while (getline(file, line)) {
        stringstream jobstream(line);
        jobstream >> execution_time;
        Job job = Job(execution_time);
        jobs.push_back(job);
    }

    file.close();
}

bool ordering_criteria(const Job &a, const Job &b) { return a.load >= b.load; }

Machine& find_lighter_machine(vector<Machine>& machines)
{
    Machine* lighter_machine = &machines[0];
    for (Machine& machine : machines) {
        if (machine.load < lighter_machine->load) {
            lighter_machine = &machine;
        }
    }
    return *lighter_machine;
}

void add_jobs_to_machines(vector<Machine>& machines, vector<Job>& jobs)
{
    for (Job& job : jobs) {
        Machine& lighter_machine = find_lighter_machine(machines);
        lighter_machine.jobs.push_back(job);
        lighter_machine.load += job.load;
    }
}


int calculate_max_machine_load(vector<Machine>& machines)
{
    Machine& heavier_machine = machines[0]; 
    for (Machine& machine : machines) {
        if (machine.load > heavier_machine.load) {
            heavier_machine = machine;
        }
    }

    return heavier_machine.load;
}

void write_output_file(vector<Machine>& machines, int& max_machine_load)
{
    ofstream file("output.txt");
    if (!file.is_open()) {
        cerr << "Error while opening the file." << endl;
    }

    for (Machine& machine : machines) {
        file << "Machine " << machine.id << " load: " << machine.load << endl;
    }

    file << "Max machine load: " << max_machine_load << endl;
    file.close();
}

int main()
{
    vector<Machine> machines = {};
    vector<Job> jobs;

    fill_vectors(machines, jobs);
    sort(jobs.begin(), jobs.end(), ordering_criteria);
    add_jobs_to_machines(machines, jobs);
    int max_machine_load = calculate_max_machine_load(machines);
    write_output_file(machines, max_machine_load);

    return 0;
}