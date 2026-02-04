#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *src;
extern int stride;
extern  int w;
extern  int h;
extern  int qmul;
extern  int qadd;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int i = src[x + y * stride];
        int neg_cond = i < 0;
        int pos_cond = i > 0;
        int abs_val = neg_cond ? -i : i;
        int computed = (abs_val * qmul + qadd) >> 11;
        if (neg_cond) {
            src[x + y * stride] = -computed;
        } else if (pos_cond) {
            src[x + y * stride] = computed;
        } // implicit: if i == 0, no change needed (stays 0)
    }
}
}
