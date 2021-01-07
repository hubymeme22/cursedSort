#include <stdio.h>
#include <stdlib.h>
//////////// initialize ////////////////
struct node {
	int value;
	int frequency;

	struct node* next;
	struct node* prev;
};

// search all the values from first to last list
//struct node* searchInsert(struct node* first, int value);
struct node* searchInsert(struct node* first, struct node* dynamic, int value);
void display_sorted(struct node* first);

//////////// main function ////////////
int main() {
	// value to be stored
	int value;

	// first node
	struct node* first = malloc(sizeof(struct node));
	struct node* current;

	// initialize the first value in array
	first->next = NULL;
	first->prev = NULL;

	// enter values and sort it
	printf("Enter a value to be sorted : ");
	scanf("%i", &value);
	first->value = value;
	first->frequency = 1;

	printf("|");
	display_sorted(first);
	printf("\n");

	while (1) {
		printf("Enter a value to be sorted : ");
		scanf("%i", &value);

		first = searchInsert(first, first, value);

		printf("|");
		display_sorted(first);
		printf("\n");
	}

	return 0;
}

/////////// redefinition /////////////
// search for value and insert in appropriate position
// returns the first position
struct node* searchInsert(struct node* first, struct node* dynamic, int value) {
	if (dynamic->value == value) {
		// increment the frequency of occurence
		dynamic->frequency += 1;

		// first node didnt change, so we'll return the same first node
		return first;
	} else if (dynamic->value > value) {
		// make new node
		// assign and update values
		struct node* new_first = malloc(sizeof(struct node));
		new_first->value = value;
		new_first->frequency = 1;

		if (dynamic->prev == NULL) {		// this means dynamic = first
			// if this is the very first node
			// then assign the current node as the first node
			// else, modify the nodes for re-routing
			dynamic->prev = new_first;
			new_first->next = dynamic;
			new_first->prev = NULL;

			// new first node is now assigned
			return new_first;
		} else {
			// re-route
			dynamic->prev->next = new_first;
			new_first->prev = dynamic->prev;
			new_first->next = dynamic;
			dynamic->prev = new_first;

			// same first node
			return first;
		}
	} else {
		// check for null
		// if there's a null, make new node and assign it as the last node
		// if next node is not null, then recurse the process
		if (dynamic->next == NULL) {
			// make new node
			struct node* newnode = malloc(sizeof(struct node));
			newnode->frequency = 1;
			newnode->value = value;

			// connect the nodes
			newnode->next = NULL;
			newnode->prev = dynamic;
			dynamic->next = newnode;

			// same first node
			return first;
		} else {
			// recurse hahaha lol noice.
			return searchInsert(first, dynamic->next, value);
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
