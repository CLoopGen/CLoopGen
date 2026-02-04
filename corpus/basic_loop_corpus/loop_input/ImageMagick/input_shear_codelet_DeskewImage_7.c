#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t max_projection;
size_t *projection;
size_t width;
ssize_t i;
ssize_t skew;

void init_vars() {
    width = 10000000; // 10M elements, adjust for ~0.01s runtime
    max_projection = 0;
    skew = 0;
    i = 0;
    
    projection = (size_t*)malloc(width * 2 * sizeof(size_t));
    if (!projection) {
        exit(1);
    }
    
    srand(time(NULL));
    for (size_t idx = 0; idx < 2 * width - 1; idx++) {
        projection[idx] = rand() % 100000;
    }
}

void loop();