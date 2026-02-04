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
    int should_divide;
    for (j = 2; j < 14; j += 1 + (j > 2)) {
        should_divide = (q.den / q.num < min_precision) && (q.num % j == 0);
        if (should_divide) {
            q.num /= j;
            j--; // allow repeated division by same j after decrement due to step logic
        }
    }
}
