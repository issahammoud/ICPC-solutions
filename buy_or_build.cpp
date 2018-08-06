#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<math.h>

#define INF 0x3f3f3f3f
using namespace std;

vector<pair<long,long>> coord;

vector<long> built[8];

vector<pair<long, pair<long, long>>> Edges;

vector<pair<long, pair<long, long>>> exEdges;

map<long, pair<long, unsigned long>> Sets;

set<pair<long, pair<long, long>>> A; // Final minimum spanning tree

	void MakeSet(long x) {
		
		Sets.insert(make_pair(x, make_pair(x, 0)));
	}
	
	long Find(long x) {
		
		if (Sets[x].first == x) return x; // Parent == x ?
		
		else return Sets[x].first = Find(Sets[x].first); // Get Parent
	}
	
	void Union(long x, long y) {
		
		long parentX = Find(x), parentY = Find(y);
		
		long rankX = Sets[parentX].second, rankY = Sets[parentY].second;
		
		if (parentX == parentY) return;
		
		else if (rankX < rankY)
			
			Sets[parentX].first = parentY;
		
		else
			
			Sets[parentY].first = parentX;

		if (rankX == rankY)
			
			Sets[parentX].second++;
	}
	
	long Kruskal(long n, vector<pair<long, pair<long, long>>> exEdges,long cum,long min) {

		for(long u=1; u <= n; u++)

		MakeSet(u); // Initialize Union-Find
		
		
		for(auto tmp : exEdges) {
			
			auto edge = tmp.second;
			
			if (Find(edge.first) != Find(edge.second)) {
				
				Union(edge.first, edge.second); // update Union-Find
				
//				A.insert(tmp); // include edge in MST
			}
		}
		
		for(auto tmp : Edges) {
			
			auto edge = tmp.second;
			
			if (Find(edge.first) != Find(edge.second)) {
				
				Union(edge.first, edge.second); // update Union-Find
				
//				A.insert(tmp); // include edge in MST
				
				cum+=tmp.first;
				
				if(cum > min) return min;

			}
		}
		
		return cum;
	}

	long Weight(long i,long j){
		
		return (coord[i].first - coord[j].first)*(coord[i].first - coord[j].first) + (coord[i].second - coord[j].second)*(coord[i].second - coord[j].second);
	}	
	
	void FillEdges(long n){
		
		pair<long, pair<long, long>> tmp;
		
		for(long i = 0; i < n - 1; i++)
			for(long j = i+1; j < n; j++)
				{
					tmp.first = Weight(i,j);
					tmp.second.first = i+1;
					tmp.second.second = j+1;
					
					Edges.push_back(tmp);
				}
	}
	


int main(){
	
	long testcases;
	long n,q;
	long *permut = nullptr;
	vector<long> *permutations = nullptr;
	
	cin >> testcases;
	
	for(int cas = 0; cas < testcases; cas++){
		
		
		cin >> n >> q;
		
		long min = INF;
		long tmp,tmp2;
		permut = new long[q];
		long nbperm = pow(2,q);
		permutations = new vector<long>[nbperm];
		
		for(long i = 0; i < q; i++)	
			{
				permut[i] = i;
				
				cin >> tmp;
				
				for(long k = 0; k <= tmp; k++)
					{
						cin >> tmp2;
						built[i].push_back(tmp2);
					}
			}
			
		for(long i = 0; i < n; i++)
			{
				cin >> tmp >> tmp2;
				coord.push_back(make_pair(tmp,tmp2));
			}
		
		for(long s = 1; s < (1 << q); s++)
			for(long e = 0; e < q; e++)
				if(s & (1 << e))
					permutations[s].push_back(permut[e]);
	
		FillEdges(n);
		
		sort(Edges.begin(), Edges.end()); // Sort edges by weight

		for(long i = 0; i < nbperm; i++){
			
			long cum = 0;	
			
			for(auto el : permutations[i]){
				for(long j = 1; j < built[el].size() - 1; j++)
					{
						
						long a = built[el][j];
						long b = built[el][j+1];
						
						exEdges.push_back(make_pair(0,make_pair(a,b)));
					}
					
				cum += built[el][0];
				}
		
		if(cum < min)
		{
			cum = Kruskal(n,exEdges,cum,min);
			
			if(min > cum)
			min = cum;
		}
			


		Sets.clear();
		exEdges.clear();
		
		}
		
		Edges.clear();
		coord.clear();
		for(long i = 0; i < nbperm; i++)
			permutations[i].clear();
		
		for(long i = 0; i < 8; i++)
			built[i].clear();
		
		delete [] permutations;
		delete permut;
		permut = nullptr;
		permutations = nullptr;
			
		cout << min << endl;
				
		if(cas != testcases- 1)
			cout << endl;
			
	}
}
	
