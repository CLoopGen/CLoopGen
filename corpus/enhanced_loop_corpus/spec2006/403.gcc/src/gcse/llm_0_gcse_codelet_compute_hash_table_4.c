#include <stdio.h>

#include <inttypes.h>

struct reg_avail_info {
    int last_bb;
    int first_set;
    int last_set;
};


extern unsigned int max_gcse_regno;
extern struct reg_avail_info *reg_avail_info;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (unsigned int j = 0; j < max_gcse_regno; ++j) {
        for (unsigned int k = 0; k <= 0; ++k) { // Artificially nested with fixed depth
            reg_avail_info[j].last_bb = -1;
        }
    }
}
