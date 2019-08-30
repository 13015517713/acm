#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
   扩展欧几里得模板
*/
ll x,y;
ll gcd(ll xx,ll yy){
    if(yy==0) return xx; return gcd(yy,xx%yy);
}
void ou(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;return;
    }
    ou(b,a%b,y,x);
    y-=a/b*x;return;
}
int main(){
    ll xx,yy,m,n,L;
    scanf("%lld%lld%lld%lld%lld",&xx,&yy,&m,&n,&L);
    ll s1=(m-n),s2=L,s3=yy-xx;
    if(s1<0){
        s1=-s1,s3=-s3;
    }
    ll gc=gcd(abs(s1),abs(s2));
    if(s3%gc!=0){
        return puts("Impossible"),0;
    }
//    cout<<s1<<"  "<<s2<<endl;
    ou(s1,s2,x,y);
    ll t=s3/gc;
    ll ans=((x*(t))%(s2/gc)+(s2/gc))%(s2/gc);
    printf("%lld\n",ans);
    return 0;
}
