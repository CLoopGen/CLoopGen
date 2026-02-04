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
    INT remainder = n % i;
    if (remainder == 0) {
        primef[size++] = i;
        n /= i;
        for (; n % i == 0; ) {
            n /= i;
        }
    }
}
}
