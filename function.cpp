#include "function.h"

void Implement::InsertBack(int data)
{
    if(!IsEmpty()){
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new Node(data, NULL);
    }else{
        head = new Node(data, NULL);
    }
    
}

void Implement::InsertFront(int data)
{
    if(!IsEmpty()){
        Node* newNode = new Node(data, head);
        head = newNode;
    }else
        head = new Node(data, NULL);
}

void Implement::InsertAfter(int data,int data_ref)
{
    Node* current = head;
    while(current != NULL){
        if(current->data == data_ref){
            current->next = new Node(data, current->next);
            break;
        }else{
            current = current->next;
        }
    }
    return;
}

void Implement::InsertBefore(int data,int data_ref)
{
    Node* current = head;
    if(!IsEmpty()){
        if (head->data == data_ref) {
            Node* temp = new Node(data, head);
            head = temp;
            return;
        }
        while(current->next != NULL){
            if(current->next->data == data_ref){
                current->next = new Node(data, current->next);
                break;
            }else{
                current = current->next;
            }
        }
    }else
        return;
}

void Implement::Delete(int data)
{
    Node* current = head;
    Node* previous = NULL;
    while (current != 0 && current->data != data) {  // Traversal
        previous = current;                       // 如果current指向NULL
        current = current->next;                  // 或是current->data == x
    }                                             // 即結束while loop
    if(current == NULL)
        return;//no such node to delete or lits is empty
    else if (current == head){
        head = current -> next;
        delete current;
        current = NULL;
    }
    else{
        previous->next = current->next;
        delete current;
        current = NULL;
    }
}

void Implement::DeleteFront()
{
    Node* current = head;
    if(!IsEmpty()){
        head = current -> next;
        delete current;
        current = NULL;
    }
}

void Implement::DeleteBack()
{
    if (IsEmpty()) {
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    
    Node* current = head;
    Node* previous = NULL;
    
    while(current->next != NULL){
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    delete current;
    current = NULL;
}

void Implement::Reverse(){
    Node* current = head;
    if(current == NULL || current->next == NULL){
        return;
    }
    Node* previous = NULL;
    Node* preceding = head->next;
    
    while (preceding != NULL) {
        current->next = previous;      // 把current->next轉向
        previous = current;            // previous往後挪
        current = preceding;           // current往後挪
        preceding = preceding->next;   // preceding往後挪
    }                                  // preceding更新成NULL即跳出while loop
    current->next = previous;
    head = current;
}


void Implement::Rotate(int k)
{
    if (k == 0)
        return;
    
    Node* current = head;
    
    int count = 1;
    while (current->next != NULL)
    {
        ++count;
        current = current->next;
    }
    k = k % count;
    
    current->next = head;
    
    Node* temp = head;
    Node* previous = NULL;
    
    for (int i = 0; i < count - k; i++) {
        previous = temp;
        temp = temp -> next;
    }
    head = temp;
    previous->next = NULL;
}

