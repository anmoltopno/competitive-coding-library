
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
 
// returns the area, which is half the determinant
double area(const vector<point> &P) {
double result = 0.0, x1, y1, x2, y2;
for (int i = 0; i < (int)P.size()-1; i++) {
x1 = P[i].x; x2 = P[i+1].x;
y1 = P[i].y; y2 = P[i+1].y;
result += (x1 * y2 - x2 * y1);
}
return fabs(result) / 2.0; }

bool isConvex(const vector<point> &P) { // returns true if all three
int sz = (int)P.size(); // consecutive vertices of P form the same turns
if (sz <= 3) return false; // a point/sz=2 or a line/sz=3 is not convex
bool isLeft = ccw(P[0], P[1], P[2]); // remember one result
for (int i = 1; i < sz-1; i++) // then compare with the others
if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
return false; // different sign -> this polygon is concave
return true; }
