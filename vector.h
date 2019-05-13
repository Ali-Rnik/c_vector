#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

struct vector
{
	int *data;
	int size;

	void (*erase)(struct vector *self, int ind);
	void (*push)(struct vector *self, int val);
};

void init_vec(struct vector **vec);
void vec_push(struct vector *vec, int val);
void vec_erase(struct vector *vec, int ind);

#endif /* VECTOR_H */
