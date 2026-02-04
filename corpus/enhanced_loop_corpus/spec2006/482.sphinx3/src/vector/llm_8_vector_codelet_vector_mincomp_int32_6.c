#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < len; i += 2) {
        if (i + 1 < len) {
            int32 min_val = (val[i] < val[i + 1]) ? val[i] : val[i + 1];
            int32 min_idx = (val[i] < val[i + 1]) ? i : i + 1;
            if (min_val < val[bi])
                bi = min_idx;
        } else {
            if (val[i] < val[bi])
                bi = i;
        }
    }
}
