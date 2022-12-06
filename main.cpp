#include <bits/stdc++.h>

#define ll long long

using namespace std;

// dsu
void make(ll node, ll parent[]) {
	// O(1)
	// creates a disconnected component
	parent[node] = node;
}

ll fnd(ll node, ll parent[]) {
	// O(1)
	// returns the parent of a component
	if (parent[node] == node) return node;
	return parent[node] = fnd(parent[node], parent);
}

void Union(ll a, ll b, ll parent[]) {
	// O(1)
	// connects two components together
	parent[fnd(a, parent)] = parent[fnd(b, parent)];
}
// dsu

void kruskal(map<ll, pair<ll, ll>> &input, map<ll, pair<ll, ll>> &ans, ll N) {
	// O(n log n)
	// this will return the minimum spanning tree
	ll parent[N + 1];
	// making all the nodes
	for (auto &e: input) {
		make(e.second.first, parent);
		make(e.second.second, parent);
	}
	for (auto &e: input) {
		ll a = e.second.first;
		ll b = e.second.second;
		// if their parents are equal they will create a cycle
		if (fnd(a, parent) == fnd(b, parent)) continue;
		Union(a, b, parent);
		ans[e.first] = {a, b};
	}
}

void dfs(map<ll, vector<ll>> &adjList, ll source, vector<ll> discovered) {
	// O (n log n)
	// use vector<ll> adjList[n+1] for non negative nodes -> O (n)
	// use pair<ll, ll> instead of ll for weighted graphs
	stack<ll> stck;
	stck.push(source);
	discovered[source] = 1;
	while (!stck.empty()) {
		ll curr = stck.top();
		cout << curr << " ";
		stck.pop();
		for (auto e: adjList[curr])
			if (!discovered[e]) {
				stck.push(e);
				discovered[e] = 1;
			}
	}
	cout << endl;
	return;
}

void bfs(map<ll, vector<ll>> &adjList, ll source, vector<ll> discovered) {
	// O (n log n)
	// use vector<ll> adjList[n+1] for non negative nodes -> O (n)
	// use pair<ll, ll> instead of ll for weighted graphs
	queue<ll> que;
	que.push(source);
	discovered[source] = 1;
	while (!que.empty()) {
		ll curr = que.front();
		cout << curr << " ";
		que.pop();
		for (auto e: adjList[curr])
			if (!discovered[e]) {
				que.push(e);
				discovered[e] = 1;
			}
	}
	cout << endl;
	return;
}

int main() {
	ll n, e;
	cin >> n >> e;
	map<ll, pair<ll, ll>> input, ans;
	// graph list
	// graph map
	// weighted graph list
	// weighted graph map
	while (e--) {
		ll x, y, z;
		cin >> x >> y >> z;
		input[z] = {x, y};
	}
	kruskal(input, ans, n);
	for (auto &element: ans) {
		cout << element.first << " " << element.second.first << " " << element.second.second << endl;
	}
//	ll source = 1;
//	vector<ll> discovered(n + 1, 0);
//	bfs(adjList, source, discovered);
//	dfs(adjList, source, discovered);

	return 0;
}

/*
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
 */
/*
 6 9
 5 4 9
 1 4 1
 5 1 4
 4 3 5
 4 2 3
 1 2 2
 3 2 3
 3 6 8
 2 6 7
 */