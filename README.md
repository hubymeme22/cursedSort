<h1>Dont mind me, just skip</h1>

<h2>
Created by Hubert F. Espinola I
</h2>
Last updated : IDK.. maybe, kiss my ass

- This program was designed for continuous sorting

- Since the program is using a linked list, the size of input does not matter

- Note that each of the list has "frequency" data member which determines the occurence of the "value" data member

<h3>Functions :

<b>searchInsert(struct node* firstNode, struct node* dyamicNode, int value);</b>

- Searches for the proper position of the value and inserts it or adds frequency of occurence if a node with the same value already exists in the node


<b>display_sorted(struct node* firstNode);</b>

- Displays the value of each node


<h3>Parameters:</h3>

<b>firstNode</b> - first node of the linked list

<b>dynamicNode</b> - first node but is needed to be passed twice for recursion purposes (lol, idk the term)

<b>value</b> - an integer input

<h3>Uses:</h3>

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
	printf("|");
	display_sorted(first);
	printf("\n");
	================ end ===============



For sorting user's input

	==================== example code ===================
	int first_value = 1;
	int stored;

	// make a new node
	struct node* first = malloc(sizeof(struct node));
	first->next = NULL;
	first->prev = NULL;

	// user input
	printf ("Enter value : ");
	scanf("%i", &stored);
	
	// store that cutie input
	first->value = stored;
	first->frequency = 1;
	
	// display visual
	printf("|");
	display_sorted(first);
	printf("\n");
	
	// clap cheeks
	while (1) {
		printf ("Enter value : ");
		scanf("%i", &stored);
		first = searchInsert(first, first, stored);

		printf("|");
		display_sorted(first);
		printf("\n");

	}
	======================== end ========================
