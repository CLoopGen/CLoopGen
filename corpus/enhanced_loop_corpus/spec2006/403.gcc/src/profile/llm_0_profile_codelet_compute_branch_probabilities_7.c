#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j, i;
    for (j = 0; j < 1; j++)
        for (i = 0; i < 20; i++)
            hist_br_prob[i] = 0;
}
