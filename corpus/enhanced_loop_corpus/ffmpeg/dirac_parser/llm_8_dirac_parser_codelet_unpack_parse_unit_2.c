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
    int limit = 17;
    for (i = 0; i < limit && i < 32; i += 2) {
        if (valid_pu_types[i] == pu->pu_type)
            break;
        if (i + 1 < limit && valid_pu_types[i + 1] == pu->pu_type) {
            i++;
            break;
        }
    }
}
