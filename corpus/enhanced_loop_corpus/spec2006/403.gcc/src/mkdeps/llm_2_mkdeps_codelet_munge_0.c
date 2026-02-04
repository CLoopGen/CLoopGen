#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern int len;
extern  char *p;
extern  char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing each character sequentially, we simulate a strided access by stepping through
    // the string with a fixed stride (e.g., 2), but still maintain logical correctness by handling edge cases.
    // We process characters at even indices first, then handle odd indices in a second pass to simulate strided behavior.
    // However, since the original logic depends on sequential context, we emulate stride via index arithmetic.

    char *base = filename;
    int n = 0;
    while (base[n]) n++; // Compute length once for safe indexing

    p = filename;
    len = 0;

    // First pass: even indices (simulated strided access)
    for (int i = 0; i < n; i += 2) {
        char c = base[i];
        switch (c) {
            case ' ':
            case '\t':
                for (char *q = &base[i] - 1; filename <= q && *q == '\\'; q--)
                    len++;
                len++;
                break;
            case '$':
                len++;
                break;
        }
        len++;
    }

    // Second pass: odd indices
    for (int i = 1; i < n; i += 2) {
        char c = base[i];
        switch (c) {
            case ' ':
            case '\t':
                for (char *q = &base[i] - 1; filename <= q && *q == '\\'; q--)
                    len++;
                len++;
                break;
            case '$':
                len++;
                break;
        }
        len++;
    }
}
