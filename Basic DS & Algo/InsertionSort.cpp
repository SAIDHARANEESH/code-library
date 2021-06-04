#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using ll = long long;

// debugging code
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

//start coding from here after input

void solve() {

  

  cout << '\n';
}

int main() {
    
  FASTIO;
    
  //read input from here
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
      cout << "Case #" << i << ": ";
      solve();
  }

  return 0;
}