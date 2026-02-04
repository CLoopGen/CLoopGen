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
    if (max_gcse_regno > 0) {
        reg_avail_info[0].last_bb = -1;
        for (i = 1; i < max_gcse_regno; ++i)
            reg_avail_info[i].last_bb = -1;
    }
}
