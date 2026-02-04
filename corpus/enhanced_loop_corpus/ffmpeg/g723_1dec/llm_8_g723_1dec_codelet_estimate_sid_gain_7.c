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
for (i = 0; i < shift * 2; i += 1) {
    t = seg * 64 + ((val << seg2) >> 1);
    t *= t;
    t += seg2 - val_add;
    if (x >= t)
        val += val_add;
    else
        val -= val_add;
    val_add >>= 2;
}
}
