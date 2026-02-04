#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern int depth;
extern uint16_t *dsty;
extern int16_t *srcy;
extern ptrdiff_t stridey;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j++) {
    for (i = 0; i < w; i += 2) {
        int val1 = srcy[i];
        int val2 = (i + 1 < w) ? srcy[i + 1] : val1;
        int limit = (1 << depth) - 1;

        dsty[i] = (val1 <= 0) ? 0 : 
                  (val1 > limit) ? 65535 : 
                  (uint16_t)(((int64_t)val1 * val1 * 65535LL) / ((int64_t)limit * limit));

        if (i + 1 < w) {
            dsty[i + 1] = (val2 <= 0) ? 0 : 
                          (val2 > limit) ? 65535 : 
                          (uint16_t)(((int64_t)val2 * val2 * 65535LL) / ((int64_t)limit * limit));
        }
    }
    dsty += stridey;
    srcy += stridey;
}
}
