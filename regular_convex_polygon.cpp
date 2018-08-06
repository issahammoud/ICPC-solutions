#include<iostream>
#include<string>
#include <iomanip>
#include<math.h>
#include <fstream>

#define eps 0.000001

using namespace std;

typedef struct point{
	
	double x,y;

} point;


double distance(point p1,point p2){
	
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double angle(point p1,point p2,point p3){
	
	double a = distance(p2,p3), b = distance(p1,p2), c = distance(p1,p3);
	
	return acos((b*b + c*c - a*a)/(2*b*c));
}


double gcd(double x, double y)
{
	
	if(fabs(x-y) < eps) y = x;
	
    return fabs(y) < eps ? x : gcd(y, fmod(x, y));
}


int main(){
	
	string x,y;
	
	point p1,p2,p3;  
	
	cin >> x;
	
	while(x!="END"){
		
		cin >> y;
		
		p1.x = stod(x);
		
		p1.y = stod(y);
						
		cin >> x >> y;

		p2.x = stod(x);
		
		p2.y = stod(y);
						
		cin >> x >> y;
		
		p3.x = stod(x);
		
		p3.y = stod(y);
		
		double arc1 = angle(p1,p2,p3), arc2 = angle(p2,p1,p3), arc3 = angle(p3,p1,p2);
		
		double factor = gcd(arc1,gcd(arc2,arc3));
		
		cout << round(3.1415926535/factor) << endl;
			
		cin >> x;
		
	}
}
