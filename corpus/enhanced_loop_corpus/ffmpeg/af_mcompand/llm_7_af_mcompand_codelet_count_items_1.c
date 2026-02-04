#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char delimiter;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_count = 0;
    char current_delim = delimiter;
    char *ptr = item_str;
    for (size_t i = 0; ptr[i] != '\0'; i++) {
        if (ptr[i] == current_delim)
            local_count++;
    }
    *nb_items += local_count;
}
