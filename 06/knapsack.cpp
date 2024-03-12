#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


struct Item {
    int id;
    int value;
    int weight;

    Item(int id, int value, int weight) : id(id), value(value), weight(weight) {}
};


vector<Item> create_item_vector()
{
    string file_name = "input.txt";
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

bool ordering_criteria(const Item &a, const Item &b)
{
    if (a.value == b.value) {
        return a.weight < b.weight;
    }
    return a.value > b.value;
}

int main() {
    vector<Item> items = create_item_vector();

    sort(items.begin(), items.end(), ordering_criteria);

    int max_weight;
    cout << "Define bag max weight: ";
    cin >> max_weight;

    int current_weight = 0;

    for (const auto &item : items) {
        if (current_weight + item.weight > max_weight) break;
        cout << "ID: " << item.id << ", Value: " << item.value << ", Weight: " << item.weight << endl;
        current_weight += item.weight;
    }

    return 0;
}
