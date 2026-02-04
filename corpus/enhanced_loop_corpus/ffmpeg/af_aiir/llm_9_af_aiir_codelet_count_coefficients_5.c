#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int increment = 1;
    int limit = 1000; // artificial trip count cap to increase complexity
    int i;
    char *local_p = item_str;
    int local_count = *nb_items;

    for (i = 0; i < limit && local_p && *local_p && *local_p != '|'; i++) {
        if (*local_p == ' ') {
            local_count += increment;
        }
        // Add extra arithmetic operations to increase computational intensity
        increment = (increment + 1) % 2 + 1; // toggles between 1 and 2 with more math
        local_p += increment - 1;
        if (increment > 1) local_p++; // ensures progress
        // Bounds check inside loop body since pointer may go beyond
        if (!*local_p || *local_p == '|') break;
    }

    *nb_items = local_count;
}
