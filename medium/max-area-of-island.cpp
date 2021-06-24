#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited;
        vector <int> arr;
        for (int i = 0; i < n; i++) arr.push_back(0);
        for (int i = 0; i < m; i++) visited.push_back(arr);
        
        int max_count = INT_MIN;
        int count;
        for (int i = 0; i < m; i++)
        {
            for(int j = 0; j< n; j++)
            {
                if (visited[i][j]) continue;
                
                count = 0;
                if (grid[i][j])
                {
                    DFS(grid, visited, i,j, count);
                }
                if (count > max_count) 
                {
                    max_count = count;
                }
            }
        }
        return max_count;
    }
    void DFS(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j, int &count)
    {
        static int dirx[] = {1,0,0,-1};
        static int diry[] = {0,1,-1,0};
        
        visited[i][j] = 1;
        if (grid[i][j]){
            count++;   
        }
        
        for (int k = 0; k < 4; k++)
        {
            if (isOkayToVisit(i+dirx[k], j+diry[k], grid, visited))
            {
                DFS(grid, visited, i+dirx[k], j+diry[k], count);
            }
        }
    }
    
    bool isOkayToVisit(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i >= m or j >= n or i < 0 or j < 0) return false;
        if (visited[i][j]) return false;
        if (grid[i][j] == 0) return false;
        
        return true;
    }
};