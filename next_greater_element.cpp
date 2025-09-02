vector<int> NGE(vector<int> v)
{
  stack<int> st;
  vector<int> nge(v.size(),-1);
  for(int i=0;i<v.size();i++)
  {
    while(!st.empty()&&v[i]>v[st.top()])
    {
        nge[st.top()]=v[i];
        st.pop();
    }
    st.push(i);
  }
  return nge;
}
