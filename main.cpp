#include <bits/stdc++.h>

#define ll long long

using namespace std;

// dsu
void make(ll v, ll parent[]) {
	// O(1)
	parent[v] = v;
}

ll fnd(ll v, ll parent[]) {
	// O(1)
	if (parent[v] == v) return v;
	return parent[v] = fnd(parent[v], parent);
}

void Union(ll a, ll b, ll parent[]) {
	// O(1)
	parent[fnd(a, parent)] = parent[fnd(b, parent)];
}
// dsu

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
	map<ll, vector<ll>> adjList;
	// graph list
	// graph map
	// weighted graph list
	// weighted graph map
	while (e--) {
		ll x, y;
		cin >> x >> y;
		adjList[x].push_back(y);
	}
	ll source = 1;
	vector<ll> discovered(n + 1, 0);
	bfs(adjList, source, discovered);
	dfs(adjList, source, discovered);

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
