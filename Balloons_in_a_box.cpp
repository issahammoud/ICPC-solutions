#include<iostream>
#include<algorithm>
#include <math.h> 

using namespace std;

long min(long a,long b){
	
	return (abs(a) < abs(b))?abs(a) : abs(b);
}

long min (long a,long b,long c){
	
	return (min(a,b) < abs(c))?min(a,b) : abs(c);
}
double distance(long *p1,long *p2){
	
	long sum=0;
	
	for(long i=0;i<3;i++)
		sum += (p1[i]-p2[i])*(p1[i]-p2[i]);
		
	return sqrt(sum);
}
double cube(double *p,long dim){
	
	double sum=0;
	
	for(long i=0;i<dim;i++)
		if(p[i]>0)
		sum+=p[i]*p[i]*p[i];
		
	return sum;
}
long approx(double x){
	
	if(x > 0)
	return (x-int(x) >=0.5)? int(x)+1 : int(x);
	
	
	return (abs(x-int(x)) >=0.5)? int(x)-1 : int(x);
}

void permute1(double *t,long *index,long dim){
	
	double *tmp = new double[dim];
	
	for(long i=0;i<dim;i++)
		tmp[i] = t[index[i]];
	
	for(long i=0;i<dim;i++)
		t[i] = tmp[i];	
}

void permute2(long **t,long *index,long dim){
	
	long **tmp = new long*[dim];
	
	for(long i=0; i<dim;i++)
			tmp[i]=new long[3];
	
	for(long i=0;i<dim;i++)
		for(long j=0;j<3;j++)
			tmp[i][j] = t[index[i]][j];
			
	for(long i=0;i<dim;i++)
		for(long j=0;j<3;j++)
			t[i][j] = tmp[i][j];
}
int main(){
	
	long cas = 1,n;
	long x0,y0,z0,x1,y1,z1;
	double pi = 3.1415926535897;
	double vbox,maxvol;
	long i,j;
	cin >> n;
	
	while(n!=0){
		
		cin >> x0 >> y0 >> z0;
		
		cin >> x1 >> y1 >> z1;
		
		vbox = abs(x1-x0)*abs(y1-y0)*abs(z1-z0);
		maxvol = 0;
		
		long **points = new long*[n];
		double *radius = new double[n];
		long *permutation = new long[n];
		
		for(i=0; i<n;i++)
			points[i]=new long[3];
				
		for(i=0; i<n;i++)
			for(j=0; j<3; j++)
				cin >> points[i][j];
	
		for(i=0; i<n; i++)
			radius[i] = min(min(x0-points[i][0],x1-points[i][0]),min(y0-points[i][1],y1-points[i][1]),min(z0-points[i][2],z1-points[i][2]));	
			
		for(i=0;i<n;i++)
			permutation[i]=i;
				
		do{
			double *tmp = new double[n];
				
			permute1(radius,permutation,n);
			permute2(points,permutation,n);	
			
			for(i=0;i<n;i++)
				tmp[i]=radius[i];
				
			for(i=1;i<n;i++)
				{
					for(j=i-1 ; j>=0; j--)
						{		
							if(tmp[j] > 0)
							tmp[i] = (tmp[i] < distance(points[i],points[j])-tmp[j])? tmp[i] : distance(points[i],points[j])-tmp[j];
							
						}
				}	
				
		
			if(maxvol < cube(tmp,n))
				maxvol = cube(tmp,n);

	
			
		}while(next_permutation(permutation,permutation+n));


		cout << "Box "<<cas<<": "<<approx(vbox-4*pi*maxvol/3)<< endl << endl;
		
		cas++;
		
		cin >> n;
		
	}
}
