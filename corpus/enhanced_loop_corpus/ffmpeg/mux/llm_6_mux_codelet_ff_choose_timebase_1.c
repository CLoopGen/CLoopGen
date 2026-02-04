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
    int temp_num = q.num;
    for (j = 2; j < 14; j += 1 + (j > 2)) {
        if (temp_num % j == 0 && q.den / temp_num < min_precision) {
            temp_num /= j;
        }
    }
    q.num = temp_num;
}
