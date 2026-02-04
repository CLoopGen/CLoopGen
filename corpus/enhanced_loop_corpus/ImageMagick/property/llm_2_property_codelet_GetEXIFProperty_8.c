#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *property;
extern size_t tag;
extern ssize_t i;
extern int c;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2 (backward traversal with stride)
    // Simulates non-unit stride access pattern; assumes valid data layout for striding
    ssize_t stride = 2;
    ssize_t effective_n = n - ((n % stride) != 0 ? (n % stride) : 0); // Adjust n to align with stride
    for (i = (ssize_t)effective_n - 1L; i >= 0; i -= stride) {
        c = property[i]; // Access with index instead of pointer arithmetic for strided access
        tag <<= 4;
        if ((c >= '0') && (c <= '9'))
            tag |= (size_t)(c - '0');
        else if ((c >= 'A') && (c <= 'F'))
            tag |= (size_t)(c - ('A' - 10));
        else if ((c >= 'a') && (c <= 'f'))
            tag |= (size_t)(c - ('a' - 10));
        else
            return;
    }
}
