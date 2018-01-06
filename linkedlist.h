#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "account.h"
#endif

struct LinkedList {
	Account *data;
	struct LinkedList *next;
};

typedef struct LinkedList *node;

node createNode ();

node addNode (node head, Account *account);

