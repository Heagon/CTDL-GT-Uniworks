#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

string getNodeName(int i) {
    string name;
    while (i >= 0) {
        name = char('A' + (i % 26)) + name;
        i = i / 26 - 1;
    }
    return name;
}

int main() {
    const int nodeCount = 300;
    const int edgeCount = 74792;
    const string outputFile = "file_input.csv";

    // Xóa file cũ nếu có
    remove(outputFile.c_str());

    // Danh sách đỉnh
    vector<string> nodes;
    for (int i = 0; i < nodeCount; ++i) {
        nodes.push_back(getNodeName(i));
    }

    // Tạo các cạnh ngẫu nhiên
    unordered_set<string> edgeSet;
    vector<tuple<string, string, int>> edges;
    srand(time(0));

    while (edges.size() < edgeCount) {
        string src = nodes[rand() % nodeCount];
        string tgt = nodes[rand() % nodeCount];
        if (src != tgt) {
            string key = src + "->" + tgt;
            if (edgeSet.find(key) == edgeSet.end()) {
                edgeSet.insert(key);
                int weight = rand() % 20 + 1;
                edges.emplace_back(src, tgt, weight);
            }
        }
    }

    // Ghi vào file CSV
    ofstream outFile(outputFile);
    outFile << "source,target,weight\n";
    for (auto& [src, tgt, weight] : edges) {
        outFile << src << "," << tgt << "," << weight << "\n";
    }
    outFile.close();

    cout << "da tao tat ca " << edgeCount << " canh roi ghi vao " << outputFile << endl;
    return 0;
}
