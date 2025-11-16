#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:

    Graph(int v) {
        V = v;
        l = new list<int>[v];
    }

    void addEdge(int a, int b, bool Undir = true) {
        l[a].push_back(b);
        if (Undir)
            l[b].push_back(a);
    }

    void printList() {
        for (int i = 0; i < V; i++) {
            cout << i << " --> ";
            for (auto nbr : l[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(0,2);
    g.addEdge(0,5);
    g.addEdge(4,6);

    g.printList();  // call it here

    return 0;
}
