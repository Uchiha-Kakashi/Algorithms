#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void print(int *a, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf(" %d ", a[i]);
	printf("\n");
}

void countingsort(int *a, int n)
{
	int i;
	int *b = NULL;
	int *c = NULL;

	b = (int *)calloc(n, sizeof(int));
	c = (int *)calloc(n, sizeof(int));

	for(i = 0; i < n; i++)
		b[a[i]] = b[a[i]] + 1;

	for(i = 1; i < n; i++)
		b[i] = b[i] + b[i-1];

	for(i = n-1; i >= 0; i--) {
		c[b[a[i]]-1] = a[i];
		b[a[i]] = b[a[i]]-1;
	}
	for(i = 0; i < n; i++)
		a[i] = c[i];

	if(b != NULL) {
		free(b);
		b = NULL;
	}

	if(c != NULL) {
		free(c);
		c = NULL;
	}
}

void radix(int **x, int n, int noofdigits, int digit)
{
	int i,j;

	int *b = NULL;
	int **c = NULL;

	b = (int *)calloc(10, sizeof(int));
	c = (int **)calloc(n, sizeof(int*));
	for(j = 0; j < n; j++)
		c[j] = (int *)calloc(noofdigits, sizeof(int));

	for(i = 0; i < n; i++)
		b[x[i][digit]] = b[x[i][digit]] + 1;

	for(i = 1; i < 10; i++)
		b[i] = b[i] + b[i-1];

	for(i = n-1; i >= 0; i--) {
		for(j = noofdigits-1; j >= 0; j--)
			c[b[x[i][digit]]-1][j] = x[i][j];
		b[x[i][digit]] = b[x[i][digit]]-1;
	}

	for(i = 0; i < n; i++)
		for(j = noofdigits-1; j >= 0; j--)
			x[i][j] = c[i][j];

	if(b != NULL) {
		free(b);
		b = NULL;
	}

	if(c != NULL) {
		for(j = n-1; j >= 0; j--)
			free(c[j]);
		free(c);
		c = NULL;
	}
}

void radixsort(int *a, int n, int noofdigits)
{
	int i,j,sum;
	int **x = NULL;

	x = (int **)calloc(n,sizeof(int*));
	for(i = 0; i < n; i++)
		x[i] = (int *)calloc(noofdigits,sizeof(int));

	for(i = 0; i < n; i++) {
		for(j = noofdigits-1; j >= 0; j--) {
			x[i][j] = a[i] % 10;
			a[i] = a[i] / 10;
		}
	}

	for(i = noofdigits-1; i >= 0; i--)
		radix(x, n, noofdigits, i);

	for(i = 0; i < n; i++) {
		a[i] = 0;
		for(j = 0; j < noofdigits; j++) {
			a[i] = a[i]*10 + x[i][j];
		}
	}
}

typedef struct node {
	int data;
	struct node *next;
}node;

void insert(node *bucket, int data, int bno)
{
	node *temp;
	node *nd = (node *)calloc(1,sizeof(node));
	nd->data = data;
	nd->next = NULL;

	if(bucket[bno].next == NULL)
		bucket[bno].next = nd;
	else {
		temp = &bucket[bno];
		while(temp->next != NULL && temp->next->data <= data)
			temp = temp->next;
		nd->next = temp->next;
		temp->next = nd;
	}
}

void bucketsort(int *a, int n, int noofbuckets, int noofdigits)
{
	int i,count,div,bno;

	node *bucket = (node *)calloc(noofbuckets,sizeof(node));
	for(i = 0; i < noofbuckets; i++) {
		bucket[i].data = -1;
		bucket[i].next = NULL;
	}

	div = pow(10,noofdigits-1);
	for(i = 0; i < n; i++) {
		bno = a[i] / div;
		insert(bucket, a[i], bno);
	}
	count = 0;
	for(i = 0; i < noofbuckets; i++) {
		node *temp = bucket[i].next;
		while(temp != NULL) {
			a[count] = temp->data;
			temp = temp->next;
			count++;
		}
	}
}



int main()
{
	int *a = NULL;
	int n, i, choice;

	while(1) {

		printf("COUNTING SORT  : 1\n");
		printf("RADIX SORT     : 2\n");
		printf("BUCKET SORT    : 3\n");

		scanf("%d", &choice);

		if(choice <= 0)
			exit(0);

		printf("How many numbers:\n");
		scanf("%d", &n);

		a = (int *)calloc(n,sizeof(int));
		for(i = 0; i < n; i++) {
			printf("a[%d] = ", i);
			scanf("%d",&a[i]);
		}

        printf("The array before sorting:\n");
        print(a, n);



		switch(choice) {
			case 1:
				countingsort(a, n);
				break;
			case 2:
				radixsort(a, n, 5);
				break;
			case 3:
				bucketsort(a, n, 10, 5);
				break;
			default:
				printf("You have made a wrong choice\n.");
		}

        printf("The array after sorting:\n");
        print(a, n);

		if(a != NULL) {
			free(a);
			a = NULL;
		}
	}
	return 0;
}
