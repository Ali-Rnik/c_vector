#include "vector.h"

void init_vec(struct vector **vec)
{
	*vec = (struct vector *) malloc(sizeof(struct vector));
	(*vec)->size = 0;
	(*vec)->erase = vec_erase;
	(*vec)->push = vec_push;
}

void vec_push(struct vector *vec, int val)
{
	vec->data = (int *) reallocarray(vec->data, vec->size + 1, 
		sizeof(int));
	if (vec->data == NULL)
		perror("Error in vec_push");
	else {
		vec->data[vec->size] = val;
		vec->size++;
	}
}

void vec_erase(struct vector *vec, int ind)
{
	if (vec->size <= 0 || ind >= vec->size || ind < 0) {
		printf("Vec_erase() misused\n");
		return;
	}

	vec->size--;
	for (int i = ind; i < vec->size; i++)
		vec->data[i] = vec->data[i+1];

	vec->data = (int *) reallocarray(vec->data, vec->size, sizeof(int));
}
