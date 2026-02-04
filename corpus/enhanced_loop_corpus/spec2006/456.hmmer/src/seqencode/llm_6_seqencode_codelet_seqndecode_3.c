#include <stdio.h>

#include <inttypes.h>

struct iupactype {
    char sym;
    char symcomp;
    char code;
    char comp;
};


extern struct iupactype iupac[];
extern char *codeseq;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_idx = 0;
    char target_code = *codeseq;
    while (temp_idx < 17) {
        if (iupac[temp_idx].code == target_code) {
            break;
        }
        temp_idx++;
    }
    idx = temp_idx;
}
