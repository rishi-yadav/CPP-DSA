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
    
    void bfs(int src){
        queue<int> q;
        vector<bool> visited{0};
        
        q.push(src);
        visited[src] = true;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            cout<<top<<endl;
            for(auto nbr: l[top]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
                    
            }
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);

    g.printList();  // call it here
    
    //    (2)
    //  /   \
    // (1)  (3)--(4)
    //   \    \
    //    (0)  (5)
    
    g.bfs(1);

    return 0;
}
