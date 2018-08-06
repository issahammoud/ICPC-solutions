#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

int main(){
	
	long p,nb;
	int c,i,j=1;
	long min;
	char command;
	list<long> l;
	
	
	cin >> p >> c;
	
	while(p!=0 || c!=0){
		
	cout << "Case " <<j<<":"<<endl;
	min = (p < c) ? p : c;
	
	
	for(i = 0;i < min; i++)
		l.push_back(i+1);
		
	
	for(i = 0;i < c; i++){
		
		cin >> command;
		
		if(command == 'N'){
			

			cout << l.front() <<endl;
			
			l.push_back(l.front());
			
			l.pop_front();
		}
		else {
			
			cin >> nb;
			
			l.remove(nb);
			l.push_front(nb);
		}	
	}
	
	cin >> p >> c;	
	j++;
	l.clear();
	prior.clear();
}
}
