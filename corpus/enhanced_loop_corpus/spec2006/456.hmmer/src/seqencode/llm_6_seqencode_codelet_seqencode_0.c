#include <stdio.h>

#include <inttypes.h>

struct iupactype {
    char sym;
    char symcomp;
    char code;
    char comp;
};


extern struct iupactype iupac[];
extern char *str;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_idx = 0;
    char target_sym = *str;
    for (idx = 0; target_sym != iupac[temp_idx].sym && temp_idx <= 17; temp_idx++) {
        idx = temp_idx + 1;
    }
    if (temp_idx <= 17) idx = temp_idx;
}
