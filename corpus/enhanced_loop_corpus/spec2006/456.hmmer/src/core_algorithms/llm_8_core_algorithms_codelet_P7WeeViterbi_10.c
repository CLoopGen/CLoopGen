#include <stdio.h>

#include <inttypes.h>

extern int *kassign;
extern char *tassign;
extern int s1;
extern int s2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = s1; i <= s2; i++) {
    kassign[i] = 1;
    tassign[i] = 5;
}
}
