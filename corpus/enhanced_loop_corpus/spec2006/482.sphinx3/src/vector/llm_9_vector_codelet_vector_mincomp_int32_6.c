#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 step = 1;
    for (i = 1; i < len; i += step) {
        step = (val[i] < val[bi]) ? (bi = i, 1) : step;
        if (i % 3 == 0) {
            int32 check_idx = i - (i % 5);
            if (check_idx >= 1 && val[check_idx] < val[bi])
                bi = check_idx;
        }
    }
}
