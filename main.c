#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node {
	int data;
	Node *next;
};

void reverse_list(Node **head);

int main(int argc, char *argv[]) {
	Node *head = NULL;
	int i;
	Node *temp;

	for (i = 0; i < 10; i++) {
		temp = (Node*) malloc(sizeof(Node));
		if (temp == NULL) {
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	reverse_list(&head);
	temp = head;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

void reverse_list(Node **head) {
	Node *current = *head;
	Node *prev = NULL;
	Node *next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
}
