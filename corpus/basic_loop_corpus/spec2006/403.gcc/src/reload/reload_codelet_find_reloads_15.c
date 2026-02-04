#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int first_inpaddr_num[30];
extern int first_outpaddr_num[30];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < noperands; i++)
    first_inpaddr_num[i] = first_outpaddr_num[i] = -2;

}
