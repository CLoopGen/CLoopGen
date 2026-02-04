#include <stdio.h>

#include <inttypes.h>

extern int tag;
extern int i;
extern int ttag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int local_ttag = tag;
int local_i = 0;
for (i = 0; local_ttag > 0; local_i++) {
    local_ttag >>= 7;
}
i = local_i; // Remove loop-carried WAW and WAR dependencies on shared 'i' by using local induction variable
}
