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
for (i = 2 , j = 2; i; i-- , j++ , ll++ , hh-- , lh-- , hl++) {
    low[i - 3] = low[j - 1];
    high[i - 3] = high[j - 2];
}
}
