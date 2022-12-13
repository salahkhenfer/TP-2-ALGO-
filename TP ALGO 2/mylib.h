
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL; // THIS A LOCAL DECLARITON OF HEAD

// THIS FOUNCTION YOU WILL GET A SINGEL ELEMENT
struct Node *GetNewNode(int data)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    return NewNode;
}
// THIS IS PRINT THE LIST
void display()
{
    struct Node *temp;
    int n = 1;

    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");

        while (temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}

// INSERT IN EMLEMENT IN THE LIST IN THE END
void insert(int data)
{ // IF LIST EMPTY
    if (head == NULL)
    {
        head = GetNewNode(data);
        return;
    }
    // IF LIST NON EMPTY INSERT ELEMENT
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    struct Node *current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = newnode;
    newnode->prev = current;
}
// DELATE AN ELEMENT IN THE LIST JEUST TAP VALUE
void removed(int val)
{
    struct Node *temp = head;
    struct Node *last = NULL;
    while (temp->data != val)
        temp = temp->next;
    last = temp->prev;
    last->next = temp->next;
    free(temp);
}
// SERCH AN ELEMENT IN THE LIST JEUST TAP VALUE
void serch(int val)
{
    struct Node *temp = head;
    while (temp->data != val)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            break;
        }
    }

    if (temp == NULL)
    {
        printf(" le data %d est ne exist pa \n ", val);
        return;
    }
    else
    {
        printf("le data %d  est exist\n ", val);
        return;
    }
}
// THIS IS SORTING THE ELEMENT OF LIST AT InseritonSort ALGORITHME

void InseritonSort()
{
    struct Node *current = NULL, *index = NULL;
    int temp;
    if (head == NULL)
    {
        return;
    }
    else
    {
        for (current = head; current->next != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data > index->data)
                {
                    swap(&(current->data), &(index->data));
                }
            }
        }
    }
}
// THIS IS SORTING THE ELEMENT OF LIST AT selectionSort ALGORITHME

void selectionSort()
{
    struct Node *key, *temp = NULL;
    key = head;

    while (key != NULL)
    {
        temp = key->next;
        while (temp != NULL)
        {
            if (key->data > temp->data)
            {
                swap(&(key->data), &(temp->data));
            }
            temp = temp->next;
        }
        key = key->next;
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// QUICK SORT

// THIS FOUNCTION GET LAST NODE IN THE LIST IN THE RIGHT
struct Node *lastNode(struct Node *LAST)
{
    while (LAST && LAST->next)
        LAST = LAST->next;
    return LAST;
}
// GIT A PIVOT IN THE LIST
struct Node *pivot(struct Node *head, struct Node *last)
{
    struct Node *base = head;
    struct Node *Front = head;
    int n = 0;

    while (Front != NULL && Front != last)
    {
        if (Front->data < last->data)
        {
            base = head;
            // swap(&(head->data), &(Front->data));
            n = head->data;
            head->data = Front->data;
            Front->data = n;
            head = head->next;
        }
        Front = Front->next;
    }
    // swap(&(head->data), &(last->data));
    n = head->data;
    head->data = last->data;
    last->data = n;
    return base;
}
void callquickSort(struct Node *head, struct Node *last)
{

    if (head == last)
    {
        return 0;
    }
    // struct Node *base = pivot(head, last);
    struct Node *base = pivot(head, last);
    if (base != NULL && base->next != NULL)
    {
        callquickSort(base->next, last);
    }
    if (base != NULL && head != NULL)
    {
        callquickSort(head, base);
    }
}

// THIS IS TIKE A FIRTST ELEMENT AND LAST IN THE LIST
void quickSort()
{
    struct Node *h = lastNode(head);

    callquickSort(head, h);
}
// THIS IS FILL THE LIST IN THE N FALUE
void Fill(int N)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        temp->data = N;
        temp = temp->next;
    }
}
// THIS IS FILL THE LIST IN THE RANDOM FALUE

void FillRandiom(int n)

{
    // if you want to add element randomly
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 100;
        insert(x);
    }
}
// GET THE LANGHT OF LIST
int LongList(struct Node *high, struct Node *low)
{
    struct Node *temp = head;
    int longoflist = 0;
    if (temp != NULL)
    {
        while (temp != low)
        {
            longoflist++;
            temp = temp->next;
        }
    }
    return longoflist;
}

// THIS IS TAKE A PIVOT RANDOMLY

struct Node *Randpivot(struct Node *high, struct Node *low)
{
    int k, n, i = 0;
    if (high == low)
        return low;
    n = LongList(high, low);
    struct Node *piv = high;
    k = rand() % n;
    for (i = 0; i < k - 1; i++)
    {
        piv = piv->next;
    }
    return piv;
}

