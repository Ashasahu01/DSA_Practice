#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node *next;
};

typedef struct {
        struct node *s1;
        struct node *s2;
} queue;

queue Q = {NULL,NULL};

void enqueue(int item){
        struct node *n = (struct node *)malloc(sizeof(struct node)); // n is our new node
        n->data = item;
        n -> next = Q.s1; //push item into stack s1
        Q.s1 = n;
}

int dequeue(){
        int item = -1;
        if(Q.s1 == NULL && Q.s2 == NULL){
                printf("Queue is Empty.\n");
                return -1;
        }

        if(Q.s2 == NULL){

                while(Q.s1){
                    struct node *temp = Q.s1;
                    Q.s1 = Q.s1->next;
                    temp->next = Q.s2;
                    Q.s2 = temp; 
                }
        }

        struct node *temp = Q.s2;
        item = temp->data;
        Q.s2 = Q.s2->next;
        free(temp);

        return item;
}

void display() {
    struct node *temp;
    
    // Print elements in s2 (front of queue)
    temp = Q.s2;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Print elements in s1 in reverse order (rear of queue)
    int arr[100]; // temporary array
    int i = 0;
    temp = Q.s1;
    while (temp) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d ", arr[j]);
    }

    printf("\n");
}


int main(){

    int choice, value;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

         switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Dequeued Element: %d\n", value);
                break;
            case 3:
                printf("Queue: ");
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
        // enqueue(2);
        // enqueue(4);
        // enqueue(6);

        // printf("Inserted elements in queue: \n");
        // display(); 

        // printf("Deleted elements: \n");
        // printf("%d\n", dequeue());
        // printf("%d \n", dequeue());

        // printf("Queue elements after: \n");
        // display();
        return 0;
}