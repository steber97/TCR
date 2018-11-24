
vector<vi> AdjList;
vi match, vis;                                          // global variables

int Aug(int l) {                 // return 1 if an augmenting path is found
  if (vis[l]) return 0;                               // return 0 otherwise
  vis[l] = 1;
  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;                           // found 1 matching
  } }
  return 0;                                                  // no matching
}
int main() {
  int V = 5, Vleft = 3;       // V is num of vertices, Vleft are left verts
  // Build your graph with only left->right edges.
  int MCBM = 0;
  match.assign(V, -1);    // V is the number of vertices in bipartite graph
  for (int l = 0; l < Vleft; l++) {         // Vleft = size of the left set
    vis.assign(Vleft, 0);                    // reset before each recursion
    MCBM += Aug(l);
  }
  printf("Found %d matchings\n", MCBM);  // the answer
  return 0;
}
