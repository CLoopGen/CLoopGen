#include <stdio.h>

#include <inttypes.h>

extern int **ip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 16000; i = i + 8) {
    int val0 = i;
    int val1 = i + 1;
    int val2 = i + 2;
    int val3 = i + 3;
    int val4 = i + 4;
    int val5 = i + 5;
    int val6 = i + 6;
    int val7 = i + 7;

    (*ip)[i]     = val4;
    (*ip)[i + 1] = val2;
    (*ip)[i + 2] = val0;
    (*ip)[i + 3] = val3;
    (*ip)[i + 4] = val1;
    (*ip)[i + 5] = val7;
    (*ip)[i + 6] = val5;
    (*ip)[i + 7] = val6;
}
}
