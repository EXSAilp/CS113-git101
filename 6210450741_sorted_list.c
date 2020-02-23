/*6210450741 Satayoo Maneekul*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct Node 
{
    int number;
    struct Node *i;
};

void sort(struct Node **n1, struct Node *n2) 
{
    struct Node *a;
    if (*n1 == NULL || (*n1)->number >= n2->number) 
    {
        n2->i = *n1;
        *n1 = n2;
    }
    else 
    {
        a = *n1;
        while (a->i != NULL && a->i->number < n2->number) 
        {
            a = a->i;
        }
        n2->i = a->i;
        a->i = n2;
    }
}

int main() 
{
    struct Node *first = NULL;
    struct Node *second = NULL;
    int x;

    while (scanf("%d", &x),x != -1) 
    {
        struct Node *second = (struct Node *)malloc(sizeof(struct Node));

        second->number = x;
        second->i = NULL;

        sort(&first, second);
    }
    for(;first;first=first->i)
    {
        printf("%d\n", first->number);
    }  
}