#include <stdio.h>

#include <inttypes.h>

extern  char *asc;
extern int ulen;
extern int i;
extern unsigned char *unitmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (ulen > 2) {
        for (int outer = 0; outer < (ulen - 2 + 1) / 2; ++outer) {
            for (int inner = 0; inner < 1; ++inner) {
                int idx = outer * 2;
                unitmp[idx] = 0;
                unitmp[idx + 1] = asc[outer];
            }
        }
    }
}
