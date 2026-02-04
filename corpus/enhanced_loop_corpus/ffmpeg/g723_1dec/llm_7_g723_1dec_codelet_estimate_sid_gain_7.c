#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int shift;
extern int seg;
extern int seg2;
extern int t;
extern int val;
extern int val_add;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_val = val;
    for (i = 0; i < shift; i++) {
        int local_t = seg * 32 + ((i == 0 ? val : prev_val) << seg2);
        local_t *= local_t;
        if (x >= local_t)
            val = prev_val + val_add;
        else
            val = prev_val - val_add;
        prev_val = val;
        val_add >>= 1;
    }
}
