#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *low;
extern int16_t *high;
extern int16_t *ll;
extern int16_t *lh;
extern int16_t *hl;
extern int16_t *hh;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4 , j = 2; i; i-- , j++ , ll-- , hh++ , lh++ , hl--) {
    low[i - 5] = high[j - 2];
    lh[0] = ll[-1];
    high[i - 5] = low[j - 1];
    hh[0] = hl[-2];
}
}
