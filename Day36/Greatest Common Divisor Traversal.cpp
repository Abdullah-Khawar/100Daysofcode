class DSU {
    vector<int> parent; // Array to store the parent of each element
    vector<int> size;   // Array to store the size of each component
    int numberOfComponents; // Number of components in the disjoint-set

public:
    // Constructor to initialize the Disjoint-Set Union (DSU) data structure
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        numberOfComponents = n;
        
        // Initializing each element as its own parent and setting size to 1
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // Find operation to find the parent of the given element with path compression
    int find(int x) {
        if (x == parent[x])
            return x;
            
        return parent[x] = find(parent[x]); // Path compression
    }

    // Union operation to merge two components
    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
    
        if (x_parent == y_parent) 
            return; // If both elements are already in the same component
    
        // Union by size: smaller component gets attached to the larger one
        if(size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent]  += size[y_parent];
        } else if(size[x_parent] < size[y_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent]  += size[x_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent]  += size[x_parent];
        }
        
        numberOfComponents -= 1; // Decrementing the number of components after union
    }
    
    // Function to get the maximum size of the components
    int maxSize() {
        return numberOfComponents;
    }
};

class Solution {
public:
    // Function to check if it's possible to traverse all pairs
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(n); // Creating a DSU object
        
        int m = *max_element(nums.begin(), nums.end()); // Finding the maximum element in the input array
        
        vector<int> first(m+1, -1); // Array to store the index of the first occurrence of each prime factor

        for (int i = 0; i < n; ++i) {
            // Finding prime factors of each element and unioning them
            for (int prime = 2; prime * prime <= nums[i]; ++prime) {
                if (nums[i] % prime != 0)
                    continue;
                
                if (first[prime] != -1) 
                    dsu.Union(first[prime], i);
                else
                    first[prime] = i;
                
                while (nums[i] % prime == 0) 
                    nums[i] /= prime;
            }
            
            // Handling the case when the remaining factor is also a prime
            if (nums[i] > 1) {
                if (first[nums[i]] != -1) 
                    dsu.Union(first[nums[i]], i);
                else 
                    first[nums[i]] = i;
            }
        }

        return dsu.maxSize() == 1; // Returning whether all elements are in the same component
    }
};
