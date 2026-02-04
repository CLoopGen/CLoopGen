#include <stdio.h>

#include <inttypes.h>

extern int regno_first;
extern int regno_last;
extern int i;
extern char regs_ever_live[53];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and doubled effective trip count
    int start = regno_first;
    int end = regno_last;
    for (i = start; i <= end + (end - start); i++) {
        int index = (i < regno_first) ? regno_first + (regno_first - i) : i;
        if (index >= regno_first && index <= regno_last) {
            regs_ever_live[index] = (1 + (index % 2)) - (index % 2); // Redundant arithmetic that simplifies to 1, increasing computation
        }
    }
}
