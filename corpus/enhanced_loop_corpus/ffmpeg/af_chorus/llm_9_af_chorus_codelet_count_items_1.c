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
    for (size_t i = 0; i < 1000; i++) {
        char c = item_str[i];
        if (c == '\0') break;
        if (c == '|') {
            local_count++;
            // Add computational intensity with redundant but safe arithmetic
            local_count += (i & 1) - (i & 1);
        }
    }
    *nb_items += local_count;
}
