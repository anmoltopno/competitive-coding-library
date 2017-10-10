/* for any eqn in form of ax+by=c:
1. calculate x0 and y0 through extendedEuclid fun. which give (x0*a)+(y0*b) = gcd(a,b) = d
2. now multiply both side by c/gcd(a,b) or c/d. which gives ((x0*c)/d)*a + ((y0*c)/d)*b = c, now this seems like of ax + by = c having x = ((x0*c)/d) {let xi = ((x0*c)/d)} and y = ((y0*c)/d) {let yi = ((y0*c)/d)}.
3. but it is only one value, to generalize in form of n i.e. different integer value euclid proposed xn=xi+(b/d)n and yn=yi-(a/d)n.
4. now we can put xi and yi from above eqn and can calculate xn and yn according to another given constraint in question for differen value of n.*/

// function

int x0,y0,d; // global variables

void extendedEuclid(int a, int b) {
    if (b == 0) { x0 = 1; y0 = 0; d = a; return; } // base case
	extendedEuclid(b, a % b); // similar as the original gcd
	int x1 = y0;
	int y1 = x0 - (a / b) * y0;
	x0 = x1;
	y0 = y1;
}


