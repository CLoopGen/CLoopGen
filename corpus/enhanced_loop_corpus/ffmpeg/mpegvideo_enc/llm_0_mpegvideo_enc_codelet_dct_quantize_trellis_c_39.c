#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int *qmat;
extern  uint8_t *scantable;
extern unsigned int threshold1;
extern unsigned int threshold2;
extern int start_i;
extern int last_non_zero;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_last_non_zero = -1;
for (int k = 63; k >= start_i; k -= 8) {
    for (int inner = 0; inner < 8 && (k - inner) >= start_i; inner++) {
        i = k - inner;
        const int j = scantable[i];
        int level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            temp_last_non_zero = i;
            goto exit_nested;
        }
    }
}
exit_nested:
if (temp_last_non_zero != -1) {
    last_non_zero = temp_last_non_zero;
}
}
