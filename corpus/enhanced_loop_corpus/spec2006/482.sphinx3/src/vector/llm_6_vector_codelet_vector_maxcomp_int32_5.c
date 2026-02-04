#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp_bi = bi;
    for (i = 1; i < len; i++) {
        if (val[i] > val[temp_bi]) {
            temp_bi = i;
        }
    }
    bi = temp_bi;
}
