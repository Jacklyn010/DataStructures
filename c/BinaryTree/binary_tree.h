#define LEFT -1
#define RIGHT 1

typedef struct Node Node;

struct Node {
	Node *parent;
	
	/* Children */
	Node *left;
	Node *right;
	
	int val;
};

void binary_tree_add(Node *parent, int dir, int val);
Node *binary_tree_new_node(Node *parent, int val);
