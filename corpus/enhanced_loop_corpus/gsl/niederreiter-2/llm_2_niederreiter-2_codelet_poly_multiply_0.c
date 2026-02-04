#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int pa[];
extern  int pb[];
extern int j;
extern int k;
extern int pt[51];
extern int pt_degree;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k <= pt_degree; k++) {
    int term = 0;
    int offset = k;
    for (j = 0; j <= k; j++) {
        const int* pa_ptr = &pa[offset - j];
        const int* pb_ptr = &pb[j];
        const int conv_term = (((*pa_ptr) * (*pb_ptr)) % 2);
        term = ((term + conv_term) % 2);
    }
    pt[k] = term;
}
}
