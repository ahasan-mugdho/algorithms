#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll  mx=2e5+123;
vector<ll> a(mx);
vector<ll> tree(mx*2+123);
vector<ll> prop(mx*2+123,0);
void init(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=a[b];
        //tree[node].prop=0;
        return ;
    }
    ll left=node*2;
    ll right=(node*2)+1;
    ll mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    //tree[node].prop=0;
}
void update(ll node,ll b,ll e,ll i,ll j,long long x)
{
    if(b>j||e<i)
        return;
    if(b>=i&&e<=j)
    {
        tree[node]+=(e-b+1)*x;
        prop[node]+=x;
        return;
    }
    ll left=node*2;
    ll right=(node*2)+1;
    ll mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node]=tree[left]+tree[right]+(e-b+1)*prop[node];
}
long long int query(ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if(b>j||e<i)
        return 0;
    if(b>=i&&e<=j)
        return tree[node]+carry*(e-b+1);
    ll left=node*2;
    ll right=(node*2)+1;
    ll mid=(b+e)/2;
    long long int p1=query(left,b,mid,i,j,carry+prop[node]);
    long long int p2=query(right,mid+1,e,i,j,carry+prop[node]);
    return p1+p2;
}
int main()
{
    optimize();
    long long int n,q,i,u,k,temp,a1,b;
    cin>>n>>q;
    for(i=1;i<=n;i++)
        cin>>a[i];
    init(1,1,n);
    for(i=0;i<q;i++)
    {
        cin>>temp;
        if(temp==1)
        {
            cin>>a1>>b>>u;
            update(1,1,n,a1,b,u);
        }
        else
        {
            cin>>k;
            cout<<query(1,1,n,k,k,0)<<endl;
        }
    }
    return 0;
}
