#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern int PL_origargc;
extern char **PL_origargv;
extern char *s;
extern int i;
extern UV mask;
extern UV aligned;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling (stride-2)
    char **argv_ptr = PL_origargv + 1;
    char **argv_end = PL_origargv + PL_origargc;
    
    for (; argv_ptr < argv_end; argv_ptr += 2) {
        // Process two elements consecutively if within bounds
        if (argv_ptr[0] == s + 1 || (aligned && argv_ptr[0] > s && argv_ptr[0] <= (char *)((UV)(s + 8) & mask))) {
            s = argv_ptr[0];
            for (; *s != '\0'; s++);
        } else {
            break;
        }

        if (argv_ptr + 1 < argv_end) {
            if (argv_ptr[1] == s + 1 || (aligned && argv_ptr[1] > s && argv_ptr[1] <= (char *)((UV)(s + 8) & mask))) {
                s = argv_ptr[1];
                for (; *s != '\0'; s++);
            } else {
                break;
            }
        }
    }
}
