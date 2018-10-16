
/*------------------------type declaration------------------------*/
typedef struct {
	int id;
	char name[31];
	int score;
	int nWinGold;
	int nLostGold;
} teamInfo;

typedef teamInfo dataTypeSLL;

typedef struct SLLNode {
	dataTypeSLL data;
	struct SLLNode *next;
} SLLNode;

typedef struct {
	SLLNode *head;
	SLLNode *tail;
} SLL;


/*----------------- Modifire when data type change-----------------*/

void iterateSLL(SLL *list) {
	SLLNode *curr = list->head;
	while (curr != NULL) {

		// TO DO
		curr = curr->next;
	}
	return;
}

/*-----------------------------------------------------------------*/

void SLL_init(SLL *list) {
	list->head = NULL;
	list->tail = NULL;
	return;
}

SLLNode *makeNewSLLNode(dataTypeSLL data) {

	SLLNode *newNode = (SLLNode *) malloc(sizeof(SLLNode));

	newNode->data = data;
	newNode->next = NULL;

	return(newNode);
}

void insertAtHead(SLL *list, dataTypeSLL data) {

	SLLNode *newNode = makeNewSLLNode(data);

	if (list->head == NULL) {
		list->head = list->tail = newNode;
		return;
	}

	newNode->next = list->head;
	list->head = newNode;
	return;
}

void insertAtTail(SLL *list, dataTypeSLL data) {

	SLLNode *newNode = makeNewSLLNode(data);

	if (list->tail == NULL) {
		list->head = list->tail = newNode;
		return;
	}

	list->tail->next = newNode;
	list->tail = newNode;
	return;
}

void insertAfter(SLL *list, SLLNode *targetNode, dataTypeSLL data) {

	if (targetNode == list->tail) {
		insertAtTail(list, data);
		return;
	}

	SLLNode *newNode = makeNewSLLNode(data);

	newNode->next = targetNode->next;
	targetNode->next = newNode;
	return;
}

void insertBefore(SLL *list, SLLNode *targetNode, dataTypeSLL data) {

	if (targetNode == list->head) {
		insertAtHead(list, data);
		return;
	}

	SLLNode *prev = NULL;
	SLLNode *curr = list->head;
	while (curr != targetNode && curr != NULL) {
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		printf("The target node not found! \n");
		return;
	}

	SLLNode *newNode = makeNewSLLNode(data);

	prev->next = newNode;
	newNode->next = curr;
	return;
}

void delete(SLL *list, SLLNode *targetNode) {

	if (targetNode == list->head) {
		list->head = list->head->next;
		free(targetNode);
		return;
	}

	SLLNode *prev = NULL;
	SLLNode *curr = list->head;
	while (curr != targetNode && curr != NULL) {
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL) {
		printf("The target node not found!\n");
		return;
	}

	if (curr == list->tail) {
		prev->next = NULL;
		list->tail = prev;
		return;
	}

	prev->next = curr->next;
	free(curr);
	return;
}

SLLNode *searchById(SLL *list, int id) {

	SLLNode *curr = list->head;
	while (curr != NULL) {

		if (curr->data.id == id) {
			return(curr);
		}
		curr = curr->next;
	}
	return(NULL);
}

