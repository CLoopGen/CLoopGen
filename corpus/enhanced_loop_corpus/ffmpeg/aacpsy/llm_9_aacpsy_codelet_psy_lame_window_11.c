#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int attacks[9];
extern int i;
extern float energy_short[9];
extern int att_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 8 + 1; i += 2) {
    const float u_prev = energy_short[i - 1];
    const float v_curr = energy_short[i];
    const float m_curr = (u_prev > v_curr) ? u_prev : v_curr;
    
    if (m_curr < 40000) {
        if (u_prev < 1.70000005F * v_curr && v_curr < 1.70000005F * u_prev) {
            if (i == 1 && attacks[0] < attacks[i])
                attacks[0] = 0;
            attacks[i] = 0;
        }
    }
    att_sum += attacks[i];

    if (i + 1 <= 8) {
        const float u_next = energy_short[i];
        const float v_next = energy_short[i + 1];
        const float m_next = (u_next > v_next) ? u_next : v_next;
        
        if (m_next < 40000) {
            if (u_next < 1.70000005F * v_next && v_next < 1.70000005F * u_next) {
                attacks[i + 1] = 0;
            }
        }
        att_sum += attacks[i + 1];
    }
}
}
