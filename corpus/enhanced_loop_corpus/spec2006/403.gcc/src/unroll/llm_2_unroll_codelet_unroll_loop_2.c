#include <stdio.h>

#include <inttypes.h>

struct _factor {
    const int factor;
    int count;
};


extern struct _factor factors[4];
extern int i;
extern unsigned long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Reverse consecutive access with for-loop emulation of while logic
    // Memory access pattern: Consecutive reverse traversal (same index order, but rewritten without while)
    for (i = 4 - 1; i >= 0; i--) {
        for (; temp % factors[i].factor == 0; temp = temp / factors[i].factor) {
            factors[i].count++;
        }
    }
}
