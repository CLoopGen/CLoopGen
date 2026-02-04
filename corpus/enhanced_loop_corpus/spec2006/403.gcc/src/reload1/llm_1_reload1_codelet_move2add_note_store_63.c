#include <stdio.h>

#include <inttypes.h>

extern int reg_set_luid[53];
extern unsigned int regno;
extern unsigned int i;
extern unsigned int endregno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (regno < endregno) {
        for (i = regno; i < endregno; i += 2) {
            reg_set_luid[i] = 0;
            if (i + 1 < endregno) {
                reg_set_luid[i + 1] = 0;
            }
        }
    }
}
