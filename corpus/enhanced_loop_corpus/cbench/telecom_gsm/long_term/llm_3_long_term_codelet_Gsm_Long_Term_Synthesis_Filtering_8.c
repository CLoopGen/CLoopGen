#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *erp;
extern word *drp;
extern longword ltmp;
extern int k;
extern word brp;
extern word drpp;
extern word Nr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access
    // Access elements in drp and erp with a stride of 2, processing every second element
    // We adjust loop bound to avoid out-of-bounds when using stride
    // This changes access pattern from sequential to strided (stride=2)
    for (k = 0; k <= 19; k++) {
        int idx = k * 2;  // Stride of 2
        drpp = (((((longword)(brp) * (longword)(drp[idx - Nr]) + 16384)) >> (15)));
        drp[idx] = ((ulongword)((ltmp = (longword)(erp[idx]) + (longword)(drpp)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
        // Optionally process odd indices as well if needed, but kept simple for clear strided pattern
    }
}
