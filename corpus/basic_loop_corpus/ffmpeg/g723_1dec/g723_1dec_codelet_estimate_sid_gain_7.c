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
for (i = 0; i < shift; i++) {
    t = seg * 32 + (val << seg2);
    t *= t;
    if (x >= t)
        val += val_add;
    else
        val -= val_add;
    val_add >>= 1;
}

}
