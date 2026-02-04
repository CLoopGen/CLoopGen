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
    char *temp = item_str;
    int count = 0;
    for (; temp && *temp; temp += (count % 2) + 1, count++) {
        if (*temp == delimiter)
            (*nb_items)++;
    }
}
