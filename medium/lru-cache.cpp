#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    
    unordered_map<int, int> m;
    unordered_map<int, list<int>::iterator> u;
    list<int> usage;
    int size;
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        
        if (m.find(key) != m.end()) {
            
            if (u.find(key) != u.end()){
                usage.erase(u[key]);
            }
            auto it = usage.insert(usage.end(),key);
            u[key] = it;
            
            return m[key];  
        } 
        else return -1;
    }
    
    void put(int key, int value) {
        
        if (u.find(key) != u.end()){
            usage.erase(u[key]);
        }
        
        auto it = usage.insert(usage.end(),key);
        u[key] = it;    
        
        if (m.find(key) == m.end() and m.size() == size) {
            m.erase(usage.front());
            u.erase(usage.front());
            usage.pop_front();
        }
        
        m[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */