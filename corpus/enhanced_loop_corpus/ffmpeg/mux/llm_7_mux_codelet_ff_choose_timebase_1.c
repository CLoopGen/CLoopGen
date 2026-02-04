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
    int prev_j = 2;
    int local_num = q.num;
    for (j = 2; j < 14; j += 1 + (j > 2)) {
        int step = 1 + (prev_j > 2);
        j = prev_j + step;
        prev_j = j;
        if (j >= 14) break;
        while (q.den / local_num < min_precision && local_num % j == 0) {
            local_num /= j;
        }
    }
    q.num = local_num;
}
