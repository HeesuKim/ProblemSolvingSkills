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


//DATE-->0822


//�����˻�BinarySearch
//ũ�⿡ ���� �˻������� �ݾ� �ٿ����� Ž��. logn���� Ž������.

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

void MakeRandomNumber(void);
void QuickSort(int[], int, int);
void DisplayBuffer(void);
int IsNumberExist(int, int);
int BinarySearch(int);
int Buf[MAX];
int CompareCount;

void MakeRandomNumber(void) {
	int i, Num;
	i = 0;
	srand((unsigned)time(NULL));

	while (i < MAX) {
		Num = rand() % 200;

		if (!IsNumberExist(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void QuickSort(int data[], int left, int right) {
	int num, i, j, temp;
	if (right > left) {
		num = data[right];
		i = left - 1;
		j = right;

		while (1) {
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

		QuickSort(data, left, i - 1);
		QuickSort(data, i + 1, right);
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

int BinarySearch(int num) {
	int left, right;
	int min;
	left = 0;
	right = MAX;

	while (right >= left) {
		CompareCount++;
		min = (left + right) / 2;

		if (num < Buf[min])
			right = min - 1;
		else
			left = min + 1;

		if (num == Buf[min])
			return min;
	}

	return -1;
}

void main() {
	int ret;
	CompareCount = 0;
	MakeRandomNumber();
	QuickSort(Buf, 0, MAX - 1);
	printf("���ĵ� ������\n");
	DisplayBuffer();

	ret = BinarySearch(23);

	if (ret == -1)
		printf("ã�� �����Ͱ� ����.\n");
	else
		printf("23�� %d��°�� ����.\n", ret);

	printf("�� �� Ƚ���� %d.\n", CompareCount);

}
*/


//�����˻�Ʈ�� ���Ի���BinarySearchTree InsertDelete
//������ ����Ǽ��� ������ ����.
//�� ���� ������� �ܸ����, ����Ʈ��1��, 2���� ���� ������ ������ �� ����.


/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define TRUE 1
#define FALSE 0

typedef struct _NODE {
	int key;
	struct _NODE *left;
	struct _NODE *right;
} NODE;

NODE *ptrNode;
NODE *head;
NODE *end;

void MakeRandomNumber(void);
void QuickSort(int[], int, int);
void DisplayBuffer(void);
int IsNumberExist(int, int);
void BSTInitialize(void);
void BSTInsert(int);
void BSTDelete(int);
void BSTDisplay(NODE *);
int Buf[MAX];
int CompareCount;

void MakeRandomNumber(void) {
	int i, Num;
	i = 0;
	srand((unsigned)time(NULL));

	while (i < MAX) {
		Num = rand() % 200;

		if (!IsNumberExist(Num, i)) {
			Buf[i] = Num;
			i++;
		}
	}
}

void QuickSort(int data[], int left, int right) {
	int num, i, j, temp;
	if (right > left) {
		num = data[right];
		i = left - 1;
		j = right;

		while (1) {
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

		QuickSort(data, left, i - 1);
		QuickSort(data, i + 1, right);
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

void BSTInitialize(void) {
	end = (NODE *)malloc(sizeof *end);
	end->left = end;
	end->right = end;
	end->key = -1;

	head = (NODE *)malloc(sizeof *head);
	head->right = end;
	head->key = 0;
}

void BSTInsert(int num) {
	NODE *p, *x;
	p = head;
	x = head->right;

	while (x != end) {
		p = x;//����������x�� �θ� �Ǵ� ��� p
		x = (num < x->key) ? x->left : x->right;
	}

	x = (NODE *)malloc(sizeof *x);
	x->key = num;
	x->left = end;
	x->right = end;

	if (num < p->key)
		p->left = x;
	else
		p->right = x;
}

void BSTDelete(int num) {
	NODE *g, *p, *x;
	NODE *temp;
	end->key = num;
	p = head;
	x = head->right;

	while (num != x->key) {
		p = x;

		if (num < x->key)
			x = x->left;
		else
			x = x->right;
	}

	temp = x;

	//ast.
	if (temp->right == end)//�ܸ�����̰ų� ���ʼ���Ʈ��(������庸�� ������)�� ���� ���
		x = x->left;
	else if (temp->right->left == end) {//��������� ���ʼ���Ʈ���� �ѹ��� �ű� �� �ִ� ���
		x = x->right;
		x->left = temp->left;
	}
	else {//����Ʈ�� ������ �ű�� ���� �Ұ����� ������ ���
		g = x->right;

		while (g->left->left != end)
			g = g->left;

		x = g->left;
		g->left = x->right;
		x->left = temp->left;
		x->right = temp->right;
	}

	free(temp);

	if (num < p->key)
		p->left = x;
	else
		p->right = x;
}

void BSTDisplay(NODE *ptr) {
	if (ptr != end) {
		BSTDisplay(ptr->left);
		printf("%5d", ptr->key);
		BSTDisplay(ptr->right);
	}
}

void main() {
	int i, ret;
	CompareCount = 0;

	MakeRandomNumber();
	//QuickSort(Buf, 0, MAX - 1);
	printf("������ ������\n");
	DisplayBuffer();

	BSTInitialize();
	for (i = 0; i < MAX; i++)
		BSTInsert(Buf[i]);

	printf("RootNode : %d\n", head->right->key);

	BSTDisplay(head->right);
	printf("\n");


	printf("%d ���� ��\n", Buf[5]);

	BSTDelete(Buf[5]);
	BSTDisplay(head->right);
	printf("\n");
}

*/


//DATE-->0824

//Ű-���� �˻� Key-Mapping Search
//�ؽ��Լ��� ����ȭ �ʿ�. O(1) �ӵ�

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define OVERFLOW 3

typedef struct _NODE {
	int Key[3];
	int Counter;
} NODE;

void Initialize(void);
void MakeRandomNumber(void);
void DisplayBuffer(void);
void DisplayHitBuffer(void);
void DisplayHitCounter(void);
int IsNumberExist(int);

int Buf[MAX];
NODE Hit[50];

void Initialize(void) {
	int i, j;
	for (i = 0; i < MAX; i++)
		Buf[i] = -1;

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 3; j++)
			Hit[i].Key[j] = -1;
		
		Hit[i].Counter = 0;
	}
}

void MakeRandomNumber(void) {
	int i, Num, index;
	i = 0;
	srand((unsigned)time(NULL));

	while (i < 50) {
		Num = rand() % 100;

		if (!IsNumberExist(Num)) {
			Buf[Num] = Num;
			index = Num % 50;

			if (Hit[index].Counter > 2)
				printf("\n OVERFLOW\n");
			else
				Hit[index].Key[Hit[index].Counter++] = Num;

			i++;
		}
	}
}

void DisplayBuffer(void) {
	int i;

	for (i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");

		printf("%4d ", Buf[i]);
	}
	
	printf("\n");
}

void DisplayHitBuffer(void) {
	int i;

	printf("====> HIT KEY DATA <====\n");

	for (i = 0; i < 50; i++) {
		if ((i % 5) == 0)
			printf("\n");

		switch (Hit[i].Counter) {
		case 0:
		case 1:
			printf("%3d", Hit[i].Key[0]);
			break;
			
		case 2:
			printf("%3d/%3d", Hit[i].Key[0], Hit[i].Key[1]);
			break;

		case 3:
			printf("%3d/%3d/%3d", Hit[i].Key[0], Hit[i].Key[1], Hit[i].Key[2]);
			break;

		default:
			printf("**");
		}
		
		printf("\t");
	}

	printf("\n\n");
}

void DisplayHitCounter(void) {
	int i;
	printf("====> HIT COUNTER DATA <====\n");

	for (i = 0; i < 50; i++) {
		if ((i % 5) == 0)
			printf("\n");

		printf("%4d ", Hit[i].Counter);
	}

	printf("\n");
}

int IsNumberExist(int number) {
	int i;

	for (i = 0; i < MAX; i++) {
		if (Buf[i] == number)
			return TRUE;
	}

	return FALSE;
}

void main() {
	Initialize();

	MakeRandomNumber();
	printf("Ű-�������� ������ ������\n");
	DisplayBuffer();

	printf("\n");

	DisplayHitBuffer();
	DisplayHitCounter();
}

*/


//16���� 10���� ��ȯ
/*
#include <stdio.h>

void main() {
	char key;
	int data;

	printf("10���� -> 16���� A\n");
	printf("16���� -> 10���� B\n");
	
	printf("������ : ");
	scanf_s("%c", &key);

	printf("���� �Է� :");
	
	if (key == 'a') {
		scanf_s("%d", &data);
		printf("10���� %d --> 16���� %x\n", data, data);
	}
	else if (key == 'b') {
		scanf_s("%x", &data);
		printf("16���� %x --> 10���� %d\n", data, data);
	}
	else {
		printf("����\n");
	}
}
*/

//���� ���߱�
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int num, i, data;
	srand((unsigned)time(NULL));
	num = rand() % 10;
	i = 1;
	printf("0~9������ �� ���߱�.\n");

	while (1) {
		printf("'%d'��° �õ� : ", i);
		scanf_s("%d", &data);

		if (data < num)
			printf("%d���� ŭ.\n", data);
		else if (data > num)
			printf("%d���� ����.\n", data);
		else {
			printf("'%d'��° �õ��� ����.\n", i);
			break;
		}

		i++;
	}
}

*/

//�Ǻ���ġ ���� ���ϱ�
/*
#include <stdio.h>

void main() {
	int i, firNum, secNum, rstNum;

	printf("�Ǻ���ġ ����\n");

	i = 0;
	firNum = 0;
	secNum = 1;

	while (i < 12) {
		rstNum = firNum + secNum;

		if ((i % 5) == 0)
			printf("\n");

		printf("%6d", rstNum);

		firNum = secNum;
		secNum = rstNum;
		i++;
	}
}
*/

//�Ҽ����ϱ�
/*
#include <stdio.h>

void main() {
	printf("1000���������� ��� �Ҽ� ����.\n");
	
	int line = 0;
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; j <= i; j++) {
			if (i % j == 0 && i != j)
				break;
			else if (i % j == 0 && i == j) {
				printf("%4d ", i);
				line++;
				if ((line % 5) == 0)
					printf("\n");
			}
		}
	}
}

*/

//����������

/*
#include <stdio.h>

void main() {
	printf("������� ���� ��� ���α׷�.\n");

	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 5; j++) {
			if (i % 2 == 1)
				printf("%3d", (5 * i) - 5 + j);
			else
				printf("%3d", (5 * i) + 1 - j);
		}
		printf("\n");
	}
}
*/


//DATE-->0831

//������ ã��
//Greedy? ������ȹ��?
/*
#include <stdio.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#define MAX_N 1000
#define MAX_WEIGHT 10000
#define MAX_VALUE (50000 * MAX_WEIGHT)

int T, E, F, N;
int P[MAX_N], W[MAX_N];
int S[MAX_WEIGHT];
FILE *inf, *outf;

void input_data(void) {
	int i;
	fscanf_s(inf, "%d %d\n", &E, &F);
	fscanf_s(inf, "%d\n", &N);

	for (i = 0; i < N; i++)
		fscanf_s(inf, "%d %d\n", &P[i], &W[i]);
}

void initialize_S(void) {
	int i;
	S[0] = 0;

	for (i = 1; i <= F - E; i++)
		S[i] = MAX_VALUE;
}

void solve(void) {
	int i, j;
	initialize_S();

	for (i = 0; i < N; i++)
		for (j = 0; j <= F - E - W[i]; j++)
			if (S[j] + P[i] < S[j + W[i]])
				S[j + W[i]] = S[j] + P[i];
}

void output_result(void) {
	if (S[F - E] == MAX_VALUE)
		printf("-1\n");
	else
		printf("�ּҽ���ð� : %d\n", S[F - E]);

}

void main() {
	int i;
	if (fopen_s(&inf, INPUT_FILE, "r") != 0) {
		printf("���Ͽ��¿���.\n");
	}
	fscanf_s(inf, "%d\n", &T);

	for (i = 0; i < T; i++) {
		input_data();
		solve();
		output_result();
	}

	fclose(inf);
}
*/


//bj 2839
/*
#include <iostream>
using namespace std;

int main() {
	int N;
	int bag3 = 0;
	int	bag5 = 0;

	cin >> N;
	bag5 = (N / 5);
	N %= 5;

	if (N == 0 || N == 3)
		cout << bag5 + (N / 3) << endl;
	else {
		while (0 < bag5--) {
			N += 5;
			bag3 = N / 3;
			if (N % 3 == 0) {
				cout << bag5 + bag3 << endl;
				return 0;
			}
		}
		cout << "-1" << endl;
	}
}

*/

//endl���� \n�� �ξ� ����ӵ��鿡�� ����.

/*
#include <iostream>
using namespace std;

int main() {
	int n, i, j, k;
	cin >> n;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (j <= (n - i))
				cout << " ";
			else
				cout << "*";
		}
		cout << "\n";
	}
}

*/

//DATE-->0902

/*
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int j = 0; j < N - i; j++)
			cout << " ";
		for (int k = 0; k < i; k++)
			cout << "*";

		cout << "\n";
	}
}

*/


//bj 1924
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	int x, y;
	int month, day;
	int date = 0;
	string a[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	cin >> x >> y;

	for (month = 1; month <= x - 1; month++) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			day = 31;
		else if (month == 2)
			day = 28;
		else
			day = 30;

		date += day;
	}

	date += y;

	date %= 7;

	cout << a[date] << "\n";
}
*/

//bj 11720
//�� �ּ��� Ʋ����

/*
#include <iostream>
using namespace std;

int main() {
	char inputNum[100] = { '0', };
	int length = 0;
	int rst = 0;

	cin >> length;
	cin >> inputNum;

	for (int i = 0; i < length; i++) {
		rst += (inputNum[i] - '0');
	}

	//int n, num;
	//int digit = 0;
	//int rst = 0;
	//cin >> n;
	//cin >> num;

	//for (int i = 1; i <= n; i++) {
	//	digit = num % 10;
	//	num /= 10;
	//	
	//	rst += digit;
	//}

	cout << rst << "\n";
}

*/


//bj 11721
//strlen ���

/*
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char inputStr[100];
	int len;

	cin >> inputStr;
	len = strlen(inputStr);

	for (int i = 1; i <= len; i++) {
		cout << inputStr[i - 1];

		if (i % 10 == 0)
			cout << "\n";
	}
}

*/


//bj 10871
/*
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int max, rst;

	cin >> a >> b >> c;

	if (a >= b) {
		if (c >= a)
			cout << a << "\n";
		else
			if (c >= b)
				cout << c << "\n";
			else
				cout << b << "\n";
	}
	else {
		if (c >= b)
			cout << b << "\n";
		else
			if (c >= a)
				cout << c << "\n";
			else
				cout << a << "\n";
	}
}

*/

//������ ���� double�� ����� ����� ������????
/*
#include <iostream>
using namespace std;

int main() {
	int C, upScr;
	int scr[1000];
	double N, sum, avg, rst;

	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;

		sum = 0;
		for (int j = 0; j < N; j++) {
			cin >> scr[j];
			sum += scr[j];
		}
		avg = sum / N;
		upScr = 0;
		for (int j = 0; j < N; j++) {
			if (scr[j] > avg)
				upScr++;
		}
		rst = upScr / N * 100;
		cout << fixed;
		cout.precision(3);
		cout << rst << "%\n";
	}
}

*/


/*
#include <iostream>
using namespace std;

bool isHanNum(int a) {
	int hun, ten, one;
	if (a < 100)
		return true;
	else {
		hun = a / 100;
		a -= hun * 100;
		ten = a / 10;
		a -= ten * 10;
		one = a;

		if (hun + (one - ten) * 2 == one)
			return true;
		else
			return false;
	}

}

int main() {
	int N;
	int rst = 0;
	cin >> N;
	for (int i = N; i >= 1; i--) {
		if (isHanNum(i)) {
			//cout << i << endl;
			rst++;
		}
			
	}

	cout << rst << "\n";
}
*/

/*bj2448
#include <iostream>
using namespace std;

char coordi[3090][6200];

void makeTri(int y, int x, int n) {
	if (n == 3) {
		coordi[y][x + 2] = '*';
		coordi[y + 1][x + 1] = '*'; coordi[y + 1][x + 3] = '*';
		for (int i = 0; i < 5; i++)
			coordi[y + 2][x + i] = '*';
	}
	else {
		n /= 2;
		makeTri(y, x + n, n);
		makeTri(y + n, x, n);
		makeTri(y + n, x + 2 * n, n);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			coordi[i][j] = ' ';
		}
	}
	makeTri(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << coordi[i][j];
		}
		cout << "\n";
	}
}
*/

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int t, len, cnt, scr;
	bool stFlag;
	char oxChar[81];
	int rstArr[1000];
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> oxChar;
		len = strlen(oxChar);
		cnt = 0;
		scr = 0;
		stFlag = false;

		for (int j = 0; j < len; j++) {
			if (!stFlag && oxChar[j] == 'O') {
				stFlag = true;
				cnt++;
				scr++;
				continue;
			}
			if (stFlag && oxChar[j] == 'O') {
				cnt++;
				scr += cnt;
				continue;
			}
			if (stFlag && oxChar[j] == 'X') {
				cnt = 0;
				stFlag = false;
				continue;
			}
		}

		rstArr[i] = scr;
	}

	for (int i = 0; i < t; i++)
		cout << rstArr[i] << "\n";
}
