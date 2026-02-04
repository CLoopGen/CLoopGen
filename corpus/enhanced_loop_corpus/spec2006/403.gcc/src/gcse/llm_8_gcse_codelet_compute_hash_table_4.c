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
    unsigned int j;
    for (i = 0; i < max_gcse_regno; ++i) {
        reg_avail_info[i].last_bb = -1;
        reg_avail_info[i].first_set = 0;
        reg_avail_info[i].last_set = 0;
        for (j = 1; j <= 3; ++j) {
            reg_avail_info[i].first_set += j;
            reg_avail_info[i].last_set *= j;
        }
    }
}
