struct point_i { int x, y; 
point_i() { x = y = 0; } 
point_i(int _x, int _y) : x(_x), y(_y) {} };

int insideCircle(point_i p, point_i c, int r) { // all integer version
int dx = p.x - c.x, dy = p.y - c.y;
int Euc = dx * dx + dy * dy, rSq = r * r; // all integer
return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; } //inside 0 /border 1 /outside 2

double chordlength(int r, double theta){
	return 2.0*(double)r*sin(theta/2);
}

double arclength(double theta){
	return (PI/360.0)*theta;
}

/*** given two points and radius, there are two circles can be drawn through the points ***/
// to get the other center, reverse p1 and p2

bool circle2PtsRad(point p1, point p2, double r, point &c) {
double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
(p1.y - p2.y) * (p1.y - p2.y);
double det = r * r / d2 - 0.25;
if (det < 0.0) return false;
double h = sqrt(det);
c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
return true; } // to get the other center, reverse p1 and p2
