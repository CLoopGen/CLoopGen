#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *pIn;
int i;

static float dataArray[128];

void init_vars() {
    pIn = dataArray;
    for (int j = 0; j < 128; j++) {
        pIn[j] = (float)(j * 2.5);
    }
}

void loop();