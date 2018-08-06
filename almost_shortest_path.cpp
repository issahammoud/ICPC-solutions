#include<iostream>
#include<vector>

#define INF 0x3f3f3f3f

using namespace std;

void savePath(vector<int> *parent, int j,int **graph,int src)
{
     if(j != src)
    for(int i = 0; i < parent[j].size(); i++)
    	{
    		
    		graph[parent[j][i]][j]  = 0;
			savePath(parent,parent[j][i],graph,src);	
		}
}

 

int minDistance(int dist[], bool sptSet[], int V)
{
     

    int min = INF, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

// source https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/
void dijkstra(int **graph, int src,int V, int d)
{
	
	int dist[V]; 
 	vector<int> t;
    bool sptSet[V];

    vector<int> parent[V];


    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        sptSet[i] = false;
    }
 
    dist[src] = 0;
 

    for (int count = 0; count < V ; count++)
    {
        int u = minDistance(dist, sptSet,V);
 
        sptSet[u] = true;
 
        for (int v = 0; v < V; v++){
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {	
            	parent[v].clear();
                parent[v].push_back(u);
                dist[v] = dist[u] + graph[u][v];
                
            }
            else if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] == dist[v])
            		
            			parent[v].push_back(u);
					
		}
		
    }
    
	savePath(parent,d,graph, src);
	
}

void dijkstra2(int **graph, int src,int V,int d)
{
     int dist[V];    
     bool sptSet[V]; 

     for (int i = 0; i < V; i++)
        dist[i] = INF, sptSet[i] = false;
  

     dist[src] = 0;
  
     
     for (int count = 0; count < V-1; count++)
     {
    
       int u = minDistance(dist, sptSet,V);
  
       sptSet[u] = true;
  
       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
  	int value = (dist[d] == INF) ? -1 : dist[d];
     cout << value << endl;
}
int main(){
	
	int n,m,s,d;
	int x,y,z;
	
	int **graph;
	
	cin >> n >> m;
	
	while(n!=0 && m!=0){
	
	cin >> s >> d;
	graph = new int*[n];
	
	for(int i = 0;i < n; i++)
		graph[i] = new int[n];
		
	for(int i = 0;i < n; i++)
		for(int j = 0; j < n; j++)
			graph[i][j] = 0;
				
	for(int i = 0; i < m; i++){
		
		cin >> x >> y >> z;
		
		graph[x][y] = z;
	}

	
 	
    dijkstra(graph, s,n,d);
    dijkstra2(graph, s,n,d);
    
    cin >> n >> m ;
	}
}
