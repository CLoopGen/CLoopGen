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
for (i = 0; i < (shift + 1) / 2; i++) {
    int temp1 = seg * 32 + (val << (seg2 & 7));
    int temp2 = seg * 16 + ((val + 1) << ((seg2 + 1) & 7));
    t = (temp1 * temp1 + temp2 * temp2) >> 1;
    if (x >= t)
        val += val_add;
    else
        val -= val_add;
    val_add = (val_add >> 1) | 0x10;
}
}
