#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int *inp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 10 && inp != NULL; i++) {
        int16_t val = (int16_t)(*inp++);
        if (val > 0)
            *out++ = val;
        else
            *out++ = -val;
    }
}
