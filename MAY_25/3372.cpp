class Solution {
public:
    int bfs(unordered_map<int,vector<int>>&adj,int k,int node,int n){
        queue<pair<int,int>>q;
        q.push({node,0});
        vector<bool>visited(n,false);
        visited[node]=true;

        int count=0;

        while(q.empty()==false){
            // auto[curr,dist]=q.front();
            int curr =q.front().first;
            int dist=q.front().second;
            q.pop();

            if(dist>k){
                continue;
            }
            count++;

            for(auto ngr:adj[curr]){
                if(visited[ngr]==false){
                    visited[ngr]=true;
                    q.push({ngr,dist+1});
                }
            }

        }
        return count;
    }

    int dfs(unordered_map<int,vector<int>>&adj,int k,int node,int parent){
        if(k<0){
            return 0;
        }
        int count=1;

        for(auto ngr:adj[node]){
            if(ngr!=parent){
                count+=dfs(adj,k-1,ngr,node);
            }

        }
        return count;
    }
    vector<int> findist(vector<vector<int>>& edges,int k){
        unordered_map<int,vector<int>>adj;

           int N=edges.size()+1;

        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>result(N);

        for(int i=0;i<N;i++){
           // result[i]=bfs(adj,k,i,N);
           result[i]=dfs(adj,k,i,-1);
        }
        return result;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        //n=edges1.size()+1;

        vector<int>tree1=findist(edges1,k);
        vector<int>tree2=findist(edges2,k-1);

        int maxele=*max_element(tree2.begin(),tree2.end());
        for(int i=0;i<tree1.size();i++){
            tree1[i]+=maxele;
        }

        return tree1;
        
    }
};
