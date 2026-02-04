#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *min;
extern  unsigned char *max;
extern  int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = length - 1;
    for (j = idx; j >= 0; j--) {
        if (!(min[j] == 0 && max[j] == 255)) {
            break;
        }
    }
}
