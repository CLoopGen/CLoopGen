#include <stdio.h>

#include <inttypes.h>

extern  char *p;
extern int hi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_i = 0;
    int temp_hi = hi;
    for (; p[local_i] != 0; local_i++) {
        temp_hi = ((temp_hi * 613) + (unsigned int)(p[local_i]));
    }
    i = local_i;
    hi = temp_hi;
}
