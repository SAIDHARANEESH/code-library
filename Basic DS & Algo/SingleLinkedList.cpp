struct Node {
	int data;
	Node *next;
	Node() {
		next = NULL
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
		Node *head;
		head = root;
		while (head->next != NULL) {
			p = head;
			head = head->next;
		}
		head->next = newNode;
	}
}