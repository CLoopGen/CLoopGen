#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int width;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Modify access to line[] with a stride of 2, writing every second element
    // This creates a non-unit stride access pattern, skipping elements
    // Remaining elements can be handled in a real scenario via another pass
    int start = (((width) > (x)) ? (width) : (x));
    for (i = start; i < maxx; i += 2) {
        line[(i - x) / 2] = Picy[width - 1];  // Stride-2 store via index scaling
    }
    // Handle odd-indexed iterations if needed in unrolled or secondary logic
    // Here we assume partial update is acceptable for demonstration
}
