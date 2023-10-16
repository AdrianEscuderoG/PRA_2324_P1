#include "List.h"

template <T> class ListArray:public List{
 private:
  T* arr;
  int max;
  int n;
  static const int MINSIZE;

 public:
  ListArray();
  ~ListArray();
  T operator[](int pos);
  friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
  void resize(int new_size);
  
}
