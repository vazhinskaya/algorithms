class Node
{
	friend class HashTable;
	Node* next;
	int data;
public:
	Node() {}
	Node(int d, Node* n)
	{
		data = d;
		next = n;
	}
	~Node() {}
};
class HashTable
{
public:
	int size;
	vector<Node*>* Nodes;
	HashTable(int s)
	{
		size = s;
		Nodes = new vector<Node*>(size);
	}
	HashTable()
	{
		size = {};
		Nodes = new vector<Node*>(size);
	}
	~HashTable() {}


	void insert(int data)
	{
		int index = getHash(data);
		if (Nodes->at(index) == NULL)
		{
			Nodes->at(index) = new Node(data, NULL);
			return;
		}
		Node* p = Nodes->at(getHash(data));
		while (p != NULL) {
			if (p->next == NULL)
			{
				p->next = new Node(data, NULL);
				break;
			}
			p = p->next;
		}
	}

	int search(int data)
	{
		for (Node* p = Nodes->at(getHash(data)); p; p = p->next)
		{
			if (p->data == data)
				return 1;
		}
		return 0;
	}

	int delet(int data)
	{
		for (Node* p = Nodes->at(getHash(data)); p; p = p->next)
		{
			if (p->data == data)
				delete p;

		}
		return 0;
	}


	int getSize()
	{
		return size;
	}



	int getHash(int key)
	{
		return (key % getSize());
	}


	void print(int start)
	{
		int lineCount = 0;
		for (int i = start; i < Nodes->size(); i++) {
			cout << i << "\t";
			Node* p = Nodes->at(i);
			while (p != NULL) {
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
	}
};






