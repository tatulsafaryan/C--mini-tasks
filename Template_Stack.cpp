#include <iostream>

template <typename T>
class List {
public:
    struct Node {
        Node* next;
        T data;
    };
private:
    Node* m_head;
    int length;
public:
    List();
    void insert(int index, const T& elem);
    T fetch(int index);
    void remove(int index);
};


template <typename T>
class Vector {
private:
    T* m_arr;
    int size;
public:
    Vector();
    ~Vector();
    void insert(int index, const T& elem);
    T fetch(int index);
    void remove(int index);
};

template <typename T, template <typename>typename Container = List>
class Stack {
private:
    Container<T> m_container;
public:
    void push(const T& elem) {
        m_container.insert(0, elem);
    }
    void pop() {
      std::cout<<m_container.fetch(0)<<std::endl;
      m_container.remove(0);
    }
};

//Functions of class Vector

template<typename T>
Vector<T>::Vector() {
  size = 1;
  m_arr = new T[size];
}

template<typename T>
Vector<T>::~Vector() {
  delete[] m_arr;
}

template<typename T>
void Vector<T>::insert(int index, const T& elem) {
  T* copy_arr = new T[size + 1];
  for(int i = 0; i < size + 1 ; ++i) {
    if(i < index) {
      copy_arr[i] = m_arr[i];
    }
    else if (i == index) {
      copy_arr[i] = elem;
    }
    else if (i > index) {
      copy_arr[i] = m_arr[i - 1];
    }
  }
    for(int i = 0; i < size + 1; ++i) {
    m_arr[i] = copy_arr[i];
  }
  delete[] copy_arr;
  size++;
}

template<typename T>
T Vector<T>::fetch(int index) {
  return m_arr[index];
}

template<typename T>
void Vector<T>::remove(int index) {
  try{
    if(size <= 2)
      throw "Error";
    T* copy_arr = new T[size];
    for(int i = 0; i < size; ++i) {
      copy_arr[i] = m_arr[i];
    }
    for(int i = 0; i < size; ++i) {
      if(i < index)
        m_arr[i] = copy_arr[i];
      else if(i > index)
        m_arr[i-1] = copy_arr[i];
    }
    delete[] copy_arr;
    size--;
  }
  catch(const char* Error){
    std::cout<<Error<<" - There is no element in Stack!!!",
    exit(EXIT_FAILURE);
  }
}

//   Function of class List
template<typename T>
List<T>::List() {
  this->length = 0;
  this->m_head = nullptr;
}

template<typename T>
void List<T>::insert(int index,const T& elem) {
  List<T>::Node* node = new Node();
  node->data = elem;
  node->next = m_head;
  m_head = node;
  length++;
}

template<typename T>
T List<T>::fetch(int index) {
  if(length != 0)
    return m_head->data;
  std::cout<<" - There is no element in Stack!!!!";
  exit(EXIT_FAILURE);
}

template<typename T>
void List<T>::remove(int index) {
  Node* tmp;
  try {
    if(m_head->next == nullptr)
    throw "Error";
    tmp = m_head;
    m_head = m_head->next;
    length--;
    delete tmp;
  }
  catch(const char* Error) {
    std::cout<<Error<<"There is no element in Stack!!!",
    exit(EXIT_FAILURE);
  }
}
int main() {
    Stack<int, Vector > stack;
    stack.push(5);
    stack.push(69);
    stack.push(11);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    return 0;
}
