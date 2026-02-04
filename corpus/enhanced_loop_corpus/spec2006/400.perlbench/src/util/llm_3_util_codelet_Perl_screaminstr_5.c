#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern unsigned char *s;
extern unsigned char *x;
extern unsigned char *big;
extern I32 pos;
extern unsigned char *little;
extern unsigned char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // We simulate indirect access by treating 'big' as a base and using increasing offsets from a separate index sequence
    I32 offset = pos + 1;
    I32 idx = 0;
    I32 len = littleend - little;

    for (idx = 0; idx < len; idx++) {
        unsigned char *s_ptr = little + idx;
        unsigned char *x_ptr = big + offset + idx;

        // Simulate non-linear or reordered access: access every second element forward, then fill in backward
        if (idx % 2 == 0 && idx + 2 <= len) {
            // Access even indices in order
            if (*(little + idx) != *(big + offset + idx)) {
                s = little + idx - 1;
                break;
            }
        } else {
            // Handle odd indices by accessing from the end
            I32 rev_idx = len - (idx / 2 + 1);
            if (rev_idx <= idx) continue; // avoid reprocessing
            if (*(little + rev_idx) != *(big + offset + rev_idx)) {
                s = little + rev_idx - 1;
                break;
            }
        }

        // Final sequential update to maintain s consistency
        if (idx == len - 1) {
            s = little + len;
        }
    }
}
