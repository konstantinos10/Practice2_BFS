#include <iostream>
#include <exception>
#include <list>
#include <vector>
#include<queue>

using namespace std ; 


class Graph {
public:
  Graph(int n);
  void addEdge(int u, int v);
  bool hasEdge(int u, int v) const;
  int vertices() const;
  const list<int> & edges(int u) const;
};
enum state { UNVISITED, SEEN, VISITED };
void bfs_help(int u, const Graph &g,vector<int> &p, vector<state> &status) {
  queue<int> Q;
  status[u] = SEEN; Q.push(u);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop(); status[u] = VISITED;
    for (int v: g.edges(u))
    if (status[v] == UNVISITED) {
    status[v] = SEEN; p[v] = u; Q.push(v);
    }
  }
}
void bfs(const Graph &g, vector<int> &p) {
  int N = g.vertices();
  vector<state> status(N);
  for (int u = 0; u < N; ++u) {
  p[u] = -1; status[u] = UNVISITED;
  }
  for (int u = 0; u < N; ++u)
  if (status[u] == UNVISITED)
  bfs_help(u, g, p, status);
  }
