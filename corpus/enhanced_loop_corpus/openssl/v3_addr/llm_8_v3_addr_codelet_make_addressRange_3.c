#include <stdio.h>

#include <inttypes.h>

extern unsigned char *min;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = length; i > 0; --i) {
        if (min[i - 1] != 0) break;
        for (j = 0; j < 3; ++j) {
            min[i - 1] += j; 
        }
    }
}
