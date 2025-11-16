#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string name;
    list<pair<string, int>> nbrs;
    
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
    
    void addEdge(string a, string b, int c, bool undir=false){
        umap[a]->nbrs.push_back({b, c});

        if (undir)
            umap[b]->nbrs.push_back({a, c});
    }
    
    void printList(){
        for(auto citypair: umap){
            string city = citypair.first;
            cout<<city<<"-->";
            Node *nbr = citypair.second;
            
            for(auto nbr: nbr->nbrs){
                cout<<nbr.first<<" "<<nbr.second<<",";
                //cout<<nbr.first<<",";
            }
            cout<<endl;
        }
    }
};

int main() {
	vector<string> cities = {"delhi", "mumbai", "chennai", "kolkata"};
	
	Graph g(cities);
	
	g.addEdge("delhi", "mumbai", 3);
	g.addEdge("delhi", "chennai", 2);
	g.addEdge("chennai", "kolkata", 11);
	g.addEdge("mumbai", "kolkata", 12);
	g.printList();

}
