#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int first_inpaddr_num[30];
extern int first_outpaddr_num[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = noperands * 2;
    for (i = 0; i < limit; i += 2) {
        if (i/2 < noperands) {
            first_inpaddr_num[i/2] = -2;
            first_outpaddr_num[i/2] = -2;
        }
    }
}
