using namespace std;

template <class n>
class Node
{
	n elem;
	Node *next;
		
	public:
			
		Node();
		Node(n elem);
		n getElem() const;
		void setElem(const n element);
		Node *getNext() const;
		void setNext(Node *a);
		
};

template <class n>
Node<n>::Node(n elemento)
{
	elem = elemento;
	next = NULL;
}

template <class n>
n  Node<n>::getElem() const
{
	return elem;
}

template <class n>
void Node<n>::setElem(const n element) 
{
	elem = element;
}

template <class n>
Node<n>* Node<n>::getNext() const
{
	return next;
}

template <class n>
void Node<n>::setNext(Node *a)
{
	next = a;
}


template <class n>
Node<n>::Node()
{
	next = NULL;
}



