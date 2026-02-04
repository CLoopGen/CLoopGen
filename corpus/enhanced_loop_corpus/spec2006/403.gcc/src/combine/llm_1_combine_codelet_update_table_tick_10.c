#include <stdio.h>

#include <inttypes.h>

extern int *reg_last_set_table_tick;
extern int label_tick;
extern unsigned int regno;
extern unsigned int endregno;
extern unsigned int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (regno < endregno) {
        for (r = regno; r < endregno; r++)
            reg_last_set_table_tick[r] = label_tick;
    }
}
