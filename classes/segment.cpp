class segmentt{
    
    private:
    vi stv,pv,lazy;
    
    void build(int l, int r, int p){
        if(l==r){
            stv[p]=pv[l];
        }
        else{
            int mid = l+(r-l)/2;n
            build(l,mid,2*p+1);
            build(mid+1,r,2*p+2);
            stv[p]=min(stv[2*p+1],stv[2*p+2]);
        }
    }
    
    int rmq(int p, int i, int j, int l, int r){
        
         if(lazy[p]!=0){
            stv[p] += lazy[p];
            if(l!=r){
                lazy[2*p+1] += lazy[p];
                lazy[2*p+2] += lazy[p];
            }
            lazy[p] = 0;
        }
        
        if(i==l && j==r) return stv[p];
        else if((i<l && j<l) || (i>r && j>r)) return INF;
        else{
            return min(rmq(2*p+1,i,j,l,(l+r)/2),rmq(2*p+2,i,j,(l+r)/2+1,r));
        }
    }
    
    void updatest(int p, int i, int j, int l, int r, int delta){
        if(lazy[p]!=0){
            stv[p] += lazy[p];
            if(l!=r){
                lazy[2*p+1] += lazy[p];
                lazy[2*p+2] += lazy[p];
            }
            lazy[p] = 0;
        }
        
        // total overlap
        if(i<=l && j>=r){
            stv[p] += delta;
            if(l!=r){
                lazy[2*p+1] += delta;
                lazy[2*p+2] += delta;
            }
            return;
        }
        else if((i<l && j<l) || (i>r && j>r)) return;
        // partial 
        updatest(2*p+1,i,j,l,(l+r)/2,delta);
        updatest(2*p+2,i,j,(l+r)/2+1,delta);
        stv[p] = min(stv[2*p+1],stv[2*p+2]);
        
    }
    
    public:
    segmentt(vi &arr){
        pv=arr;
        int n = ceil(log2(arr.size()));
        stv.assign(2*pow(2,n)-1, 0);
        lazy.assign(2*pow(2,n)-1, 0);
        build(0,arr.size()-1,0);
    }    
    int rmq(int i, int j){ return rmq(0,i,j,0,pv.size()-1); }
    //int nextpower2(int num){ return pow(2,(int)(log(num)/log(2)))==num?num:pow(2,(int)(log(num)/log(2))+1);}
    void updatest(int i, int j, int delta){
        return updatest(0,i,j,0,pv.size()-1,delta);        
    }
};
