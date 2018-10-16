#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SLL.h"

typedef struct {
	int idTeam1;
	int idTeam2;
	int resultTeam1;
	int resultTeam2;
} match;

typedef struct {
	match mat[50];
} round;

int getData(char *fn, SLL *list, round *rounds) {

	FILE *f = fopen(fn, "r");
	if (f == NULL) {
		printf("Can not open file %s\n", fn);
		return(-1);
	}

	int n;
	int i;
	fscanf(f, "%d", &n);

	teamInfo tempData;
	for (i = 0; i < n; i++) {
		fscanf(f, "%d", &(tempData.id));

		fscanf(f, " %[^\n]s", tempData.name);
		/* tempData.name[ strlen(tempData.name) - 1 ] = '\0'; */

		tempData.score = 0;
		tempData.nWinGold = 0;
		tempData.nLostGold = 0;
		
		insertAtTail(list, tempData);
	}

	char tempStr[10];

	for (i = 1; i < n; i++) {
		fgets(tempStr, 10, f);
		fgets(tempStr, 10, f);

		printf("--%s--\n", tempStr);
		
		for (int j = 0; j < (n / 2); j++) {
			fscanf(f, "%d", &(rounds[i].mat[j].idTeam1));
			fscanf(f, "%d", &(rounds[i].mat[j].idTeam2));
		}	
	}

	
	return(n);
}

void printTesmsInfo(SLL *list) {

	SLLNode *curr = list->head;

	printf("%-6s%-30s%-6s%-15s%-15s\n",
		   "ID",
		   "Tendoibong",
		   "Diem",
		   "Sobanthang",
		   "Sobanthua"
		   );
	
	while (curr != NULL) {

		printf("%-6d%-30s%-6d%-15d%-15d\n",
			   curr->data.id,
			   curr->data.name,
			   curr->data.score,
			   curr->data.nWinGold,
			   curr->data.nLostGold
			   );
		curr = curr->next;
	}
	return;
}

void printRounds(SLL *list, round rounds[], int n) {

	int i;
	for (i = 1; i < n; i++) {
		printf("Vong %d\n", i);
		for (int j = 0; j < (n / 2); j++) {
			printf("%s - %s\n",
				   searchById(list, (rounds[i].mat[j]).idTeam1)->data.name,
				   searchById(list, (rounds[i].mat[j]).idTeam2)->data.name
				   );
		}
	}
	
	return;
}

void update(SLL *list, round rounds[], int *order, int n) {

	printf("\nCap nhat ket qua thi dau vong %d\n", *order);
	for (int i = 0; i < (n / 2); i++) {

		SLLNode *team1 = searchById(list, (rounds[*order].mat[i]).idTeam1);
		SLLNode *team2 = searchById(list, (rounds[*order].mat[i]).idTeam2);
		printf("%s - %s : ", team1->data.name, team2->data.name);

		int resultTeam1;
		int resultTeam2;
		
		scanf("%d - %d", &resultTeam1, &resultTeam2);

		rounds[*order].mat[i].resultTeam1 = resultTeam1;
		rounds[*order].mat[i].resultTeam2 = resultTeam2;

		if (resultTeam1 > resultTeam2) {
			team1->data.score += 3;
			team1->data.nWinGold += resultTeam1;
			team1->data.nLostGold += resultTeam2;
			
			team2->data.nWinGold += resultTeam2;
			team2->data.nLostGold += resultTeam1;
		}
		else if (resultTeam1 < resultTeam2) {
			
			team1->data.nWinGold += resultTeam1;
			team1->data.nLostGold += resultTeam2;

			team2->data.score += 3;
			team2->data.nWinGold += resultTeam2;
			team2->data.nLostGold += resultTeam1;
		}
		else {
			team1->data.score += 1;
			team1->data.nWinGold += resultTeam1;
			team1->data.nLostGold += resultTeam2;

			team2->data.score += 1;
			team2->data.nWinGold += resultTeam2;
			team2->data.nLostGold += resultTeam1;
		}
	}

	*order = *order + 1;
	return;
}

int getMinScore(SLL *list) {

	int min = 100;
	SLLNode *curr = list->head;
	while (curr != NULL) {

		if (curr->data.score < min) {
			min = curr->data.score;
		}
		curr = curr->next;
	}
	return(min);
}

void thongke(SLL *list) {

	int minScore = getMinScore(list);

	SLLNode *curr = list->head;
	printf("Cac doi co diem thap nhat la : \n");
	printf("%-6s%-30s%-6s%-15s%-15s\n",
		   "ID",
		   "Tendoibong",
		   "Diem",
		   "Sobanthang",
		   "Sobanthua"
		   );
	while (curr != NULL) {

		if (curr->data.score == minScore) {
			printf("%-6d%-30s%-6d%-15d%-15d\n",
			   curr->data.id,
			   curr->data.name,
			   curr->data.score,
			   curr->data.nWinGold,
			   curr->data.nLostGold
			   );
		}
		curr = curr->next;
	}

	curr = list->head;
	printf("Cac doi con lai la : \n");
	printf("%-6s%-30s%-6s%-15s%-15s\n",
		   "ID",
		   "Tendoibong",
		   "Diem",
		   "Sobanthang",
		   "Sobanthua"
		   );
	while (curr != NULL) {

		if (curr->data.score != minScore) {
			printf("%-6d%-30s%-6d%-15d%-15d\n",
			   curr->data.id,
			   curr->data.name,
			   curr->data.score,
			   curr->data.nWinGold,
			   curr->data.nLostGold
			   );
		}
		curr = curr->next;
	}
	return;
}

int main() {

	int op;

	SLL list;
	SLL_init(&list);

	round *rounds = (round *) malloc( 100 * sizeof(round));

	int n = getData("bongda.txt", &list, rounds);

	int order = 1;
	do {
		printf("---------------------------------------------------\n");
		printf("1. In thong tin cac doi. \n");
		printf("2. In lich thi dau \n");
		printf("3. Cap nhat ket qua\n");
		printf("4. thong ke\n");
		printf("5. Exit program! \n");

		printf("Your option : ");
		scanf("%d", &op);

		printf("---------------------------------------------------\n");
		
		switch (op) {
		case 1: {
			printTesmsInfo(&list);
			break;
		}
		case 2: {
			printRounds(&list, rounds, n);
			break;
		}

		case 3: {
			update(&list, rounds, &order, n);
			break;
		}
		case 4: {
			thongke(&list);
			break;
		}	
		case 5: {
			printf("Goodbye! \n");
			break;
		}
		}
	} while(op != 5);

	return(0);
}
