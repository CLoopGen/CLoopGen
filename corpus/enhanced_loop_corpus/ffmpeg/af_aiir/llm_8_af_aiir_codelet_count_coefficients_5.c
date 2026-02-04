#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = item_str;
    int count = 0;
    for (; temp_p[0] && temp_p[1] && temp_p[2] && temp_p[3] && 
           (temp_p[0] != '|' || temp_p[1] != '|' || temp_p[2] != '|' || temp_p[3] != '|');
           temp_p += 4) {
        if (temp_p[0] == ' ') count++;
        if (temp_p[1] == ' ') count++;
        if (temp_p[2] == ' ') count++;
        if (temp_p[3] == ' ') count++;
    }
    // Handle remaining characters
    for (; *temp_p && *temp_p != '|'; temp_p++) {
        if (*temp_p == ' ')
            count++;
    }
    *nb_items += count;
}
