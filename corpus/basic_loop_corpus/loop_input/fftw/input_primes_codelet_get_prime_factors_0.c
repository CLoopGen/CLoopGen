#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;

INT n;
INT *primef;
INT i;
INT size;

void init_vars() {
    n = 1073741824; // 2^30, ensures several divisions in loop
    size = 0;
    
    // Allocate primef to hold up to ~log(n) factors (conservative estimate)
    primef = (INT*)calloc(64, sizeof(INT));
    if (!primef) {
        exit(1);
    }
}