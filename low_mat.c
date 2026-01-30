#include <stdio.h>
#include <stdlib.h>
struct matrix
{
    int *A; // we cannot take a fix size so that we use pointer create it dynamically for our req size
    int n;
};
void Set(struct matrix *m, int i, int j, int x) // it sets the value of lower triangular elements
{
    if (i >= j)
        m->A[i * (i - 1) / 2 + j - 1] = x;
}

int Get(struct matrix m, int i, int j) // it returns the values
{
    if (i >= j)
        return m.A[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

void Display(struct matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[i] * (i - 1) / 2 + j - 1);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct matrix m;
    int x;
    printf("Enter Dimension of Matrix");
    scanf("%d", &m.n);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    printf("Enter all elements");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("\n \n");
    Display(m);

    return 0;
}