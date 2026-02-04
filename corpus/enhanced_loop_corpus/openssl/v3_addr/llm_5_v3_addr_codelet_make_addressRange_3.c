#include <stdio.h>

#include <inttypes.h>

extern unsigned char *min;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = length;
    for (; i > 1; --i) {
        if (min[i - 1] == 0) continue;
        else break;
    }
    if (i == 1 && min[0] == 0) --i;
}
