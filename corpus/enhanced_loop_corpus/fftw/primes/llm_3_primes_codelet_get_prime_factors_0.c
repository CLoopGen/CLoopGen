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
    INT *pf = primef + size;
    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            *(pf++) = i;
            INT quotient;
            for (quotient = n / i; quotient % i == 0; quotient /= i)
                ;
            n = quotient;
        }
    }
    size = pf - primef;
}
