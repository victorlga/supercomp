#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <climits>

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

int fill_sack(vector<Item>& items, int capacity, int i)
{
    if (capacity < 0) {
        return INT_MIN;
    }
    if (capacity == 0 || i == items.size()) {
        return 0;
    }

    int exclude = fill_sack(items, capacity, i+1);

    int include = items[i].value + fill_sack(items, capacity - items[i].weight, i+1);

    return max(include, exclude);
}

int main()
{
    string file_name = "in1.txt";
    vector<Item> items = create_item_vector(file_name);
    int capacity = 200;
    int value = fill_sack(items, capacity, 0);
    cout << "Total value: " << value << endl;

    return 0;
}
