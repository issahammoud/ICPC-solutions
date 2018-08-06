#include<iostream>
#include<vector>
#include<string>

using namespace std;


long long int check(vector<long long int> vect){
	
	long long int count = 0, occ[3] = {1, 0, 0};
	
	for(long long int i = 0; i < vect.size(); i++)
		{
			count += occ[vect[i]];
			
			occ[vect[i]]++;
		}

	return count;
}

int main(){
	
	long long int count;

	string input;
	
	vector<long long int> sub;
	
	while(cin >> input){
		
		count = 0;
				
		long long int i = 0,j;
		
		cout << input.size() << endl;
		while(i < input.size()){
			
			j = 0; 
			while(input[i] >= '0' && input[i] <= '9' && i < input.size()){
				
				if(sub.size() == 0)
					sub.push_back((input[i] - '0')%3);
				
				else sub.push_back((sub[j-1] + (input[i] - '0'))%3);
				
				i++;
				j++;
			}
			
			if(sub.size()!= 0){
				
				count += check(sub);
				
				sub.clear();
			}
			i++;
		}
		
		cout << count << endl;
		

	}
	
	return 0;
	
}
