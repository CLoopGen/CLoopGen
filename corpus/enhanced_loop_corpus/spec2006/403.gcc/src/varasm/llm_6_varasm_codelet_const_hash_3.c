#include <stdio.h>

#include <inttypes.h>

extern  char *p;
extern int len;
extern int hi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_hi = hi;
    for (i = 0; i < len; i++) {
        temp_hi = ((temp_hi * 613) + (unsigned int)(p[i]));
    }
    hi = temp_hi;
}
