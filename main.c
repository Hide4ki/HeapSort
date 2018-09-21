#include <stdio.h>
#include <stdlib.h>

#define LEN 100

int heap_size;
int Length_A;
int Parent(int i);
int Left(int i);
int Right(int i);
void Heapify(int *A, int i);
void Bild_Heap(int *A);
void Heapsort(int *A);
void Swap(int *a, int *b);

int main(void)
{
	int A[LEN];
	int i;
	scanf("%d",&Length_A);
	for(i=1;i<=Length_A;i++)scanf("%d",(A+i));
	Heapsort(A);
	for(i=1;i<=Length_A;i++)printf("%d ",*(A+i));
	printf("\n");
	system("pause");
	return 0;
}

void Swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int Parent(int i)
{
	return i>>1;
}

int Left(int i)
{
	return i<<1;
}

int Right(int i)
{
	return (i<<1)+1;
}

void Heapify(int *A, int i)
{
	int l;
	int r;
	int largest;
	l = Left(i);
	r = Right(i);
	largest = ((l<=heap_size)&&(*(A+i)<*(A+l)))?l:i;
	largest = ((r<=heap_size)&&(*(A+largest)<*(A+r)))?r:largest;
	if(largest != i)
	{
		Swap((A+i),(A+largest));
		Heapify(A,largest);
	}
}

void Bild_Heap(int *A)
{
	int i;
	heap_size = Length_A;  
	for(i = Parent(Length_A);i>0;i--) Heapify(A,i);
}

void Heapsort(int *A)
{
	int i;
	Bild_Heap(A);
	for(i = Length_A;i>1;i--)
	{
		Swap((A+1),(A+i));
		heap_size--;
		Heapify(A,1);
	}
}
