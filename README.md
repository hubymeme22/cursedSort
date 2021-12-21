# CursedSort
#### By : Hubert F. Espinola I
#### Last updated : -/-/-
A simple linked list program designed for continuous sorting.

(update from me)
I'm currently second year and I thought this concept (back then) was for sorting but, it turns out that this concept is very similar to run-length encoding compression, but in linked list form.

#### Functions:
- searchInsert(**struct node*** firstNode, **struct node*** dynamicNode, **int** value)
--This function inserts the new value to the list
--***firstNode***  - the head node (starting node)
--***dynamicNode*** - also the head node (just needed for checking and sorting)
--***value*** - the integer value to be inserted

- display_sorted(***struct node**** firstNode)
-- Displays the sorted values on the list.

#### Example usage:

In this example, the array `arr` is sorted:
```C
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
	for (int i = 1; i < arr_size; i++)
		first = searchInsert(first, first, arr[i]);

	// display values from the sorted linked list
	printf("|");
	display_sorted(first);
	printf("\n");
	================ end ===============
```

`Example output : | 1 | 1 | 2 | 3 | 4 | 9 | 40 |`

In this example, the input of the user is sorted during run-time:
```C
	int first_value = 1;
	int stored;

	// make a new node
	struct node* first = malloc(sizeof(struct node));
	first->next = NULL;
	first->prev = NULL;

	// user input on the first node
	printf ("Enter value : ");
	scanf("%i", &stored);
	
	// store the user's first input
	first->value = stored;
	first->frequency = 1;
	
	// display visual every after input
	printf("|");
	display_sorted(first);
	printf("\n");
	
	// loop the process above
	while (1) {
		printf ("Enter value : ");
		scanf("%i", &stored);
		first = searchInsert(first, first, stored);

		printf("|");
		display_sorted(first);
		printf("\n");

	}
```
