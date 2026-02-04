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
for (i = 0, count = 0; i < 162; i++) {
    for (j = i + 2; j < 243; j++, count++) {
        dist = 0;
        tmp_i = i;
        tmp_j = j;
        for (; tmp_i | tmp_j; tmp_i /= 3, tmp_j /= 3) {
            int mod_i = tmp_i % 3;
            int mod_j = tmp_j % 3;
            dist += (mod_j > mod_i) ? (mod_j - mod_i) : (mod_i - mod_j);
        }
        lut[count] = dist;
    }
}
}
