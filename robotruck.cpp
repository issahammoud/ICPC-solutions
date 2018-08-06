#include<iostream>
#include<vector>

using namespace std;

int distance(int x0,int y0,int x1,int y1){
	
	return abs(x0-x1)+abs(y0-y1);
}
int main(){
	
	vector<int> cump,cumd,dynamic,x,y;
	int testcases;
	int n,c;
	int tmp1,tmp2,tmp3;
	cin >> testcases;
	
	while(testcases){
		
		
		cin >> c >> n;
		
		cumd.push_back(0);
		cump.push_back(0);
			
		x.push_back(0);
		y.push_back(0);
	
		dynamic.push_back(0);
		
		for(int j = 1; j <= n; j++){
			
			cin >> tmp1 >> tmp2 >> tmp3;
			
			x.push_back(tmp1);
			y.push_back(tmp2);
			
			cumd.push_back(cumd[j-1] + distance(x[j],y[j],x[j-1],y[j-1]));
			cump.push_back(tmp3+cump[j-1]);
			
			dynamic.push_back(0);
		}
		
		for(int j = 1; j <= n; j++)
			for(int k = j; k > 0; k--){
						
						if(cump[j] - cump[k-1] > c)
							break;
							
						int dist = x[j] + y[j] + x[k] + y[k] + cumd[j] - cumd[k];
						
						if(k == j) dynamic[j] = dynamic[k-1] + dist;
						
						else dynamic[j] = (dynamic[j] < dynamic[k-1] + dist)? dynamic[j] : dynamic[k-1] + dist;
				
			}
			
			cout << dynamic[n] << endl;
			
			if(testcases != 1) cout <<endl;
			testcases--;
			cump.clear();
			cumd.clear();
			x.clear();
			y.clear();
			
	}
}
