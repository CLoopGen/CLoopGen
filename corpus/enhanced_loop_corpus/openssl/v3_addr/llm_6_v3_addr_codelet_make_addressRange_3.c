#include <stdio.h>

#include <inttypes.h>

extern unsigned char *min;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_i = length;
    for (i = temp_i; i > 0; --i) {
        if (min[i - 1] != 0) {
            temp_i = i;
            break;
        }
    }
    i = temp_i;
}
