Created by Hubert F. Espinola I
Last updated : January 1, 2021

This program was designed for continuous sorting
= Since the program is using a linked list, the size of input does not matter
= Note that each of the list has "frequency" data member which determines the occurence of the "value" data member

Function :
	searchInsert(struct node* firstNode, struct node* dyamicNode, int value);
		- Searches for the proper position of the value and inserts it or adds frequency of occurence if a node with the same value already exists in the node
	display_sorted(struct node* firstNode);
		- Displays the value of each node

	Parameters:
	firstNode = first node of the linked list
	dynamicNode = first node but is needed to be passed twice for recursion purposes (lol, idk the term)
	value = an integer input

Uses:
	For sorting an array:
	============ example code ==========
	int arr[] = {1, 2, 3, 1, 4, 40, 9};
	int arr_size = 7;

	// initialize the first value
	struct node* first = malloc(sizeof(struct node));
	first->next = NULL;
	first->prev = NULL;

	first->value = arr[0];
	first->frequency = 1;

	// pass the rest of the array as inputs
	for (int i = 1; i < arr_size; i++) {
		first = searchInsert(first, first, arr[i]);
	}

	// display values from the sorted linked list
	display_sorted(first);	
	================ end ===============



	For sorting user's input
	==================== example code ===================
	int first_value = 1;
	int stored;

	// make a new node
	struct node* first = malloc(sizeof(struct node));
	first->next = NULL;
	first->prev = NULL;

	while (1) {
		printf ("Enter value : ");
		scanf("%i", &stored);
		first = searchInsert(first, first, stored);
	}
	======================== end ========================
