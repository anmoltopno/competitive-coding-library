struct point { double x, y;
point() { x = y = 0.0; }
point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const { 
	if (fabs(x - other.x) > EPS) 
		return x < other.x; 
		return y < other.y; }
    bool operator == (point other) const {
	return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } 
};

// pythagoras hypot
double hypot(double dx,double dy){ return sqrt(dx * dx + dy * dy);} 

//return distance b/w p1 and p2
double dist(point p1, point p2) { 
return hypot(p1.x - p2.x, p1.y - p2.y); }

double areaherons(double s1,double s2, double s3){
	double s = (s1+s2+s3)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c))
}

double perimeter(double s1, double s2, double s3){
	return s1+s2+s3;
}

/**A triangle with area A and semi-perimeter s has an inscribed circle (incircle) with radius r = A/s **/

double rInCircle(double ab, double bc, double ca) {
return areaherons(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca)); }
double rInCircle(point a, point b, point c) {
return rInCircle(dist(a, b), dist(b, c), dist(c, a)); }


 
