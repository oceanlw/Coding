#include "stdlib.h"
#include "stdio.h"

typedef struct llnode {
    int value;
    struct llnode *next;
} llnode;


void revert_linked_list(llnode * &head)
{
    llnode *current = head, *temp = NULL, *front = NULL;

    if (head == NULL || head->next == NULL) {
        return;
    }

    temp = current->next;
    front = temp->next;
    temp->next = current;
    current->next = NULL;
    current = temp;

    if (front == NULL)
    {
        head = current;
        return;
    }

    while (front->next)
    {
        temp = front->next;
        front->next = current;
        current = front;
        front = temp;
    }
    
    front->next = current;
    head = front;

    return;
}

void print_linked_list(llnode *head)
{
    llnode *temp = head;

    while (temp)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main(int args, char **argv)
{
    llnode *ll[10], *list;
    int i;

    for (i = 0; i < 10; ++i)
    {
        ll[i] = (llnode *)malloc(sizeof(llnode));
        ll[i]->value = i;
        ll[i]->next = NULL;

        if (i > 0)
        {
            ll[i-1]->next = ll[i];
        }
    }
    list = ll[0];

    print_linked_list(list);
    revert_linked_list(list);
    print_linked_list(list);

    for (i = 0; i < 10; ++i)
    {
        free(ll[i]);
    }
    
    return 0;
}
