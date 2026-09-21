class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector <int> visited (V,0);
        pq.push({0,0}); // wt , node pushed
        
        int sum = 0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int w=it.first;
            int n=it.second;
            if(visited[n] == 1) { continue; }
            sum+=w;
            visited[n]=1;
            
            for(auto &node : edges)
            {
                int u = node[0];
                int v = node[1];
                int wei = node[2];
                if(u==n && visited[v] == 0)
                {
                    pq.push({wei,v});
                }
                else if(v==n && visited[u] == 0)
                {
                    pq.push({wei,u});
                }
                
            }
            
        }
        return sum;
        
    }
};
