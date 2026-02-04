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
    for (i = max_gcse_regno; i > 0; --i) {
        reg_avail_info[i-1].last_bb = -1;
        reg_avail_info[i-1].first_set = reg_avail_info[i-1].last_set;
    }
}
