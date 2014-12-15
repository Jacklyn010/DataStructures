#define LEFT -1
#define RIGHT 1

#define TRUE 1
#define FALSE 0

#define max(a, b) { a > b ? a : b; }
#define min(a, b) { a < b ? a : b; }

typedef int boolean;

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
void binary_tree_delete_all(Node *root);
boolean binary_tree_is_search_tree(Node *node, int min, int max);
