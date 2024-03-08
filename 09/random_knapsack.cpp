#include <random>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

struct Item {
    int id;
    int value;
    int weight;

    Item(int id, int value, int weight) : id(id), value(value), weight(weight) {}
};

vector<Item> create_item_vector(const string& file_name)
{
    ifstream file(file_name);
    vector<Item> items;

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    string line;
    int value, weight, id = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> value >> weight;
        items.push_back(Item(++id, value, weight));
    }

    file.close();
    return items;
}


int fill_sack_1(vector<Item> items, int max_weight)
{
    random_device rd;
    mt19937 gen(rd());

    int weight = 0;

    for (auto& item : items) {
        if ((weight + item.weight) > max_weight) break;

        bernoulli_distribution distr;
        bool random_choice= distr(gen);

        if (random_choice) {
            weight += item.weight;
        }
    }

    return weight;
}

int fill_sack_2(vector<Item> items, int max_weight)
{
    random_device rd;
    mt19937 gen(rd());

    shuffle(items.begin(), items.end(), gen);

    int weight = 0;

    for (auto& item : items) {
        if ((weight + item.weight) > max_weight) break;
        weight += item.weight;
    }

    return weight;
}


int main()
{
    string file_name = "in1.txt";
    vector<Item> items = create_item_vector(file_name);

    int max_weight;
    cout << "Define bag max weight: ";
    cin >> max_weight;

    int weight_1 = 0;
    int weight_2 = 0;
    int iter = 10000;

    for (int i = 0; i < iter; i++) {
        weight_1 += fill_sack_1(items, max_weight);
        weight_2 += fill_sack_2(items, max_weight);
    }

    cout << "Avg weight_1: " << weight_1 / iter << endl;
    cout << "Avg weight_2: " << weight_2 / iter << endl;

    return 0;
}
