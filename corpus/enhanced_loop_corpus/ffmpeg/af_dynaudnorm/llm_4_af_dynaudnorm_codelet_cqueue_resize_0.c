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
    for (int i = 0; i < side; i++) {
        if (i != side - 1) {
            q->elements[i] = q->elements[side];
        }
    }
}
