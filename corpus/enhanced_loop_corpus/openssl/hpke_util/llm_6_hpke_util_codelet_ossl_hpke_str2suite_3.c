#include <stdio.h>

#include <inttypes.h>

extern  char *suitestr;
extern char *st;
extern int delim_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_st;
    int local_count = 0;
    for (local_st = (char *)suitestr; *local_st != '\x00'; local_st++) {
        local_count += (*local_st == ',');
    }
    delim_count = local_count;
}
