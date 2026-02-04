#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m1;
extern  unsigned char *m2;
extern char *p;
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_i = i;
    unsigned char *local_m1 = m1;
    unsigned char *local_m2 = m2;
    char *local_p = p;
    unsigned int local_diff = diff;
    for (; temp_i < j; temp_i++) {
        if (local_m1[temp_i] == local_m2[temp_i]) {
            local_p[0] = ' ';
            local_p[1] = ' ';
            local_p += 2;
        } else {
            local_p[0] = '^';
            local_p[1] = '^';
            local_p += 2;
            local_diff = 1;
        }
        if (temp_i % 8 == 7 && temp_i != j - 1) {
            *local_p++ = ' ';
        }
    }
    p = local_p;
    diff = local_diff;
}
