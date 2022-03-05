/********************************************
	Class: Data Structure and Algorithms, KECE208
		   2nd semester, 2018

	1st Project: List
	linked_list.c

	Name:
	StudentID:
	E-mail:

**********************************************/

#include "linked_list.h"
#include "string.h"
extern int list_exist;

/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
 */


struct linked_list* create_list (int number_of_nodes, int list_type)
{
	int a[number_of_nodes];
	int i, j;
	int bFound;

	if (number_of_nodes < 1)
	{
		printf("Function create_list: the number of nodes is not specified correctly \n");
		return NULL;
	}
	if(list_exist == 1)
	{
		printf("Function create_list: a list already exists \n Restart a Program \n");
		exit(0);	
	}
	if(list_type != 0 && list_type != 1)
	{
		printf("Function create_list: the list type is wrong\n");
		exit(0);	
	}
	struct linked_list * new_list = (struct linked_list*)malloc(sizeof(struct linked_list));
	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->number_of_nodes = 0;
	new_list->type_of_list = list_type;

	//now put nodes into the list with random numbers.
	srand((unsigned int)time(NULL));
	if(list_type == 0)
	{
		for ( i = 0; i < number_of_nodes; ++i )
		{
			while ( 1 )
			{
                    
				a[i] = rand() % number_of_nodes + 1;
				bFound = 0;
				for ( j = 0; j < i; ++j )
				{
					if ( a[j] == a[i] )
					{
						bFound = 1;
						break;
					}
				}
				if ( !bFound )
					break;
			}
			struct linked_node* new_node = create_node(a[i]);
			insert_node(new_list, new_node);
		}
	}
	else if(list_type == 1)
	{
		for ( i = 0; i < number_of_nodes; ++i )
		{
			while ( 1 )
			{
                    
				a[i] = rand() % number_of_nodes + 1;
				bFound = 0;
				for ( j = 0; j < i; ++j )
				{
					if ( a[j] == a[i] )
					{
						bFound = 1;
						break;
					}
				}
				if ( !bFound )
					break;
			}
			struct linked_node* new_node = create_node(a[i]);
			push_Stack(new_list, new_node);
		}
	}
	list_exist = 1;
	printf("List is created \n");
	return new_list;
}
/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
*/

void remove_list(struct linked_list* list)
{
	int total = list->number_of_nodes;						// original number of nodes

	if(total == 1)							// if number of nodes is 1.
	{
		struct linked_node* delNode = list->head;
		printf("The node with value %d is deleted!\n", delNode->value);	// remove the first node
		free(delNode);
		list->number_of_nodes--;
		free(list);									// remove the list
		list_exist = 0;
		printf("The list is completely deleted: %d nodes are deleted\n", total);
	} else {
		struct linked_node* delNode = list->head;
		list->head = delNode->next;
		
		printf("The node with value %d is deleted!\n", delNode->value);	// remove the first node
		free(delNode);

		while(list->head != NULL)									// remove until the last node
		{
			struct linked_node* realDelNode = list->head;
			list->head = list->head->next;
			printf("The node with value %d is deleted!\n", realDelNode->value);
			free(realDelNode);
			list->number_of_nodes--;
		}

		free(list);
		list_exist = 0;									// remove the list.
		printf("The list is completely deleted: %d nodes are deleted\n", total);
	}
}

/*	
	@Function name: remove_list
	@Parameters: struct linked_list* list
	@Returns: return void;
	@Descriptions: If number of nodes is 1, remove the first and then remove the list. If number of nodes is not 1, remove each node using while loop and then remove the list.
	@Error cases:
 */
struct linked_node* create_node (int node_value)
{
	struct linked_node* node = (struct linked_node*)malloc(sizeof(struct linked_node));
	node->value = node_value;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
*/
void insert_node(struct linked_list* list, struct linked_node* node)
{
	node->next = NULL;
	node->prev = NULL;

	if(list->head == NULL)		//if head is NULL, tail is also NULL.
	{
		list->head = node;
		list->tail = node;
		list_exist = 1;
	}
	else if(list->head == list->tail)
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	else if(list->head != list->tail)
	{
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	(list->number_of_nodes)++;
}

/*	
	@Function name:
	@Parameters:
	@Returns:	
	@Descriptions:	
	@Error cases:
 */
void advanced_insert_node(struct linked_list* list, struct linked_node* node, int nth_node, int start_point)
{

	if(list_exist == 0)
	{
		printf("There is no list.\n");
		exit(0);
	}

	
	if(nth_node < 0)
	{
		printf("Function advanced_insert_node: The specified order is not proper value to be used\n");
		exit(0); //exit
	}

	if(start_point == 0) {							// In case of head,

		if(nth_node >= list->number_of_nodes)					// if order is bigger than number of nodes, confirm repetition and insert at tail.
		{
			struct linked_node* cur = list->head;

			while(1)
			{
				if(cur->value == node->value)
				{
					printf("Function advanced_insert_node: A duplicate number exists\n");
					exit(0); //exit
				}

				if(cur->next == NULL)
					break;
				
				cur = cur->next;
			}

			node->prev = list->tail;
			list->tail->next = node;
			list->tail = node;
			list->number_of_nodes++;
			return;

		} else if(nth_node == 0) {
			struct linked_node* cur = list->head; // confirm repetition and then insert at head.

			while(1)
			{
				if(cur->value == node->value)
				{
					printf("Function advanced_insert_node: A duplicate number exists\n");
					exit(0); //exit
				}

				if(cur->next == NULL)
					break;
				
				cur = cur->next;
			}
			node->next = list->head;
			list->head->prev = node;
			list->head = node;
			list->number_of_nodes++;
			return;
		} else {
			struct linked_node* cur = list->head;
			struct linked_node* creNode = list->head;
			int order = 0;

			while(1)
			{

				if(order == nth_node)
					creNode = cur;

				if(cur->value == node->value)
				{
					printf("Function advanced_insert_node: A duplicate number exists\n");
					exit(0);
				}

				if(cur->next == NULL)
					break;
				
				order++;
				cur = cur->next;
			}

			node->prev = creNode->prev;						// First, link new node
			node->next = creNode;

			creNode->prev->next = node;						// change original links.
			creNode->prev = node;

			list->number_of_nodes++;
			return;
		}

	} else {

		if(nth_node >= list->number_of_nodes)					// If order is bigger than number of nodes insert
		{
			struct linked_node* cur = list->tail;

			while(1)
			{
				if(cur->value == node->value)
				{
					printf("Function advanced_insert_node: A duplicate number exists\n");
					exit(0);
				}

				if(cur->prev == NULL)
					break;
				
				cur = cur->prev;
			}
			
			node->next = list->head;
			list->head->prev = node;
			list->head = node;
			list->number_of_nodes++;
			return;

		} else if(nth_node == 0) {

			struct linked_node* cur = list->tail;

			while(1)
			{
				if(cur->value == node->value)
				{
					printf("Function advanced_insert_node: A duplicate number exists\n");
					exit(0);
				}

				if(cur->prev == NULL)
					break;
				
				cur = cur->prev;
			}

			node->prev = list->tail;
			list->tail->next = node;
			list->tail = node;
			list->number_of_nodes++;
			return;
		} else {

			struct linked_node* cur = list->tail;
			struct linked_node* creNode = list->tail;
			int order = 0;

			while(1)
			{

				if(order == nth_node)
					creNode = cur;

				if(cur->value == node->value)
				{
					printf("Function advanced_insert_node: A duplicate number exists\n");
					exit(0); //exit
				}

				if(cur->prev == NULL)
					break;
				
				order++;
				cur = cur->prev;
			}

			node->next = creNode->next;						// First, link new node
			node->prev = creNode;

			creNode->next->prev = node;						// change original links.
			creNode->next = node;

			list->number_of_nodes++;
			return;
		}

	}
}
	
/*	
	@Function name: advanced_insert-node
	@Parameters: struct linked_list* list, struct linked_node* node, int nth_node, int start_point
	@Returns: return void	
	@Descriptions: n is smaller than 0 -> print error. n is bigger than number of nodes -> after confirm repetition, insert at list->tail or head. else -> after confirm repetition, insert at before (from head) or after (from tail) creNode.  	
	@Error cases:
 */

void remove_node(struct linked_list* list, int rm_node_value)
{

	if(list_exist == 0)
	{
		printf("There is no list.\n");
		exit(0);
	}
	
	if(list->type_of_list == 1)					// Stack is not allowed
	{
		printf("Function remove_node: The list type is not normal. Removal is not allowed\n");
		exit(0);
	}

	struct linked_node* cur = list->head;
	struct linked_node* delNode = list->head;				// node to remove
	// int list_del = (list->number_of_nodes == 1) ? 1 : 0;

	while(1)
	{
		if(cur->value == rm_node_value)
		{
			delNode = cur;
			break;
		}

		if(cur->next == NULL)
			break;
		
		cur = cur->next;
	}

	if(delNode->value != rm_node_value)					// if value of delNode is not rm node value?
	{
		printf("Function remove_node: There is no such node to remove\n");  // there is no such node.
		exit(0);
	}

	if(list->number_of_nodes == 1) {
		free(delNode);
		list->number_of_nodes--;
		printf("node deleted\n");
		free(list);
		list_exist = 0;
		printf("list deleted\n");
	}
	else if(delNode == list->head)
	{
		list->head = delNode->next;
		list->head->prev = NULL;
		free(delNode);
		list->number_of_nodes--;
		printf("node deleted\n");
	}
	else if(delNode == list->tail)
	{
		list->tail = delNode->prev;
		list->tail->next = NULL;
		free(delNode);
		list->number_of_nodes--;
		printf("node deleted\n");
	} else {
		delNode->prev->next = delNode->next;				// Because node to remove is delNode, start remove
		delNode->next->prev = delNode->prev;

		free(delNode);
		list->number_of_nodes--;

		printf("node deleted\n");
	}
		
	return;
}
/*	
	@Function name:remove_node
	@Parameters: struct linked_list* list, int rm_node_value
	@Returns: void
	@Descriptions: if, type of the list is normal, search the node and if there is a node to remove, remove that node. If the number of the node is 1, remove list after remove the node.
	@Error cases
 */
void push_Stack(struct linked_list* list, struct linked_node* node)
{
	if (list->type_of_list == 0)								// only stack list
	{
		printf("Function push_Stack: The list type is not a stack\n");
		exit(0);
	}

	struct linked_node* newNode = node;

	if(list->number_of_nodes == 0)
	{
		list->head = newNode;
		list->tail = newNode;
		list->number_of_nodes++;
		return;
	} else {
		list->tail->next = newNode;
		newNode->prev = list->tail;
		list->tail = newNode;
		list->number_of_nodes++;
		return;
	}
}
/*	
	@Function name: push_Stack
	@Parameters: struct linked_list* list, struct linked_node* node
	@Returns: return void
	@Descriptions: if type of the list is stack, insert new node at the tail of list.
	@Error cases:
 */
void pop_Stack(struct linked_list* list, int number)
{
	if (list->type_of_list == 0)								// only stack
	{
		printf("Function push_Stack: The list type is not a stack\n");
		return;
	}

	if (list->number_of_nodes < number)
	{
		printf("Function popStack: The number of nodes which will be removed is more than that in the stack\n");
		return;
	} else if (number < 1) {
		printf("Function popStack: The number of nodes which will be removed is more than 1\n");
		return;
	} else if (list->number_of_nodes == number) {

		while(1)											//delete the node as many as input number
		{
			struct linked_node* delNode = list->tail;
			list->tail = delNode->prev;
			list->tail->next = NULL;
			free(delNode);
			list->number_of_nodes--;
			number--;
			if(number == 1)
				break;
		}

		struct linked_node* delNode = list->head;
		free(delNode);
		list->number_of_nodes--;
		free(list);											//remove the list
		list_exist = 0;
		return;

	} else {

		while(1)									//delete the node as many as input number
		{
			struct linked_node* delNode = list->tail;
			list->tail = delNode->prev;
			list->tail->next = NULL;
			free(delNode);
			list->number_of_nodes--;
			number--;
			if(number == 0)
				break;
		}

		return;
	}
}
/*	
	@Function name: pop_Stack
	@Parameters: struct linked_list* list, int number
	@Returns: void	
	@Descriptions: if input number is wrong, print the error and then exit the program.delete the node from the tail as many as input number. if function remove all node in the list, remove the list, too.
	@Error cases:
 */

void search_node(struct linked_list* list, int find_node_value)
{
	if(list->head == NULL)
	{
		printf("Function search_node : There is no such node to search.");
		exit(0);
	}

	
	struct linked_node* cur = list->head;
	int od = 1;

	if (cur->value == find_node_value)
	{
		printf("The order of %d is %d.\n", find_node_value, od);
		return;
	}

	while(cur->next != NULL)
	{
		cur = cur->next;
		od++;

		if (cur->value == find_node_value)
		{
			printf("The order of %d is %d.\n", find_node_value, od);
			return;
		}
	}

	printf("Function search_node : There is no such node to search.\n");	
	exit(0);

}

/*	
	@Function name: search_node
	@Parameters: struct linked_list* list, int find_node_value
	@Returns: void
	@Descriptions: linearly search the node whose value is equal to find_node_value. if search the node successfully, print the order of node. else -> print the error message and exit the program.
	@Error cases:
 */

void reverse_range(struct linked_list* list, int order1, int order2)
{
	if(order1 > order2 || order1 <= 0 || order2 > list->number_of_nodes)
	{
		printf("Function reverse_range: Input value is invalid");
		exit(0); //exit
	}

	if(order1==order2)
		return;

	int n = order1-order2+1;
	int order = 1,i;
	struct linked_node* stg[order2-order1+1];      //In create_list, there is also array statement with parameter.
	struct linked_node* cur = list->head;

	if(order1==1 && order2==list->number_of_nodes) {
		reverse_range(list, order1+1, order2-1);
		list->tail->prev->next = list->head;	// link the node before the last node
		list->head->prev = list->tail->prev;
		list->head->next->prev = list->tail;	// link the node after the first node
		list->tail->next = list->head->next;

		list->head = list->tail;
		list->tail = cur;
		list->head->prev = NULL;
		list->tail->next = NULL;

		return;

	} else if(order1 == 1) {
		struct linked_node* postNode = list->tail;

		while(1)
		{
			if(order == order2+1)
				postNode = cur;
			
			if(order >= order1 && order <= order2)
				stg[order-order1] = cur;
			
			if(cur->next == NULL)
				break;

			order++;
			cur = cur->next;
		}
		order = order2-order1;
		list->head = stg[order];			// link the first node
		list->head->prev = NULL;
		postNode->prev=stg[0];				// link the last node
		stg[0]->next = postNode;

		for(i=order; i>0; i--)
		{
			stg[i]->next = stg[i-1];
			stg[i-1]->prev = stg[i];
		}

		return;
		
		
	} else if (order2 == list->number_of_nodes) {
		struct linked_node* preNode = list->head;

		while(1)
		{
			if(order == order1-1)
				preNode = cur;
			
			if(order >= order1 && order <= order2)
				stg[order-order1] = cur;
			
			if(cur->next == NULL)
				break;
			order++;
			cur = cur->next;
		}

		order = order2-order1;
		list->tail = stg[0];			// link the last node
		list->tail->next = NULL;
		preNode->next = stg[order];		// link the first node
		stg[order]->prev = preNode;

		for(i=order; i>0; i--)
		{
			stg[i]->next = stg[i-1];
			stg[i-1]->prev = stg[i];
		}

		return;

	} else {
		struct linked_node* preNode = list->head;
		struct linked_node* postNode = list->tail;
		while(1)
		{
			if(order == order1-1)
				preNode = cur;
			if(order == order2+1)
				postNode = cur;
			
			if(order >= order1 && order <= order2)
				stg[order-order1] = cur;
			
			if(cur->next == NULL)
				break;
			order++;
			cur = cur->next;
		}

		preNode->next = postNode;
		postNode->prev = preNode;
		cur = preNode;
		order = order2-order1;

		while(1)						// reverse orders
		{
			cur->next = stg[order];
			stg[order]->prev = cur;

			stg[order]->next = (order==0) ? postNode : stg[--order];
			if(stg[order]->next == postNode)
			{
				postNode->prev = stg[order];
				break;
			}
			cur = cur->next;
		}

		return;

	}
	
}

/*	
	@Function name: reverse_range
	@Parameters: struct linked_list* list, int order1, int order2
	@Returns: void	
	@Descriptions: reverse the order of nodes in range of order1 to order2.
	@Error cases:
 */

void modify_node(struct linked_list* list, int modify_node_value, int new_value)
{
		struct linked_node* modNode = list->head;
		struct linked_node* cur = list->head;

		while(1)
		{
			if(cur->value == new_value)							// A duplicate number exists
			{
				printf("Function modify_node: A duplicate number exists\n");			// error
				exit(0);
			}
			if(cur->value == modify_node_value)					// find the node to modify
				modNode = cur;									// founded

			if(cur->next == NULL)								// if cur is the last node -> break the loop
				break;
			
			cur = cur->next;
		}

		if(modNode->value != modify_node_value)					// if there is no node to modify,
		{
			printf("Function modify_node: There is no such value in the list\n");		// error
			exit(0);
		}

		modNode->value = new_value;				// modify the value of node
		printf("The value %d turns into %d.\n", modify_node_value, new_value);
		return;
}
/*	
	@Function name: modify_node
	@Parameters: struct linked_list* list, int modify_node_value, int new_value
	@Returns: return void
	@Descriptions: Traversing the list, compare each node's value with modify_node_value to find the node to modify. If it founded, modify the value of node.
	@Error cases:
 */

void odd_sequence_reverse(struct linked_list* list) 
{
	int i=1;
	while(1)
	{
		if(i*i < list->number_of_nodes)
			reverse_range(list, (i-1)*(i-1)+1, i*i);
		
		if(i*i >= list->number_of_nodes)
			break;
		
		i++;
	}

	reverse_range(list,(i-1)*(i-1)+1, list->number_of_nodes);

	return;
}

/*	
	@Function name: odd_sequence_reverse
	@Parameters: struct linked_list* list
	@Returns: void	
	@Descriptions: This function makes group with its nodes in odd sequence numbers and then make the each group rearranged in reverse order. Makeing group in odd sequence numbers, rearrage the group using reverse_range function that maded before.
	@Error cases:
 */
void print_list(struct linked_list* list)
{
	if(list_exist == 0)
	{
		printf("There is no list to print \n");
		return;
	}
	struct linked_node * temp = list->head;
	printf("****************************************************************************\n\n");
	printf("	Number of nodes: %d \n", list->number_of_nodes);
	printf("\n");
	int i=0;
	for(i=0; i < list->number_of_nodes; i++)
	{
		printf ("%d   ", temp->value);
		temp = temp->next;
	}
	printf("\n");
	printf("****************************************************************************\n\n");
	free(temp); // free local variable..?
}

