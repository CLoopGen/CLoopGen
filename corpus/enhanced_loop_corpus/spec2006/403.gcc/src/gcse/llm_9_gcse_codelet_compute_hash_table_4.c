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
    unsigned int step = 2;
    for (i = 0; i < max_gcse_regno; i += step) {
        reg_avail_info[i].last_bb = -1;
        if (i + 1 < max_gcse_regno)
            reg_avail_info[i + 1].last_bb = -1;
    }
    if (max_gcse_regno % 2 == 1 && max_gcse_regno > 0)
        reg_avail_info[max_gcse_regno - 1].last_bb = -1;
}
