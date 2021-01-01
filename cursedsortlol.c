#include <stdio.h>
#include <stdlib.h>
//////////// global vars //////////////
int max = 3;	// array max

//////////// initialize ////////////////
struct node {
	int value;
	int frequency;

	struct node* next;
	struct node* prev;
};

// search all the values from first to last list
//struct node* searchInsert(struct node* first, int value);
void searchInsert(struct node* first, int value);
void display_sorted(struct node* first);

//////////// main function ////////////
int main() {
	// values to be inserted: 1 2 1 3 5
	struct node* first = malloc(sizeof(struct node));
	struct node* current;

	first->value = 3;
	first->frequency = 1;
	first->next = NULL;

	// needs a changing node (current)
	// and keep track on first node
	current = first;

//	current = searchInsert(current, 3);
//	current = searchInsert(current, 1);
//	current = searchInsert(current, 2);
//	current = searchInsert(current, 4);
// let's try to use a void function for searching and inserting.


	printf("|");
	display_sorted(current);
	printf("\n");

	return 0;
}

/////////// redefinition /////////////
// search for value and insert in appropriatr position
void searchInsert(struct node* first, int value) {
	puts ("SI repeated??");
	if (first->value == value) {
		// increment the frequency of occurence
		first->frequency += 1;
	// value < f
	} else if (first->value > value) {
		// make new node
		// assign and update values
		struct node* new_first = malloc(sizeof(struct node));
		new_first->value = value;
		new_first->frequency = 1;

		// connect the two nodes
		new_first->next = first;
		if (first->prev == NULL) {
			// if this is the very first node
			// then assign the current node as the first node
			// else, modify the nodes for re-routing
			first->prev = new_first;
			new_first->prev = NULL;
		} else {
			// first re-route
			(first->prev)->next = new_first;
			new_first->prev = (first->prev);

			// final re-route
			first->prev = new_first;
			new_first->next = first;
		}
	// value > f
	} else { //if (first->value < value) {
		// check for null
		// if there's a null, make new node and assign it as the last node
		// if next node is not null, then recurse the process
		if (first->next == NULL) {
			// make new node
			struct node* newnode = malloc(sizeof(struct node));
			newnode->frequency = 1;
			newnode->value = value;

			// connect the nodes
			newnode->next = NULL;
			first->next = newnode;
			return first;
		} else {
			// recurse hahaha lol noice.
			return searchInsert(first->next, value);
		}
	}
}

void display_sorted(struct node* list) {
	if (list->next == NULL) {
		for (int i = 0; i < list->frequency; i++) {
			printf (" %i |", list->value);
		}
	} else {
		for (int i = 0; i < list->frequency; i++) {
			printf (" %i |", list->value);
		}
		display_sorted(list->next);
	}
}
