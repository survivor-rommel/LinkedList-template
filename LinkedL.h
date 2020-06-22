template <class l>
class LinkedList
{
	int size;
	Node<l> *head;
	
	public:
		
		class Iterator
		{
			Node<l> *itera;
			LinkedList<l> lista1;
			int pos;
	
			public:
		
				Iterator(LinkedList<l> lista1);
				Iterator(Node<l> *n);
				Iterator(LinkedList<l> lista1, int position);
				bool hasNext();
				Node<l>* Next();
				Iterator* first();
		        		
				Iterator& operator = (Node<l> *ptr);
				l operator *();
		
				void operator ++ (int)
				{
					itera = itera->getNext();
				}
		
				friend ostream& operator << (ostream &o,const Iterator &lli)
				{
					o << lli.itera->getElem() ;
    				return o;
				}
		
		};
	
	
	public:

		LinkedList();
		LinkedList(const LinkedList &copia);

		void insertar_adelante(const Node<l> &n);
		void insertar_atras(const Node<l> &n);
		void insertar_posicion(const Node<l> &n, int pos);
		void remover_adelante();
		void remover_atras();
		void remover_posicion(const int pos);
		void show();
		Iterator begin();
		Iterator end();
		
		Node<l> *getHead();
		~LinkedList();
		
					
};








template <class l>
LinkedList<l>::Iterator::Iterator(LinkedList<l> lista1)
{
	itera = lista1.getHead();
}

template <class l>
LinkedList<l>::Iterator::Iterator(Node<l> *n)
{
	itera = n;
}


template <class l>
LinkedList<l>::Iterator::Iterator(LinkedList<l> lista1, int position)
{
	itera = lista1.getHead();
	if (position != 0) 
	{
		while (itera != NULL && position)
		{
			itera = itera->getNext();
			position--;
		}
	}
}


template <class l>
bool LinkedList<l>::Iterator::hasNext()
{
	if (itera->getNext() != NULL)		 
	{
		return true;
	}
	return false;
}

template <class l>
Node<l>* LinkedList<l>::Iterator::Next()
{
	return itera->getNext();
}




template <class l>
typename LinkedList<l>::Iterator* LinkedList<l>::Iterator::first()
{
	itera = lista1.getHead();
}


template <class l>
typename LinkedList<l>::Iterator& LinkedList<l>::Iterator::operator = (Node<l> *ptr)
{
	itera = ptr;
}

template <class l>
l LinkedList<l>::Iterator::operator *()
{
	return itera->getElem();
}






//Constructor

template <class l>
LinkedList<l>::LinkedList()
{
	head = NULL;
	size = 0;
}




//Constructor copia
template <class l>
LinkedList<l>::LinkedList(const LinkedList &copia)
{
	size = copia.size;
	head  = copia.head;
}





template <class l>
void LinkedList<l>::remover_adelante()
{
	Node<l> *temporal = head;
    head = head->getNext();
    delete temporal;
    return;
}


template <class l>
void LinkedList<l>::remover_atras()
{
	Node<l> *punteroo = head;
	Node<l> *temporal = punteroo;
	while(punteroo->getNext()!=NULL)
	{
		temporal = punteroo;
		punteroo = punteroo->getNext();
	}
	    
	delete punteroo;
	temporal->setNext(NULL);
}


template <class l>
void LinkedList<l>::remover_posicion(const int pos)
{
	int posicion = pos;
	
	if(posicion == 0 )
    {
        Node<l> *temporal = head;
        head = head->getNext();
        delete temporal;
        return;
    }
    
    Node<l> *punteroo = head;
    while(punteroo->getNext()!=NULL && --posicion)
       	punteroo = punteroo->getNext();
		
    if(punteroo->getNext()==NULL)  return;
	    
    Node<l> *temporal = punteroo->getNext();
    punteroo->setNext(punteroo->getNext()->getNext());
	delete temporal;
	
    size--;

}


//Se itera sobre todos los nodos de la lista 
template <class l>
void LinkedList<l>::show()
{
	
	Node<l> *punteroo = head;
	int c = 1;
	while(punteroo)
    {
    	cout<< "Nodo "<< c<< ": "<< punteroo->getElem()<<endl;
        punteroo = punteroo->getNext();
        c++;
    }
}

template <class l>
void LinkedList<l>::insertar_adelante(const Node<l> &n)
{
	Node<l> *new_node = new Node<l>(n);
	Node<l> *punteroo = head;
	if (size == 0) 
	{
		head = new_node;
		size++;
		return;
	}
	
	new_node->setNext(head);
	head = new_node;
	
	size++;
}

template <class l>
void LinkedList<l>::insertar_atras(const Node<l> &n)
{
	Node<l> *new_node = new Node<l>(n);
	Node<l> *punteroo = head;
	if (size == 0) 
	{
		head = new_node;
		size++;
		return;
	}
		
	while (punteroo->getNext() != NULL)
	{
		punteroo = punteroo->getNext();
    }
    punteroo->setNext(new_node);
		
	size++;	
}

template <class l>
void LinkedList<l>::insertar_posicion(const Node<l> &n, int posicion)
{
	Node<l> *new_node = new Node<l>(n);
	
	if(posicion==0)
    {
        new_node->setNext(head);
        head = new_node;
        return;
    }
    posicion--;
    
    Node<l> *punteroo = head;
    while(punteroo != NULL && --posicion)
    {
        punteroo = punteroo->getNext();
    }
    
    if(punteroo == NULL)
    return;
    new_node->setNext(punteroo->getNext());
    punteroo->setNext(new_node);
	
	size++;
}


template <class l>
typename LinkedList<l>::Iterator LinkedList<l>::begin()
{
	Iterator ite(head); 
	return ite;
}


template <class l>
typename LinkedList<l>::Iterator LinkedList<l>::end()
{
	Iterator ite(head);
		
	if (size != 0) 
	{
		while ( LinkedList::Iterator::itera != NULL)
		{
			ite = ite->Next();
		}
	}
	 
	return ite;
}


template <class l>
Node<l>* LinkedList<l>::getHead()
{
	return head;
}

//Destructor



template <class l>
LinkedList<l>::~LinkedList()
{
	Node<l> *punteroo = head;
	Node<l> *siguiente2 = NULL;
	
	
	while(punteroo != NULL)
    {
        siguiente2 = punteroo->getNext();
        delete punteroo;
        punteroo = siguiente2;
    }
}

