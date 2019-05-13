#include <stdio.h>
#include <stdlib.h>

struct stack {
	int n;
	char name[N][40];
	float score[N];
};

typedef struct stack Stack;

Stack student;

void create_stack(){
	student.n = 0;
}

void push(char *name, float score){
	if(student.n == N){
		printf("Stack overflow!\n");
		getch();
		exit(1);
	}
	strcpy(student.name[student.n], name);
	student.score[student.n] = score;
	student.n++;
}

char* pop(){
	if(student.n == 0){
		printf("Empty stack!\n");
		getch();
		exit(1);
	}
	char *callback;
	callback = (char*) malloc(70 * sizeof(char));
	strcpy(callback, student.name[student.n-1]);
	
	student.n--;
	return callback;
}

main(){
	char name[50];
	float score;
	int op, x;
	
	create_stack();
	do{
		system("cls");
		printf("1-Insert\n2-Delete\n3-Show\n4Exit\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				fflush(stdin);
				printf("Name: ");
				gets(name);
				fflush(stdin);
				printf("Score: ");
				scanf("%f", &score);
				push(name, score);
				fflush(stdin);
				printf("Student added: %s.\n", name);
				break;
			case 2:
				printf("Student deleted: %s.\n", pop());
				system("pause");
				break;
			case3 :
				for(x = 0; x < student.n; x++)
					printf("Student: %s, score: %f.\n", student.name[x], student.score[x]);
				break;
			case 4:
				printf("Exit\n");
				break;
			default:
				printf("Forbidden action!");
				break;				
		}
		system("pause");
	}while (op != 4);
}
