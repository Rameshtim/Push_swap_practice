#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

/* function prototypes */
struct Node* SortedMerge(struct Node* a, struct Node* b);
void FrontBackSplit(struct Node* source,
					struct Node** frontRef, struct Node** backRef);

/* Utility function to merge two sorted linked lists */
void MergeSort(struct Node** headRef)
{
	struct Node* head = *headRef;
	struct Node* a;
	struct Node* b;

	// Base case -- length 0 or 1
	if ((head == NULL) ||
		(head->next == NULL))
	{
		return;
	}

	// Split head into 'a' and 'b' sublists
	FrontBackSplit(head, &a, &b);

	// Recursively sort the sublists
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted
	lists together */
	*headRef = SortedMerge(a, b);
}

struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	struct Node* result = NULL;
	struct Node* current = NULL;

	/* Base cases */
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;

	/* Pick either a or b, and iteratively merge */
	while (a != NULL && b != NULL) {
		if (a->data <= b->data) {
			if (result == NULL) {
				result = a;
				current = a;
			} else {
				current->next = a;
				current = a;
			}
			a = a->next;
		} else {
			if (result == NULL) {
				result = b;
				current = b;
			} else {
				current->next = b;
				current = b;
			}
			b = b->next;
		}
	}

	/* If one of the lists is not empty, append it to the result list */
	if (a != NULL) {
		current->next = a;
	} else {
		current->next = b;
	}

	return result;
}

/* Utility function to split the nodes of the given list into front and back halves */
void FrontBackSplit(struct Node* source,
					struct Node** frontRef, struct Node** backRef)
{
	struct Node* fast;
	struct Node* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two at that point */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

/* Function to print nodes in a given linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Function to insert a node at the beginning of the linked list */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}


int main()
{
	struct Node *res = NULL;
	struct Node *a = NULL;
	push(&a,15);
	push(&a,10);
	push(&a,5);
	push(&a,20);
	push(&a,3);
	push(&a,2);

	printf("Unsorted list\n");
	printList(a);

	MergeSort(&a);
	printf("\nSorted list\n");
	printList(a);

}