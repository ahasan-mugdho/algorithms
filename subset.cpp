#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'


vector<string> str;
void sub_set(string s,ll i)
{
  string s1=s+"0";
  string s2=s+"1";
  if(i==20)
  {
    str.push_back(s1);
    str.push_back(s2);
    return;
  }
  sub_set(s1,i+1);  
  sub_set(s2,i+1);
  
  
}
int main() 
{
  optimize();//remove before interactive problems
  sub_set("",1);
  
  return 0;
}
