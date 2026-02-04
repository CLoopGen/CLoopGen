#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern float *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *b_ptr = B;
    float alpha_local = alpha;
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            *b_ptr = *b_ptr * alpha_local;
            b_ptr++;
        }
        b_ptr += ldb - n2;
    }
}
