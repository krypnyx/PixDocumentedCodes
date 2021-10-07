#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Example:
Input :
6 3
1 2
3 4
4 5

Output :
Graph does not contain a cycle

Input :
6 4
1 2
3 4
4 5
3 5

Output :
Graph contains a cycle


*/

ll n, m;
vector<vector<ll>> adj;
bool cycle = false;
bool visited[100000] ;
ll parent[100000] = { -1};
void bfs (ll s ) {

	queue<ll> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {

		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (!visited[u]) {
				visited[u] = true;
				q.push(u);
				parent[u] = v;
			}
			else if ( parent[v] != u) {
				cycle = true;
				break;
			}
		}
	}
}

int main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	cin >> n >> m;
	adj.resize(n + 1);

	for (int i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
		}
	}
	if (cycle)
		cout << "Graph contains a cycle\n";
	else
		cout << "Graph does not contain a cycle\n";



	return 0;

}



