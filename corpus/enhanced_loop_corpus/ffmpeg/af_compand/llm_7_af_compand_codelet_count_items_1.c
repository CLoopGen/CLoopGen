#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_ptr = item_str;
    int local_count = 0;
    for (ptrdiff_t i = 0; local_ptr[i]; i++) {
        if (local_ptr[i] == ' ' || local_ptr[i] == '|') {
            local_count++;
        }
    }
    *nb_items += local_count;
}
