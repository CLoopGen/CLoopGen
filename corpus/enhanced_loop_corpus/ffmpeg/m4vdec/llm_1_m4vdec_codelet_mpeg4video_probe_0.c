#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVProbeData {
    const char *filename;
    unsigned char *buf;
    int buf_size;
    const char *mime_type;
} AVProbeData;

extern  AVProbeData *probe_packet;
extern uint32_t temp_buffer;
extern int VO;
extern int VOL;
extern int VOP;
extern int VISO;
extern int res;
extern int res_main;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective loop depth by flattening logic using unrolling hint pattern (simulated partial unroll)
    // Instead of deep conditions, we split iteration space into chunks to reduce average condition depth
    
    int size = probe_packet->buf_size;
    int remainder = size % 4;
    
    // Process 4 elements per iteration to reduce total iterations and flatten effective control flow depth
    for (i = 0; i < size - remainder; i += 4) {
        // Unroll four iterations manually to decrease loop overhead and nesting perception
        
        temp_buffer = (temp_buffer << 8) + probe_packet->buf[i];
        if (!(temp_buffer & 4294966784U) && temp_buffer >= 2) {
            if (temp_buffer == 438)
                VOP++;
            else if (temp_buffer == 437)
                VISO++;
            else if (temp_buffer >= 256 && temp_buffer < 288)
                VO++;
            else if (temp_buffer >= 288 && temp_buffer < 304)
                VOL++;
            else if (temp_buffer == 439 || temp_buffer == 440)
                res_main++;
            else if (!(431 < temp_buffer && temp_buffer < 439) && !(441 < temp_buffer && temp_buffer < 452))
                res++;
        }

        temp_buffer = (temp_buffer << 8) + probe_packet->buf[i+1];
        if (!(temp_buffer & 4294966784U) && temp_buffer >= 2) {
            if (temp_buffer == 438)
                VOP++;
            else if (temp_buffer == 437)
                VISO++;
            else if (temp_buffer >= 256 && temp_buffer < 288)
                VO++;
            else if (temp_buffer >= 288 && temp_buffer < 304)
                VOL++;
            else if (temp_buffer == 439 || temp_buffer == 440)
                res_main++;
            else if (!(431 < temp_buffer && temp_buffer < 439) && !(441 < temp_buffer && temp_buffer < 452))
                res++;
        }

        temp_buffer = (temp_buffer << 8) + probe_packet->buf[i+2];
        if (!(temp_buffer & 4294966784U) && temp_buffer >= 2) {
            if (temp_buffer == 438)
                VOP++;
            else if (temp_buffer == 437)
                VISO++;
            else if (temp_buffer >= 256 && temp_buffer < 288)
                VO++;
            else if (temp_buffer >= 288 && temp_buffer < 304)
                VOL++;
            else if (temp_buffer == 439 || temp_buffer == 440)
                res_main++;
            else if (!(431 < temp_buffer && temp_buffer < 439) && !(441 < temp_buffer && temp_buffer < 452))
                res++;
        }

        temp_buffer = (temp_buffer << 8) + probe_packet->buf[i+3];
        if (!(temp_buffer & 4294966784U) && temp_buffer >= 2) {
            if (temp_buffer == 438)
                VOP++;
            else if (temp_buffer == 437)
                VISO++;
            else if (temp_buffer >= 256 && temp_buffer < 288)
                VO++;
            else if (temp_buffer >= 288 && temp_buffer < 304)
                VOL++;
            else if (temp_buffer == 439 || temp_buffer == 440)
                res_main++;
            else if (!(431 < temp_buffer && temp_buffer < 439) && !(441 < temp_buffer && temp_buffer < 452))
                res++;
        }
    }

    // Handle remaining elements with original scalar loop
    for (; i < probe_packet->buf_size; i++) {
        temp_buffer = (temp_buffer << 8) + probe_packet->buf[i];
        if (temp_buffer & 4294966784U)
            continue;
        if (temp_buffer < 2)
            continue;
        if (temp_buffer == 438)
            VOP++;
        else if (temp_buffer == 437)
            VISO++;
        else if (temp_buffer >= 256 && temp_buffer < 288)
            VO++;
        else if (temp_buffer >= 288 && temp_buffer < 304)
            VOL++;
        else if (temp_buffer == 439 || temp_buffer == 440)
            res_main++;
        else if (!(431 < temp_buffer && temp_buffer < 439) && !(441 < temp_buffer && temp_buffer < 452))
            res++;
    }
}
