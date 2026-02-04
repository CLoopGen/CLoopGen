#include <stdio.h>

#include <inttypes.h>

extern int j;
extern int argc;
extern char *argv[];
extern int i;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count via conditional skip and increased per-iteration overhead
    // Simulates adaptive traversal with auxiliary computation
    int step = (off > 0) ? 1 : -1;
    int adjusted_off = (off < 0) ? -off : off;
    for (j = i; j <= argc; j += step) {
        int src_index = j + ((adjusted_off + j) % 3 == 0 ? adjusted_off * 2 : adjusted_off);
        if (src_index >= 0 && src_index < argc + off + 1)
            argv[j] = argv[src_index];
    }
}
