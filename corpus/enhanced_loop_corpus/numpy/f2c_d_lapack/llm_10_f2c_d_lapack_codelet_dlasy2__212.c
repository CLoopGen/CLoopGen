#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__;
extern integer j;
extern integer k;
extern doublereal t16[16];
extern doublereal tmp[4];
extern doublereal btmp[4];
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= 8; ++i__) {
    k = 9 - i__;
    if (k >= 1 && k <= 4) {
        temp = 1.0 / t16[k + (k << 2) - 5];
        tmp[k - 1] = btmp[k - 1] * temp;
        for (j = k + 1; j <= 4; ++j) {
            tmp[k - 1] -= temp * t16[k + (j << 2) - 5] * tmp[j - 1];
        }
    } else {
        temp = 0.0;
        for (j = 1; j <= 4; ++j) {
            temp += btmp[j - 1];
        }
        temp /= 4.0;
        for (j = 1; j <= 4; ++j) {
            tmp[j - 1] = temp * (i__ & 1 ? 1.0 : -1.0);
        }
    }
}
}
