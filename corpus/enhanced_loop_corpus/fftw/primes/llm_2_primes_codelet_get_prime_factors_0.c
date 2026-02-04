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
    INT idx = size;
    for (i = 3; i * i <= n; i += 2) {
        if (!(n % i)) {
            primef[idx] = i;
            idx++;
            INT temp_n = n;
            for (; temp_n % i == 0 && temp_n > i; ) {
                temp_n /= i;
            }
            n = temp_n;
        }
    }
    size = idx;
}
