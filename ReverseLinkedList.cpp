#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* reverseLinkedList(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* second = head->next;
    Node* newHead = reverseLinkedList(second);
    second->next = head;
    head->next = nullptr;
    return newHead;
}

Node* reverseLinkedListNoRecursive(Node* head){
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* temp = head->next;
    Node* tempPrevious = head;
    head->next = nullptr;
    while(temp != nullptr){
        Node* tempNext = temp->next;
        temp->next = tempPrevious;
        tempPrevious = temp;
        temp = tempNext;
    }
    return tempPrevious;
}

int main()
{
    Node* head = nullptr;
    for(int i=1;i<=10;i++){
        Node* node = new Node;
        node->value = i;
        node->next = head;
        head = node;
    }

    //head = reverseLinkedList(head);
    head = reverseLinkedListNoRecursive(head);

    for(int i=1;i<=10;i++){
        cout<<head->value<<endl;
        head = head->next;
    }
    return 0;
}
