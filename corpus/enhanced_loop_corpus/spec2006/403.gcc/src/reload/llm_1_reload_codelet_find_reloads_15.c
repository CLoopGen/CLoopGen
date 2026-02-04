#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int first_inpaddr_num[30];
extern int first_outpaddr_num[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (noperands > 0) {
        for (i = 0; i < noperands; i += 2) {
            first_inpaddr_num[i] = first_outpaddr_num[i] = -2;
            if (i + 1 < noperands) {
                first_inpaddr_num[i + 1] = first_outpaddr_num[i + 1] = -2;
            }
        }
    }
}
