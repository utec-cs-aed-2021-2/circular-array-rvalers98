#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> { 
        T* stack;
        int capacity;
        int size;
    public:
        StackArray(int _capacity);
        ~StackArray();
        void push(T data);
        T pop();
        void resize(int new_size);
    private:
        int next(int index);
        int prev(int index);
};

template <class T>
StackArray<T>::StackArray(int _capacity){
    this->capacity = _capacity;
    this->size = 0;
    this->stack = new T[_capacity];
}

template <class T>
StackArray<T>::~StackArray()
{
   delete[] stack;
}

template<class T>
int StackArray<T>::next(int index){
    return (index + 1);
}

template<class T>
int StackArray<T>::prev(int index){
    return index - 1;
}

template <class T>
void StackArray<T>::push(T data){
    this->stack[this->size++] = data; 
    if (this->size == this->capacity){
        resize(this->capacity*2);
    }
}

template <class T>
T StackArray<T>::pop(){
    if(this->size > 0){
        return array[--this->size]; 
    }
}

template<class T>
void StackArray<T>::resize(int new_size){
    this->capacity = new_size;
    int *temp = new int[this->capacity];
    for (int i = 0; i < size; i++)
        temp[i] = stack[i];
    delete[] stack;
    stack = temp;
}





