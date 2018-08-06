#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	
	int nx,ny;
	double w,tmp;
	vector<double> x,y;
	bool yes;
	
	cin >> nx >> ny >> w;
	
	do{
		
		yes = true;
		
		for(int i = 0; i < nx; i++)
			{
				cin >> tmp;
					
				x.push_back(tmp);
			}
		
		
		for(int i = 0; i < ny; i++)
			{
				cin >> tmp;

				y.push_back(tmp);
			}
		
		if(nx < ny)
			{
				sort(x.begin(),x.end());
				
					
				for(int i = 0; i < nx; i++){
					
					if((i == 0 && 0 < x[i] - w/2) || (i == nx-1 && x[i] + w/2 < 75) || (i!=nx-1 && x[i] + w/2 < x[i+1] - w/2))
						{
							yes = false;
							break;
						}
			}
				
				if(yes){
					
				sort(y.begin(),y.end());	
				
				for(int i = 0; i < ny; i++){
					if((i == 0 && 0 < y[i] - w/2) || (i == ny-1 && y[i] + w/2 < 100) || (i!=ny-1 && y[i] + w/2 < y[i+1] - w/2))
						{
							yes = false;
							break;
						}	
				}
				}		
				
			}
		else 
			{
			
			sort(y.begin(),y.end());
				
				for(int i = 0; i < ny; i++){
					if((i == 0 && 0 < y[i] - w/2) || (i == ny-1 && y[i] + w/2 < 100) || (i!=ny-1 && y[i] + w/2 < y[i+1] - w/2))
						{
							yes = false;
							break;
						}	
					}
					
				
				if(yes){
				
				sort(x.begin(),x.end());
				
				for(int i = 0; i < nx; i++){
					if((i == 0 && 0 < x[i] - w/2) || (i == nx-1 && x[i] + w/2 < 75) || (i!=nx-1 && x[i] + w/2 < x[i+1] - w/2))
						{
							yes = false;
							break;
						}
					}
				}		
			}
			
		if(yes)
			cout << "YES" << endl;
		
		else cout << "NO" <<endl;
			
		x.clear();
		y.clear();
		
		cin >> nx >> ny >> w;
	}
	while(nx != 0 || ny != 0 || w != 0.0 );
	
	
}
