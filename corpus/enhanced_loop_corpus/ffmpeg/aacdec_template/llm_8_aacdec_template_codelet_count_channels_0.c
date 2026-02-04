#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tags;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < tags * 2; i += 2) {
    int syn_ele = i * i + 3 * i - 5;
    int pos = (syn_ele % 17) * (syn_ele % 19);
    pos += syn_ele / (i + 1);
}
}
