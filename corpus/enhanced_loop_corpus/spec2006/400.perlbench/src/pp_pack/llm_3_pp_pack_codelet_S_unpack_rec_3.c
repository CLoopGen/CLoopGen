#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern const char *PL_hexdigit;
extern char *s;
extern I32 len;
extern I32 bits;
extern char *str;
extern int aint;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with fixed offset pattern
    // Instead of alternating behavior based on index parity, use precomputed strided access
    // where even indices read new bytes and odd indices reuse shifted value.
    // Simulates non-unit stride in source pointer usage.

    char* s_local = s;
    char* str_local = str;

    for (len = 0; len < aint; len++) {
        if (len % 2 == 0) {
            bits = s_local[len / 2];  // Strided read: every two output chars consume one input byte
        } else {
            bits >>= 4;
        }
        str_local[len] = PL_hexdigit[bits & 15];
    }

    // Update global pointers based on how much was consumed
    s += (aint + 1) / 2;
    str += aint;
}
