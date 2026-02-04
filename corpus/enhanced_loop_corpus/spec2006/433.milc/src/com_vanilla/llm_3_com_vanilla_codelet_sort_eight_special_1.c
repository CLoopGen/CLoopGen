#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided and reverse-ordered access with symmetric indexing
    // Loop iterates forward but accesses pt in a strided and mirrored way
    for (i = 0; i <= 3; i++) {
        // Use symmetric offset calculation with stride of 2 in pt
        pt[2 * i] = tt[i];
        pt[2 * i + 1] = tt[7 - i];
    }
}
