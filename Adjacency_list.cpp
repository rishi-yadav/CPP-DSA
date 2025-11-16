#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string name;
    list<string> nbrs;
    
    Node(string name){
        this->name = name;
    }
};

class Graph{
    unordered_map<string, Node*> umap;
    
public:
    Graph(vector<string> cities){
        for(auto city: cities){
            umap[city] = new Node(city);
        }
    }
    
    void addEdge(string a, string b, bool undir=false){
        umap[a]->nbrs.push_back(b);
        
        if (undir)
            umap[b]->nbrs.push_back(a);
    }
    
    void printList(){
        for(auto citypair: umap){
            string city = citypair.first;
            cout<<city<<"-->";
            
            Node *nbr = citypair.second;
            
            for(auto nbr: nbr->nbrs){
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
	vector<string> cities = {"delhi", "mumbai", "chennai", "kolkata"};
	
	Graph g(cities);
	g.addEdge("delhi", "mumbai");
	g.addEdge("delhi", "chennai");
	g.addEdge("chennai", "kolkata");
	g.addEdge("mumbai", "kolkata");
	g.printList();
	
}
