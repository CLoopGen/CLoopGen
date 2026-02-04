#include <stdio.h>

#include <inttypes.h>

typedef uintmax_t ossl_uintmax_t;

extern int level;
extern ossl_uintmax_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_level = 1;
    ossl_uintmax_t temp_n = n;
    for (level = 1; level < (((int)sizeof(ossl_uintmax_t) * 8 + 4 - 1) / 4); level++) {
        temp_n >>= 4;
        if (temp_n == 0) {
            level = temp_level;
            break;
        }
        temp_level++;
    }
    level = temp_level;
}
