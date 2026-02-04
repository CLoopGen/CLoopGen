#include <stdio.h>

#include <inttypes.h>

extern int total_hist_br_prob[20];
extern int i;
extern int hist_br_prob[20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 1; j++)
        for (i = 0; i < 20; i++)
            total_hist_br_prob[i] += hist_br_prob[i];
}
