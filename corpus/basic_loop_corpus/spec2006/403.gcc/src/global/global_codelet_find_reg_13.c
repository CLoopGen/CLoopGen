#include <stdio.h>

#include <inttypes.h>

extern int max_regno;
extern short *reg_renumber;
extern int *reg_allocno;
extern int num;
extern int best_reg;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 53; j < max_regno; j++)
    if (reg_allocno[j] == num)
        reg_renumber[j] = best_reg;

}
