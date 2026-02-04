#include <stdio.h>

#include <inttypes.h>

extern char *PL_Cmd;
extern char **a;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access using pointer arithmetic with for-loops only
    char *ptr = PL_Cmd;
    char **arg_ptr = a;

    for (; ptr && *ptr; ) {
        // Skip whitespace using for-loop
        for (; *ptr && (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\f'); ++ptr);
        
        // If not at end, store current position
        if (*ptr) {
            *arg_ptr++ = ptr;
        }

        // Advance through non-whitespace using for-loop
        for (; *ptr && !(*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\f'); ++ptr);

        // Terminate token if not at string end
        if (*ptr) {
            *ptr++ = '\x00';
        }
    }

    a = arg_ptr; // Update global a if needed
}
