#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = item_str; *p; p++) {
        (*nb_items) += ((*p == ' ') + (*p == '|'));
    }
}
