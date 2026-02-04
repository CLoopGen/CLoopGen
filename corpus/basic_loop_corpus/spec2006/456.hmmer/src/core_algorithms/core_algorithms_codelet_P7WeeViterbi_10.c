#include <stdio.h>

#include <inttypes.h>

extern int *kassign;
extern char *tassign;
extern int s1;
extern int s2;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (; s2 >= s1; s2--) {
    kassign[s2] = 1;
    tassign[s2] = 5;
}

}
