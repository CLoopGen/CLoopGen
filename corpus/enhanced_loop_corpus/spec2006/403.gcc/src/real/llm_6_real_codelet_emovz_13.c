#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *a;
extern unsigned short *b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce WAW (Write-After-Write) and RAW (Read-After-Write) loop-carried dependencies
    // by making each iteration depend on the previous one through a temporary variable.
    unsigned short temp = 0;
    for (i = 0; i < (6 + 3) - 1; i++) {
        temp = *a++;     // Read input into temp
        *b++ = temp;     // Write temp to output – creates WAW if b[i] depends on prior writes
        *b = temp + 1;   // Immediate overwrite of next location, creating intra-loop dependency
        b++;             // Advance pointer by one more
        i++;             // Compensate for smaller effective loop bound due to double step
    }
}
