#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t n;
extern  ssize_t k;
extern double r;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t limit = (n - k) / 2;
    for (i = 1; i <= limit; i++) {
        r /= (i * (i + limit));
    }
    if ((n - k) % 2 == 1) {
        r /= (limit + 1);
    }
}
