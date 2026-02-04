#include <stdio.h>

#include <inttypes.h>

extern char b1[81];
extern char b2[81];
extern char *p;
extern size_t i;
extern unsigned int diff;
extern unsigned int real_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_i = 0;
    unsigned int local_diff = 0;
    unsigned int local_real_diff = 0;
    char temp_p[81];
    size_t temp_idx = 0;

    for (local_i = 0; b1[local_i] != '\x00'; local_i++) {
        char b1_val = b1[local_i];
        char b2_val = b2[local_i];
        if (b1_val == b2_val || b1_val == ' ' || b2_val == ' ') {
            temp_p[temp_idx] = ' ';
            local_diff |= (b1_val != b2_val);
        } else {
            temp_p[temp_idx] = '^';
            local_real_diff = 1;
            local_diff = 1;
        }
        temp_idx++;
    }

    for (size_t k = 0; k < temp_idx; k++) {
        *p++ = temp_p[k];
    }

    diff = local_diff;
    real_diff = local_real_diff;
}
