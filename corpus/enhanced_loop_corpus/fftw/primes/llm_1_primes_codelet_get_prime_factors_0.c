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
    for (i = 3; i * i <= n; i += 2) {
        if (!(n % i)) {
            primef[size++] = i;
            INT temp_n = n;
            n = 1;
            for (; temp_n % i == 0; temp_n /= i) {
                // Factor out all occurrences of i
            }
            n = temp_n;
        }
    }
}
