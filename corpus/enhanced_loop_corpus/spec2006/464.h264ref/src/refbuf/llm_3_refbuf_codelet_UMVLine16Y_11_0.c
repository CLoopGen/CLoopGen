#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write pattern using a separate index for line, improving spatial locality
    int line_idx = 0;
    for (i = x; i < maxx; i++) {
        line[line_idx++] = Picy[(i - x) % 1]; // Still accesses Picy[0], but structured for potential extension
    }
}
