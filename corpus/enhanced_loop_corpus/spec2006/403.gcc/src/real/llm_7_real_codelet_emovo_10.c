#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies by unrolling and removing address reuse
    // Also breaks RAW/WAR by ensuring independent accesses when possible
    if (6 - 1 > 0) *q     = *p;
    if (6 - 1 > 1) *(q-1) = *(p+1);
    if (6 - 1 > 2) *(q-2) = *(p+2);
    if (6 - 1 > 3) *(q-3) = *(p+3);
    if (6 - 1 > 4) *(q-4) = *(p+4);
    // No loop-carried dependency due to full unrolling and direct addressing
}
