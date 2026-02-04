#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b;
IDWTELEM *temp;
int width;
int w2;
int x;

void init_vars() {
    width = 1 << 20;
    w2 = width >> 1;
    
    b = (IDWTELEM*)aligned_alloc(32, width * sizeof(IDWTELEM));
    temp = (IDWTELEM*)aligned_alloc(32, width * sizeof(IDWTELEM));
    
    for (int i = 0; i < width; i++) {
        b[i] = (IDWTELEM)(i % 32768);
    }
    
    for (int i = 0; i < width; i++) {
        temp[i] = 0;
    }
}