#include "linkedlist.h"

node createNode () {
	node temp;
	temp = (node)malloc(sizeof(struct LinkedList));
	temp->next = NULL;
	return temp;
}

node addNode (node head, Account *account) {
	node temp, p;
	temp = createNode();
	temp->data = account;
	if (head == NULL) {
		head = temp;
	} else {
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}	
