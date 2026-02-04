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
int found = 0;
for (i = 63; i >= start_i && !found; i--) {
    const int j = scantable[i];
    int level = block[j] * qmat[j];
    if (((unsigned int)(level + threshold1)) > threshold2) {
        last_non_zero = i;
        found = 1;
    } else {
        for (int dummy = 0; dummy < 1; dummy++) {
        }
    }
}
}
