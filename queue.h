#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> {
        T *queue; 
        int front,back;
        int capacity; 
    public:
        QueueArray(int _capacity);
        ~QueueArray();
        void enqueue(T data);
        T dequeue();
        bool is_full();
        bool is_empty();
    private:
        int next(int index);
        int prev(int index);
};

template <class T>
QueueArray<T>::QueueArray(int _capacity){
    this->queue = new int[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
QueueArray<T>::~QueueArray(){
    delete[] queue;
}

template<class T>
int QueueArray<T>::next(int index){
    return (index + 1);
}

template<class T>
int QueueArray<T>::prev(int index){
    return index - 1;
}

template <class T>
bool QueueArray<T>::is_full(){
    return (front == 0 && back == capacity - 1) || (back == front - 1);
}

template <class T>
bool QueueArray<T>::is_empty(){
    return front == -1;
}

template <class T>
void QueueArray<T>::enqueue(T data){
    if(is_full()){
        throw "Array is full";
    }
    if(is_empty){
        front = back = 0;
    }
    else if(back == capacity - 1){
        back = 0;
    }
    else{
        back++;
    }
     array[back] = data;
}

template <class T>
T QueueArray<T>::dequeue(){
    if(is_empty()){
        throw "Error";
    }
    T data = queue[front];
    if(front == back){
        front = back = -1;
    }
    else if(back == capacity - 1){
        front = 0;
    }
    else{
        front++;
    }
    return data;
}

