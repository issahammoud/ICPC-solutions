#include<iostream>
#include<vector>
#include <bitset>
#include <math.h> 
#include<algorithm>

#define pmax 100000

using namespace std;

vector<double> premiers;

void generate(){
	
	bitset<10000001> P;
	
	P.set(); // initialisation
	
	P[0] = P[1] = 0;
	
	for (long long i = 2; i < pmax; i++)
		
		if (P[i]) {
		
			for (long long j=i*i; j < pmax; j+=i)
				
				P[j]=0;
				
			premiers.push_back(i);
		}
	}

long long nearest_prime(double p,bool mode){
	
	long low = lower_bound(premiers.begin(),premiers.end(),p) - premiers.begin();
	
	if(low - 1 < 0) return -1;
	
	if(mode && p == premiers[low]) return (long long)(p);

	return premiers[low- 1];
}


int main(){
	
	long long m,a,b;
	long long p,q;
	long long x,y;
	long long max;
 
	generate();
	cin >> m >> a >> b;
	
	while(m!=0 || a!=0 || b!=0)
	{
		
		x = y = nearest_prime(sqrt(m),true);
		p = q = x;
		max = p*q;

		y = nearest_prime(double(m/(x*1.0)),true);
		
		while(a*y <= x*b && x != -1 && y != -1){
			

			if(max < x*y && x*y <= m)
			{
				p = x;
				q = y;
				max = p*q;
			}
			
			x = nearest_prime(x,false);
			y = nearest_prime(double(m/(x*1.0)),true);
		}
		
		cout << p << " "<< q << endl;
		
		cin >> m >> a >> b;
		
		
	}
	return 0;
}
