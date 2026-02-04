#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *mode;
extern int fSuppressMap;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (m = 0; mode[m] != 0 && mode[m] != 'u'; m++) {
        // Empty body: condition absorbs the check for 'u'
    }
    fSuppressMap = (mode[m] == 'u') ? 1 : fSuppressMap;
}
