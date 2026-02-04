#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *PredPel;
int i;
int LoopArray[25];

static int PredPel_storage[27];

void init_vars() {
    for (int j = 0; j < 27; j++) {
        PredPel_storage[j] = rand() % 256;
    }
    PredPel = PredPel_storage;

    for (int j = 0; j < 25; j++) {
        LoopArray[j] = 0;
    }

    i = 0;
}