#include <stdio.h>

#include <inttypes.h>

extern int64_t tmpval;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t values[64];
    size_t idx = 0;
    int64_t temp = tmpval;
    for (; temp > 9; idx++, temp /= 10)
        values[idx] = temp;
    len += idx;
    tmpval = values[idx-1] / 10;
}
