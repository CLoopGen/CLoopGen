#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

__attribute__((aligned(64))) extern real_t a[32000];
__attribute__((aligned(64))) extern real_t b[32000];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (int nl = 0; nl < 100000; nl++) {
        int temp_j = -1;
        real_t temp_a[32000];
        // First pass: compute new values without modifying original array
        for (int i = 0; i < 32000; i++) {
            temp_a[i] = a[i];
            if (a[i] > (real_t)0.) {
                temp_j++;
                temp_a[i] = b[temp_j];
            }
        }
        // Second pass: update a[] and j without data hazards
        for (int i = 0; i < 32000; i++) {
            a[i] = temp_a[i];
        }
        j = temp_j; // Update j once at the end to remove intra-loop WAW/WAR hazards
    }
}
