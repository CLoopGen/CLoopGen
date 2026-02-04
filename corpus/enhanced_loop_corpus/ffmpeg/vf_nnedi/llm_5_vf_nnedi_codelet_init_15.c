#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *bdata;
extern int j;
extern int k;
extern double mean[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j++) {
    double cmean = 0.0;
    int valid_data_count = 0;
    for (k = 0; k < 48; k++) {
        int idx = j * 48 + k;
        if (bdata[idx] >= 0.0f) {
            cmean += bdata[idx];
            valid_data_count++;
        }
    }
    mean[j] = valid_data_count > 0 ? cmean / valid_data_count : 0.0;
}
}
