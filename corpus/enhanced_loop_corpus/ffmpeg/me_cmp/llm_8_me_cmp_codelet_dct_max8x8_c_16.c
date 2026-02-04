#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 128; i += 2) {
        int16_t val1 = temp[i];
        int16_t abs_val1 = val1 >= 0 ? val1 : -val1;
        sum = sum > abs_val1 ? sum : abs_val1;
        if (i + 1 < 128) {
            int16_t val2 = temp[i + 1];
            int16_t abs_val2 = val2 >= 0 ? val2 : -val2;
            sum = sum > abs_val2 ? sum : abs_val2;
        }
    }
}
