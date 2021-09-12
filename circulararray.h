#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T& operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");
    void display();
    void arraydata(int arr[]);
private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
bool CircularArray<T>::is_empty(){
    return front == -1;
}

template <class T>
bool CircularArray<T>::is_full(){
    return front == next(back) && !is_empty();
}

template <class T>
int CircularArray<T>::size(){
    if(is_empty()){
        return true;
    }
    if(back>=front){
        return back - front + 1;
    }
    else{
        return capacity - front + back + 1;
    }
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for(int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}

template <class T>
T &CircularArray<T>::operator[](int index){
    if(index >= capacity){
        throw "Index no valid";
    }
    return array[(front + index) % capacity];
}

template <class T>
void CircularArray<T>::push_front(T data){
    if(is_full()){
        throw "Array is full";
    }
    if(is_empty()){
        front = back = 0;
    }
    else{
        front = prev(front);
    }
    array[front] = data;
}

template <class T>
void CircularArray<T>::push_back(T data){
    if(is_full()){
        throw "Array is full";
    }
    if(is_empty()){
        front = back = 0;
        array[back] = data;
    }
    else{
        array[next(back)] = data;
        back = next(back);
    }
    
}

template<class T>
void CircularArray<T>::insert(T data, int pos){
    int n = size();
    if(pos < 0 || pos > n){
        throw "Index no valid";
    }
    if(n == capacity){
        throw "Array is full";
    }
    if(pos == 0){
        push_front(data);
    }
    else{
        for (int i = n - 1; i >= pos; i--){
            (*this)[i+1] = (*this)[i];
        }    
        (*this)[pos] = data;
        back = next(back);
    }
}

template <class T>
T CircularArray<T>::pop_front(){
    if(is_empty()){
        throw "Array is full";
    }
    T temp = array[front];
    if(front == back){
        front = back = -1;
    }
    else{
        front = next(front);
    }
    return temp;
}

template <class T>
T CircularArray<T>::pop_back(){
    if(is_empty()){
        throw "Array is full";
    }
    T temp = array[back];
    if(front == back){
        front = back = -1;
    }
    else{
        back = prev(back);
    }
    return temp;
}

template <class T>
void CircularArray<T>::clear(){
    front = back = -1;
}


template<class T> 
void CircularArray<T>::sort(){
    int tempfa = front;
    if (is_empty()){
        throw "Array is empty";
    }
    else{
        do{
            int tempfn = next(tempfa);
            while (tempfn != next(back)){
                if(array[tempfa] > array[tempfn]){
                    int temp = array[tempfa];
                    array[tempfa] = array[tempfn];
                    array[tempfn] = temp;
                }
                tempfn = next(tempfn);
            }
            tempfa = next(tempfa);
        }while(next(tempfa)!=next(back));
    }
}

template<class T> 
bool CircularArray<T>::is_sorted(){
    int temp1,temp = front; 
    int temp2 = back;
    if (temp1 == temp2){
        return true; 
    } 
    while(++temp != temp2){
        if(array[temp]<array[temp1]){
            return false;
        }
        ++temp;
    }
    return true;
}

template <class T>
void CircularArray<T>::display(){
    for (int i = 0; i < size(); i++){
        cout << (*this)[i] << ",";
    }
    cout << endl;
}

template <class T>
void CircularArray<T>::arraydata(int arr[]){
    for (int i = 0; i < size(); i++){
        arr[i] = (*this)[i];
    }
}

template <class T>
void CircularArray<T>::reverse(){
    int n = size();
    int tarr[n]={0};
    CircularArray<T>* arr = new CircularArray<int>(capacity);
    int temp = front; 
    while(temp != back){
        arr->push_front(array[temp]);
        temp = next(temp);
    }
    arr->push_front(array[back]);
    arr->arraydata(tarr);
    for (int i = 0; i < size(); i++){
        (*this)[i] = tarr[i];
    }
}

