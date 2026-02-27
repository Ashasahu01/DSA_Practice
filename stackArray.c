#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int Top;
    int *S;  //s as ptr so that later we dynamically allocate array
};

void create(struct stack *st){
    printf("Enter size: ");
    scanf("%d", &st->size);
    st->Top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void Display(struct stack st){
    int i;
    for(i=st.Top; i>=0;i--)
        printf("%d ",st.S[i]);
}

void push(struct stack *st, int x){
    if(st->Top==st->size-1)
        printf("Stack overflow\n");
    else{
        st->Top++;
        st->S[st->Top] = x;

    }
}

int pop(struct stack *st){
    int x = -1;
    if(st->Top == -1)
        printf("Stack underflow\n");
    else{
        x = st->S[st->Top];
        st->Top--;
    }
    return x;
}

int peek(struct stack st, int pos){
    int x = -1;
    if((st.Top-pos +1 )<0)
        printf("Invalid position \n");
    else
        x = st.S[st.Top-pos+1];

    return x;
}

int isEmpty(struct stack st){
    if(st.Top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack st){
    if(st.Top == st.size - 1)
        return -1;
    else
        return 0;
}

int stackTop(struct stack st){
    if(st.Top == -1)
        return -1;
    else
        return st.S[st.Top];
}

int main(){
    struct stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    push(&st, 50);
    push(&st, 60);  //shows stack overflow if we give size less than 6

    printf("%d \n",pop(&st));
    printf("%d \n",pop(&st));

    Display(st);

    return 0;
}