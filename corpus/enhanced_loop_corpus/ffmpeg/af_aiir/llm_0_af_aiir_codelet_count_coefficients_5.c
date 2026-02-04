#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (char *temp_p = item_str; temp_p && *temp_p && *temp_p != '|'; temp_p++) {
        for (int i = 0; i < 1; i++) { // Artificially increased nesting depth
            if (*temp_p == ' ')
                (*nb_items)++;
        }
    }
}
