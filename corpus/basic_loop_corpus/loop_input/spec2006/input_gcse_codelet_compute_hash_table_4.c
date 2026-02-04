#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct reg_avail_info {
    int last_bb;
    int first_set;
    int last_set;
};

unsigned int max_gcse_regno;
struct reg_avail_info *reg_avail_info;
unsigned int i;

void init_vars() {
    max_gcse_regno = 16777216; // ~64 MB of data: 16,777,216 * 24 bytes per struct = ~400 MB
    reg_avail_info = calloc(max_gcse_regno, sizeof(struct reg_avail_info));
}