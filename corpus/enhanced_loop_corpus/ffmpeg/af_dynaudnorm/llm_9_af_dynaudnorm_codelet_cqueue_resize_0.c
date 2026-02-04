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
    for (int i = 0; i < side / 2; i++) {
        double temp = q->elements[side] + q->elements[side - 1];
        q->elements[2 * i] = temp / 2.0;
        q->elements[2 * i + 1] = temp * 0.5;
    }
}
