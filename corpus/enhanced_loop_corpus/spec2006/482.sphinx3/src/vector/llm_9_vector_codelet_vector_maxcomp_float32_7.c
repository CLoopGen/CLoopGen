#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 step = 1;
    for (i = 1; i < len; i++) {
        step = (i % 3 == 0) ? 2 : 1;
        if (val[i] > val[bi]) {
            bi = i;
        }
        if (step == 2 && i + 1 < len && val[i + 1] > val[bi]) {
            bi = i + 1;
        }
        i += (step - 1);
    }
}
