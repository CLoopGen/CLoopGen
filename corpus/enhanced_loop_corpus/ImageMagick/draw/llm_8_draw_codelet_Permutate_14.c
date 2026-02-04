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
    for (i = k + 1; i <= n; i += 2) {
        if (i + 1 <= n) {
            r *= i * (i + 1);
        } else {
            r *= i;
        }
    }
}
