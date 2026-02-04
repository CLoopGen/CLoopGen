#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int group_len;
extern int swb_size;
extern  float *scaled;
extern float maxval;
extern int w2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (w2 = 0; w2 < group_len; w2 += 2) {
    for (i = 0; i < swb_size; i += 2) {
        float val1 = scaled[w2 * 128 + i];
        float val2 = (i + 1 < swb_size) ? scaled[w2 * 128 + i + 1] : val1;
        float val3 = (w2 + 1 < group_len) ? scaled[(w2 + 1) * 128 + i] : val1;
        float val4 = (w2 + 1 < group_len && i + 1 < swb_size) ? scaled[(w2 + 1) * 128 + i + 1] : val1;
        maxval = ((maxval > val1) ? maxval : val1);
        maxval = ((maxval > val2) ? maxval : val2);
        maxval = ((maxval > val3) ? maxval : val3);
        maxval = ((maxval > val4) ? maxval : val4);
    }
}
}
