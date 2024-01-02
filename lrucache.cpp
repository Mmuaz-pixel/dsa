#include <iostream>
#include <vector>

class LRUCache {
private:
    int capacity;
    std::vector<int> keys;
    std::vector<int> values;

    int findKeyIndex(int key) {
        for (int i = 0; i < keys.size(); ++i) {
            if (keys[i] == key) {
                return i;
            }
        }
        return -1; // Key not found
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        int index = findKeyIndex(key);
        if (index != -1) {
            // Key found, update its position in the keys vector
            keys.erase(keys.begin() + index);
            keys.insert(keys.begin(), key);
            return values[index];
        }
        return -1; // Not found
    }

    void put(int key, int value) {
        int index = findKeyIndex(key);
        if (index != -1) {
            // Update the existing key
            keys.erase(keys.begin() + index);
            values.erase(values.begin() + index);
        } else if (keys.size() >= capacity) {
            // Remove the least recently used key
            keys.pop_back();
            values.pop_back();
        }

        // Insert the new key-value pair
        keys.insert(keys.begin(), key);
        values.insert(values.begin(), value);
    }
};

int main() {
    // Example usage of the LRUCache
    LRUCache lruCache(2);
    lruCache.put(1, 1);
    lruCache.put(2, 2);
    std::cout << lruCache.get(1) << std::endl; // Output: 1
    lruCache.put(3, 3); // evicts key 2
    std::cout << lruCache.get(2) << std::endl; // Output: -1 (not found)
    lruCache.put(4, 4); // evicts key 1
    std::cout << lruCache.get(1) << std::endl; // Output: -1 (not found)
    std::cout << lruCache.get(3) << std::endl; // Output: 3
    std::cout << lruCache.get(4) << std::endl; // Output: 4

    return 0;
}
