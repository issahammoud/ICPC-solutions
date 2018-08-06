#include<iostream>
#include<vector>
#include <limits>
#include <iomanip>
#include<math.h>
#include<algorithm>
#define INF std::numeric_limits<double>::max() 
#define eps 1e-06
#include<fstream>
using namespace std;


typedef struct point{
	
	double x,y;
	
	bool operator<(const point& a) const
    {
    	
    	if(x < a.x)
    		return true;
    	if(x == a.x)
    		return y < a.y;
    		
        return false;
    }

} point;

double dist2(point p1,point p2){
	
	return double((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

point vectdir(point p1,point p2){
	
	point p;
	
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;

	
	return p;
}

double norme(point p){
	
	return double(sqrt(p.x*p.x + p.y*p.y));
}

double vectoriel(point p, point p1, point p2) {
    
	return double((p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x));
}

double dist2droit(point p, point p1,point p2){
	
	point dir = vectdir(p1,p2);
	
	return double(fabs(vectoriel(p1,p,p2))/norme(dir));
}


vector<point> toconvex(vector<point> pts){
    
	int n = pts.size(),k = 0; 
	
	vector<point> vect;
    
	point p;
    p.x = p.y = 0;
    
    for(int i = 0; i < 2*n; i++)
    	vect.push_back(p);
    	
    sort(pts.begin(), pts.end());
    
    for(int i = 0; i < n; i++){
        while(k >= 2 && vectoriel(vect[k - 2], vect[k - 1] , pts[i]) <= 0) k--;
        vect[k++] = pts[i];
    }

    for(int i = n - 2, t = k + 1; i >= 0; i--){
        while(k >= t && vectoriel(vect[k - 2], vect[k - 1] , pts[i]) <= 0) k--;
        vect[k++] = pts[i];
    }
    vect.resize(k);
	return vect;
}

int main(){
	
	int n,testcases = 1;
	point p;
	vector<point> pts;
	
	cin >> n;
	
	while(n!=0){
		
		pts.clear();
		
		for(int i = 0; i < n; i++){
			
			cin >> p.x >> p.y;
			
			pts.push_back(p);
		}
	

	pts = toconvex(pts);
	
	double result = INF;
	
	for(int i = 0; i < pts.size() - 1; i++) {
            
			double max = 0;
            
			for(int j = 0; j < pts.size(); j++)
                max = (max < dist2droit(pts[j],pts[i],pts[i+1])) ? dist2droit(pts[j],pts[i],pts[i+1]) : max;
             
			   
            result = (result > max) ? max : result;
        }
	

	cout << "Case " << testcases << ": " << fixed << setprecision(2) << result << endl;
	testcases++;
	cin >> n;	
		
	}
}
