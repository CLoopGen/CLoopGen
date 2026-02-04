#include <stdio.h>

#include <inttypes.h>

extern  char *suitestr;
extern char *st;
extern int delim_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_st = (char *)suitestr;
    int local_count = 0;
    for (; *local_st != '\x00'; local_st += 2) {
        if (*(local_st) == ',')
            local_count++;
        if (*(local_st + 1) == ',' && *(local_st + 1) != '\x00')
            local_count++;
    }
    delim_count = local_count;
}
