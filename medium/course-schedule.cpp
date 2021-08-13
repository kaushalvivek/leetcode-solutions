#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool loopFound = false;
    bool explored[100001] = {false};
    
    void DFS(unordered_map<int, vector<int>> &adjm, vector<bool> &visited, int n, int curr) {
        
        if (loopFound)
            return;
        
        visited[curr] = true; // current node has now been visited
        explored[curr] = true;
        
        for (auto i : adjm[curr]) { // iterate over all edges from curr to others
                    
            if (visited[i]) { // if i was already visited
                loopFound = true;
                return;
            }

            if (!explored[i]) // if the path hasn't been explored yet
                DFS(adjm, visited, n, i); // search for edges from i -> ...

            visited[i] = false; // mark i as unvisited again
        }
        
        visited[curr] = false; // mark curr as unvisited again
        
        return;
    }
    
    bool cycleExists(unordered_map<int, vector<int>> &adjm, int n) {
        
        vector<bool> visited; 
            
        for(int i = 0; i < n; i++)
            visited.push_back(false); // none of the nodes are visited at the start
        
        for (int i = 0; i < n; i++) {
            
            DFS(adjm, visited, n, i); // start DFS from each node going from 0 -> n-1
            
            if (loopFound)
                return true;
        }
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> adjm;
        
        vector<int> temp;
        
        for (int i = 0; i < numCourses; i++) { // no edges at first
            adjm[i] = temp;
        }
        
        for (auto item : prerequisites)
            adjm[item[0]].push_back(item[1]); // add edge
        
        // return false if cycle in graph, true otherwise
        return !cycleExists(adjm, numCourses);
    }
};