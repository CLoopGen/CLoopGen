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
    uint16_t temp_qe;
    uint8_t temp_nlps_sw, temp_nlps_nsw, temp_nmps;
    for (i = 0; i < 47; i++) {
        temp_qe = cx_states[i].qe;
        temp_nlps_sw = 2 * cx_states[i].nlps + cx_states[i].sw;
        temp_nlps_nsw = 2 * cx_states[i].nlps + 1 - cx_states[i].sw;
        temp_nmps = 2 * cx_states[i].nmps;

        ff_mqc_qe[2 * i] = temp_qe;
        ff_mqc_qe[2 * i + 1] = temp_qe;
        ff_mqc_nlps[2 * i] = temp_nlps_sw;
        ff_mqc_nlps[2 * i + 1] = temp_nlps_nsw;
        ff_mqc_nmps[2 * i] = temp_nmps;
        ff_mqc_nmps[2 * i + 1] = temp_nmps + 1;
    }
}
