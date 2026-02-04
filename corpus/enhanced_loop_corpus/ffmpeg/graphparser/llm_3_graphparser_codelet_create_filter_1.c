#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *name;
extern char name2[30];
extern  char *inst_name;
extern  char *filt_name;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with temporary pointer variables
    char *ptr_name2 = name2;
    char *ptr_name = name;
    int index = 0;
    for (k = 0; ptr_name2[index]; index++, k++) {
        if (ptr_name2[index] == '@' && ptr_name[index + 1]) {
            ptr_name2[index] = 0;
            inst_name = ptr_name;
            filt_name = ptr_name2;
            break;
        }
    }
}
