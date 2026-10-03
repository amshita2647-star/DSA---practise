class DisjointSet
{
    vector<int> size, parent;

public:

    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution
{
public:

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // {weight, {u, v}}
        vector<pair<int, pair<int, int>>> edges;

        // Convert adjacency list into edge list
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];

                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }

        // Create Disjoint Set
        DisjointSet ds(V);

        // Sort according to weight
        sort(edges.begin(), edges.end());

        int mstWt = 0;

        // Kruskal's Algorithm
        for (auto it : edges)
        {
            int wt = it.first;

            int u = it.second.first;
            int v = it.second.second;

            // Check whether adding this edge creates a cycle
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWt += wt;

                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};
