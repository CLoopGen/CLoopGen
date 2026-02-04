#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct cqueue {
    double *elements;
    int size;
    int max_size;
    int nb_elements;
} cqueue;

extern cqueue *q;
extern  int side;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < side; i += 2) {
        q->elements[i] = q->elements[side];
        if (i + 1 < side)
            q->elements[i + 1] = q->elements[side];
    }
}
