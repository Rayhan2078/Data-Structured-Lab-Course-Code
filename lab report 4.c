#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void display (struct Node *node)
{
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf ("\n");
}

int searchElement (struct Node *head, int item, int index)
{
  if (head == NULL)
    return -1;
  if (head->data == item)
    return index;
  index++;
  return searchElement (head->next, item, index);
}

int main ()
{
  int item;

  struct Node *head = NULL;
  struct Node *node2 = NULL;
  struct Node *node3 = NULL;
  struct Node *node4 = NULL;

  head = (struct Node *) malloc (sizeof (struct Node));
  node2 = (struct Node *) malloc (sizeof (struct Node));
  node3 = (struct Node *) malloc (sizeof (struct Node));
  node4 = (struct Node *) malloc (sizeof (struct Node));


  head->data = 10;		
  head->next = node2;		 

  node2->data = 15;
  node2->next = node3;

  node3->data = 20;
  node3->next = node4;

  node4->data = 25;
  node4->next = NULL;

  printf ("Linked List: ");
  display (head);

  printf ("Enter element to search: ");
  scanf ("%d", &item);

  int index = searchElement (head, item, 0);

  if (index == -1)
    printf ("Item not found");
  else
    printf ("Item found at position: %d", index + 1);

  return 0;
}
\\



#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Node* SortedMerge(struct Node* a, struct Node* b);
void FrontBackSplit(struct Node* source,
					struct Node** frontRef, struct Node** backRef);

void MergeSort(struct Node** headRef)
{
	struct Node* head = *headRef;
	struct Node* a;
	struct Node* b;

	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	FrontBackSplit(head, &a, &b);

	MergeSort(&a);
	MergeSort(&b);
	*headRef = SortedMerge(a, b);
}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	struct Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}
void FrontBackSplit(struct Node* source,
					struct Node** frontRef, struct Node** backRef)
{
	struct Node* fast;
	struct Node* slow;
	slow = source;
	fast = source->next;

	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}


void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

void push(struct Node** head_ref, int new_data)
{
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

int main()
{
	struct Node* res = NULL;
	struct Node* a = NULL;

	push(&a, 15);
	push(&a, 10);
	push(&a, 5);
	push(&a, 20);
	push(&a, 3);
	push(&a, 2);

	MergeSort(&a);

	printf("Sorted Linked List is: \n");
	printList(a);

	getchar();
	return 0;
}
\\


#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;          // Data
    struct node *next; // Address
}*head;


void createList(int n);
int countNodes();
void displayList();


int main()
{
    int n, total;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList(); 
    total = countNodes();

    printf("\nTotal number of nodes = %d\n", total);

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link data field with data
        head->next = NULL; // Link address field to NULL

        temp = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL; 

                temp->next = newNode; 
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

int countNodes()
{
    int count = 0;
    struct node *temp;

    temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                 
        }
    }
}
\\


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
	
   struct node *next;
   struct node *prev;
};

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next){
      length++;
   }
	
   return length;
}

void displayForward() {

   struct node *ptr = head;
   printf("\n[ ");
	
   while(ptr != NULL) {        
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

void displayBackward() {

   struct node *ptr = last;
   printf("\n[ ");
	
   while(ptr != NULL) {    
	
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr ->prev;
      
   }
	
}

void insertFirst(int key, int data) {

   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   if(isEmpty()) {
      last = link;
   } else {
      head->prev = link;
   }
   link->next = head;
   head = link;
}

void insertLast(int key, int data) {

   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   if(isEmpty()) {
      last = link;
   } else {
      last->next = link;     
      
      link->prev = last;
   }

   last = link;
}

struct node* deleteFirst() {

   struct node *tempLink = head;
	
   if(head->next == NULL){
      last = NULL;
   } else {
      head->next->prev = NULL;
   }
	
   head = head->next;
   return tempLink;
}


struct node* deleteLast() {
   struct node *tempLink = last;
	
   if(head->next == NULL) {
      head = NULL;
   } else {
      last->prev->next = NULL;
   }
	
   last = last->prev;
	
   return tempLink;
}

struct node* delete(int key) {

   struct node* current = head;
   struct node* previous = NULL;
	
   if(head == NULL) {
      return NULL;
   }
   while(current->key != key) {
      //if it is last node
		
      if(current->next == NULL) {
         return NULL;
      } else {
         previous = current;
		
         current = current->next;             
      }
   }

   if(current == head) {
      head = head->next;
   } else {
      current->prev->next = current->next;
   }    

   if(current == last) {
      last = current->prev;
   } else {
      current->next->prev = current->prev;
   }
	
   return current;
}

bool insertAfter(int key, int newKey, int data) {
   struct node *current = head; 
	
   if(head == NULL) {
      return false;
   }

   while(current->key != key) {

      if(current->next == NULL) {
         return false;
      } else {           
         current = current->next;
      }
   }
	
   struct node *newLink = (struct node*) malloc(sizeof(struct node));
   newLink->key = newKey;
   newLink->data = data;

   if(current == last) {
      newLink->next = NULL; 
      last = newLink; 
   } else {
      newLink->next = current->next;         
      current->next->prev = newLink;
   }
	
   newLink->prev = current; 
   current->next = newLink; 
   return true; 
}

void main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("\nList (First to Last): ");  
   displayForward();
	
   printf("\n");
   printf("\nList (Last to first): "); 
   displayBackward();

   printf("\nList , after deleting first record: ");
   deleteFirst();        
   displayForward();

   printf("\nList , after deleting last record: ");  
   deleteLast();
   displayForward();

   printf("\nList , insert after key(4) : ");  
   insertAfter(4,7, 13);
   displayForward();

   printf("\nList  , after delete key(4) : ");  
   delete(4);
   displayForward();
}
