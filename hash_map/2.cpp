class HashEntry {
private:
	int key;
	int value;
public:
	HashEntry(int key, int value) {
		this->key = key;
		this->value = value;
	}

	int getKey() {
		return key;
	}

	int getValue() {
		return value;
	}
};

const int Size = 120;



class Hash {
private:
	HashEntry **Hashtable;
public:
	Hash() {
		Hashtable = new HashEntry*[Size];
		for (int i = 0; i < Size; i++)
			Hashtable[i] = NULL;
	}

	int get(int key) {
		int hash = (key % Size);
		while (Hashtable[hash] != NULL && Hashtable[hash]->getKey() != key)
			hash = (hash + 1) % Size;
		if (Hashtable[hash] == NULL)
			return -1;
		else
			return Hashtable[hash]->getValue();
	}

	void put(int key, int value) {
		int hash = (key % Size);
		while (Hashtable[hash] != NULL && Hashtable[hash]->getKey() != key)
			hash = (hash + 1) % Size;
		if (Hashtable[hash] != NULL)
			delete Hashtable[hash];
		Hashtable[hash] = new HashEntry(key, value);
	}

	~Hash() {
		for (int i = 0; i < Size; i++)
			if (Hashtable[i] != NULL)
				delete Hashtable[i];
		delete[] Hashtable;
	}
};