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
    int temp_reg;
    for (j = 53; j < max_regno; j++) {
        if (reg_allocno[j] == num) {
            temp_reg = best_reg + reg_renumber[j]; // Introduce temporary that depends on current value (RAW)
            reg_renumber[j] = temp_reg;           // Write new value based on prior read
        }
    }
}
