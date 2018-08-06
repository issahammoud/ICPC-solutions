#include <algorithm>
#include <iostream>
#include <list>
#include <iterator>
#include<vector>

using namespace std;

int main(){
	
	vector<int> vect;
	list<int> l;
	
	int dim,nb,i,j,sum;
	
	cin >> dim;
	
	for(i=0;i<dim;i++)
		{
			cin >> nb;
			vect.push_back(nb);
		}
		
	i = 0;
	j = vect.size();
	sum = 0;
	
	while(vect[i] <= 0)
		i++;
	
	while(vect[j] <= 0)
		j--;
	
	l.push_back(vect[i]);
		
	if(i != j){
		
	for(int k = i; k<j; k++)
		sum+=vect[k];
		
	if(vect[i] > vect[j] && vect[i] > sum)
		l.push_front(vect[i]);
	
	else if(vect[j] > vect[i] && vect[j] > sum)
		l.push_front(vect[j]);
		
	else if(sum > vect[i] && sum > vect[j])
		l.push_front(sum);
		
	
	
	
	}
}
