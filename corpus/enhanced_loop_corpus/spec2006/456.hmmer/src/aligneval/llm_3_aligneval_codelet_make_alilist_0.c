#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int *s1_list;
extern int col;
extern int r1;
extern int r2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via alternating forward and backward access)
    int len = 0;
    while (s1[len] != '\x00') len++; // Compute length first for boundary control

    for (col = 0; col < len; col++) {
        // Use indirect indexing: even indices accessed normally, odd indices from end
        int idx = (col % 2 == 0) ? col : len - 1 - (col / 2); // Non-uniform indirect pattern
        if (idx >= len) continue; // Safety check

        if (!((s1[idx]) == ' ' || (s1[idx]) == '.' || (s1[idx]) == '_' || (s1[idx]) == '-' || (s1[idx]) == '~')) {
            s1_list[r1] = ((s2[idx]) == ' ' || (s2[idx]) == '.' || (s2[idx]) == '_' || (s2[idx]) == '-' || (s2[idx]) == '~') ? -1 : r2;
            r1++;
        }
        if (!((s2[idx]) == ' ' || (s2[idx]) == '.' || (s2[idx]) == '_' || (s2[idx]) == '-' || (s2[idx]) == '~'))
            r2++;
    }
}
