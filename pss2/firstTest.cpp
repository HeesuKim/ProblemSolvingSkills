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
	printf("정렬할 데이터 초기화\n");
	MakeRandomNumber();
	DisplayBuffer();
	printf("정렬 후 데이터\n");
	BubbleSort();
	DisplayBuffer();
	printf("\n");
}
*/


//셸정렬
//미리 정렬이 되어있으면 더욱 빠르다는 삽입정렬의 특성을 극대화.
//부분부분을 미리 정렬해놓으면서 진행.

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
	printf("정렬할 데이터 초기화\n");
	makeRandomNumber();
	displayBuffer();
	printf("정렬 후 데이터\n");
	shellSort();
	displayBuffer();
	printf("\n");
}

*/


//DATE-->0821


//quickSort 퀵정렬
//일반적으로 가장빠르지만
//정렬되어있는 데이터의 경우 O(n^2)로 저하

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
	printf("정렬할 데이터 초기화\n");
	makeRandomNumber();
	displayBuffer();
	printf("정렬 후 데이터\n");
	quickSort(buf, 0, MAX-1);
	displayBuffer();
	printf("\n");
}
*/

//기수정렬 radixSort
//자릿수가 있는 자료에 한정적으로 정렬 가능
//O(자릿수(자료수 + 큐의개수))의 성능

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

	//1의 자릿수로 정렬
	for (i = 0; i < MAX; i++) {
		num = buf[i];
		digit = num % MAX;
		pPut(digit, num);
	}

	printf("\n1의 자릿수로 정렬된 숫자 리스트\n");

	for (i = 0; i < MAX; i++) {
		printf("\n%d의 자리 :", i);

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
	printf("\n\n1차 정렬 후 buf안 데이터들\n");
	displayBuffer();

	//10의 자릿수로 정렬
	j = 0;

	for (i = 0; i < MAX; i++) {
		num = buf[i];
		digit = num / MAX;
		pPut(digit, num);
	}
	
	printf("\n10의 자릿수로 정렬된 숫자 리스트\n");

	for (i = 0; i < MAX; i++) {
		printf("\n%d의 자리 :", i);

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
	printf("\n\n2차 정렬 후 buf안 데이터들\n");
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
	printf("정렬할 데이터 초기화\n");
	makeRandomNumber();
	displayBuffer();
	radixSort();

	printf("\n");
}
*/

//mergeSort 병합정렬
//divide & conquer 나눈 후 합치며 정렬 O(nlogn)

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
	printf("정렬할 데이터 초기화\n");
	makeRan();
	displayBuf();
	printf("정렬 후 데이터\n");
	mergeSort(buf, 0, MAX - 1);
	displayBuf();
	printf("\n");
}
*/

//heapSort 힙정렬
//O(nlogn), 업힙 다운힙 각각 레벨별로 O(n), 깊이 logn을 곱해 시간복잡도 계산
//최악, 최선 성능차이 미미

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

		if (i < NUM && buf[i] < buf[i + 1])//주의. 더 큰쪽과 바꿔야 힙이 깨지지 않음. 부모노드가 되기 때문.
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

	printf("정렬할 데이터 초기화\n");

	makeRan();
	displayBuf();
	printf("정렬 후 데이터\n");
	heapSort(NUM);
	displayBuf();
	printf("\n");
}
*/


//DATE-->0822


//이진검색BinarySearch
//크기에 따라 검색범위를 반씩 줄여가며 탐색. logn번에 탐색가능.

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
	printf("정렬된 데이터\n");
	DisplayBuffer();

	ret = BinarySearch(23);

	if (ret == -1)
		printf("찾는 데이터가 없음.\n");
	else
		printf("23은 %d번째에 존재.\n", ret);

	printf("총 비교 횟수는 %d.\n", CompareCount);

}
*/


//이진검색트리 삽입삭제BinarySearchTree InsertDelete
//삭제의 경우의수를 나누어 생각.
//더 쉬운 방법으로 단말노드, 서브트리1개, 2개의 경우로 나누어 생각할 수 있음.


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
		p = x;//최종적으로x의 부모가 되는 노드 p
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
	if (temp->right == end)//단말노드이거나 왼쪽서브트리(삭제노드보다 작은값)만 있을 경우
		x = x->left;
	else if (temp->right->left == end) {//삭제노드의 왼쪽서브트리를 한번에 옮길 수 있는 경우
		x = x->right;
		x->left = temp->left;
	}
	else {//서브트리 단위로 옮기는 것이 불가능한 나머지 경우
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
	printf("생성된 데이터\n");
	DisplayBuffer();

	BSTInitialize();
	for (i = 0; i < MAX; i++)
		BSTInsert(Buf[i]);

	printf("RootNode : %d\n", head->right->key);

	BSTDisplay(head->right);
	printf("\n");


	printf("%d 삭제 후\n", Buf[5]);

	BSTDelete(Buf[5]);
	BSTDisplay(head->right);
	printf("\n");
}

*/


//DATE-->0824

//키-매핑 검색 Key-Mapping Search
//해쉬함수의 복잡화 필요. O(1) 속도

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
	printf("키-매핑으로 생성된 데이터\n");
	DisplayBuffer();

	printf("\n");

	DisplayHitBuffer();
	DisplayHitCounter();
}

*/


//16진수 10진수 변환
/*
#include <stdio.h>

void main() {
	char key;
	int data;

	printf("10진수 -> 16진수 A\n");
	printf("16진수 -> 10진수 B\n");
	
	printf("고르세요 : ");
	scanf_s("%c", &key);

	printf("숫자 입력 :");
	
	if (key == 'a') {
		scanf_s("%d", &data);
		printf("10진수 %d --> 16진수 %x\n", data, data);
	}
	else if (key == 'b') {
		scanf_s("%x", &data);
		printf("16진수 %x --> 10진수 %d\n", data, data);
	}
	else {
		printf("오류\n");
	}
}
*/

//숫자 맞추기
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int num, i, data;
	srand((unsigned)time(NULL));
	num = rand() % 10;
	i = 1;
	printf("0~9사이의 수 맞추기.\n");

	while (1) {
		printf("'%d'번째 시도 : ", i);
		scanf_s("%d", &data);

		if (data < num)
			printf("%d보다 큼.\n", data);
		else if (data > num)
			printf("%d보다 작음.\n", data);
		else {
			printf("'%d'번째 시도로 정답.\n", i);
			break;
		}

		i++;
	}
}

*/

//피보나치 수열 구하기
/*
#include <stdio.h>

void main() {
	int i, firNum, secNum, rstNum;

	printf("피보나치 수열\n");

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

//소수구하기
/*
#include <stdio.h>

void main() {
	printf("1000이전까지의 모든 소수 나열.\n");
	
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

//지그재그출력

/*
#include <stdio.h>

void main() {
	printf("지그재그 숫자 출력 프로그램.\n");

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

//최적해 찾기
//Greedy? 동적계획법?
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
		printf("최소실행시간 : %d\n", S[F - E]);

}

void main() {
	int i;
	if (fopen_s(&inf, INPUT_FILE, "r") != 0) {
		printf("파일오픈에러.\n");
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

//endl보다 \n이 훨씬 실행속도면에서 빠름.

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
//왜 주석은 틀릴까

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
//strlen 사용

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

//나누는 수도 double로 맞춰야 결과가 나오네????
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
/*
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

*/

//DATE-->0903

/*
#include <iostream>
using namespace std;

int main() {
	int note[8] = { 0 };
	bool aFlag = false;
	bool dFlag = false;

	for (int i = 0; i < 8; i++)
		cin >> note[i];

	if (note[0] == 1)
		aFlag = true;
	else if (note[0] == 8)
		dFlag = true;
	else {
		cout << "mixed" << "\n";
		return 0;
	}

	for (int i = 1; i < 8; i++) {
		if ((aFlag && note[i] != i + 1) ||
			(dFlag && note[i] != 8 - i)) {
			cout << "mixed" << "\n";
			return 0;
		}
	}

	if (note[7] == 8)
		cout << "ascending" << "\n";
	else
		cout << "descending" << "\n";
}

*/


//-->DATE 0905
/*

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char word[1000001];
	int alphabet[26] = { 0 };
	int alNum;
	int maxAl = 0;
	int maxIdx = 0;
	int leng;

	cin >> word;

	leng = strlen(word);

	for (int i = 0; i < leng; i++) {
		alNum = (int)word[i];

		if (alNum < 93)
			alphabet[alNum - 65]++;
		else
			alphabet[alNum - 97]++;

	}

	maxAl = alphabet[0];
	for (int i = 1; i < 26; i++) {
		if (alphabet[i] > maxAl) {
			maxAl = alphabet[i];
			maxIdx = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == maxAl && maxIdx != i) {
			cout << "?" << "\n";
			return 0;
		}
	}

	cout << (char)(maxIdx + 65) << "\n";
}
*/

//-->DATE 0906


//bj2908 왜 문자열은 오답으로 나올까

/*
#include <iostream>
using namespace std;

int main() {
	int a, b, num1, num2, num3;
	cin >> a >> b;

	num1 = a / 100;
	num2 = (a - (a / 100 * 100)) / 10;
	num3 = a % 10;

	a = num3 * 100 + num2 * 10 + num1;

	num1 = b / 100;
	num2 = (b - (b / 100 * 100)) / 10;
	num3 = b % 10;

	b = num3 * 100 + num2 * 10 + num1;

	cout << ((a > b) ? a : b) << "\n";





	char num1[4];
	char num2[4];

	cin >> num1 >> num2;

	char temp;

	temp = num1[0];
	num1[0] = num1[2];
	num1[2] = temp;

	temp = num2[0];
	num2[0] = num2[2];
	num2[2] = temp;

	if ((num1 - '0') > (num2 - '0'))
		cout << num1 << "\n";
	else
		cout << num2-'0' << "\n";
}
*/


/*bj5622
#include <iostream>
#include <string.h>
using namespace std;

int retTime(char alpha) {
	int ascii = (int)alpha;

	if (ascii <= 82)
		return ((ascii - 65) / 3) + 3;
	else if (ascii == 83)
		return 8;
	else if (ascii >= 84 && ascii <= 86)
		return 9;
	else
		return 10;
}

int main() {
	char inputWord[16];
	int leng, sum;

	cin >> inputWord;

	leng = strlen(inputWord);
	sum = 0;
	for (int i = 0; i < leng; i++)
		sum += retTime(inputWord[i]);

	cout << sum << "\n";
}

*/

/*bj2941
#include <iostream>
#include <string.h>

using namespace std;

int alpCounter(char word[], int leng) {
	int retCnt = 0;
	for (int i = 0; i < leng; i++) {
		if ((word[i] == 'c' && word[i + 1] == '=') ||
			(word[i] == 'c' && word[i + 1] == '-') || 
			(word[i] == 'd' && word[i + 1] == '-') || 
			(word[i] == 'l' && word[i + 1] == 'j') || 
			(word[i] == 'n' && word[i + 1] == 'j') || 
			(word[i] == 's' && word[i + 1] == '=') || 
			(word[i] == 'z' && word[i + 1] == '=')) {
			retCnt++;
			i++;
			continue;
		}
		else if (word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=') {
			retCnt++;
			i += 2;
		}
		else
			retCnt++;
	}

	return retCnt;
}

int main() {
	char inputWord[101];
	int wordNumber;
	int leng;

	cin >> inputWord;
	leng = strlen(inputWord);
	wordNumber = alpCounter(inputWord, leng);

	cout << wordNumber << "\n";
}
*/


/*bj1316
#include <iostream>
#include <string.h>
using namespace std;

char wordStorage[26] = { 0 };
int storageCnt = 0;

bool isGword(char word[], char len) {
	for (int i = 1; i < 26; i++)
		wordStorage[i] = 0;

	wordStorage[0] = word[0];
	storageCnt = 1;

	for (int i = 1; i < len; i++) {
		for (int j = 0; j < storageCnt; j++) {
			if (word[i] == wordStorage[j] && word[i - 1] != word[i])
				return false;
		}
		wordStorage[storageCnt++] = word[i];
	}

	return true;
}

int main() {
	int N, cnt, leng;
	bool flag = false;
	char inputWord[101];
	
	cin >> N;

	cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> inputWord;
		leng = strlen(inputWord);

		if (isGword(inputWord, leng))
			cnt++;
	}

	cout << cnt << "\n";
}
*/

//-->DATE 0907

//bj6064 실패
/*
#include <iostream>
using namespace std;

int getGcm(int a, int b)
{
	if (b == 0)
		return a;
	else
		return getGcm(b, a % b);
}


int main()
{
	int T, M, N, x, y;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> x >> y;

		while ((x != y) && (x <= (M * N) / getGcm(M, N)))
		{
			if (x < y)
				x += M;
			else
				y += N;
		}

		if (x != y)
			cout << "-1\n";
		else
			cout << x << "\n";
	}
}
*/

//bj 2751 
//#include <iostream>
//using namespace std;

//void Swap(int arr[], int idx1, int idx2) {
//	int temp = arr[idx1];
//	arr[idx1] = arr[idx2];
//	arr[idx2] = temp;
//}
//
//int Partition(int arr[], int left, int right) {
//	int pivot = arr[left];
//	int low = left + 1;
//	int high = right;
//
//	while (low <= high) {
//		while (pivot > arr[low])
//			low++;
//		while (pivot < arr[high])
//			high--;
//		if (low <= high)	//중요. 아직 low가 high보다 작을 때만 바꿈
//			Swap(arr, low, high);
//	}
//
//	Swap(arr, left, high);	//pivot과 high위치 교환
//
//	return high;			//pivot이 삽입된 위치 정보 반환
//}
//
//void QuickSort(int arr[], int left, int right) {
//	if (left <= right) {
//		int pivot = Partition(arr, left, right);
//		QuickSort(arr, left, pivot - 1);	//pivot의 위치를 기준(제외)으로 좌우 나눔
//		QuickSort(arr, pivot + 1, right);
//	}
//}

//퀵소트 
/*
void quickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = arr[left];
		int lIdx = left + 1;
		int rIdx = right;
		int temp;

		while (lIdx <= rIdx)
		{
			while (arr[lIdx] < pivot)
				lIdx++;
			while (arr[rIdx] > pivot)
				rIdx--;

			if (lIdx <= rIdx)
			{
				temp = arr[lIdx];
				arr[lIdx] = arr[rIdx];
				arr[rIdx] = temp;
			}
		}

		temp = arr[left];
		arr[left] = arr[rIdx];
		arr[rIdx] = temp;

		quickSort(arr, left, rIdx - 1);
		quickSort(arr, rIdx + 1, right);
	}
}

int main()
{
	int arr[1000001];
	int T;

	cin >> T;
	for (int i = 0; i < T; i++)
		cin >> arr[i];
	
	quickSort(arr, 0, T - 1);

	for (int i = 0; i < T; i++)
		cout << arr[i] << "\n";
}
*/

//bj 10989 radix정렬 런타임오류 해결불가. 인덱스 방식으로 바꿈
/*
#include <iostream>
#include <queue>
using namespace std;

void radixSort(int arr[], int n)
{
	queue<int> bucket[10];
	int divisor, idx;

	divisor = 1;
	for (int i = 0; i < 5; i++)
	{
		//cout << i + 1 << "의 자리\n";
		for (int j = 0; j < n; j++)
		{
			bucket[(arr[j] / divisor) % 10].push(arr[j]);
			//cout << (arr[j] / divisor) % 10 << " bucket에 push한 값 " << arr[j] << "\n";
		}
			

		idx = 0;
		for (int j = 0; j < 10; j++)
		{
			//cout << j << "번 버켓\n";
			while (!bucket[j].empty())
			{
				arr[idx++] = bucket[j].front();
				//cout << "arr[" << idx - 1 << "]에 " << bucket[j].front() << "삽입\n";
				bucket[j].pop();
			}
		}

		divisor *= 10;
	}
}

int main()
{
	int arr[10001] = { 0 };
	int N, inputNum;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> inputNum;
		arr[inputNum]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] > 0)
			for (int j = 0; j < arr[i]; j++)
				cout << i << "\n";
	}
}
*/

//bj9426 시간초과
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	int temper[250001];
	int scope[5001];
	int sum = 0;
	int scIdx;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> temper[i];

	for (int i = 0; i < N - K + 1; i++)
	{
		scIdx = 0;
		for (int j = i; j < i + K; j++)
			scope[scIdx++] = temper[j];

		sort(scope, scope + K);
		sum += scope[(K + 1) / 2 - 1];
	}

	cout << sum << "\n";
}
*/

/*//세그먼트트리이용 통과
#include <iostream>
#define MAX 2500001
#define maxIdx 65535
using namespace std;

typedef long long ll;


ll sTree[4 * MAX];
ll arr[MAX];

ll update(ll idx, ll cnt, ll node, ll start, ll end)
{
	if (!(idx >= start && idx <= end))
		return sTree[node];

	if (start == end)
		return sTree[node] += cnt;

	ll mid = (start + end) / 2;

	return sTree[node] = update(idx, cnt, node * 2, start, mid) +
		update(idx, cnt, node * 2 + 1, mid + 1, end);
}

ll getMidNum(ll idx, ll node, ll start, ll end)
{
	if (start == end)
		return start;

	ll mid = (start + end) / 2;
	if (idx <= sTree[node * 2])
		return getMidNum(idx, node * 2, start, mid);
	else
		return getMidNum(idx - sTree[node * 2], node * 2 + 1, mid + 1, end);
}

int main()
{
	int N, K;
	cin >> N >> K;

	ll sum = 0;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < K - 1; i++)
		update(arr[i], 1, 1, 0, maxIdx);

	for (int i = K - 1; i < N; i++)
	{
		update(arr[i], 1, 1, 0, maxIdx);
		sum += getMidNum((K + 1) / 2, 1, 0, maxIdx);
		update(arr[i - K + 1], -1, 1, 0, maxIdx);
	}

	cout << sum << "\n";
}
*/


//bj2108 오버해서 작성했더니 틀린곳도 못찾음.
/*
#include <iostream>
#include <math.h>
#define MAX 500001
#define maxIdx 4001
using namespace std;

typedef long long ll;

ll sTree[4 * MAX];
ll arr[MAX];

int temp;
ll maxi = 0;
ll mostIdx = -5000;

ll update(ll idx, ll cnt, ll node, ll start, ll end)
{
	if (!(start <= idx && idx <= end))
	{
		//cout << "sTree[" << node << "] return\n";
		return sTree[node];
	}

	if (start == end)
	{
		if (sTree[node] + 1 > maxi)
			maxi = sTree[node] + 1;

		return sTree[node] += cnt;
	}

	ll mid = (start + end) / 2;
	if ((start + end) < 0)
		if (-(start + end) % 2 == 1)
			mid -= 1;

	return sTree[node] = update(idx, cnt, node * 2, start, mid) +
		update(idx, cnt, node * 2 + 1, mid + 1, end);
}

ll getMidNum(ll idx, ll node, ll start, ll end)
{
	if (start == end)
		return start;

	ll mid = (start + end) / 2;
	if ((start + end) < 0)
		if (-(start + end) % 2 == 1)
			mid -= 1;

	if (idx <= sTree[node * 2])
		return getMidNum(idx, node * 2, start, mid);
	else
		return getMidNum(idx - sTree[node * 2], node * 2 + 1, mid + 1, end);
}

ll searchNode(ll idx, ll node, ll start, ll end)
{
	if (start == end)
		return sTree[node];

	ll mid = (start + end) / 2;
	if ((start + end) < 0)
		if (-(start + end) % 2 == 1)
			mid -= 1;

	if (idx <= sTree[node * 2])
		return searchNode(idx, node * 2, start, mid);
	else
		return searchNode(idx - sTree[node * 2], node * 2 + 1, mid + 1, end);
}

int main()
{
	int N;
	double sum, avg;
	cin >> N;

	sum = 0;
	avg = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		update(arr[i], 1, 1, -maxIdx, maxIdx);
	}

	bool mManyFlag = false;
	for (int i = 1; i <= N; i++)
	{
		if (searchNode(i, 1, -maxIdx, maxIdx) == maxi)
		{
			if (!mManyFlag)
				mManyFlag = true;
			else
			{
				mostIdx = getMidNum(i, 1, -maxIdx, maxIdx);
				break;
			}
		}
	}

	avg = sum / N;//산술평균
	cout << floor(avg + 0.5) << "\n";
	cout << getMidNum((N % 2 == 0 ? N / 2 : N / 2 + 1), 1, -maxIdx, maxIdx) << "\n";//중앙
	cout << mostIdx << "\n";//최빈
	cout << getMidNum(N, 1, -maxIdx, maxIdx) - getMidNum(1, 1, -maxIdx, maxIdx) << "\n";//범위
}

*/
/*
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int arr[500001];
	int idxCnt[8001] = { 0 };
	int N, maxNum, midNum, subMinMax;
	double sum, avg;

	cin >> N;

	sum = 0;
	maxNum = -432;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		
		idxCnt[arr[i] + 4000]++;
		if (idxCnt[arr[i] + 4000] > maxNum)
		{
			maxNum = idxCnt[arr[i] + 4000];
		}
			
	}

	//산평
	avg = sum / (double)N;
	avg = floor(avg + 0.5);

	//중앙
	sort(arr, arr + N);
	midNum = arr[N / 2];

	//최빈
	bool mFlag = false;
	int temp = 0;
	for (int i = 0; i <= 8000; i++)
	{
		if (idxCnt[i] == maxNum)
		{
			if (!mFlag)
			{
				mFlag = true;
				temp = i - 4000;
			}
			else
			{
				maxNum = i - 4000;
				mFlag = false;
				break;
			}
		}
	}
	if (mFlag)
		maxNum = temp;

	//범위
	subMinMax = arr[N - 1] - arr[0];

	cout << avg << "\n";
	cout << midNum << "\n";
	cout << maxNum << "\n";
	cout << subMinMax << "\n";
}

*/

//bj1181
/*
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string a, string b)
{
	if (a.length() == b.length())
		return a < b;

	return a.length() < b.length();
}

int main()
{
	int n;
	string a[20001];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n, cmp);

	for (int i = 0; i < n; i++)
		if (a[i] != a[i + 1])
			cout << a[i] << '\n';
}
*/

//소수
/*
#include <iostream>
using namespace std;

int notPrime[1001] = { 0 };

void eratos(int  N)
{
	notPrime[1] = 1;
	for (int i = 2; i*i <= N; i++)
	{
		if (notPrime[i] == 0)
		{
			for (int j = i*i; j <= N; j += i)
				notPrime[j] = 1;
		}
	}
}

int main()
{
	int n, inNum, cnt;
	cin >> n;

	eratos(1000);
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> inNum;
		if (!notPrime[inNum])
			cnt++;
	}

	cout << cnt << "\n";
}
*/

//DATE-->0902


//bj 9020
/*
#include <iostream>
#define MAX 10001
using namespace std;

int notPrime[MAX] = { 0 };

void eratos(int  N)
{
	notPrime[1] = 1;
	for (int i = 2; i*i < N; i++)
	{
		if (notPrime[i] == 0)
		{
			for (int j = i*i; j < N; j += i)
				notPrime[j] = 1;
		}
	}
}

int main()
{
	int n, inNum;
	eratos(MAX);

	cin >> n;

	int mid, up, down;
	for (int i = 0; i < n; i++)
	{
		cin >> inNum;
		
		mid = inNum / 2;
		
		up = mid;
		down = mid;

		for (int j = 0; j < mid; j++)
		{
			if (!notPrime[up] && !notPrime[down])
			{
				cout << down << " " << up << "\n";
				break;
			}
			up++;
			down--;
		}
	}
}

*/

//bj1874 시간초과
/*
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> mStack;
	
	int t, inNum;
	int idx = 1;
	int stackIdx = 0;

	cin >> t;

	mStack.push(0);
	while (t--)
	{
		cin >> inNum;

		if (inNum > mStack.top())
		{
			for (int i = idx; i <= inNum; i++)
			{
				mStack.push(i);
				cout << "+\n";
			}
			idx = inNum + 1;
		}

		if (inNum == mStack.top())
		{
			mStack.pop();
			cout << "-\n";
		}
		else {
			cout << "NO\n";
			break;
		}
	}
}
*/


//bj 1260 dfs bfs 스택과 큐

/*
#include <iostream>
#include <queue>
#define MAX 1000 + 1

using namespace std;

int n;
int visit[MAX];
int graph[MAX][MAX];

void dfs(int num)
{
	cout << num << " ";

	for (int i = 1; i <= n; i++)
	{
		if (graph[num][i] && visit[i] == 0)
		{
			visit[i] = 1;
			dfs(i);
		}
	}
}

void bfs(int num)
{
	queue<int> que;

	for (int i = 1; i <= n; i++)
		visit[i] = 0;

	que.push(num);
	visit[num] = 1;

	while (!que.empty())
	{
		int viNum = que.front();
		que.pop();
		cout << viNum << " ";

		for (int i = 1; i <= n; i++)
		{
			if (graph[viNum][i] && visit[i] == 0)
			{
				visit[i] = 1;
				que.push(i);
			}
		}
	}
}

int main()
{
	int m, start;
	int fr, to;

	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		cin >> fr >> to;

		graph[fr][to] = graph[to][fr] = 1;
	}

	visit[start] = 1;
	dfs(start);
	cout << "\n";
	bfs(start);
	cout << "\n";
}

*/


//deque
//bj1021
/*
#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int n, m, arr[51] = { 0 }, rst = 0, lCnt, rCnt;
	deque<int> nQ, lQ, rQ;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		nQ.push_back(i);

	for (int i = 0; i < m; i++)
	{
		lCnt = rCnt = 0;
		cin >> arr[i];
		if (arr[i] == nQ.front())
		{
			nQ.pop_front();
			continue;
		}

		lQ.clear();
		rQ.clear();
		lQ = rQ = nQ;
		nQ.clear();

		while (lQ.front() != arr[i])
		{
			lQ.push_back(lQ.front());
			lQ.pop_front();
			lCnt++;
		}
		lQ.pop_front();

		while (rQ.front() != arr[i])
		{
			rQ.push_front(rQ.back());
			rQ.pop_back();
			rCnt++;
		}
		rQ.pop_front();

		if (lCnt < rCnt)
		{
			nQ = lQ;
			rst += lCnt;
		}
		else
		{
			nQ = rQ;
			rst += rCnt;
		}
	}

	cout << rst << "\n";
}

*/

//-->DATE 0910
//bj2747 메모이제이션 피보나치
/*
#include <iostream>
using namespace std;

int memo[50];
int fibo(int n)
{
	if (n <= 1)
		return n;
	else if (memo[n] != 0)
		return memo[n];
	else
		return memo[n] = fibo(n - 2) + fibo(n - 1);
}

int main()
{
	int n;
	cin >> n;
	cout << fibo(n) << "\n";

	return 0;
}
*/

//bj11051 이항계수
/*
#include <iostream>
using namespace std;

long long combi[1001][1001];
int main()
{
	int n, k;
	cin >> n >> k;

	combi[0][0] = 1;

	for (int i = 1; i <= n; i++)
		combi[i][0] = combi[i][i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= (i - 1); j++)
			combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % 10007;

	cout << combi[n][k] << "\n";

	return 0;
}

*/

//bj10844
/*

#include <iostream>
#define MOD 1000000000
using namespace std;

int main()
{
	int n, sum = 0;
	int number[101][10] = { 0 };

	cin >> n;

	for (int i = 0; i < 10; i++)
		number[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		number[i][0] = number[i - 1][1] % MOD;
		number[i][9] = number[i - 1][8] % MOD;
		for (int j = 1; j <= 8; j++)
			number[i][j] = (number[i - 1][j - 1] + number[i - 1][j + 1]) % MOD;
	}

	for (int i = 1; i < 10; i++)
		sum  = (sum + number[n][i]) % MOD;

	cout << sum << "\n";
}

*/

//bj1005 시간초과 해결불가
//#include <iostream>
//using namespace std;
//
//struct building
//{
//	int bTime;
//	int maxIdx = 0;
//	int maxTime = 0;
//}typedef building;
//
//int main()
//{
//	building bd[1001];
//	int t, n, k, x, y, w, sum;
//
//	cin >> t;
//	for (int i = 0; i < t; i++)
//	{
//		cin >> n >> k;
//		for (int j = 1; j <= n; j++)
//			cin >> bd[j].bTime;
//
//		for (int j = 1; j <= k; j++)
//		{
//			cin >> x >> y;
//			if (bd[x].bTime > bd[y].maxTime)
//			{
//				bd[y].maxTime = bd[x].bTime;
//				bd[y].maxIdx = x;
//			}
//		}
//
//		cin >> w;
//
//		sum = bd[w].bTime;
//		while (1)
//		{
//			if (bd[w].maxIdx == 1)
//				break;
//
//			sum += bd[w].maxTime;
//			w = bd[w].maxIdx;
//		}
//
//		sum += bd[1].bTime;
//		cout << sum << "\n";
//	}
//}

//#include <iostream>
//using namespace std;
//
//int fti[1001][3] = { 0 };
////0 btime
////1 maxTime
////2 maxIdx
//
//void init()
//{
//	for (int i = 0; i < 1001; i++)
//		for (int j = 0; j < 3; j++)
//			fti[i][j] = 0;
//}
//
//int main()
//{
//	int t, n, k, x, y, w, sum;
//
//	cin >> t;
//	for (int i = 0; i < t; i++)
//	{
//		cin >> n >> k;
//
//		init();
//
//		for (int j = 1; j <= n; j++)
//			cin >> fti[j][0];
//
//		for (int j = 1; j <= k; j++)
//		{
//			cin >> x >> y;
//			if (fti[x][0] > fti[y][1])
//			{
//				fti[y][1] = fti[x][0];
//				fti[y][2] = x;
//			}
//		}
//
//		cin >> w;
//
//		sum = fti[w][0];
//		while (1)
//		{
//			if (fti[w][2] == 1)
//				break;
//
//			sum += fti[w][1];
//			w = fti[w][2];
//		}
//
//		sum += fti[1][0];
//		cout << sum << "\n";
//	}
//}


//bj1520 시간초과
/*
#include <iostream>
using namespace std;

int goMap[501][501] = { 0 };
int dp[501][501] = { 0 };
int nextCol[4] = { -1, 0, 1, 0};//위오아왼 (세로)
int nextRow[4] = { 0, 1, 0, -1};
int m, n, nC, nR;

int solve(int col, int row)
{
	if (col == m && row == n)
		return 1;

	if (dp[col][row] != 0)
		return dp[col][row];
	
	for (int i = 0; i < 4; i++)
	{
		nC = col + nextCol[i];
		nR = row + nextRow[i];

		if ((1 <= nC && nC <= m) && (1 <= nR && nR <= n) &&
			goMap[col][row] > goMap[nC][nR])
			dp[col][row] += solve(nC, nR);
	}

	return dp[col][row];
}


int main()
{
	cin >> m >> n;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> goMap[i][j];

	cout << solve(1, 1) << "\n";

	return 0;
}

*/

//bj11066
/*
#include <iostream>
using namespace std;

int chap[509];
int chaSum[509];
int dp[509][509];

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int t, k;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> chap[j];
			chaSum[j] = chap[j] + chaSum[j - 1];
		}

		for (int j = 1; j < k; j++)
		{
			for (int x = 1; j + x <= k; x++)
			{
				int y = j + x;
				dp[x][y] = 999999999;

				for (int mid = x; mid < y; mid++)
					dp[x][y] =
						min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + (chaSum[y] - chaSum[x - 1]));
			}
		}
		
		cout << dp[1][k] << "\n";
	}

	return 0;
}
*/


//->DATE0912
//bj1992 오답
/*
#include <iostream>
using namespace std;

int quad[65][65];

void solve(int r, int c, int num)
{
	int temp = quad[r][c];
	bool flag = false;

	for (int i = r; i < r + num; i++)
	{
		for (int j = c; j < c + num; j++)
		{
			if (quad[i][j] != temp)
			{
				flag = true;
				break;
			}
		}
		
		if (flag)
			break;
	}

	if (flag)
	{
		int nNum = num / 2;
		
		cout << "(";
		solve(r, c, nNum);
		solve(r, c + nNum, nNum);
		solve(r + nNum, c, nNum);
		solve(r + nNum, c + nNum, nNum);
		cout << ")";
		
	}
	else
		cout << temp;
}

int main ()
{
	int n;
	
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> quad[i][j];

	solve(1, 1, n);
}
*/

//bj1074 왜 틀린지 모르겠음 너무 조건이 까다로움

/*
#include <iostream>
#include <math.h>
using namespace std;

typedef long long ll;

ll solve(ll row, ll col, ll rst)
{
	ll i = 1, j = 1, inI = 1, inJ = 1, tmpI, tmpJ;

	while (1 < row && i <= row) i *= 2;
	while (1 < col && j <= col) j *= 2;

	i /= 2; j /= 2;
	tmpI = i; tmpJ = j;

	if (i != 0)
	{
		while (i--)
			inI *= 2;
		rst += inI * 2;
	}
		
	if (j != 0)
	{
		while (j--)
			inJ *= 2;
		rst += inJ;
	}

	row -= tmpI; col -= tmpJ;

	if (row >= 2 || col >= 2)
		rst = solve(row, col, rst);
	else
	{
		if (row == 1)
			rst += 2;
		if (col == 1)
			rst += 1;
	}

	return rst;
}

int main()
{
	ll N, r, c, i = 1, j = 1;

	
	while(cin >> N >> r >> c)
		cout << solve(r, c, 0) << "\n";
}

*/


//-->DATE0913

/*bj7569*/
/*
#include <iostream>
#include <queue>
using namespace std;

struct tomQu {
	int r, c, h;
	int cnt = 0;
}typedef tomQu;

int main()
{
	int M, N, H;
	int toma[101][101][101];
	int dirH[6] = { 1, -1, 0, 0, 0, 0 };
	int dirR[6] = { 0, 0, 1, -1, 0, 0 };
	int dirC[6] = { 0, 0, 0, 0, 1, -1 };
	queue<tomQu> q;

	cin >> M >> N >> H;
	
	int totalTom = 0;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= M; k++)
			{
				cin >> toma[i][j][k];
				if (toma[i][j][k] == 0)
					totalTom++;

				tomQu theToma;
				theToma.h = i;
				theToma.r = j;
				theToma.c = k;
				if (toma[i][j][k] == 1)
				{
					q.push(theToma);
					//cout << "push : " << i << " " << j << " " << k << "\n";
				}
			}

	//cout << "totalTom : " << totalTom << "\n";

	if (totalTom == 0)
	{
		cout << 0 << "\n";
		return 0;
	}
	
	int topCnt = 0;
	while (!q.empty())
	{
		tomQu temp = q.front();
		//cout << "pop : " << temp.h << " " << temp.r << " " << temp.c << "\n";
		q.pop();
		if (temp.cnt > topCnt)
			topCnt = temp.cnt;

		for (int i = 0; i < 6; i++)
		{
			int nH = temp.h + dirH[i];
			int nR = temp.r + dirR[i];
			int nC = temp.c + dirC[i];

			if (!(1 <= nH && nH <= H) ||
				!(1 <= nR && nR <= N) ||
				!(1 <= nC && nC <= M))
				continue;

			if (toma[nH][nR][nC] == 0)
			{
				toma[nH][nR][nC] = 1;
				tomQu theToma;
				theToma.h = nH;
				theToma.r = nR;
				theToma.c = nC;
				theToma.cnt = temp.cnt + 1;
				q.push(theToma);
				//cout << "push : " << nH << " " << nR << " " << nC << "\n";

				totalTom--;
			}
		}
	}

	if (totalTom > 0)
		cout << -1 << "\n";
	else
		cout << topCnt << "\n";
}
*/

//bj2252 위상정렬
/*
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct stde
{
	int number = -1;
	queue<int> to;
};

stde students[32001];
stack<int> rst;
int visit[32001] = { 0 };

int popQueue(queue<int> * q)
{
	if (!(q->empty()))
	{
		int temp = q->front();
		q->pop();
		return temp;
	}
	else
		return -1;
}

void dfs(int stNum)
{
	//cout << "visit : " << stNum << "\n";
	if (visit[stNum] == 0)
		visit[stNum] = 1;
	else
		return;

	int nextStu;

	while ((nextStu = popQueue(&(students[stNum].to))) != -1)
	{
		if (visit[nextStu] == 0)
			dfs(nextStu);
	}

	rst.push(stNum);
}

int main()
{
	int N, M, A, B;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		students[A].number = A;
		students[A].to.push(B);
	}

	for (int i = 1; i <= N; i++)
		dfs(i);

	while (!rst.empty())
	{
		cout << rst.top() << " ";
		rst.pop();
	}
}

*/

//-->Date 0914
//bj1753
/*
#include <iostream>
#include <vector>
#include <queue>
#define MAXV 20001
#define INF 999999999
using namespace std;

struct graph {
	int to, val;
}typedef Graph;

struct pqVal {
	int gNum;
	int distance = INF;
};

struct cmp//우선순위큐 비교기준 오버로딩
{
	bool operator()(pqVal a, pqVal b)
	{
		return a.distance > b.distance;//작은거부터 나옴
	}

};

vector<Graph> vg[MAXV];
priority_queue<pqVal, vector<pqVal>, cmp> q;
int dist[MAXV];
bool visit[MAXV];

int main()
{
	int V, E, K, u, v, w;
	Graph temp;
	pqVal start;

	cin >> V >> E >> K;

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		temp.to = v;
		temp.val = w;
		vg[u].push_back(temp);
	}

	for (int i = 1; i <= V; i++)
	{
		dist[i] = INF;
		visit[i] = false;
	}

	dist[K] = 0;
	start.distance = 0; start.gNum = K;
	q.push(start);
	
	while (!q.empty())
	{
		int curNum = q.top().gNum;
		//cout << "curNum : " << curNum << "\n";
		q.pop();

		if (visit[curNum])
			continue;
		else
			visit[curNum] = true;

		for (auto in : vg[curNum])
		{
			//cout << "in.to : " << in.to << "\n";
			//cout << "<<<  " << dist[in.to] << " " << (dist[curNum] + in.val) << "\n";
			if (dist[in.to] > (dist[curNum] + in.val))
			{
				dist[in.to] = dist[curNum] + in.val;
				start.distance = dist[in.to]; start.gNum = in.to;
				//cout << "push " << in.to << "\n";
				q.push(start);
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}
}

*/



//-->Date0916 카카오


//1번
//#include <iostream>
//#include <string>
//#include <vector>
//#include <bitset>
//
//using namespace std;
//
//int main()
//{
//	vector<int> arr1, arr2;
//	vector<int> tranMap;
//
//	arr1.push_back(9);
//	arr2.push_back(30);
//
//	bitset<16> bit = (arr1[0] | arr2[0]);
//	string rst = bit.to_string();
//	vector<string> ret;
//
//	int n = 5;
//	char temp;
//	string tempStr = "";
//
//
//	for (int i = 16 - n; i < 16; i++)
//	{
//		temp = rst.at(i);
//		
//		if (temp == '0')
//			tempStr += " ";
//		else
//			tempStr += "#";
//	}
//
//	cout << tempStr << "\n";
//
//	/*for (int i = 0; i < arr1.size(); i++)
//	{
//		tranMap[i] = arr1[i] | arr2[i];
//	}
//
//	cout << tranMap[0] << "\n";*/
//
//	return 0;
//}
//
//
////vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
////	vector<string> answer;
////	bitset<16> bit;
////
////	for (int i = 0; i < arr1.size(); i++)
////	{
////		bit = (arr1[i] | arr2[i]);
////		string tmpStr = bit.to_string();
////		string retStr = "";
////		char temp;
////
////		for (int j = 16 - n; j < 16; j++)
////		{
////			temp = tmpStr.at(j);
////
////			if (temp == '0')
////				retStr += " ";
////			else
////				retStr += "#";
////		}
////
////		answer.push_back(retStr);
////	}
////
////	return answer;
////}


//2번

//#include <iostream>
//#include <string>
//using namespace std;
//
//int solution(string dartResult) {
//	int answer = 0;
//	char temp;
//	int tempAsc;
//	int tmpNum = -1;
//	int scr[3] = { 0 };
//	int tmpScr[3] = { 0 };
//	int j = 0;
//	int k = 0;
//
//	for (int i = 0; i < dartResult.size(); i++)
//	{
//		temp = dartResult.at(i);
//		cout << temp << "\n";
//		int tmpNum = -1;
//		switch (temp)
//		{
//		case '0':
//				tmpNum = 0;
//				break;
//		case '1':
//			if (dartResult.at(i + 1) == '0')
//			{
//				tmpNum = 10;
//				i++;
//			}
//			else
//				tmpNum = 1;
//			break;
//		case '2':
//			tmpNum = 2;
//			break;
//		case '3':
//			tmpNum = 3;
//			break;
//		case '4':
//			tmpNum = 4;
//			break;
//		case '5':
//			tmpNum = 5;
//			break;
//		case '6':
//			tmpNum = 6;
//			break;
//		case '7':
//			tmpNum = 7;
//			break;
//		case '8':
//			tmpNum = 8;
//			break;
//		case '9':
//			tmpNum = 9;
//			break;
//		}
//		//cout << "tmpNum : " << tmpNum << "\n";
//
//		if (tmpNum != -1)
//		{
//			tmpScr[j++] = tmpNum;
//			cout << "tmpScr[" << j - 1 << "] = " << tmpScr[j - 1] << "\n";
//		}
//		
//		tempAsc = char(temp);
//		
//		cout << "tempAsc" << tempAsc << "\n";
//		int sFlag = -1;
//
//		switch (tempAsc)
//		{
//		case 83://S
//			scr[k++] += tmpScr[j - 1];
//			break;
//		case 68://D
//			scr[k++] += (tmpScr[j - 1] * tmpScr[j - 1]);
//			break;
//		case 84://T
//			scr[k++] += (tmpScr[j - 1] * tmpScr[j - 1] * tmpScr[j - 1]);
//			break;
//		case 42://*
//			if (j == 1)
//				scr[0] *= 2;
//			else
//			{
//				if (sFlag != -1)
//					scr[sFlag] -= scr[sFlag];
//				else
//				{
//					scr[k - 2] *= 2;
//					scr[k - 1] *= 2;
//				}
//			}
//			break;
//		case 35://#
//			scr[k - 1] -= (scr[k - 1] * 2);
//			sFlag = k - 1;
//			break;
//		}
//	}
//
//	answer = scr[0] + scr[1] + scr[2];
//
//	return answer;
//}
//
//
//
//int main()
//{
//	string test = "1D2S#10S";
//
//	cout << solution(test) << "\n";
//	
//	return 0;
//}

//3번
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cctype>
//#include <algorithm>
//
//using namespace std;
//
//int solution(int cacheSize, string cities[]) {
//	int answer = 0;
//	string cache[30];
//	int head = 0, tail = cacheSize - 1;
//	int least = 0;
//	
//	for (int i = 0; i < 4; i++)
//	{
//		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
//
//		bool flag = false;
//		for (int j = 0; j < head; j++)
//		{
//			if (cache[j].compare(cities[i]) == 0)
//			{
//				cout << cache[j] << "  -- hit\n";
//				answer += 1;
//				string temp = cache[j];
//				for (int k = j; k < head - 1; k++)
//					cache[k] = cache[k + 1];
//
//				cache[head - 1] = temp;
//				flag = true;
//
//				cout << "head : " << head << "\n";
//				cout << "히트 후 캐쉬상황 : ";
//				for (int i = 0; i < cacheSize; i++)
//					cout << cache[i] << " ";
//				cout << "\n";
//
//
//				break;
//			}
//		}
//
//		if (flag)
//			continue;
//		
//		if (head <= tail)
//			cache[head++] = (cities[i]);
//		else
//		{
//			for (int j = 0; j < tail; j++)
//			{
//				cache[j] = cache[j + 1];
//			}
//			cache[head - 1] = cities[i];
//		}
//
//		cout << "캐쉬상황 : ";
//		for (int i = 0; i < cacheSize; i++)
//			cout <<cache[i] << " ";
//		cout << "\n";
//		answer += 5;
//	}
//
//	return answer;
//}
//
//
//
//int main()
//{
//	string test[9] = {"Jeju", "Pangyo", "NewYork", "newyork"};
//
//	cout << solution(2, test) << "\n";
//
//	return 0;
//}


//4번
//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//string solution(int n, int t, int m, string timetable[], int rr) {
//	string answer = "";
//	int maxNum = m;
//	int time = 900;
//	int inTime;
//	int fHou, fMin;
//	int inNum = 0;
//	int maxTime = -1;
//	int answerInt = 0;
//
//	for (int i = 0; i < rr; i++)
//	{
//		inTime = 0;
//		inTime += (atoi((timetable[i].substr(0, 2)).c_str())) * 100;
//		inTime += atoi((timetable[i].substr(3, 2)).c_str());
//
//		cout << "inTime : " << inTime << "\n";
//		if (inTime <= time)
//		{
//			inNum++;
//			if (inTime > maxTime)
//				maxTime = inTime;
//		}
//
//		if (maxNum == inNum)
//		{
//			n--;
//			inNum = 0;
//			time += t;
//			if (time % 100 >= 60)
//			{
//				time += 100;
//				time -= 60;
//			}
//		}
//
//		if (n < 0)
//		{
//			answerInt = maxTime - 1;
//			break;
//		}
//	}
//
//	for (int i = 1; i <= n - 1; i++)
//	{
//		time += t;
//		if (time % 100 >= 60)
//		{
//			time += 100;
//			time -= 60;
//		}
//	}
//	
//	answerInt = time;
//
//	string tempStr = to_string(answerInt);
//
//	if (tempStr.size() == 3)
//		tempStr.insert(0, "0");
//
//	tempStr.insert(2, ":");
//
//	answer = tempStr;
//
//	return answer;
//}
//
//int main()
//{
//	string arr[3] = { "09:10", "09:09", "08:00" };
//	string rst = solution(2, 10, 2, arr, 3);
//	
//
//	cout << rst << "\n";
//	return 0;
//}

//#include <string>
//#include <cctype>
//#include <algorithm>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int solution(string str1, string str2) {
//	int answer = 0;
//	vector<string> sub1, sub2;
//
//	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
//	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
//
//	string temp;
//	for (int i = 0; i < str1.size() - 1; i++)
//	{
//		temp = str1.substr(i, 2);
//		if (char(str1.at(i)) < 65 || 90 < char(str1.at(i)) ||
//			char(str1.at(i + 1)) < 65 || 90 < char(str1.at(i + 1)))
//			continue;
//
//		sub1.push_back(temp);
//	}
//
//	for (int i = 0; i < str2.size() - 1; i++)
//	{
//		temp = str2.substr(i, 2);
//		if (char(str2.at(i)) < 65 || 90 < char(str2.at(i)) ||
//			char(str2.at(i + 1)) < 65 || 90 < char(str2.at(i + 1)))
//			continue;
//
//		sub2.push_back(temp);
//	}
//
//
//
//	return answer;
//}
//
//int main()
//{
//	string str1 = "e=m*c^2";
//
//	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
//
//	cout << str1 << "\n";
//}


//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//int solution(int m, int n, vector<string> board) {
//	int answer = 0;
//	char pan[31][31] = { 0 };
//	int delPan[31][31] = { 0 };
//
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			pan[i][j] = board[i].at(j);
//		}
//	}
//
//	bool eFlag = true;
//	int sts = 3;
//	while (sts--)
//	{
//		for (int i = 0; i < 31; i++)
//			delPan[i][i] = 0;
//		cout << sts << "---------\n";
//		if (eFlag == false)
//			break;
//		eFlag = false;
//
//		for (int i = 0; i < m - 1; i++)
//		{
//			for (int j = 0; j < n - 1; j++)
//			{
//				if (pan[i][j] == pan[i][j + 1] && pan[i][j] == pan[i + 1][j + 1] &&
//					pan[i][j] == pan[i + 1][j])
//				{
//					delPan[i][j] = delPan[i][j + 1] = delPan[i + 1][j + 1] = delPan[i + 1][j] = 1;
//					cout << "1pan[" << i << "][" << j << "] = " << pan[i][j] <<"\n";
//				}
//					
//			}
//		}
//
//		for (int i = 0; i < m; i++)
//			for (int j = 0; j < n; j++)
//				if (delPan[i][j] == 1)
//				{
//					eFlag = true;
//					pan[i][j] = 'd';
//					answer++;
//
//					//cout << "2pan[" << i << "][" << j << "] = " << pan[i][j] << "\n";
//
//					int temp = i - 1;
//					while (temp >= 0)
//					{
//						if (pan[temp][j] != 'd')
//						{
//							for (int k = i; k > 0; k--)
//							{
//								pan[k][j] = pan[k - 1][j];
//							}
//							
//
//
//							cout << "3pan[" << i << "][" << j << "] = " << pan[i][j] << "\n";
//							break;
//						}
//						else
//							temp--;
//					}
//				}
//	}
//
//	return answer;
//}
//
//int main()
//{
//	vector<string> test({ "CCBDE", "AAADE", "AAABF", "CCBBF" });
//
//	cout << solution(4, 5, test) << "\n";
//}


//--> Date 0917

//프로그래머스 148
/*
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > sumMatrix(vector<vector<int> >A, vector<vector<int> >B)
{
	vector<vector<int> > answer;
	

	for (int i = 0; i < A.size(); i++)
	{
		int temp =  0;
		vector<int> subAns;

		for (int j = 0; j < A[i].size(); j++)
		{
			temp = (A[i])[j] + (B[i])[j];
			subAns.push_back(temp);
		}
		
		answer.push_back(subAns);
	}

	return answer;
}
int main()
{
	vector<vector<int> > a{ { 1,2 },{ 2,3 },{ 2,3 },{ 2,3 } }, b{ { 3,4 },{ 5,6 },{ 2,3 },{ 2,3 } };
	vector<vector<int> > answer = sumMatrix(a, b);

	for (int i = 0; i<answer.size(); i++)
	{
		for (int j = 0; j<answer[i].size(); j++)
		{
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}
*/

//프로그래머스149
/*
#include<vector>
#include<iostream>
using namespace std;

int getGcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return getGcd(b, a % b);
}

vector<int> gcdlcm(int a, int b)
{
	vector<int> answer;

	int gcd = getGcd(a, b);
	int lcm = a * b / gcd;

	answer.push_back(gcd);
	answer.push_back(lcm);

	return answer;
}
int main()
{
	int a = 3, b = 12;
	vector<int> testAnswer = gcdlcm(a, b);

	cout << testAnswer[0] << " " << testAnswer[1];
}

*/

//프로그래머스 147

/*
#include<iostream>
using namespace std;

long long fibonacci(int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return fibonacci(n - 2) + fibonacci(n - 1);
}

int main()
{
	int testCase = 10;
	long long testAnswer = fibonacci(testCase);

	cout << testAnswer;
}
*/

//프로그래머스 146 약수의 합
/*
#include<iostream>
using namespace std;

int sumDivisor(int n)
{
	int ret = 0;

	for (int i = 1; i * i < n; i++)
		if (n % i == 0)
			ret += (i + (n / i));

	return ret;
}

int main()
{
	int testCase = 10;
	int testAnswer = sumDivisor(testCase);

	cout << testAnswer;
}
*/


//-->Date0919
//프로그래머스 140 행렬의 곱셉
/*
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> >productMatrix(vector<vector<int> >A, vector<vector<int> >B)
{
	vector<vector<int> >answer;
	
	
	for (int i = 0; i < A.size(); i++)
	{
		vector<int> innerAns;
		for (int j = 0; j < B[0].size(); j++)
		{
			int temp = 0;

			for (int k = 0; k < A[0].size(); k++)
			{
				temp += (A[i][k] * B[k][j]);
				//cout << "temp : " << temp << "\n";
			}

			//cout << "innerAns : " << temp << "\n";
			innerAns.push_back(temp);
		}

		answer.push_back(innerAns);
	}

	return answer;
}

int main()
{
	vector<vector<int> >A{ { 1,2 },{ 2,3 }, {4,5} };
	vector<vector<int> >B{ { 2,3,4 },{ 3,4,5 } };
	vector<vector<int> > testAnswer = productMatrix(A, B);

	for (int i = 0; i<testAnswer.size(); i++)
	{
		for (int j = 0; j<testAnswer[i].size(); j++)
			cout << testAnswer[i][j] << " ";
		cout << "\n";
	}
}
*/

//프로그래머스 150 콜라츠 추측
/*
#include<iostream>
using namespace std;

int collatz(int num)
{
	int answer = 0;

	while (num != 1)
	{
		if (num % 2 == 0)
			num /= 2;
		else
			num = (num * 3) + 1;

		answer++;

		if (answer == 500)
			return -1;
	}

	return answer;
}


int main()
{
	int testCase = 6;
	int testAnswer = collatz(testCase);

	cout << testAnswer;
}
*/


//프로그래머스 175 2016년
/*
#include<iostream>
#include<string>
using namespace std;

string getDayName(int a, int b)
{
	string answer = "";
	string d[7] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };

	int month, day, date = 0;

	for (month = 1; month <= a - 1; month++) {
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			day = 31;
		else if (month == 2)
			day = 29;
		else
			day = 30;

		date += day;
	}

	date += b;
	date %= 7;
	answer += d[date];

	return answer;
}
int main()
{
	int a = 2, b = 29;

	//아래는 테스트 출력을 위한 코드입니다.
	cout << getDayName(a, b);
}

*/


//프로그래머스 179
/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int getMinSum(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < A.size(); i++)
		answer += A[i] * B[i];

	return answer;
}
int main()
{
	vector<int> tA{ 1,2 }, tB{ 3,4 };

	//아래는 테스트 출력을 위한 코드입니다.
	cout << getMinSum(tA, tB);
}
*/

//-->Date 0920
//pg 170 다음 큰 숫자

/*
#include <iostream>
#include <cmath>
using namespace std;

int nextBigNumber(int n)
{
	int answer = 0;

	int digit[22] = { 0 };
	int dNum = 0;
	for (int i = 0; n != 0; i++)
	{
		digit[i] = n % 2;
		n /= 2;
		dNum++;
	}

	int tempDig = 0;
	int oneCnt = 0;
	bool lastFlag = false;
	while (1)
	{
		if (digit[tempDig] == 1)
		{
			oneCnt++;
			if (digit[tempDig + 1] == 0)
			{
				if (tempDig == dNum - 1)
					dNum++;

				digit[tempDig + 1] = 1;
				for (int i = tempDig; i >= 0; i--)
					digit[i] = 0;
				for (int i = 0; i < (oneCnt - 1); i++)
					digit[i] = 1;

				break;
			}
		}
		
		tempDig++;
	}

	for(int i = 0; i < dNum; i++)
	{
		//cout << digit[i] << " ";
		answer += (pow(2, i) * digit[i]);
	}

	return answer;
}
int main()
{
	int n = 78;

	//아래는 테스트 출력을 위한 코드입니다.
	cout << nextBigNumber(n);
}

*/

//-->Date 0921
//NHN모의테스트
/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct number
{
	int val;
	int issTen;
};

int main() {
	vector<number> inNum;
	int isTen[10] = { 0 };
	int sorArr[10] = { 0 };

	int a, id = 0;
	int tt = 5;
	while (cin >> a)
	{
		number t;
		t.val = a;
		t.issTen = 0;
		if (a >= 10)
			t.issTen = 1;
		inNum.push_back(t);
		cout << "in : " << a << "\n";
		id++;
	}
	
	int sorIdx = 0;
	while (!inNum.empty())
	{
		int maxVal = (inNum[0].issTen == 1 ? inNum[0].val / 10 : inNum[0].val);
		int maxId = 0;

		
		
		for (int i = 1; i < inNum.size(); i++)
		{
			int temp = inNum[i].val;

			if (inNum[i].issTen == 1)
				temp /= 10;

			

			if (temp > maxVal)
			{
				maxVal = temp;
				maxId = i;
			}
			else if (temp == maxVal)
			{
				//cout << "ss -- > " << inNum[i].val << " / " << inNum[maxId].val << "\n";
				if ((inNum[i].issTen == 1 && inNum[maxId].issTen == 1) &&
					(inNum[i].val % 10 > inNum[maxId].val % 10))
				{
					maxVal = temp;
					maxId = i;
				}
				else if ((inNum[maxId].issTen == 1 && inNum[maxId].val % 10 < temp) ||
					(inNum[i].issTen == 1 && inNum[i].val % 10 > inNum[maxId].val))
					maxId = i;
			}
		}
		//cout << "maxVal : " << inNum[maxId].val << "\n";

		sorArr[sorIdx++] = inNum[maxId].val;
		inNum.erase(inNum.begin() + maxId);
	}

	string temp = "";
	long long big, small;
	for (int i = 0; i < id; i++)
		temp += to_string(sorArr[i]);
	big = stoll(temp);
	temp.clear();
	for (int i = id - 1; i >= 0; i--)
		temp += to_string(sorArr[i]);
	small = stoll(temp);

	cout << big + small << "\n";

	return 0;
}
*/

//모의시험2번
//2차원배열 동적할당
//왜틀리지
/*
#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[N];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[j][i] << " ";

		cout << "\n";
	}

	for (int i = 0; i < N; i++)
		delete[]arr[i];
	delete[]arr;
	
	return 0;
}
*/


