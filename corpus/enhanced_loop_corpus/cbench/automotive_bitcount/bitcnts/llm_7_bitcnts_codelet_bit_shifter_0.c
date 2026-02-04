#include <stdio.h>

#include <inttypes.h>

extern long x;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    long local_x = x;
    int local_n = 0;
    int local_i = 0;
    for (; local_i < (sizeof(long) * 8); local_i++) {
        local_n += (int)((local_x >> local_i) & 1L);
    }
    i = local_i;
    n = local_n;
}
