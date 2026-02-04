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



void loop() {
    for (j = 1; j < 20; j += 2) {
        if (q.den / q.num < min_precision && q.num % j == 0) {
            q.num /= j;
            j--; // Extend trip count by allowing repeated division by same factor
        }
    }
}
