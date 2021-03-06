// HashTable.cpp
#include <vector>
#include "LinkedList.cpp" // available at MMLS.

template <typename T>
class HashTable {
  vector< LinkedList<T> > table;
  int hashfunction (int hashitem) { // hash function
    //return hashitem % table.size();
    return hashitem % table.size();
  }
 public:
  HashTable (int size) {
    table.resize (size); // resize vector to support size elements.
  }
  ~HashTable() {
    for (int i = 0; i < table.size(); i++)
      table[i].makeEmpty();
  }
  int size() {
    return table.size();
  }
  void insert (T newItem,int key) {
    int location = hashfunction (key);
    table[location].insertFront (newItem);
    //cout << location << " , " << table[location] << endl;
  }
  bool retrieve (T & target,int key) {
    int location = hashfunction (key);
    if (!table[location].find (target))
    {
        return false;
    }
    else
    {
       cout << location << " , " << table[location] << endl;
       return true;
    }

  }
  friend ostream& operator<< (ostream& os, HashTable<T>& ht) {
    for (int i = 0; i < ht.size(); i++)
      os << i << " = " << ht.table[i] << endl;
    return os;
  }
};
