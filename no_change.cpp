#include<iostream>
#include<vector>

using namespace std;


int main(){
	
	vector<int> nb;
	int size,x,i,j,k,tmp;
	int testcase;
	
	cin >> testcase;
	
	for(int cas = 0; cas < testcase; cas++){
		
	cin >> x >> size;
	
	if(x ==0 && size ==0)
		cout <<"YES" <<endl<<endl;
	else {
		
	
	for(i=0; i < size; i++)
	{
		cin >> tmp;
			
		if(i==0)
		nb.push_back(tmp);
		
		else nb.push_back(tmp+nb[i-1]);	
	}
	
	if(nb.back()==0){
		cout <<"NO" <<endl<<endl;
	}
		
	else {
	
	bool dynamic[size][x+1];

					
	for(i = 0; i < size; i++){
		for(j = 1; j <= x; j++){
		
				
		if(j%nb[i] == 0 || (i!=0 && dynamic[i-1][j] == true) || (i!=0 && j-nb[i] > 0 && dynamic[i][j-nb[i]] == true))
		 	dynamic[i][j] = true;
		
		else  dynamic[i][j] = false;
			
	}
	}

	if(dynamic[size-1][x] == true)
		cout << "YES" << endl;
	

	else cout << "NO" << endl;
	
	if(cas != testcase-1)
	cout << endl;
}
	nb.clear();
	
}
}
return 0;
}




