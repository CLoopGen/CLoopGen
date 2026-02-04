#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *min;
extern  unsigned char *max;
extern  int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_min, temp_max;
    for (j = length - 1; j >= 0; j--) {
        temp_min = min[j];
        temp_max = max[j];
        if (!(temp_min == 0 && temp_max == 255)) break;
    }
}
