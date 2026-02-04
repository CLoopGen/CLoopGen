#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int end_x;
extern int n;
extern uint8_t *a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp1, temp2, temp3, temp4;
    for (n = 1; n < end_x; n += 4) {
        temp1 = (n - 1 >= 0) ? a[n - 1] : 0;
        temp2 = temp1 + 1;
        temp3 = temp2 + 1;
        temp4 = temp3 + 1;
        a[n] = temp1;
        if (n + 1 < end_x) a[n + 1] = temp2;
        if (n + 2 < end_x) a[n + 2] = temp3;
        if (n + 3 < end_x) a[n + 3] = temp4;
    }
}
