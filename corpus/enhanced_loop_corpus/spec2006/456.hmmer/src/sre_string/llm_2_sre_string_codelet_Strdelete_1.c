#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern int pos;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (process every second element forward, then backward pass to fill)
    // This modifies the original behavior slightly but maintains shifting logic in strides
    char *start = s1 + pos;
    int i;
    int len = 0;
    for (i = 0; start[i]; i++) {
        len++;
    }
    // First pass: shift odd indices
    for (i = 1; i < len; i += 2) {
        start[i - 1] = start[i];
    }
    // Second pass: shift even indices
    for (i = 3; i < len; i += 2) {
        start[i - 2] = start[i];
    }
    // Final compacting pass to handle residual gaps (simplified reconstruction)
    s = start;
    while (*s) {
        *s = *(s + 1);
        s++;
    }
}
