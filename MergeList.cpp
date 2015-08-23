#include <iostream>
#include <climits>
#include <queue>

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

    node* gain_head(){
        return head;
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

class compare{
public:
    bool operator()(node* n1,node* n2) const {
    if (!n1 || !n2) return !n1;
    return n1->payload > n2->payload;
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

linkedList mergeK(linkedList array[],int k){
    linkedList result;
    int min = INT_MAX;
    do{
        min = INT_MAX;
        for(int i=0;i<=k-1;i++){
            if(!array[i].empty()){
                if(array[i].front() < min){
                    min = array[i].front();
                }
            }
        }
        for(int i=0;i<=k-1;i++){
            if(!array[i].empty()){
                if(array[i].front() == min){
                    array[i].pop_front();
                    break;
                }
            }
        }
        if(min != INT_MAX) result.push_back(min);
    }while(min != INT_MAX);

    return result;
}

linkedList mergeKListUsePriorityQueues(linkedList array[],int k){
    linkedList result;
    priority_queue<node*,vector<node*>,compare> q;
    for(int i=0;i<=k-1;i++){
        q.push(array[i].gain_head());
    }
    while(q.size() > 0){
        node* temp = q.top();
        q.pop();
        result.push_back(temp->payload);
        if(temp->next != nullptr){
            q.push(temp->next);
        }
    }
    return result;
}
int main()
{
    linkedList a,b,c;

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

    c.push_back(3);
    c.push_back(5);
    c.push_back(9);
    c.push_back(12);
    c.push_back(19);

    //合并2个已排好序的链表
    //linkedList result = merge(a,b);
    linkedList array[] = {a,b,c};
    //合并K个已排好序的链表(O(nk))
    //linkedList result = mergeK(array,3);
    //合并K个已排好序的链表,使用优先队列(O(nlogk))
    linkedList result = mergeKListUsePriorityQueues(array,3);
    result.output();

    return 0;
}
