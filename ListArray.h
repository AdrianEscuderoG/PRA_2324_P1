#include "List.h"
#include <iostream>
template<typename T> class ListArray:public List<T>{
 private:
  T* arr;
  int max;
  int n;
  static const int MINSIZE=2;

 public:
  void insert(int pos, T e) override;
  void append(T e) override;
  void prepend(T e) override;
  T remove(int pos) override;
  T get(int pos)override;
  int search(T e)override;
  bool empty()override;
  int size()override;
  ListArray();
  ~ListArray();
  T operator[](int pos);
  friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
 private:
  void resize(int new_size);
  
};
template<typename T>
void ListArray<T>::insert(int pos, T e){
 if(pos<0 || pos>size()){
  throw std::out_of_range();
 }
 if(pos==0){
  prepend(e);
 }else if(pos==n){
  append(e);
 }else{
  if(n==max){
   resize(max+1);
  }
  for(int i=n;i>pos;i--){
   arr[i]=arr[i-1];
  }
  arr[pos]=e;
 }
 return;
}

template<typename T>
void ListArray<T>::append(T e){
 if(n==max){
  resize(max+1);
 }
 arr[n]=e;
 return;
}

template<typename T>
void ListArray<T>::prepend(T e){
 if(n==max){
  resize(max+1);
 }
 for(int i=n;i>0;i--){
  arr[i]=arr[i-1];
 }
 arr[0]=e;
 return;
}

template<typename T>
T ListArray<T>::remove(int pos){
 if(pos<0 || pos>size()-1){
  throw std::out_of_range();
  }
 T a = arr[pos];
 for(int i=pos;i<n;i++){
  arr[pos]=arr[pos+1];
 }
 return a;
}

template<typename T>
T ListArray<T>::get(int pos){
 if(pos<0 || pos>size()-1){
  throw std::out_of_range();
  }
 return arr[pos];
}

template<typename T>
int ListArray<T>::search(T e){
 for(int i=0; i<size();i++){
	if(arr[i]==e){
	return i;
	}
 }
 return -1;
}

template<typename T>
bool ListArray<T>::empty(){
 if(n==0){
  return true;
 }else{
  return false;
 }
}

template<typename T>
int ListArray<T>::size(){
 return max;
}

template<typename T>
ListArray<T>::ListArray(){
 n=0;
 max=MINSIZE;
 arr[MINSIZE];
}

template<typename T>
ListArray<T>::~ListArray(){
 delete[] arr;
}

template<typename T>
T ListArray<T>::operator [](int pos){
 if(pos<0||pos>=size()){
  throw std::out_of_range();
 }
}

template<typename T>
void ListArray<T>::resize(int new_size){
 T arr1= new T[new_size];
 for(int i=0;i<n;i++){
  arr1[i]=arr[i];
 }
 *arr=*arr1;
 delete[] arr;
 max=new_size;
}


