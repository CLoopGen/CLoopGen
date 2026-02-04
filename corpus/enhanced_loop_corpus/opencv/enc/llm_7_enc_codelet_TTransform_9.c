#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        const int base = i * 4;
        const int a0 = base + 0;
        const int a1 = base + 1;
        const int a2 = base + 2;
        const int a3 = base + 3;
        tmp[0 + i * 4] = tmp[a1] + tmp[a0];  // Reversed access: WAR-like pattern introduced
        tmp[1 + i * 4] = tmp[a3] + tmp[a2];
        tmp[2 + i * 4] = tmp[a3] - tmp[a2];
        tmp[3 + i * 4] = tmp[a0] - tmp[a1];  // Uses updated values if earlier iterations modified them
    }
}
