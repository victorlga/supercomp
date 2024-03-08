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

int fill_sack(vector<Item> items, bool randomness, int max_weight)
{
    int seed = 10;
    mt19937 gen(seed);
    uniform_real_distribution<> float_distr(0.0, 1.0);

    vector<Item> sack;
    int current_weight = 0;

    while (!items.empty()) {

        float random_float = float_distr(gen);
        int index;

        if (random_float < 0.75 and !randomness) {
            index = 0;
        } else {
            uniform_int_distribution<> int_distr(0, items.size() - 1);
            index = int_distr(gen);
        }

        Item& item = items[index];

        if (current_weight + item.weight <= max_weight) {
            current_weight += item.weight;
            sack.push_back(item);
            items.erase(items.begin() + index);
        } else {
            break;
        }
    }

    cout << "Items in the sack:" << endl;
    for (const Item& item : sack) {
        cout << "ID: " << item.id << ", Value: " << item.value << ", Weight: " << item.weight << endl;
    }

    return current_weight;
}

int main()
{
    string file_name = "in1.txt";
    // cout << "Define input file name: ";
    // cin >> file_name;
    vector<Item> items = create_item_vector(file_name);

    sort(items.begin(), items.end(), order_by_value);

    int max_weight;
    cout << "Define bag max weight: ";
    cin >> max_weight;

    bool randomness = 1;
    int r_weight = fill_sack(items, randomness, max_weight);
    int weight = fill_sack(items, !randomness, max_weight);
    cout << "Total weight with randomness: " << r_weight << endl;
    cout << "Total weight: " << weight << endl;

    return 0;
}