#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DiracParseUnit {
    int next_pu_offset;
    int prev_pu_offset;
    uint8_t pu_type;
} DiracParseUnit;

DiracParseUnit *pu;
int i;
uint8_t valid_pu_types[17];

void init_vars() {
    pu = (DiracParseUnit*)malloc(sizeof(DiracParseUnit));
    if (!pu) exit(1);
    pu->pu_type = 10;

    for (int j = 0; j < 17; j++) {
        valid_pu_types[j] = j + 5;
    }
    valid_pu_types[10] = 10;
}