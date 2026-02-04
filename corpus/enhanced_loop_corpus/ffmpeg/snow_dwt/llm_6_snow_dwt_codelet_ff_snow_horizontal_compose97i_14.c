#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int width;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM *restrict local_temp = temp;
    IDWTELEM *restrict local_b = b;
    int local_width = width;
    int local_w2 = w2;
    for (x = 1; x < (local_width >> 1); x++) {
        IDWTELEM val = local_b[x] - ((3 * (local_b[x + local_w2 - 1] + local_b[x + local_w2]) + 4) >> 3);
        local_temp[2 * x] = val;
        if (x > 1) {
            local_temp[2 * x - 1] = local_b[x + local_w2 - 1] - local_temp[2 * x - 2] - val;
        }
    }
    // Handle x=1 separately to maintain correctness
    if (1 < (local_width >> 1)) {
        temp[1] = b[local_w2] - temp[0] - temp[2];
    }
}
