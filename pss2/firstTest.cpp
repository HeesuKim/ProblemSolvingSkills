//#include <stdio.h>
//
//int main() {
//	printf("Hello Problems!\n");
//	printf("Hello Git!~!\n");
//	printf("Push Test Line Please.\n");
//	return 0;
//}



//DATE-->0820


//��������selectionsort
//�� Ƚ���� ũ���� ��ȯ Ƚ���� N���̸� ����ϹǷ�
//������ ������ �ϳ� �ϳ��� ũ�Ⱑ ū ��쿡 ����.

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
	printf("������ ������ �ʱ�ȭ\n");
	MakeRandomNumber();
	DisplayBuffer();

	printf("���� �� ������\n");
	SelectionSort();
	DisplayBuffer();
	printf("\n");
}

*/


//��������
//�� Ƚ���� ���� �̵� Ƚ���� ����.


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
	printf("������ ������ �ʱ�ȭ\n");
	MakeRandomNumber();
	DisplayBuffer();
	printf("���� �� ������\n");
	InsertionSort();
	DisplayBuffer();
	printf("\n");
}

*/


//��������
//������.

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

void MakeRandomNumber(void);
void BubbleSort(void);
void DisplayBuffer(void);
int IsNumberExist(int, int);
int Buf[MAX];

void MakeRandomNumber(void) {
	int i, Num;
	i = 1;
	srand((unsigned)time(NULL));
	Buf[0] = 100;

	while (i < MAX) {
		Num = rand() % 100;

		if (!IsNumberExist(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void BubbleSort(void) {
	int i, j, dummy;

	for (i = MAX - 1; i >= 0; i--) {
		for (j = 1; j <= i; j++) {
			if (Buf[j - 1] > Buf[j]) {
				dummy = Buf[j - 1];
				Buf[j - 1] = Buf[j];
				Buf[j] = dummy;
			}
		}
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
	printf("������ ������ �ʱ�ȭ\n");
	MakeRandomNumber();
	DisplayBuffer();
	printf("���� �� ������\n");
	BubbleSort();
	DisplayBuffer();
	printf("\n");
}
*/


//������
//�̸� ������ �Ǿ������� ���� �����ٴ� ���������� Ư���� �ش�ȭ.
//�κкκ��� �̸� �����س����鼭 ����.

/*
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
	printf("������ ������ �ʱ�ȭ\n");
	makeRandomNumber();
	displayBuffer();
	printf("���� �� ������\n");
	shellSort();
	displayBuffer();
	printf("\n");
}

*/


//DATE-->0821


//quickSort ������
//�Ϲ������� �����������
//���ĵǾ��ִ� �������� ��� O(n^2)�� ����

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

void makeRandomNumber();
void quickSort(int data[], int, int);
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

void quickSort(int data[], int left, int right) {
	int num, i, j, temp;

	if (right > left) {
		num = data[right];
		i = left - 1;
		j = right;

		for (;;) {
			while (data[++i] < num);
			while (data[--j] > num);
			if (i >= j)
				break;

			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
		temp = data[i];
		data[i] = data[right];
		data[right] = temp;

		quickSort(data, left, i - 1);
		quickSort(data, i + 1, right);
	}
}


void main() {
	printf("������ ������ �ʱ�ȭ\n");
	makeRandomNumber();
	displayBuffer();
	printf("���� �� ������\n");
	quickSort(buf, 0, MAX-1);
	displayBuffer();
	printf("\n");
}
*/

//������� radixSort
//�ڸ����� �ִ� �ڷῡ ���������� ���� ����
//O(�ڸ���(�ڷ�� + ť�ǰ���))�� ����

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

typedef struct _NODE {
	int data;
	struct _NODE * next;
} NODE;

NODE *front[10];
NODE *rear[10];
NODE *ptrNode;
int buf[MAX];

void makeRandomNumber();
void radixSort();
void displayBuffer();
int isNumberExist(int, int);
void initQueue(void);
void pPut(int, int);
int pGet(int);

void makeRandomNumber() {
	int i, num;
	srand((unsigned)time(NULL));
	i = 0;
	
	while (i < MAX) {
		num = rand() % 100;

		if (!isNumberExist(num, i)) {
			buf[i] = num;
			i++;
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

void radixSort(void) {
	int i, num, digit, j;
	j = 0;

	//1�� �ڸ����� ����
	for (i = 0; i < MAX; i++) {
		num = buf[i];
		digit = num % MAX;
		pPut(digit, num);
	}

	printf("\n1�� �ڸ����� ���ĵ� ���� ����Ʈ\n");

	for (i = 0; i < MAX; i++) {
		printf("\n%d�� �ڸ� :", i);

		while (1) {
			num = pGet(i);

			if (num != -1) {
				printf("%3d", num);
				buf[j++] = num;
			}
			else
				break;
		}
	}
	printf("\n\n1�� ���� �� buf�� �����͵�\n");
	displayBuffer();

	//10�� �ڸ����� ����
	j = 0;

	for (i = 0; i < MAX; i++) {
		num = buf[i];
		digit = num / MAX;
		pPut(digit, num);
	}
	
	printf("\n10�� �ڸ����� ���ĵ� ���� ����Ʈ\n");

	for (i = 0; i < MAX; i++) {
		printf("\n%d�� �ڸ� :", i);

		while (1) {
			num = pGet(i);

			if (num != -1) {
				printf("%3d", num);
				buf[j++] = num;
			}
			else
				break;
		}
	}
	printf("\n\n2�� ���� �� buf�� �����͵�\n");
	displayBuffer();
}

void initQueue() {
	int i;

	for (i = 0; i < MAX; i++) {
		front[i] = (NODE*)malloc(sizeof(NODE));
		rear[i] = (NODE*)malloc(sizeof(NODE));
		front[i]->next = rear[i];
		rear[i]->next = front[i];
	}
}

void pPut(int index, int num) {
	ptrNode = (NODE*)malloc(sizeof(NODE));
	ptrNode->data = num;
	
	if (front[index]->next == rear[index]) {
		front[index]->next = ptrNode;
		ptrNode->next = rear[index];
		rear[index]->next = ptrNode;
	}
	else {
		rear[index]->next->next = ptrNode;
		ptrNode->next = rear[index];
		rear[index]->next = ptrNode;
	}
}

int pGet(int index) {
	int ret;
	NODE * deleteNode;

	if (front[index]->next == rear[index])
		return -1;
	else {
		deleteNode = front[index]->next;
		front[index]->next = deleteNode->next;
		ret = deleteNode->data;

		free(deleteNode);
	}
	return ret;
}

void main() {
	initQueue();
	printf("������ ������ �ʱ�ȭ\n");
	makeRandomNumber();
	displayBuffer();
	radixSort();

	printf("\n");
}
*/

//mergeSort ��������
//divide & conquer ���� �� ��ġ�� ���� O(nlogn)

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5
#define TRUE 1
#define FALSE 0

void makeRan(void);
void mergeSort(int[], int, int);
void displayBuf(void);
int isNumExist(int, int);

int buf[MAX];
int temp[MAX];

void makeRan() {
	int i, num;
	i = 1;
	srand((unsigned)time(NULL));
	buf[0] = MAX;

	while (i < MAX) {
		num = rand() % MAX;

		if (!isNumExist(num, i)) {
			buf[i] = num;
			i++;
		}
	}
}

void displayBuf() {
	for (int i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");

		printf("%4d", buf[i]);
	}
	printf("\n");
}

int isNumExist(int num, int idx) {
	for (int i = 0; i < idx; i++) {
		if (buf[i] == num)
			return TRUE;
	}
	return FALSE;
}

void mergeSort(int data[], int left, int right) {
	int i, j, k, mid;
	if (right > left) {
		mid = (left + right) / 2;

		mergeSort(data, left, mid);
		mergeSort(data, mid + 1, right);

		for (i = mid + 1 ; i > left; i--) {
			temp[i - 1] = data[i - 1];
		}

		for (j = mid; j < right; j++) {
			temp[right + mid - j] = data[j + 1];
		}

		for (k = left; k <= right; k++) {
			data[k] = (temp[i] < temp[j]) ? temp[i++] : temp[j--];
		}
	}
}

void main() {
	printf("������ ������ �ʱ�ȭ\n");
	makeRan();
	displayBuf();
	printf("���� �� ������\n");
	mergeSort(buf, 0, MAX - 1);
	displayBuf();
	printf("\n");
}
*/

//heapSort ������
//O(nlogn), ���� �ٿ��� ���� �������� O(n), ���� logn�� ���� �ð����⵵ ���
//�־�, �ּ� �������� �̹�

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_INT 65536
#define MAX 100

void makeRan(void);
void displayBuf(void);
int isNumExist(int, int);

void heapSort(int);
void upheap(int);
void downheap(int);
void insData(int);
int remData(void);

int buf[MAX + 1];
int data[MAX];
int NUM;



void makeRan() {
	int i, num;
	i = 0;
	srand((unsigned)time(NULL));

	while (i < MAX) {
		num = rand() % MAX;

		if (!isNumExist(num, i)) {
			data[i] = num;
			i++;
		}
	}
}

void displayBuf() {
	for (int i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");

		printf("%4d", data[i]);
	}
	printf("\n");
}

int isNumExist(int num, int idx) {
	for (int i = 1; i < idx; i++) {
		if (data[i] == num)
			return TRUE;
	}
	return FALSE;
}

void heapSort(int N) {
	for (int i = 0; i < MAX; i++)
		insData(data[i]);

	for (int i = MAX - 1; i >= 0; i--)
		data[i] = remData();
}

void upheap(int k) {
	int v = buf[k];
	

	while (buf[k / 2] <= v) {
		buf[k] = buf[k / 2];
		k /= 2;
	}
	buf[k] = v;
}

void downheap(int k) {
	int i, v;
	v = buf[k];

	while (k <= NUM / 2) {
		i = 2 * k;

		if (i < NUM && buf[i] < buf[i + 1])//����. �� ū�ʰ� �ٲ�� ���� ������ ����. �θ��尡 �Ǳ� ����.
			i++;

		if (v >= buf[i])
			break;

		buf[k] = buf[i];
		k = i;
	}
	
	buf[k] = v;
}

void insData(int v) {
	buf[++NUM] = v;
	upheap(NUM);
}

int remData() {
	int v = buf[1];
	buf[1] = buf[NUM--];
	downheap(1);

	return v;
}

void main() {
	NUM = 0;
	buf[0] = MAX_INT;

	printf("������ ������ �ʱ�ȭ\n");

	makeRan();
	displayBuf();
	printf("���� �� ������\n");
	heapSort(NUM);
	displayBuf();
	printf("\n");
}
*/
