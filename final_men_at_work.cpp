#include<iostream>
#include<queue>
#include<conio.h>
using namespace std;

typedef struct t{
	
	int x,y,t;
} triplet;

bool isValid(char sym[50][50], int w[50][50],triplet u, int n){
	
	return u.x >= 0 && u.x < n && u.y >=0 && u.y < n && ((sym[u.x][u.y] == '.' && (w[u.x][u.y] == 0 || (u.t/w[u.x][u.y])%2 == 0 ))|| (sym[u.x][u.y] == '*' && w[u.x][u.y] !=0 && ((u.t)/w[u.x][u.y])%2 == 1));
	
}

void BFS(triplet root, int n, bool Visited[50][50][50],int w[50][50],char sym[50][50]){
	
	queue<triplet> Q;
	triplet tmp,u = root;
	
	Q.push(root);
	
	while (!Q.empty() && u.t < 1000) {
	
		u = Q.front();
	
		Q.pop();
		
			
		if (!Visited[u.x][u.y][u.t]){
		
		Visited[u.x][u.y][u.t] = true;
	
		tmp.x = u.x;
		tmp.y = u.y;
		tmp.t = u.t+1;
			
		if(isValid(sym,w,tmp,n))
				Q.push(tmp);
			
			
		tmp.x = u.x;
		tmp.y = u.y-1;
		tmp.t = u.t+1;
		if(isValid(sym,w,tmp,n))	
			Q.push(tmp);
		
		
		tmp.x = u.x;
		tmp.y = u.y+1;
		tmp.t = u.t+1;
		if(isValid(sym,w,tmp,n))
			Q.push(tmp);
		
			tmp.x = u.x-1;
			tmp.y = u.y;
			tmp.t = u.t+1;
		if(isValid(sym,w,tmp,n))
			Q.push(tmp);
		
			tmp.x = u.x+1;
			tmp.y = u.y;
			tmp.t = u.t+1;	
		if(isValid(sym,w,tmp,n))
			Q.push(tmp);
		
		
		if(u.x == n-1 && u.y == n-1)
			break;
		}
	}
	
	if(u.x != n-1 || u.y != n-1 || u.t == 1000)
		cout <<"NO" <<endl;
	else cout << u.t << endl;
	
}

int main(){
	
	
	int n;
	int count = 0;
	cin >> n;
	
	while(scanf("%d",&n)){
		
		if(count!=0) cout << endl;
		
		count++;
		
		int w[50][50];
		char sym[50][50],tmp;
		bool visited[50][50][50];
		
		for(int i = 0; i < 50; i++)
			for(int j = 0; j < 50; j++)
			{
				sym[i][j] = ' ';
				w[i][j] = 0;
				
				}
					
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> sym[i][j];
				
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				{
					cin >> tmp;		
					w[i][j] = tmp - '0';
				}


		for(int i = 0; i < 50; i++)
			for(int j = 0; j < 50; j++)
				for(int k = 0; k < 50; k++)
					visited[i][j][k] = false;
						
		triplet root;
		root.x = root.y = root.t = 0;
		
		BFS(root,n,visited,w,sym);
		
	
	}
}
