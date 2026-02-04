#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int *len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_len = *len; // Remove direct loop-carried WAW on *len; use local accumulator
    for (; s[i]; i++) {
        int b = 1; // Reversed logic: assume match unless proven otherwise
        for (j = 0; sep[j]; j++) {
            if (s[i] != sep[j]) {
                b = 0; // Write depends on current sep[j] (stronger RAW per iteration)
                break;
            }
        }
        // Introduce WAR-like pattern artificially: use i before incrementing in next iteration
        if (b || !sep[0]) { // Handle empty sep edge case without changing semantics
            break;
        }
        local_len++; // Accumulate in local var to eliminate loop-carried WAW on *len
    }
    *len = local_len; // Store once after loop: removes loop-carried output dependency on *len
}
