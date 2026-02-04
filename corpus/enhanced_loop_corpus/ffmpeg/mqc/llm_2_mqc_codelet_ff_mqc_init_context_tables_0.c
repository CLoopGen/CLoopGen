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

extern uint16_t ff_mqc_qe[94];
extern uint8_t ff_mqc_nlps[94];
extern uint8_t ff_mqc_nmps[94];
extern  MqcCxState cx_states[47];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Reorder operations to write consecutive elements in each array per iteration
    for (i = 0; i < 47; i++) {
        int idx = 2 * i;
        uint16_t qe_val = cx_states[i].qe;
        uint8_t nlps_base = 2 * cx_states[i].nlps;
        uint8_t nmps_base = 2 * cx_states[i].nmps;
        uint8_t sw = cx_states[i].sw;

        ff_mqc_qe[idx]     = qe_val;
        ff_mqc_qe[idx + 1] = qe_val;

        ff_mqc_nlps[idx]     = nlps_base + sw;
        ff_mqc_nlps[idx + 1] = nlps_base + 1 - sw;

        ff_mqc_nmps[idx]     = nmps_base;
        ff_mqc_nmps[idx + 1] = nmps_base + 1;
    }
}
