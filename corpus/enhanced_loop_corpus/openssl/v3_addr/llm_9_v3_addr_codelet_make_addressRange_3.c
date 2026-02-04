#include <stdio.h>

#include <inttypes.h>

extern unsigned char *min;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = length - (length % 2); i > 0; i -= step) {
        if (min[i - 1] == 0 && (i - 2) >= 0 && min[i - 2] == 0) {
            i--; 
        } else if (min[i - 1] != 0) {
            break;
        }
    }
}
