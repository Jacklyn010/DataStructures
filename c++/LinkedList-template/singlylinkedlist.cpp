using namespace std;

template <typename T>
LinkedList<T>::~LinkedList() {
	Node<T> *prev = head;
	Node<T> *next = NULL;
	
	while (prev) {
		next = prev->next;
		
		delete prev;
		
		prev = next;
	}
}

template <typename T>
void LinkedList<T>::add(const T &val) {
	Node<T> *node = newNode(val);
	
	if (!head) {
		head = node;
	} else {
		tail->next = node;
	}
	
	tail = node;
	
	length++;
}

template <typename T>
Node<T> *LinkedList<T>::getNode(int index) {
	Node<T> *node = head;
	
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	
	return node;
} 

template <typename T>
T LinkedList<T>::get(int index) {
	if (index < 0 || index >= length) {
		throw LinkedListException(ARRAY_INDEX_OUT_OF_BOUNDS);
	}
	
	return getNode(index)->val;
}

template <typename T>
T LinkedList<T>::remove(int index) {
	if (index < 0 || index >= length) {
		throw LinkedListException(ARRAY_INDEX_OUT_OF_BOUNDS);
	}
	
	Node<T> *prev = getNode(index - 1);
	Node<T> *remove = prev->next;
	
	T val = prev->val;
	
	prev->next = remove->next;
	
	delete remove;
	
	return val;
}

template <typename T>
Node<T> *LinkedList<T>::newNode(const T &val) {
	Node<T> *node = new Node<T>;
	
	node->val = val;
	node->next = NULL;
	
	return node;
}
