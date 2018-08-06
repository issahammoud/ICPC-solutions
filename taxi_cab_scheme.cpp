#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

#define NIL 0
#define INF 0x3f3f3f3f

vector<pair<int,int>> X, Y;

vector<int> Adj[501];

int PairX[501];

int PairY[501];

unsigned int Dist[501];

map<pair<int,int>,int> node2id;
bool BFS() {
	
	queue<int> Q;

	Dist[NIL] = INF;

	for(int i = 1; i < X.size()+1; i++) { // start from nodes that are not yet matched
		
		Dist[i] = (PairX[i] == NIL) ? 0 : INF;
		
		if (PairX[i] == NIL)
		
		Q.push(i);
	}

	while (!Q.empty()) { // find all shortest paths to NIL
	
	int x = Q.front(); 
	
	Q.pop();
	
	if (Dist[x] < Dist[NIL]) // can this become a shorter path?

		for (auto y : Adj[x])

			if (Dist[PairY[y - X.size()]] == INF) {

				Dist[PairY[y - X.size()]] = Dist[x] + 1; // update path length
				
				Q.push(PairY[y - X.size()]);
			}
			
		}
	
	
	return Dist[NIL] != INF; // any shortest path to NIL found?
	}

bool DFS(int x) {
	
	if (x == NIL)
		
		return true; // reached NIL
	
	for (auto y : Adj[x])
	
		if (Dist[PairY[y - X.size()]] == Dist[x] + 1 && DFS(PairY[y - X.size()])) { // follow trace of BFS
			
			PairX[x] = y; // add edge from x to y to matching
			
			PairY[y - X.size()] = x;
			
			return true;
		}
	
	Dist[x] = INF;
	
	return false; // no augmenting path found
	}

int HopcroftKarp() {
	
	fill_n(PairX, X.size()+1, NIL); // initialize: empty matching
	
	fill_n(PairY, Y.size()+1, NIL);
	
	int Matching = 0; // count number of edges in matching
	
	while (BFS()) { // find all shortest augmenting paths

		for(int i = 1; i < X.size()+1; i++) // update matching cardinality

			if (PairX[i] == NIL && DFS(i)) // does an augmenting path start at x?
				Matching++;
				
			
			}

		return Matching;
	}

int main(){
	
	int testcases;
	int n;
	vector<int> time,dist;
	int a,b,c,d,h,m;
	
	cin >> testcases;
	
	while(testcases){
		
		cin >> n;
		int id = 0;
		
		for(int i = 0; i < n; i++){
			
			scanf("%d:%d %d %d %d %d",&h,&m,&a,&b,&c,&d);
			
			X.push_back({c,d});
				
			Y.push_back({a,b});
			
			
			time.push_back(h*60 + m);
			dist.push_back(abs(a-c) + abs(b-d));
		}
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				
				int passage = abs(X[i].first - Y[j].first) + abs(X[i].second - Y[j].second);
				
				if (time[j] > time[i] + dist[i] + passage) 
					Adj[i+1].push_back(j+1+n);
			}
			
			cout << n - HopcroftKarp() << endl;
			
			X.clear();
			Y.clear();
			time.clear();
			dist.clear();
			for(int i =0; i < 500; i++)
				Adj[i].clear();
			
			testcases--;
	}
	
}
