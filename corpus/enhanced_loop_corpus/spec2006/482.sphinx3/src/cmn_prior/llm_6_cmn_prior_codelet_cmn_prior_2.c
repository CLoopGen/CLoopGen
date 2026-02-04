#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef float float32;

extern int32 ceplen;
extern float32 *sum;
extern float32 sf;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 j;
    float32 temp = 1.0f;
    for (j = 0; j < ceplen; j++) {
        temp = sum[j] * sf + temp;  // Introduce RAW dependency: each iteration depends on previous 'temp'
        sum[j] = temp;               // WAW: 'temp' written before used in next iteration
    }
}
