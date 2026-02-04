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
    for (i = 3; i * i <= n && size < 10; i += 4) {
        if (n % i == 0) {
            primef[size++] = i;
            for (INT j = 0; j < 5 && n % i == 0; ++j) {
                n /= i;
            }
        }
        if (i * i <= n) {
            ++i;
        }
    }
}
