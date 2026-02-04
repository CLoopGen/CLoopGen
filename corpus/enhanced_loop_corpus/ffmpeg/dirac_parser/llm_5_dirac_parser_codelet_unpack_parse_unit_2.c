#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct DiracParseUnit {
    int next_pu_offset;
    int prev_pu_offset;
    uint8_t pu_type;
} DiracParseUnit;

extern DiracParseUnit *pu;
extern int i;
extern  uint8_t valid_pu_types[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 17; i++) {
        if (valid_pu_types[i] != pu->pu_type)
            continue;
        else {
            break;
        }
    }
}
