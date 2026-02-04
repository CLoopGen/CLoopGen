#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lsf;
extern double min_spacing;
extern int size;
extern int i;
extern float prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            float val1 = (lsf[i] > prev + min_spacing) ? lsf[i] : (prev + min_spacing);
            prev = lsf[i] = val1;
            float val2 = (lsf[i+1] > prev + min_spacing) ? lsf[i+1] : (prev + min_spacing);
            prev = lsf[i+1] = val2;
        } else {
            float val = (lsf[i] > prev + min_spacing) ? lsf[i] : (prev + min_spacing);
            prev = lsf[i] = val;
        }
    }
}
