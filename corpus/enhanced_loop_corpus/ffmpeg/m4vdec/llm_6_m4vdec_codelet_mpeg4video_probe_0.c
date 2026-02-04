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
    uint32_t local_temp = temp_buffer;
    int local_VOP = VOP;
    int local_VISO = VISO;
    int local_VO = VO;
    int local_VOL = VOL;
    int local_res_main = res_main;
    int local_res = res;

    for (i = 0; i < probe_packet->buf_size; i++) {
        local_temp = (local_temp << 8) + probe_packet->buf[i];
        if (local_temp & 4294966784U)
            continue;
        if (local_temp < 2)
            continue;
        if (local_temp == 438)
            local_VOP++;
        else if (local_temp == 437)
            local_VISO++;
        else if (local_temp >= 256 && local_temp < 288)
            local_VO++;
        else if (local_temp >= 288 && local_temp < 304)
            local_VOL++;
        else if (local_temp == 439 || local_temp == 440)
            local_res_main++;
        else if (!(431 < local_temp && local_temp < 439) && !(441 < local_temp && local_temp < 452))
            local_res++;
    }

    VOP = local_VOP;
    VISO = local_VISO;
    VO = local_VO;
    VOL = local_VOL;
    res_main = local_res_main;
    res = local_res;
    temp_buffer = local_temp;
}
