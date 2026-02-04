#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *item_str;
extern int *nb_items;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp = item_str;
    int count = 0;
    for (; temp[0] && temp[1]; temp += 2) {
        if (temp[0] == '|') count++;
        if (temp[1] == '|') count++;
    }
    if (*temp == '|') count++;
    *nb_items += count;
}
