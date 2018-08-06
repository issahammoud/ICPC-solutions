#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

vector<int> Adj;
vector<bool> Visited;

string path;

bool BFS(int n){
	
	queue<pair<int,string>> q;
	pair<int,string> tmp;
	int first,aux;
	
	q.push({(1 << n) - 1,""});
	
	Visited[(1 << n) - 1] = true;
	
	while(!q.empty()){
		
		tmp = q.front();
		
		q.pop();
		
		for(int j = 0; j < n; j++){
			
			if(tmp.first & (1 << j)){
				
				first = tmp.first ^ (1 << j);
				
				aux = 0;
				
				for(int k = 0; k < n; k++)
					if(first & (1 << k))
						aux = aux | Adj[k];
					
				if(!Visited[aux]){
						
					Visited[aux] = true;
						
					char index = j + '0';
						
					if(aux == 0){
							
						path = tmp.second + index;
							
						return true;
						}
						
						q.push({aux,tmp.second + index});
				} 
			}
		}
	}
		
		return false;
}
int main(){
	
	int n,m;
	int a,b;

	cin >> n >> m;
	
	while(n != 0 || m!=0){
				
		for(int i = 0; i < n; i++)
			Adj.push_back(0);
		
		for(int i = 0; i < (1 << n); i++)
			 Visited.push_back(false);
		
		for(int i = 0; i < m; i++){
						
			cin >> a >> b;
			
			Adj[a] = Adj[a] | (1 << b);
			
			Adj[b] = Adj[b] | (1 << a);
		}
		
		if(m >= n)
			cout << "Impossible" << endl;
		
		else {
			
		if(BFS(n)){
			cout <<path.length() <<": " << path << endl;
			for(int i = 0; i < path.length(); i++){
				
				if(i != 0)
					cout <<" ";
				cout << path[i] - '0';
			}
				
			cout << endl;
		}
		else cout << "Impossible" << endl;
			

		}
		
		Adj.clear();
		Visited.clear();
		path = "";
		cin >> n >> m;
	}
}
