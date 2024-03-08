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

bool order_by_value(const Item &a, const Item &b)
{
    if (a.value == b.value) {
        return a.weight < b.weight;
    }
    return a.value > b.value;
}

bool order_by_weight(const Item &a, const Item &b)
{
    if (a.weight == b.weight) {
        return a.value > b.value;
    }
    return a.weight < b.weight;
}