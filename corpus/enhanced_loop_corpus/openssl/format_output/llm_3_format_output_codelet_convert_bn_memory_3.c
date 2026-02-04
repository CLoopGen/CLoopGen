#include <stdio.h>

#include <inttypes.h>

extern int n;
extern char *p;
extern char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Instead of direct sequential access, we use a precomputed access pattern (even indices first, then odd).
    // Since we cannot define new global arrays, we simulate indirect traversal using modular arithmetic.
    int len = 0;
    char *temp = p;
    while (temp[len] != '\0') len++; // Compute length safely

    for (int j = 0; j < len; j++) {
        // Access pattern: even indices first, then odd (indirect-like ordering)
        int idx = (j % 2 == 0) ? j / 2 : len / 2 + (j / 2);
        if (idx >= len) continue;

        char c = p[idx];
        if (c == '0' || c == ' ') {
            if (c == '0') {
                q = &p[idx];
                p[idx] = ' ';
                n--;
            }
        }
    }
}
