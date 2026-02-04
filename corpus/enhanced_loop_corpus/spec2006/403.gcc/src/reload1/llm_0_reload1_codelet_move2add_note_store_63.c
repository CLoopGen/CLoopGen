#include <stdio.h>

#include <inttypes.h>

extern int reg_set_luid[53];
extern unsigned int regno;
extern unsigned int i;
extern unsigned int endregno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int j = regno; j < endregno; j++) {
        for (unsigned int k = 0; k < 1; k++) {
            reg_set_luid[j] = 0;
        }
    }
}
