#include <iostream> 
#include <vector> 
#include <queue>
using namespace std; 
struct Edge 
{
	int source; 
	int destination; int cost; 
 	Edge(int src, int dest, int cst) 
	{ 
		source = src; destination =dest; cost = cst; 
 	} 
}; 
 
struct DisjointSet 
{ 
	vector<int> parent; 
	vector<int> rank; 
 	DisjointSet(int n) 
	{ 
		parent.resize(n); 
		rank.resize(n, 0); 
 		for (int i = 0; i < n; i++) 
		{ 
			parent[i] = i; 
 		} 
 	} 
 	int find(int x) 
	{ 
		if (parent[x] != x) 
		{ 
			parent[x] = find(parent[x]); 
 		} 
 		return parent[x]; 
 	} 
 	void unionSets(int x, int y) 
	{ 
		int xRoot = find(x); 
		int yRoot = find(y); 
 		if (rank[xRoot] < rank[yRoot]) 
 		{ 
 			parent[xRoot] = yRoot; 
 		} 
 		else if (rank[xRoot] > rank[yRoot]) 
 		{ 
			parent[yRoot] = xRoot; 
 		}
 		else 
 		{ 
 			parent[yRoot] = xRoot; 
 			rank[xRoot]++; 
 		} 
	} 
}; 

findMinimumCost(vector<Edge>& edges, int numCities) 
{  
	edges.end(), [](const Edge& a, const Edge& b)
 	{ 
 		return a.cost < b.cost; 
 	}; 
 	DisjointSet disjointSet(numCities); 
	int minCost = 0; 
 	for (const Edge& edge : edges) 
	{ 
		int sourceRoot = disjointSet.find(edge.source); 
		int destinationRoot = disjointSet.find(edge.destination);  
		if (sourceRoot != destinationRoot) 
		{ 
			disjointSet.unionSets(sourceRoot, destinationRoot); 
			minCost += edge.cost; 
 		} 
	}
	return minCost; 
} 
int main()
{ 
 
	int numCities = 5; 
    vector<Edge> edges;
	edges.push_back(Edge(0, 1, 2));
	edges.push_back(Edge(0, 2, 3)); 
	edges.push_back(Edge(1, 2, 1)); 
	edges.push_back(Edge(1, 3, 4)); 
	edges.push_back(Edge(2, 3, 2)); 
	edges.push_back(Edge(2, 4, 3)); 
	edges.push_back(Edge(3, 4, 1)); 
 
	int minCost = findMinimumCost(edges, numCities); 
	cout << "Minimum cost of leasing phone lines to connect all offices: " << minCost << endl; 
	return 0; 
}
