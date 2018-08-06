#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include <fstream>
using namespace std;

set<int> Adj[51]; 
vector<int> Circuit;
vector<int> save[51];


int main(){
	
	int testcases;
	int occ[51];
	int occu[51][51];
	int n,a,b;
	bool lost,self;
	int adjnb;
	int v;
	
	cin >> testcases;
	
	for(int i = 0; i < testcases; i++){
		
		cin >> n;
		
		int count = 0;
		lost = false;
		for(int j = 0; j < 51; j++)
			{
				Adj[j].clear();
				occ[j] = 0;
			
				for(int k = 0; k < 51; k++)
					occu[j][k] = 0;
			}
		
		for(int j = 0; j < n; j++){
			
			
			cin >> a >> b;
			
			occ[a]++;
			occ[b]++;
			Adj[a].insert(b);
			Adj[b].insert(a);
			
			occu[a][b]++;
			
			if(a!=b)
			occu[b][a]++;
		}
		
		
					
		for(int j = 1; j < 51; j++)
			if(occ[j]%2 == 1)
				{
					cout << "Case #" << i+1 << " \n" <<"some beads may be lost" << endl;
					lost = true;
					break;	
				 } 
		

		if(!lost){
				
			
			v = a;
			
			stack<int> Stack;
			
			Stack.push(v);
			
			while (!Stack.empty()) {
				
				if (!Adj[v].empty()) { // follow edges until stuck
					
					Stack.push(v);
					
					int tmp = *Adj[v].begin();
					
					occu[v][tmp]--;
					if(tmp != v)
					occu[tmp][v]--;
						
					Adj[v].erase(tmp); // remove edge, modifying graph
					
					Adj[tmp].erase(v);
					
						if(occu[v][tmp] != 0)
							{
								Adj[v].insert(tmp);
								Adj[tmp].insert(v);
							}
					
					v = tmp;
					
									} 
				else { 						// got stuck: stack contains a circuit
					
					Circuit.push_back(v); 	// append node at the end of circuit
					
					v = Stack.top(); 		// backtrack using stack, find larger circuit
					
					Stack.pop();
					}
			}
			
			cout << "Case #" << i+1 << endl;

			


			for(int j = 0; j < Circuit.size()-1; j++)
					cout << Circuit[j] << " " << Circuit[j+1] << endl;
								
				
			Circuit.clear();
			for(int j = 0; j < 51; j++)
				save[j].clear();
		}
		
		if(i!= testcases-1)
			cout << endl;
	}
		
		
}	

