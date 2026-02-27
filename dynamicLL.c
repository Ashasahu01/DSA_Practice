#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;  //Node used as a type 

Node* Input(){
    int data;
    scanf("%d", &data);

    Node *head = 0;
    Node *tail = 0;

    while(data != -1){
        Node* n = (Node*)malloc(sizeof(Node));
        n->data = data;
        n->next = NULL;
        
        if(head == NULL){  //if LinkedList were not created
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
        scanf("%d", &data);
    }

    return head;
}

int main(){
    Input();
   

    return 0;
}