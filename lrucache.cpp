#include <iostream>
#include <vector>

using namespace std;

class LRUCache
{
private:
	int capacity;
	vector<int> keys;
	vector<int> values;

	int findKeyIndex(int key)
	{
		for (int i = 0; i < keys.size(); ++i)
		{
			if (keys[i] == key)
			{
				return i;
			}
		}
		return -1; // Key not found
	}

public:
	LRUCache(int capacity) : capacity(capacity) {}

	int get(int key)
	{
		int index = findKeyIndex(key);
		if (index != -1)
		{
			// Key found, update its position in the keys vector
			keys.erase(keys.begin() + index);
			keys.insert(keys.begin(), key);
			return values[index];
		}
		return -1; // Not found
	}

	void put(int key, int value)
	{
		int index = findKeyIndex(key);
		if (index != -1)
		{
			// Update the existing key
			keys.erase(keys.begin() + index);
			values.erase(values.begin() + index);
		}
		else if (keys.size() >= capacity)
		{
			// Remove the least recently used key
			keys.pop_back();
			values.pop_back();
		}

		// Insert the new key-value pair
		keys.insert(keys.begin(), key);
		values.insert(values.begin(), value);
	}
};

int main()
{
	// Example usage of the LRUCache
	LRUCache lruCache(2);
	lruCache.put(1, 1);
	lruCache.put(2, 2);
	cout << lruCache.get(1) << endl; // Output: 1
	lruCache.put(3, 3);				 // evicts key 2
	cout << lruCache.get(2) << endl; // Output: -1 (not found)
	lruCache.put(4, 4);				 // evicts key 1
	cout << lruCache.get(1) << endl; // Output: -1 (not found)
	cout << lruCache.get(3) << endl; // Output: 3
	cout << lruCache.get(4) << endl; // Output: 4

	return 0;
}
