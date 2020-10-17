struct Node {
	int data;
	Node *left, *right;
	Node() {
		left = NULL;
		right = NULL;
	}
};

Node *root;
void insert(int data) {
	Node *newNode;
	newNode.data = data;
	if (root == NULL) {
		root = newNode;
	}
	else {
		Node *head, *p;
		head = root;
		while (head != NULL) {
			p = head;
			if (data < root->data) {
				head = head->left;
			} 
			else {
				head = head->right;
			}
		}
		head = newNode;
		if (p->data > data) {
			p->left = head;
		}
		else {
			p->right = head;
		}
	}
}