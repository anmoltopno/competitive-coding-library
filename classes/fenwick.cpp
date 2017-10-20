class BIT {
private: vector<int> ft; 

public: BIT(int n){
	 ft.assign(n + 1, 0); 
	} 

int rmq(int b) { 
	int sum = 0; 
	for (; b; b -= (b)&(-b)) 
		sum += ft[b];	
	return sum;
}

int rmq(int a, int b) { 

	return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); 
}

void update(int k, int delta) { 

	for (; k < (int)ft.size(); k += (k)&(-k)) ft[k] += delta; }

};
