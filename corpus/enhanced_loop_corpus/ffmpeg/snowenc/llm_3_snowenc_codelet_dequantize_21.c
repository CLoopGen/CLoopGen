#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *src;
extern int stride;
extern  int w;
extern  int h;
extern  int qmul;
extern  int qadd;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Reverse Row Traversal
    // Access rows in reverse order and process columns with explicit stride-based indexing
    // This increases temporal distance between accesses to adjacent rows, creating a strided pattern
    for (y = h - 1; y >= 0; y--) {
        for (x = 0; x < w; x += 2) {  // Process every second element first (strided access)
            int idx = x + y * stride;
            int i = src[idx];
            if (i < 0) {
                src[idx] = -((-i * qmul + qadd) >> 13);
            } else if (i > 0) {
                src[idx] = ((i * qmul + qadd) >> 13);
            }
            // Handle next element if within bounds
            if (x + 1 < w) {
                int idx2 = (x + 1) + y * stride;
                int j = src[idx2];
                if (j < 0) {
                    src[idx2] = -((-j * qmul + qadd) >> 13);
                } else if (j > 0) {
                    src[idx2] = ((j * qmul + qadd) >> 13);
                }
            }
        }
    }
}
