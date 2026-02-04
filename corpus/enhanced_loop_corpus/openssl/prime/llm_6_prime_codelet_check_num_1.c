#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int j = 0;
    for (i = 0; '0' <= s[i] && s[i] <= '9'; i++) {
        j = i; // Introduce WAW dependency: j is overwritten each iteration, creating a loop-carried dependence on j
    }
    // Use j after loop to maintain data dependency; prevents dead code elimination
    i = j + 1;
}
