#include<bits/stdc++.h>
using namespace std;
#define INF 99999999;
typedef long long ll;


struct node{
	node *arr[2];
	bool end;
	node(){
		arr[0]=arr[1]=NULL;
		end=-1;
	}
};

node *root = new node();

void insert(int num){
	bitset<32> bits(num);
	string st = bits.to_string();
	node *current = root;
	for(int i=0; i<32; i++){
		int bit = st[i]-'0';
		if(current->arr[bit]==NULL){
			node *temp = new node();
			current->arr[bit]=temp;
			current = temp;
		}
		else{
			current = current->arr[bit];
		}
	}
	current->end = 1;
}

int search_max(int num){
	bitset<32> bits(num);
	string st = bits.to_string();
	string maxs="";
	node *current = root;
	for(int i=0; i<32; i++){
		int bit = st[i]-'0';
		if(current->arr[!bit]==NULL){
			current = current->arr[bit];
			maxs+=(bit+'0'); 
		}
		else{
			current = current->arr[!bit];
			maxs+=(!bit+'0');
		}
	}
	bitset<32> bitts(maxs);
	return bitts.to_ulong();
}

/********* make sure to make chk = false after every deletion ******/
bool chk = true;

void dlt(string st, int idx, node *current){
	if(idx==32){
		free(current);
		return;
	}
	int bit = st[idx]-'0';
	dlt(st,idx+1,current->arr[bit]);
	if(chk) current->arr[bit]=NULL;
	if(current->arr[!bit]==NULL && chk) free(current);
	else chk = false;
	
}

int main(){
	insert(5);
	insert(7);
	insert(11);
	bitset<32> bit(7);
	dlt(bit.to_string(),0,root);
	bit.reset();
	chk=true;
	bitset<32> bitt(11);
	dlt(bitt.to_string(),0,root);
	cout<<(2^search_max(2))<<' '<<(5^search_max(5))<<' '<<(8^search_max(8));
}

