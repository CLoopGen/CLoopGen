#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp1;
extern int energy[5];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_temp = -2147483648;
    for (i = 0; i < 10; i++) {
        int idx = i / 2;
        int val = (i % 2 == 0) ? (energy[idx] * 2) : (energy[idx] + 1);
        if (val > local_temp)
            local_temp = val;
    }
    temp1 = local_temp;
}
