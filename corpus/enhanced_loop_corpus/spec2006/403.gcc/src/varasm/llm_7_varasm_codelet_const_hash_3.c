#include <stdio.h>

#include <inttypes.h>

extern  char *p;
extern int len;
extern int hi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_hi = 0;
    for (i = 0; i < len; i += 2) {
        int val1 = (i < len) ? (unsigned int)(p[i]) : 0;
        local_hi = (local_hi * 613) + val1;
        if (i + 1 < len) {
            int val2 = (unsigned int)(p[i + 1]);
            local_hi = (local_hi * 613) + val2;
        }
    }
    hi = (hi * 613) + local_hi;
}
