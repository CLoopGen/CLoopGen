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
    for (i = 0; i < 94; i += 2) {
        int idx = i / 2;
        uint16_t qe_val = cx_states[idx].qe;
        uint8_t nlps_base = 2 * cx_states[idx].nlps;
        uint8_t nmps_base = 2 * cx_states[idx].nmps;
        uint8_t sw = cx_states[idx].sw;

        ff_mqc_qe[i] = qe_val;
        ff_mqc_qe[i + 1] = qe_val;
        ff_mqc_nlps[i] = nlps_base + sw;
        ff_mqc_nlps[i + 1] = nlps_base + 1 - sw;
        ff_mqc_nmps[i] = nmps_base;
        ff_mqc_nmps[i + 1] = nmps_base + 1;
    }
}
