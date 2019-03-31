namespace ariel {
	class Tree {
	private:
		struct node
		{
			int key;
			node* left;
			node* right;
		};
		node* Root;

		void insert_node(int i, node* n);
		void printInOrder(node* n);
		node* returnNodePrivate(int i, node* n);
		int findSmallestPrivate(node* n);
		void removeNode(int i, node* parent);
		void removeRoot();
		void removeMatch(node* parent, node* match, bool left);
		bool containsNode(int i, node* n);
		int treeSize(node* n);
		int findParent(int i, node* n);
		void deleteTree(node* n);
	
	

	public:
		Tree();
		node* createLeaf(int i);
		void insert(int i);
		void print();
		node* returnNode(int i);
		int findSmallest();
		void remove(int i);
		bool contains(int i);
		int size();
		int root();
		int parent(int i);
		int left(int i);
		int right(int i);
		void delete();


	};
};