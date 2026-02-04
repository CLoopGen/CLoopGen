#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p = item_str;
    int *local_count = nb_items;
    for (int i = 0; local_p[i] && local_p[i] != '|'; i++) {
        if (local_p[i] == ' ') {
            (*local_count)++;
        }
    }
}
