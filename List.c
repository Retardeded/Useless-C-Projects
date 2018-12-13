// author: Piotr Kurek

#include <stddef.h> // size_t
#include <stdint.h> // int_fast32_t
#include <stdbool.h>
#include "list.h"
#include <stdio.h> 
#include <math.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct ForwardList
{
    struct ForwardList * next; 
    T value;

} ForwardList;

ForwardList* constructList(T element)
{
    ForwardList * head = NULL;
    head = malloc(sizeof(ForwardList));
    head->value = element;
    head->next = NULL;
    
    return head;
}

ForwardList* constructListN(size_t elements, T value)
{
    ForwardList * head = NULL;
    head = malloc(sizeof(ForwardList));
    head->value = value;
    head->next = NULL;
    elements--;
    ForwardList *current = head;
    while(elements > 0)
    {
        ForwardList * node = NULL;
        node = malloc(sizeof(ForwardList));
        node->value = value;
        current->next = node;
        current = node;
    }

    return head;
}

void destruct(ForwardList* l)
{
    ForwardList *node = l;
    while(node->next != NULL)
    {
        ForwardList *temp = node;
        node = node->next;
        free(temp);
    }
    l = NULL;
}

ForwardList* cloneList(const ForwardList* l)
{
    ForwardList *secondHead = NULL;
    secondHead = malloc(sizeof(ForwardList));
    secondHead->value = l->value;
    ForwardList *current = l;
    ForwardList *secondCurrent = secondHead;
    while(current->next != NULL)
    {
        ForwardList * node = NULL;
        node = malloc(sizeof(ForwardList));
        node->value = current->next->value;
        secondCurrent->next = node;
        secondCurrent = node;
        current = current->next;
    }

}

void clear(ForwardList* l)
{
    ForwardList *node = l->next;
    while(node->next != NULL)
    {
        ForwardList *temp = node;
        node = node->next;
        free(temp);
    }
}

T get(const ForwardList* l)
{
    return l->value;
}

ForwardList* nextNode(const ForwardList* l)
{
    return l->next;
}
size_t size(const ForwardList* l)
{
    size_t size = 1;
    ForwardList *node = l;
    while(node->next != NULL)
    {
        node = node->next;
        size++;
    }
    return size;
}
T* at(ForwardList* l, size_t index)
{
    ForwardList *node = l;
    int counter = 0;
    while(counter != index)
    {
        node = node->next;
    }
    T *pointer = node->value;
    return pointer;
}
T* front(ForwardList* l)
{
    T *pointer = &(l->value);
    return pointer;
}
T* back(ForwardList* l)
{
    ForwardList *node = l;
    while(node->next != NULL)
    {
        node = node -> next;
    }
    T *pointer = &(node->value);
    return pointer;
}

ForwardList* push_front(ForwardList* l, T element)
{
    ForwardList *newHead = NULL;
    newHead = malloc(sizeof(ForwardList));

}
void main()
{
    
}