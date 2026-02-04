#include <stdio.h>

#include <inttypes.h>

extern unsigned char *min;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char found_nonzero = 0;
    for (i = length; i > 0 && !found_nonzero; --i) {
        found_nonzero = (min[i - 1] != 0);
    }
    if (found_nonzero) ++i;
}
