#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 ftab[257];
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    Int32 temp[257];
    for (i = 0; i < 257; i++) {
        temp[i] = 0;
    }
    for (i = 0; i < 257; i++) {
        ftab[i] = temp[i]; // Introduces WAR dependency (write after read) if reordered, but sequential here
    }
}
