#include <iostream>

using namespace std;

struct node{
    int payload;
    node* next;
    node(int payload){this->payload = payload;next = nullptr;};
};

class linkedList{
    node *head,*tail;
public:
    linkedList():head(nullptr),tail(nullptr){};

    bool empty(){
        return head == nullptr;
    }

    void push_back(int value){
        if(empty()){
            head = tail = new node(value);
        }else{
            tail->next = new node(value);
            tail = tail->next;
        }
    }

    void pop_front(){
        if(empty()) {throw "The list is empty!";}
        node* first_node = head;
        head = head->next;
        delete first_node;
    }

    int front(){
        if(empty()){throw "The list is empty!";}
        return head->payload;
    }

    void output(){
        node* iterator = head;
        while(iterator){
            cout<<iterator->payload<<endl;
            iterator = iterator->next;
        }
    }

};

linkedList merge(linkedList a,linkedList b){
    linkedList result;
    while(!a.empty()||!b.empty()){
        if(a.empty()){
            result.push_back(b.front());
            b.pop_front();
        }else if(b.empty()){
            result.push_back(a.front());
            a.pop_front();
        }else if(a.front()>b.front()){
            result.push_back(b.front());
            b.pop_front();
        }else {
            result.push_back(a.front());
            a.pop_front();
        }
    }
    return result;
}

int main()
{
    linkedList a,b;

    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    a.push_back(9);

    b.push_back(2);
    b.push_back(4);
    b.push_back(6);
    b.push_back(8);
    b.push_back(10);

    a.output();
    cout<<endl;
    b.output();
    cout<<endl;

    linkedList result = merge(a,b);
    result.output();

    return 0;
}
