#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define C 64

char result[10000000][65];
char temp[10000000][65];
int counter = 0;

char* left(char* ptr, char* leftpart, int a);
char* right(char* ptr, char* rightpart, int a);
int zeroplacement(char* arr, int size);
void Recursion(int a, int b);

int main() {
	system("chcp 1251");
	int N, K;
	printf("Введіть к-сть нулів(не більше 64): ");
	error1 : scanf_s("%d", &N);
	rewind(stdin);
	if (N > 64) {
		printf("Введена надто велика к-сть нулів. Повторіть спробу: ");
		goto error1;
	}
	printf("Введіть к-сть одиниць(не більше к-сті нулів): ");
	error2 : scanf_s("%d", &K);
	rewind(stdin);
	if (K > N) {
		printf("Введена надто велика к-сть одиниць. Повторіть спробу: ");
		goto error2;
	}

	Recursion(N, K);
	printf("\tРекурсія\n-----------------\n");
	for (int i = 0; i < counter; i++) {
		printf("%s\n", result[i]);
	}
	printf("-----------------");
}

void Recursion(int a, int b) {
	if (a == b) {
		char res[C];
		int i = 0;
		for (; i < a; i++) {
			res[i] = '1';
		}
		res[i] = '\0';
		strcpy(result[0], res);
		counter = 1;
	}
	else {
		Recursion(a-1, b);
		int k = 0;
		for (int i = 0; i < counter; i++) {
			 k += zeroplacement(result[i], k);
		}
		for (int i = 0; i < k; i++) {
			strcpy(result[i], temp[i]);
		}
		counter = k;
	}
}

int zeroplacement (char* arr, int size) {
	int a = strlen(arr);
	char left_part[100];
	char right_part[100];
	char* res;
	int i = 0;
	int kst = 0;
	for (; i < a; i++) {
		int k = a - i;
		char* leftptr = left(arr, left_part, i);
		char* rightptr = right(arr, right_part, k);
		if (leftptr == NULL) {
			_strrev(rightptr);
			res = strcat(rightptr, "0");
			_strrev(rightptr);
			strcpy(temp[size++], res);
			kst++;
		}
		else if(leftptr != NULL && rightptr != NULL) {
			strcat(leftptr, "0");
			res = strcat(leftptr, rightptr);
			strcpy(temp[size++], res);
			kst++;
		}
	}
	char* leftptr = left(arr, left_part, a);
	res = strcat(leftptr, "0");
	strcpy(temp[size++], res);
	kst++;
	return kst;
}

char* left(char* ptr, char* leftpart, int a) {
	if (a == 0) {
		return NULL;
	}
	else {		
		strncpy(leftpart, ptr, a);
	}
	leftpart[a] = '\0';
	char* leftptr = leftpart;
	return leftptr;
}

char* right(char* ptr, char* rightpart, int a) {
	if (a == 0) {
		return NULL;
	}
	else {
		_strrev(ptr);
		strncpy(rightpart, ptr, a);
		rightpart[a] = '\0';
		_strrev(rightpart);
		_strrev(ptr);
	}
	char* rightptr = rightpart;
	return rightptr;
}