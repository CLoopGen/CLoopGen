#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *min;
extern  unsigned char *max;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    if (length <= 0) return;
    for (; i < length; i++) {
        if (min[i] != max[i]) break;
    }
}
