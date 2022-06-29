#include <iostream>
using namespace std;

template<class TList>
class List{
    private:
        template<class TNode>
        class Node{
            public:
                Node *pNext;
                TNode data;
                Node(TNode data = TNode(), Node *pNext = nullptr){ // parametr on default
                    this->data = data;
                    this->pNext = pNext;
                }               
        };
        Node<TList> *head_;
        int size_;
    public:
        List();
        void push_back(TList data);
        int getSize();
        TList& operator[](const int index);
        ~List();
};

template<class TList>
List<TList>::List(){
    size_ = 0;
    head_ = nullptr;
}

template<class TList>
void List<TList>::push_back(TList data){
    if(head_ == nullptr){
        head_ = new Node<TList>(data);
    }
    else{
        Node<TList> *current = this->head_;
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        current->pNext = new Node<TList>(data);
    }
    size_++;
}

template<class TList>
int List<TList>::getSize(){
    return size_;
}

template<class TList>
TList& List<TList>::operator[](const int index){   
    Node<TList> *current = this->head_;
    int indexCurrent = 0;
    while(current != nullptr){        
        if(indexCurrent == index)return current->data;
        current = current->pNext;
        indexCurrent++;
    }
    return current->data; // to avoid warning
}

template<class TList>
List<TList>::~List(){

}

int main(){
    List<int> list;
    int numbersCount;
    cout << "Enter an amount of numbers in list:\n"; 
    cin >> numbersCount; 
    for(int i = 0; i < numbersCount; i++){
        list.push_back(rand() % 10);
    }
    for(int i = 0; i < list.getSize(); i++){
        cout << "list[" << i << "] = " << list[i] << endl;
    }
    return 0;
}