/////problem  https://codeforces.com/contest/2143/problem/C    maxtree 
///// topological sort



cin>>n;
    vl adj[n],indegree(n);
    for(i=0;i<n-1;i++)
    {
      cin>>u>>v>>x>>y;
      u--;v--;
      if(x>y)
      {
        adj[u].pb(v);
        indegree[v]++;
      }
      else
      {
        adj[v].pb(u);
        indegree[u]++;
      }
    }
    queue<ll> q;
    for(i=0;i<n;i++)
    {
      if(indegree[i]==0)q.push(i);
    }
    vl ans;
    while(!q.empty())
    {
      ll node=q.front();
      q.pop();
      ans.pb(node);
      for(auto it: adj[node])
      {
        indegree[it]--;
        if(indegree[it]==0)q.push(it);
      }
    }
    j=0;vl val(n);
    for(i=n;i>0;i--)
    {
      val[ans[j]]=i;
      j++;
    }
    for(i=0;i<n;i++)cout<<val[i]<<" ";
    cout<<endl;
