#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern INT n;
extern INT *primef;
extern INT i;
extern INT size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 3; i * i <= n && n > 1; i += 2) {
    if ((n % i) == 0) {
        primef[size++] = i;
        n /= i;
        i -= 2; // backtrack i to retest the same factor in next iteration due to step increment
    }
}
}
