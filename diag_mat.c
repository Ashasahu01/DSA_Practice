//Diagonal Matrix
#include <stdio.h>

struct Matrix
{
    int A[10];  // Array
    int n;
};

void Set(struct Matrix *m, int i, int j, int x) // it sets the value of diagonal elements
{
    if (i == j)
        m->A[i - 1] = x;
}
int Get(struct Matrix m, int i, int j) // it returns the values
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

void Display(struct Matrix m)   // Display function
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    m.n = 4;

    Set(&m, 1, 1, 5);
    Set(&m, 2, 2, 8);
    Set(&m, 3, 3, 9);
    Set(&m, 4, 4, 12);
    printf("%d \n", Get(m, 1, 1));
    Display(m);
    return 0;
}