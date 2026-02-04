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
    for (i = 0; i < 47; i++) {
        for (int j = 0; j < 2; j++) {
            ff_mqc_qe[2 * i + j] = cx_states[i].qe;
            ff_mqc_nlps[2 * i + j] = 2 * cx_states[i].nlps + (j == 0 ? cx_states[i].sw : 1 - cx_states[i].sw);
            ff_mqc_nmps[2 * i + j] = 2 * cx_states[i].nmps + j;
        }
    }
}
