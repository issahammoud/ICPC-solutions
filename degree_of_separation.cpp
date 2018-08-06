#include<iostream>
#include<string>
#include<map>
using namespace std;

int min(int a,int b){
	
	return (a < b)? a : b;
}

int main(){
	
	long p,r,id;
	int **dist;
	string a,b;
	map<string,int> name2id;
	int testcases = 1;
	int max;
	bool connected;
	
	cin >> p >> r;
	
	while(p!=0 || r!=0){
		
		dist = new int*[p];
		id = 0;
		max = 0;
		connected = true;
		for(int i = 0;i < p; i++)
			dist[i] = new int[p];
			
		
		for(int i = 0 ; i < p; i++)
			for(int j = 0; j < p; j++)
				dist[i][j] = (i == j)? 0 : p;
				
		for(int i = 0; i < r; i++){
			
			cin >> a >> b;
			if(name2id.count(a) == 0)
				{
					name2id[a] = id;
					id++;	
				}
				
				if(name2id.count(b) == 0)
				{
					name2id[b] = id;
					id++;
				}
				
				dist[name2id[a]][name2id[b]] = 1;
				dist[name2id[b]][name2id[a]] = 1;
		}
						
			for(int k=0; k < p; k++) // check sub-path combinations
				for(int i=0; i < p; i++)
					for(int j=0; j < p; j++) // concatenate paths
					{
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
						
						if(k == p-1 && max < dist[i][j] && dist[i][j] != p)
							max = dist[i][j];
							
						if(k == p-1 && dist[i][j] == p)
							connected = false;
					}
		
		if(!connected)
			 cout <<"Network " << testcases << ": " << "DISCONNECTED" << endl << endl;			
		else cout <<"Network " << testcases << ": " << max << endl << endl;
		
		testcases++;		
		name2id.clear();
		cin >> p >> r;
	}
	
	
}
