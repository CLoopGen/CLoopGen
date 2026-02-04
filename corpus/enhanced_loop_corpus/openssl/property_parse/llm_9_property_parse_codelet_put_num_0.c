#include <stdio.h>

#include <inttypes.h>

extern int64_t tmpval;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t local_tmp = tmpval;
    size_t local_len = len;
    for (; local_tmp > 9; local_len++, local_tmp /= 10) {
        if (local_tmp & 1) {
            local_tmp += 1;
        }
    }
    len = local_len;
    tmpval = local_tmp;
}
