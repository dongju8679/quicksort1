#include <stdio.h>
#include <iostream>
#include "malloc.h"

using namespace std;

#define MAX_N 5


struct aa_t_
{
	int id;
	int val;
};

typedef struct aa_t_ aa_t;

int N;

aa_t in[MAX_N];

void quickSort(aa_t in[], int first, int last);
int print_sort(void);


int check_condition(aa_t in[], int i, int pivot)
{
	int ret = 0;
	if (in[i].id <= in[pivot].id)
	{
		ret = 1;
	}
	return ret;
}

int main(void)
{
	int ret = 0;
	int i;

	freopen("quicksort1.txt", "r", stdin);
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &in[i].id);
		scanf("%d", &in[i].val);
		printf("id(%d), val(%d)\n", in[i].id, in[i].val);
	}

	quickSort(in, 0, N - 1);

	print_sort();
	return ret;
}

int print_sort(void)
{
	int ret = 0;
	int i;
	printf("\n");
	printf("dongju start\n");

	for (i = 0; i < N; i++) {

		printf("id(%d), val(%d)\n", in[i].id, in[i].val);
	}
	return ret;
}

#if 1
void quickSort(aa_t in[], int first, int last)
{
    int pivot;
    int i;
    int j;
    aa_t temp;
    
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
#if 0
            while (in[i].id <= in[pivot].id && i < last)
#else
            while ((check_condition(in, i, pivot) == 1) && (i < last))
#endif
            {
                i++;
            }
            while (in[j].id > in[pivot].id)
            {
                j--;
            }
            if (i < j)
            {
                temp = in[i];
                in[i] = in[j];
                in[j] = temp;
            }
        }

        temp = in[pivot];
        in[pivot] = in[j];
        in[j] = temp;

        quickSort(in, first, j - 1);
        quickSort(in, j + 1, last);
    }
}
#endif

