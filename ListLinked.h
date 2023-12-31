#include <iostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
	    Node<T> *first;
	    int n;
    public:
	    ListLinked();
	    ~ListLinked();
	    void insert(int pos, T e) override;
	    void append(T e)override;
	    void prepend (T e)override;
	    T remove (int pos)override;
	    T get(int pos)override;
	    int search(T e)override;
	    bool empty()override;
	    int size()override;
	    void invert_list()override;
	    T operator [] (int pos);
	    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
		Node<T> *aux= list.first;
		out<<"List = [";
		while(aux!=nullptr){
			out<<aux->data<<" ";
			aux=aux->next;
		}
		out<<"]";
		return out;
	    }
};

template<typename T>
ListLinked<T>::ListLinked(){
	n=0;
	first=nullptr;
}

template<typename T>
ListLinked<T>::~ListLinked(){
  while(first!=nullptr){
    Node<T> *aux =first->next;
    delete first;
    first=aux;
    n--;
  }
	std::cout<<"Lista borrada"<<std::endl;
}
template<typename T>
void ListLinked<T>::insert(int pos, T e){//prepend, append o inserta mediante previo y aux
	if(pos<0 || pos>size()){
		throw std::out_of_range("insert fuera de rango");
	}
	if(pos==0){
		prepend(e);
	}else if(pos==n){
		append(e);
	}else{
		Node<T> *aux= first;
		Node<T> *previo=nullptr;
		for(int i=0;i<pos;i++){
			previo=aux;
			aux=aux->next;
	       	}
		previo->next= new Node(e,aux);//el nuevo es aquel al que apunta el previo y q apunta al aux
		n++;
	}
	return;
}

template<typename T>
void ListLinked<T>::append(T e){//Llega al final y crea un nuevo nodo
	Node<T> *aux=first;
	while(aux->next!=nullptr){
		aux=aux->next;
	}
	aux->next= new Node(e);
	n++;
	return;
}
template<typename T>
void ListLinked<T>::prepend(T e){//Crea apuntado al first
	Node<T> *aux=new Node(e,first);
	first=aux;
	n++;
	return;
}

template<typename T>
T ListLinked<T>:: remove(int pos){
	if(n==0){
		throw std::out_of_range("remove lista vacía");
	}
	if(pos<0 || pos>(size()-1)){
		throw std::out_of_range("remove fuera de rango");
	}
	Node<T> *aux=first;
	if(pos==0){
		first=first->next;
	}else{
		Node<T> *previo=nullptr;
		for(int i=0;i<pos;i++){
			previo=aux;
			aux=aux->next;
		}
		previo->next=aux->next;
	}
	n--;
	T a=aux->data;
	delete aux;
	return a;
}

template<typename T>
T ListLinked<T>:: get(int pos){
        if(n==0){
                throw std::out_of_range("remove lista vacía");
        }
        if(pos<0 || pos>(size()-1)){
                throw std::out_of_range("remove fuera de rango");
        }
        Node<T> *aux=first;
        for(int i=0;i<pos;i++){
                aux=aux->next;
        }
        return aux->data;
}

template<typename T>
int ListLinked<T>::search(T e){
	Node <T> *aux= first;
	int i=0;
	while(aux!=nullptr){
	if(aux->data==e){
		return i;
	}
	aux=aux->next;
	i++;
	}
	return -1;
} 
template<typename T>
bool ListLinked<T>::empty(){
	if(n==0){
		return 1;
	}else{
		return 0;
	}
}

template<typename T>
int ListLinked<T>::size(){
	return n;
}
template<typename T>
T ListLinked<T>::operator [](int pos){
	if(pos<0||pos>=size()){
		throw std::out_of_range("operador fuera de rango");
	}
	Node<T> *aux=first;
        for(int i=0;i<pos;i++){
                aux=aux->next;
        }
        return aux->data; 
}

template<typename T>
void ListLinked<T>::invert_list(){
	if(n<=1){
		return;
	}
	Node <T> *aux=first;
	T cambio[n];
	int i=0;
	while(aux!=nullptr){
		cambio[i]=aux->data;
		aux=aux->next;
		i++;
	}
	aux=first;
	i=n-1;
	while(aux!=nullptr){
                aux->data=cambio[i];
                aux=aux->next;
                i--;
        }
	return;
}
