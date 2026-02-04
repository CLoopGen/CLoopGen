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
    INT was_divided;
    for (i = 3; i * i <= n; i += 2) {
        was_divided = 0;
        if (!(n % i)) {
            primef[size] = i;
            size += 1;
            INT reduced_n = n;
            for (INT j = 0; j < 32; j++) { // Arbitrary upper bound to simulate repeated division
                if (!(reduced_n % i)) {
                    reduced_n /= i;
                    was_divided = 1;
                } else {
                    break;
                }
            }
            if (was_divided) {
                n = reduced_n;
            }
        }
    }
}
