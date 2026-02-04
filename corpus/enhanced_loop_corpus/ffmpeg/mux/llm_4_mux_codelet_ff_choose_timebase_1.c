#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVRational {
    int num;
    int den;
} AVRational;

extern int min_precision;
extern AVRational q;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 2; j < 14; j += 1 + (j > 2)) {
        if (q.den / q.num >= min_precision || q.num % j != 0) continue;
        q.num /= j;
    }
}
