#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

extern R *I;
extern R *O;
extern INT n0;
extern INT is0;
extern INT os0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride (every 2nd element)
    // Processes only every second element based on the original stride
    INT half_n = n0 >> 1;
    R* I_local = I;
    R* O_local = O;
    for (; half_n > 0; --half_n, I_local += 2*is0, O_local += 2*os0) {
        *O_local = *I_local;
    }
    // Update global state if needed: move I and O by total accessed offset
    I += (n0 >> 1) * 2 * is0;
    O += (n0 >> 1) * 2 * os0;
    n0 = n0 & 1; // Set n0 to 1 if odd, 0 if even (leftover element)
}
