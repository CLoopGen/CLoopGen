#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int DWTELEM;

DWTELEM *b;
DWTELEM *temp;
int width2;
int x;
int w2;

void init_vars() {
    width2 = 64 * 1024; 
    w2 = width2;
    size_t total_size = 2 * width2 * sizeof(DWTELEM); 

    b = aligned_alloc(32, 2 * width2 * sizeof(DWTELEM));
    temp = aligned_alloc(32, 2 * width2 * sizeof(DWTELEM));

    for (int i = 0; i < 2 * width2; i++) {
        b[i] = rand() % 1000;
    }

    for (int i = 0; i < 2 * width2; i++) {
        temp[i] = 0;
    }
}