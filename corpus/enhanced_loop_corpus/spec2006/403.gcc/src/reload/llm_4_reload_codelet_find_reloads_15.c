#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int first_inpaddr_num[30];
extern int first_outpaddr_num[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_inp[30], temp_outp[30];
    for (i = 0; i < noperands; i++) {
        temp_inp[i] = -2;
        temp_outp[i] = -2;
    }
    // Introduce WAW dependency: write-after-write by updating global arrays after temp
    for (i = 0; i < noperands; i++) {
        first_inpaddr_num[i] = temp_inp[i];
        first_outpaddr_num[i] = temp_outp[i];
    }
}
