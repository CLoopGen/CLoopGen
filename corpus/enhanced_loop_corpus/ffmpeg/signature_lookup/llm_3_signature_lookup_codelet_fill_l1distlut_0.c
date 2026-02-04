#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t lut[];
extern int i;
extern int j;
extern int tmp_i;
extern int tmp_j;
extern int count;
extern uint8_t dist;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint8_t *lut_ptr = &lut[0];
    for (i = 0; i < 242; i++) {
        for (j = i + 1; j < 243; j++) {
            dist = 0;
            tmp_i = i;
            tmp_j = j;
            for (; tmp_i | tmp_j; ) {
                int diff = (tmp_j % 3) - (tmp_i % 3);
                dist += diff >= 0 ? diff : -diff;
                tmp_i /= 3;
                tmp_j /= 3;
            }
            *lut_ptr++ = dist;
        }
    }
}
