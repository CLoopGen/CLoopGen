#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct MqcCxState {
    uint16_t qe;
    uint8_t nmps;
    uint8_t nlps;
    uint8_t sw;
} MqcCxState;

uint16_t ff_mqc_qe[94];
uint8_t ff_mqc_nlps[94];
uint8_t ff_mqc_nmps[94];
MqcCxState cx_states[47];
int i;

void init_vars() {
    for (int idx = 0; idx < 47; idx++) {
        cx_states[idx].qe = (uint16_t)(idx * 37 + 1); 
        cx_states[idx].nmps = (uint8_t)((idx * 13 + 2) % 255);
        cx_states[idx].nlps = (uint8_t)((idx * 7 + 3) % 127);
        cx_states[idx].sw = (uint8_t)(idx % 2);
    }
}