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

struct Sack {
    int total_weight;
    vector<Item> items;

    Sack(int total_weight, vector<Item> items) : total_weight(total_weight), items(items) {}
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


Sack fill_sack_1(vector<Item> items, int max_weight)
{
    random_device rd;
    mt19937 gen(rd());

    int weight = 0;
    Sack sack = Sack(0, {});;

    for (auto& item : items) {

        bernoulli_distribution distr;
        bool random_choice= distr(gen);

        if (random_choice && (sack.total_weight + item.weight) <= max_weight) {
            sack.total_weight += item.weight;
            sack.items.push_back(item);
        }
    }

    return sack;
}


int main()
{
    string file_name = "in1.txt";
    vector<Item> items = create_item_vector(file_name);

    int max_weight;
    cout << "Define bag max weight: ";
    cin >> max_weight;

    Sack best_sack = Sack(0, {});

    int iter = 10;

    for (int i = 0; i < iter; i++) {
        Sack sack_temp = fill_sack_1(items, max_weight);
        if (sack_temp.total_weight > best_sack.total_weight) best_sack = sack_temp;
    }

    for (Item& item : best_sack.items) {
        cout << "ID: " << item.id << endl;
    }

    return 0;
}