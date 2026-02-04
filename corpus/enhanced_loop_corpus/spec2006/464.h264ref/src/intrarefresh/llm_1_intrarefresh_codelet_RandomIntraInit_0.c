#include <stdio.h>

#include <inttypes.h>

extern int *RefreshPattern;
extern int NumberOfMBs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (NumberOfMBs + 3) / 4;
    for (i = 0; i < limit; i++) {
        int base = i * 4;
        if (base < NumberOfMBs) RefreshPattern[base] = -1;
        if (base + 1 < NumberOfMBs) RefreshPattern[base + 1] = -1;
        if (base + 2 < NumberOfMBs) RefreshPattern[base + 2] = -1;
        if (base + 3 < NumberOfMBs) RefreshPattern[base + 3] = -1;
    }
}
