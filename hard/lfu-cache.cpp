#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class LFUCache {
public:
    
    unordered_map<int, int> keyFreqMap; // key-> freq
    unordered_map<int, list<int>> freqKeyListMap; // freq -> list of keys
    unordered_map<int,  pair<int, list<int>::iterator>> keyValPosMap; // key -> value, pos of key in list
    
    int minFreq, maxCap;
    
    LFUCache(int capacity) {
        maxCap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        
        if (maxCap == 0) return -1;
        
        // key exists
        if(keyValPosMap.find(key) != keyValPosMap.end())
        {
            int val = keyValPosMap[key].first;
            put(key, val);
            return val;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        
        if (maxCap == 0) return;
        
        if (keyValPosMap.find(key) != keyValPosMap.end())
        {
            keyValPosMap[key].first = value; // update value
            int oldFreq = keyFreqMap[key]++; // save old freq and update freq
            freqKeyListMap[oldFreq].erase(keyValPosMap[key].second); // remove from old freq list
            
            // new freq does not exist in map
            if (freqKeyListMap.find(oldFreq+1) == freqKeyListMap.end())
            {
                freqKeyListMap[oldFreq+1] = {}; // create an empty list
            }
            auto pos = freqKeyListMap[oldFreq+1].insert(freqKeyListMap[oldFreq+1].begin(), key); // add to new freq list
            keyValPosMap[key].second = pos; // update position iterator
            
            // this key had min freq, and min freq now has no keys
            if (oldFreq == minFreq and freqKeyListMap[minFreq].empty())
            {
                freqKeyListMap.erase(minFreq++); // remove minFreq map from array and update minFreq by adding 1
            }
        }
        
        else
        {
            // cache is full
            if (keyValPosMap.size() == maxCap)
            {
                // removing lfu key
                
                int keyToRemove = freqKeyListMap[minFreq].back(); // get key to remove
                freqKeyListMap[minFreq].pop_back(); // remove least freq used -> oldest key : from freqKeyListMap
                keyFreqMap.erase(keyToRemove); // remove entry from keyFreqMap
                keyValPosMap.erase(keyToRemove); // remove entry from keyValPosMap
                
                // min freq now has no keys
                if (freqKeyListMap[minFreq].empty())
                {
                    freqKeyListMap.erase(minFreq); // remove minFreq map from array
                }
            }
            
            // adding new key

            keyFreqMap[key] = 1; // add entry to keyFreqMap
            
            // freq 1 does not exist in map
            if (freqKeyListMap.find(1) == freqKeyListMap.end())
            {
                freqKeyListMap[1] = {}; // create an empty list
            }
            
            auto pos = freqKeyListMap[1].insert(freqKeyListMap[1].begin(), key); // add entry to freqKeyListMap
            keyValPosMap[key] = make_pair(value, pos); // add entry to keyValPosMap

            minFreq = 1; // change minFreq to 1, as new entry is added
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */