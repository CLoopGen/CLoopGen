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
    char *temp_p = item_str;
    int count = *nb_items;
    for (; *temp_p; temp_p++) {
        if (*temp_p == delimiter)
            count++;
    }
    *nb_items = count;
}
