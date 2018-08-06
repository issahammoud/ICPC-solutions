#include<iostream>
#include<math.h>

using namespace std;


// second method
unsigned long long ones2(long double n){
	
	if(n == 0) return 1;	
	return 2*ones2(n-1) + pow(2,n-1);
}


unsigned long long ones(long long x, long double y){
		
	return (unsigned long long)(x*(1+ y/2.0));
}
long long max(long long a, long long b){
	
	return (a > b)? a : b;
}
long long borders( long long p, long long n){
	
	 long long cum = p;
	 long long power = pow(2,n);

	
	for(long long i = 1; i < power; i*=2){
		
		
		long long k = p/(2*i);
		
		cum+= k*i + max(0, p - (2*k +1)*i); 
	}
	
	return cum;
}
int main(){
	
	unsigned long long A,B;
	unsigned long long a,b;
	long long cum;
	
	
	while(cin >> A >> B){
		
		cum = 0;
		
		a = (A == 0)? 0 : (long long)floor(log2(A));
		b = (B == 0)? 0 : (long long)floor(log2(B));
		for(long i = a; i < b ; i++){
			
			cum += ones((long long)pow(2,i),i);

//second method
//			cum += ones2(i);

		}
				
		unsigned long long tmp = (A == 0)? 0 :A - (long long)pow(2,a);
		
		cum -= (tmp == 0)? 0 : borders(tmp,a);
				
		tmp = (B == 0)? 0 : B+1 - (long long)pow(2,b);

		cum += (tmp == 0)? 0 : borders(tmp,b);
		
		cout << cum << endl;
				
	}
	
	
}
