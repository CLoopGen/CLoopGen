#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *w;
extern  int n;
extern float vsum;
extern float wsum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (i = 0; i < n; i++) {
        temp = w[n + i];
        if (temp == 0) continue;
        vsum += w[i] * (temp / (1.F + (temp >= 0 ? temp : -temp)));
        wsum += w[i];
    }
}
