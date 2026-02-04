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



void loop(){
for (i = 0, count = 0; i < 242; i++) {
    for (j = i + 1; j < 243; j++, count++) {
        dist = 0;
        for (tmp_i = i, tmp_j = j; tmp_i > 0 || tmp_j > 0; tmp_i /= 3, tmp_j /= 3) {
            dist += (((tmp_j % 3) - (tmp_i % 3)) >= 0 ? ((tmp_j % 3) - (tmp_i % 3)) : (-((tmp_j % 3) - (tmp_i % 3))));
        }
        lut[count] = dist;
    }
}
}
