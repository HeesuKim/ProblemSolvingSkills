//#include <stdio.h>
//
//int main() {
//	printf("Hello Problems!\n");
//	printf("Hello Git!~!\n");
//	printf("Push Test Line Please.\n");
//	return 0;
//}



//DATE-->0820


//선택정렬selectionsort
//비교 횟수는 크지만 교환 횟수는 N번이면 충분하므로
//정렬할 데이터 하나 하나의 크기가 큰 경우에 유용.

/*
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

void MakeRandomNumber(void);
void SelectionSort(void);
void DisplayBuffer(void);
int IsNumberExist(int, int);
int Buf[MAX];

void MakeRandomNumber(void) {
	int i, Num;
	i = 1;
	Buf[0] = 100;
	
	while (i < MAX) {
		Num = rand() % MAX;

		if (!IsNumberExit(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void SelectionSort(void) {
	int i, j, min, dummy;

	for (i = 0; i < MAX; i++) {
		min = i;

		for (j = i + 1; j < MAX; j++) {
			if (Buf[j] < Buf[min])
				min = j;
		}

		dummy = Buf[min];
		Buf[min] = Buf[i];
		Buf[i] = dummy;
	}
}

void DisplayBuffer(void) {
	int i;

	for (i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");

		printf("%4d", Buf[i]);
	}
	printf("\n");
}

int IsNumberExist(int number, int index) {
	int i;

	for (i = 0; i < index; i++) {
		if (Buf[i] == number)
			return TRUE;
	}
	return FALSE;
}

void main() {
	printf("정렬할 데이터 초기화\n");
	MakeRandomNumber();
	DisplayBuffer();

	printf("정렬 후 데이터\n");
	SelectionSort();
	DisplayBuffer();
	printf("\n");
}

*/


//삽입정렬
//비교 횟수가 적고 이동 횟수가 많음.


/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

void MakeRandomNumber(void);
void InsertionSort(void);
void DisplayBuffer(void);
int IsNumberExist(int, int);
int Buf[MAX];

void MakeRandomNumber(void) {
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Buf[0] = 100;

	while (i < MAX) {
		Num = rand() % MAX;

		if (!IsNumberExist(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void InsertionSort(void) {
	int i, j, dummy;
	for (i = 0; i < MAX; i++) {
		dummy = Buf[i];
		j = i;

		while (Buf[j - 1] > dummy && j > 0) {
			Buf[j] = Buf[j - 1];
			j--;
		}
		Buf[j] = dummy;
	}
}

void DisplayBuffer(void) {
	int i;
	for (i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");

		printf("%4d", Buf[i]);
	}
	printf("\n");
}

int IsNumberExist(int number, int index) {
	int i;
	for (i = 0; i < index; i++) {
		if (Buf[i] == number)
			return TRUE;
	}
	return FALSE;
}

void main() {
	printf("정렬할 데이터 초기화\n");
	MakeRandomNumber();
	DisplayBuffer();
	printf("정렬 후 데이터\n");
	InsertionSort();
	DisplayBuffer();
	printf("\n");
}

*/


//버블정렬
//간단함.
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define MAX 100
//#define TRUE 1
//#define FALSE 0
//
//void MakeRandomNumber(void);
//void BubbleSort(void);
//void DisplayBuffer(void);
//int IsNumberExist(int, int);
//int Buf[MAX];
//
//void MakeRandomNumber(void) {
//	int i, Num;
//	i = 1;
//	srand((unsigned)time(NULL));
//	Buf[0] = 100;
//
//	while (i < MAX) {
//		Num = rand() % 100;
//
//		if (!IsNumberExist(Num, i)) {
//			Buf[i] = Num;
//			i++;
//		}
//	}
//}
//
//void BubbleSort(void) {
//	int i, j, dummy;
//
//	for (i = MAX - 1; i >= 0; i--) {
//		for (j = 1; j <= i; j++) {
//			if (Buf[j - 1] > Buf[j]) {
//				dummy = Buf[j - 1];
//				Buf[j - 1] = Buf[j];
//				Buf[j] = dummy;
//			}
//		}
//	}
//}
//
//void DisplayBuffer(void) {
//	int i;
//
//	for (i = 0; i < MAX; i++) {
//		if ((i % 10) == 0)
//			printf("\n");
//		printf("%4d", Buf[i]);
//	}
//	printf("\n");
//}
//
//int IsNumberExist(int number, int index) {
//	int i;
//
//	for (i = 0; i < index; i++) {
//		if (Buf[i] == number)
//			return TRUE;
//	}
//	return FALSE;
//}
//
//
//void main() {
//	printf("정렬할 데이터 초기화\n");
//	MakeRandomNumber();
//	DisplayBuffer();
//	printf("정렬 후 데이터\n");
//	BubbleSort();
//	DisplayBuffer();
//	printf("\n");
//}


//셸정렬
//미리 정렬이 되어있으면 더욱 빠르다는 삽입정렬의 특성을 극대화.
//부분부분을 미리 정렬해놓으면서 진행.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

void makeRandomNumber();
void shellSort();
void displayBuffer();
int isNumberExist(int, int);

int buf[MAX];

void makeRandomNumber() {
	int i, num;
	srand((unsigned)time(NULL));
	i = 1;
	buf[0] = 100;

	while (i < MAX) {
		num = rand() % MAX;

		if (!isNumberExist(num, i)) {
			buf[i] = num;
			i++;
		}
	}
}

void shellSort() {
	int i, j, h, dummy;
	for (h = 0; h < MAX; h = 3 * h + 1);
	for (; h > 0; h /= 3) {
		for (i = h; i < MAX; i++) {
			dummy = buf[i];
			j = i;

			while (buf[j - h] > dummy && j >= h) {
				buf[j] = buf[j - h];
				j -= h;
			}
			buf[j] = dummy;
		}
	}
}

void displayBuffer(void) {
	int i;
	for (i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");

		printf("%4d", buf[i]);
	}
	printf("\n");
}

int isNumberExist(int number, int index) {
	int i;
	for (i = 0; i < index; i++) {
		if (buf[i] == number)
			return TRUE;
	}
	return FALSE;
}

void main() {
	printf("정렬할 데이터 초기화\n");
	makeRandomNumber();
	displayBuffer();
	printf("정렬 후 데이터\n");
	shellSort();
	displayBuffer();
	printf("\n");
}