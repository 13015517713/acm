#include<bits/stdc++.h>
#define int long long
using namespace std; const int maxn = 4e5+10;
struct node{
    int Left,Right,val,val1;
}s[maxn<<2]; int a[maxn],n,q;
void push_up(int k){
    s[k].val=s[k<<1].val+s[k<<1|1].val;
    s[k].val1=s[k<<1].val1+s[k<<1|1].val1;
}
void build(int k,int l,int r){
    s[k].Left=l,s[k].Right=r;
    if(l==r){
        s[k].val1=a[l];
        s[k].val=a[l]*(n-l+1);
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r); push_up(k);
}
void updata(int k,int l,int r,int val){
    int L=s[k].Left,R=s[k].Right;
    if(L==R){
        s[k].val1=val;
        s[k].val=val*(n-l+1);return;
    }
    int mid=(L+R)>>1;
    if(mid>=l) updata(k<<1,l,r,val);
    if(mid<r) updata(k<<1|1,l,r,val); push_up(k);
}
int query(int k,int l,int r,int mode){
    int L=s[k].Left,R=s[k].Right;
    if(L>=l&&R<=r){
        if(mode==1) return s[k].val;
        else return s[k].val1;
    }
    int mid=(L+R)>>1;
    int res=0;
    if(mid>=l) res+=query(k<<1,l,r,mode);
    if(mid<r) res+=query(k<<1|1,l,r,mode); return res;
}
signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            int t1=query(1,l,r,1);
            int t2=query(1,l,r,2);
            cout<<t1-t2*(n-r)<<endl;
        }
        else{
            updata(1,l,l,r);
        }
    }
    return 0;
}
