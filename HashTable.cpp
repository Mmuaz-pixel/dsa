#include <iostream>
#include <vector>
#include <list>

using namespace std; 

class HashTable
{
private:
	static const int tableSize = 10; // You can adjust the table size based on your requirements
	vector<list<int>> table;

public:
	HashTable() : table(tableSize) {}

	// Hash function to map values to indices
	int hashFunction(int key)
	{
		return key % tableSize;
	}

	// Insert a key into the hash table
	void insert(int key)
	{
		int index = hashFunction(key);
		table[index].push_back(key);
	}

	// Search for a key in the hash table
	bool search(int key)
	{
		int index = hashFunction(key);
		for (const auto &value : table[index])
		{
			if (value == key)
			{
				return true;
			}
		}
		return false;
	}

	// Remove a key from the hash table
	void remove(int key)
	{
		int index = hashFunction(key);
		table[index].remove(key);
	}
};

int main()
{
	HashTable hashTable;

	// Insert some keys
	hashTable.insert(5);
	hashTable.insert(15);
	hashTable.insert(25);

	// Search for a key
	cout << "Search 15: " << (hashTable.search(15) ? "Found" : "Not found") << endl;

	// Remove a key
	hashTable.remove(15);

	// Search again after removal
	cout << "Search 15 after removal: " << (hashTable.search(15) ? "Found" : "Not found") << endl;

	return 0;
}