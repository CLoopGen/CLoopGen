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
        tmp_i = i;
        for (j = i + 1; j < 243; j++, count++) {
            tmp_j = j;
            dist = 0;
            int local_tmp_i = tmp_i;
            int local_tmp_j = tmp_j;
            for (; local_tmp_i > 0 || local_tmp_j > 0; ) {
                int diff = (local_tmp_j % 3) - (local_tmp_i % 3);
                dist += (diff >= 0) ? diff : -diff;
                local_tmp_i /= 3;
                local_tmp_j /= 3;
            }
            lut[count] = dist;
        }
    }
}
