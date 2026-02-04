#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern unsigned long long mu;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int outer_i;
    for (outer_i = size - 1; outer_i >= 0; outer_i--) {
        int inner_i = outer_i;
        if (inner_i == outer_i) {
            mu += buf[inner_i] * ((unsigned long long)1 << (8 * (size - inner_i - 1)));
        }
    }
}
