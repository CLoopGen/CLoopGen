#include <stdio.h>

#include <inttypes.h>

extern  char *m1;
extern  char *m2;
extern char bdiff[81];
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t idx;
    unsigned int local_diff = diff;
    for (idx = i; idx < j; idx++) {
        char m1_val = m1[idx];
        char m2_val = m2[idx];
        bdiff[idx] = (m1_val == m2_val) ? ' ' : '^';
        if (m1_val != m2_val) {
            local_diff = 1;
        }
    }
    diff = local_diff;
}
