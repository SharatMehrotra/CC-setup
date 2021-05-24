#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define ui unsigned ll
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0)
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define f first
#define INF pow(10,14)+7
//#define s second
ll N=300000;
vector<bool>visited(N+1,false);
//bool visited[505][505];
// use ((x%n)+n)%n when x can be negative
bool isprime(ll x)
{
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i ==0 ) return false;
    }
    return true;
}
void findfact (ll x,map<ll,vector<ll>>&m)
{
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            if(i==x/i) m[x].push_back(i);
            else
            {
                 m[x].push_back(i);
                 m[x].push_back(x/i);
            }
            break;
        }
    }
    return;
}
struct cmp{
    bool operator() (const pair<ll,ll>& a, const pair<ll,ll>& b){
        if(a.f>b.f) return false;
        else if(a.f<b.f) return true;
        if(a.second<b.second) return false;
        return true; 
    }
};
bool isPalindrome(string t)
{
    ll st=0;
    ll end=t.size()-1;
    while(st<=end)
    {
        if(t[st]!=t[end]) return false;
        st++;
        end--;
    }
    return true;
}
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
bool pow2 (ll x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
} 
/*void dfs(vector<vector<char>>&s,ll i,ll j,ll n,ll m,ll &t,ll k,ll count)
{
    if(i<0||j<0||i==n||j==m||visited[i][j]||s[i][j]=='#'||t>=count-k)
    return;
    visited[i][j]=true;
    s[i][j]='*';
    t++;
    if(i>=1) dfs(s,i-1,j,n,m,t,k,count);
    if(j>=1) dfs(s,i,j-1,n,m,t,k,count);
    if(i<n-1) dfs(s,i+1,j,n,m,t,k,count);
    if(j<m-1) dfs(s,i,j+1,n,m,t,k,count);
}*/
ull factorial(ull n) 
{ 
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); 
} 
ull binomialCoeff(ull  n, ull k)  
{  
    ull res = 1;  
  
    // Since C(n, k) = C(n, n-k)  
    if ( k > n - k )  
        k = n - k;  
  
    // Calculate value of  
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]  
    for (ull i = 0; i < k; ++i)  
    {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
  
    return res;  
}
set<ll>hp;
void primeFactors(set<ll>&s,ll  n)  
{  
    // Prll the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        s.insert(2);
        n = n/2;  
    }  
  
    // n must be odd at this poll. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, prll i and divide n  
        while (n % i == 0)  
        {  
            s.insert(i);
            n = n/i;  
        }  
    }  
    if(n>2) s.insert(n);
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
}  
ll minFlipsMonoIncr(string S) { //flips to make binary string increasing 
        ll flip=0;
        ll ones=0;
        bool flag=false;
        for(ll i=0;i<S.size();i++)
        {
            if(S[i]-'0'==1) flag=true;
            if(flag&&S[i]-'0'==0) flip++;
            else if(S[i]=='1') ones++;
            if(flip>ones) flip=ones;
        }
        return flip;
}
ll kadane(vector<ll>arr)
{
    ll curr=0;
    ll maxsum=INT_MIN;
    for(ll i=0;i<arr.size();i++)
    {
        curr+=arr[i];
        maxsum=max(maxsum,curr);
        curr=max(curr,(ll)0);
    }
    return maxsum;
}
ll minDist(vector<ll>&dist,vector<bool>&visit,ll n)
{
    ll minV;
    ll minDist2=INT_MAX;
    for(ll i=1;i<=n;i++)
    {
        if(dist[i]<minDist2 && !visit[i])
        {
            minDist2=dist[i];
            minV=i;
        }
    }
    return minV;
}
set<ll>s;
void SieveOfEratosthenes(ll n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
            s.insert(p);
} 
bool isvalid(int i,int j,int n,int m)
{
    return  i>=0 && j>=0 && i<n && j<m; // n rows and m columns
}
void primeFactors(ll x,vector<ll>&m)  
{  
    // Print the number of 2s that divide n  
    ll n=x;
    while (n % 2 == 0)  
    {  
        m.pb(2);
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            m.pb(i);  
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
        {
            m.pb(n);
        }  
}  
int main() {
    	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	    #endif
        IOS;
        ll T;
        cin>>T;
        while(T--)
        {
           ll n;
           cin>>n;
           string s;
           cin>>s;
           ll z=0;
           for(ll i=0;i<n;i++) if(s[i]=='0') z++;
           if(z==1){
               cout<<"BOB"<<"\n";
               continue;
            }
           if(z%2){
               cout<<"ALICE"<<"\n";
               continue;
           }
           cout<<"BOB"<<'\n';
        }
}