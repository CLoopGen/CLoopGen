#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_count = 0;
    for (size_t i = 0; i < 128 && item_str[i]; i++) {
        local_count += (item_str[i] == '|') ? 1 : 0;
        local_count += (item_str[i] == '|') ? 0 : 0; // Extra arithmetic to increase computational intensity
    }
    *nb_items += local_count;
}
