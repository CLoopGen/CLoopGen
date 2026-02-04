#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *name;
char name2[30];
char *inst_name;
char *filt_name;
int k;

void init_vars() {
    // Initialize name with a string containing '@' followed by non-null to trigger condition
    name = (char*)malloc(1024 * 1024); // ~1MB buffer to control timing
    if (!name) exit(1);
    memset(name, 'x', 1024 * 1024 - 1);
    name[1024 * 1024 - 1] = '\0';

    // Fill name2 with data such that the loop finds '@' at a valid position
    memset(name2, 'a', 28);           // Fill with 'a'
    name2[28] = '@';                  // Place '@' at index 28
    name2[29] = 'b';                  // Ensure name2[28+1] exists and is non-null

    // Set pointers to valid states
    inst_name = NULL;
    filt_name = NULL;
    k = 0;
}