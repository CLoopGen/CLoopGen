#include <stdio.h>

#include <inttypes.h>

extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Increase trip count by processing every character in steps of 1, but include redundant checks
    // and simulate higher workload via unrolled-like behavior without actual unrolling
    for (i = 0; s[i] != '\0' && ('0' <= s[i] && s[i] <= '9'); i += 1) {
        // Extend condition scope to ensure full traversal until non-digit or null terminator
        // Additional check increases effective trip count when non-digit follows digit
        if (s[i+1] == '\0') break;  // Peek ahead to influence control flow slightly
    }
}
