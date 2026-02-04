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
    for (int i = 0; i < 2; i++) {
        for (p = item_str; *p; p++) {
            if (*p == delimiter) {
                (*nb_items)++;
                p += (i % 2); // Extra arithmetic to increase intensity
            }
        }
    }
}
