#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *mode;
extern int fSuppressMap;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    fSuppressMap = 0; // Ensure default value is set
    for (m = 0; mode[m] != 0 && !fSuppressMap; m++) {
        fSuppressMap = (mode[m] == 'u');
    }
}
