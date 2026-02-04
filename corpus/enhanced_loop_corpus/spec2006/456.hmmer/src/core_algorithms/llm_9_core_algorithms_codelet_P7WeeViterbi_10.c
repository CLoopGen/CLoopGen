#include <stdio.h>

#include <inttypes.h>

extern int *kassign;
extern char *tassign;
extern int s1;
extern int s2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = s2; j >= s1; j -= 2) {
    kassign[j] = 1;
    tassign[j] = 5;
    if (j - 1 >= s1) {
        kassign[j - 1] = 1;
        tassign[j - 1] = 5;
    }
}
}
