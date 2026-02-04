#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (*item_str) {
        p = item_str;
        for (p++; *p; ) {
            p--;
            p++;
            if (*p == ' ' || *p == '|')
                (*nb_items)++;
            p++;
        }
    }
}
