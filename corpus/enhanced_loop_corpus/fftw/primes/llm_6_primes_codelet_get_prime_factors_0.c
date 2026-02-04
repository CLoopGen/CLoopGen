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
    INT temp_n = n;
    for (i = 3; i * i <= temp_n; i += 2) {
        if (!(temp_n % i)) {
            primef[size] = i;
            size++;
            INT div_count = 0;
            INT local_temp = temp_n;
            for (; !(local_temp % i); div_count++) {
                local_temp /= i;
            }
            temp_n = local_temp;
        }
    }
    n = temp_n;
}
