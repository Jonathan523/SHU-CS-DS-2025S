#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

vector<int> g[100];
int in[100];
vector<int> tp;
stack<int> s;
bool state[100];
int NodeNumber, EdgeNumber;

void build() {
  // cout << "请输入有向无环图的结点数和边数：";
  cin >> NodeNumber >> EdgeNumber;
  // cout << "请依次输入边：" << '\n';
  for (int i = 0; i < EdgeNumber; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    in[y]++;
  }

  for (int i = 0; i < NodeNumber; i++) {
    state[i] = false;
  }
}

void dfs(int x) {
  state[x] = true;

  for (int i = 0; i < g[x].size(); i++) {
    int nextnode = g[x][i];
    if (!state[nextnode]) {
      dfs(nextnode);
    } else {
      continue;
    }
  }

  s.push(x);
}

void tpsort() {
  for (int i = 0; i < NodeNumber; i++) {
    if (in[i] == 0) {
      dfs(i);
    }
  }
}

int main() {
  build();
  tpsort();
  if (s.size() < NodeNumber) {
    cout << "原图中有环";
  }

  for (int i = 0; i < NodeNumber; i++) {
    cout << s.top() << ' ';
    s.pop();
  }


}