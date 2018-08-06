#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

bool toRight(long *p,int m,int k, long th){
	
	int count = 0;
	
	long cum=0;
	
	for(int i=0;i<m-1;i++){
		
		cum+=p[i];
		
		if(cum+p[i+1] > th)
			{
				count++;
				cum = 0;	
			}
	}
	
	return count >= k;
}

long dichotomie(long g,long d,long *p,int m,int k){
	
	long th;
	
	while(d-g !=1 && d!=g){
		
		th = (d-g)/2 +g;
		if(toRight(p,m,k,th)) g=th;
		else d = th;
	}
	
	if(g==d) return d;
	
	if(toRight(p,m,k,g)) return d;
	
		return g;
}

int main(){
	
	int testcases;
	int m,k,id;
	long long threshold,cum;
	long *pages;
	double max;
	vector<long> value;
	vector<int> index;
	cin >> testcases;
	
	while(testcases!=0){
	
	cin >> m >> k;
	threshold = 0;
	max =0;
	id = 0;
	pages = new long[m];
	
	for(int i=0; i<m;i++){
		
		cin >> pages[i];
		cum+=pages[i];
		
		if(pages[i] > max)
			max = pages[i];
	}
	
	threshold = dichotomie(max,cum,pages,m,k);
	
	cum=0;
	k--;
	for(int i = m-1; i>=0;i--){
		
		cum+=pages[i];
		
		if(cum > threshold || (k > i && k>=1) ){
			
			k--;
			id++;
			
			cum=pages[i];
		}
			
		value.push_back(pages[i]);
		index.push_back(id);
	}
	
	for(int i = m-1; i > 0 ; i--){
		
		cout << value[i];
	
		if(index[i] != index[i-1])
			cout << " / ";
		
		else cout << " ";
	}
	
	cout << value[0] << endl;

	value.clear();
	index.clear();
	
	testcases--;
}
}
