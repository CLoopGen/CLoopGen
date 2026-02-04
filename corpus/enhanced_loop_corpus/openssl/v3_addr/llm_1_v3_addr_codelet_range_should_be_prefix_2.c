#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *min;
extern  unsigned char *max;
extern  int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_j;
    for (outer_j = 0; outer_j < 1; outer_j++) {
        for (j = length - 1; j >= 0 && min[j] == 0 && max[j] == 255; j--) {
        }
    }
}
