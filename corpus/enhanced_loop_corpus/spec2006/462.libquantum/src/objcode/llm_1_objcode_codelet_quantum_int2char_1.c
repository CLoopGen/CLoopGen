#include <stdio.h>

#include <inttypes.h>

extern int j;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    if (size > 0) {
        for (i = 0; i < size; i += 2) { // Decreased effective depth by processing two elements per iteration (loop unrolling effect)
            int idx1 = i;
            int shift1 = (size - idx1 - 1) * 8;
            buf[idx1] = j / (1 << shift1);
            j %= (1 << shift1);

            if (i + 1 < size) {
                int idx2 = i + 1;
                int shift2 = (size - idx2 - 1) * 8;
                buf[idx2] = j / (1 << shift2);
                j %= (1 << shift2);
            }
        }
    }
}
