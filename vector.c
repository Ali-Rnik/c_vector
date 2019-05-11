#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct vector
{
	int *data;
	int size;
};

void vec_push(int val, struct vector *vec);
void vec_erase(int ind, struct vector *vec);

int main()
{
	int val;
	struct vector *vec;
	vec = (struct vector *) malloc(sizeof(struct vector));
	vec->size = 0;

	freopen("a.in", "r", stdin);

	while (val != 1000) {
		scanf("%d", &val);
		vec_push(val, vec);
	}

	vec_erase(vec->size - 1, vec);
	vec_erase(1, vec);
	for (int i = 0; i < vec->size; i++)
		printf("%d ", vec->data[i]);
}

void vec_push(int val, struct vector *vec)
{
	vec->data = (int *) reallocarray(vec->data, vec->size + 1, 
		sizeof(vec->data));
	if (vec->data == NULL)
		perror("Error in vec_push");
	else {
		vec->data[vec->size] = val;
		vec->size++;
	}
}

void vec_erase(int ind, struct vector *vec)
{
	if (vec->size <= 0 || ind >= vec->size || ind < 0) {
		printf("Vec_erase() misused\n");
		return;
	}

	for (int i = ind; i < vec->size - 1; i++)
		vec->data[i] = vec->data[i+1];

	vec->data = (int *) reallocarray(vec->data, vec->size - 1, 
		sizeof(vec->data));
	if (vec->data == NULL)
		perror("Error in vec_pop");
	else
		vec->size--;
}
