#include <stdio.h>
#include <stdlib.h>

/**
 @author Md.Tanjim Mahtab Taosif (213902007) <itsmahtab007@gmail.com>
 */

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_node(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void print_list()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void find_node(int data)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("%d is present in the list\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%d is not present in the list\n", data);
}

int main()
{
    insert_node(1);
    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);
    insert_node(6);
    insert_node(7);
    insert_node(8);
    insert_node(9);
    insert_node(10);
    printf("Automatically generated list: ");
    print_list();
FindNode:
    printf("\nEnter the element to find: ");
    int data;
    scanf("%d", &data);
    find_node(data);
    goto FindNode;
    return 0;
}