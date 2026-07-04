class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_oranges=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) fresh_oranges++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }  
        int time=0;
        while(!q.empty() && fresh_oranges>0)
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int>p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    grid[x-1][y]=2;
                    fresh_oranges--;
                    q.push({x-1,y});
                }
                if(x+1<n && grid[x+1][y]==1)
                {
                    grid[x+1][y]=2;
                    fresh_oranges--;
                    q.push({x+1,y});
                }
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    grid[x][y-1]=2;
                    fresh_oranges--;
                    q.push({x,y-1});
                }
                if(y+1<m && grid[x][y+1]==1)
                {
                    grid[x][y+1]=2;
                    fresh_oranges--;
                    q.push({x,y+1});
                }
            }
            time++;
        } 
        if(fresh_oranges==0) return time;
        else return -1;
    }
};