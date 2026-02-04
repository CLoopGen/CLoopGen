#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height; loop_cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (cnt = 2; cnt--;) {
        uint32_t offset = (cnt * 16) + 8;
        {
            dst_tmp[0] = src_tmp[offset];
            dst_tmp[1] = src_tmp[offset + 1];
            dst_tmp[2] = src_tmp[offset + 2];
            dst_tmp[3] = src_tmp[offset + 3];
        }
        ;
        src_tmp += 32;
        {
            {
                dst_tmp[4] = src_tmp[0];
                dst_tmp[5] = src_tmp[1];
            }
            ;
        }
        ;
        {
            {
                dst_tmp[6] = src_tmp[2];
            }
            ;
            {
                dst_tmp[7] = src_tmp[3];
            }
            ;
        }
        ;
        {
            {
                dst_tmp[8] = src_tmp[4];
            }
            ;
            {
                dst_tmp[9] = src_tmp[5];
            }
            ;
        }
        ;
        {
            {
                dst_tmp[10] = src_tmp[6];
            }
            ;
            {
                dst_tmp[11] = src_tmp[7];
            }
            ;
        }
        ;
        {
            {
                dst_tmp[12] = src_tmp[8];
            }
            ;
            {
                dst_tmp[13] = src_tmp[9];
            }
            ;
        }
        ;
        {
            {
                {
                    dst_tmp[14] = src_tmp[10];
                }
                ;
                {
                    dst_tmp[15] = src_tmp[11];
                }
                ;
                {
                    {
                        dst_tmp[16] = src_tmp[12];
                    }
                    ;
                    {
                        dst_tmp[17] = src_tmp[13];
                    }
                    ;
                }
                ;
                {
                    {
                        dst_tmp[18] = src_tmp[14];
                    }
                    {
                        dst_tmp[19] = src_tmp[15];
                    }
                }
                ;
                {
                    dst_tmp[20] = src_tmp[16];
                }
                ;
                {
                    dst_tmp[21] = src_tmp[17];
                }
                ;
                {
                    {
                        dst_tmp[22] = src_tmp[18];
                    }
                    ;
                    {
                        dst_tmp[23] = src_tmp[19];
                    }
                    ;
                }
                ;
            }
            ;
            {
                {
                    dst_tmp[24] = src_tmp[20];
                }
                ;
                {
                    dst_tmp[25] = src_tmp[21];
                }
                ;
                {
                    {
                        dst_tmp[26] = src_tmp[22];
                    }
                    ;
                    {
                        dst_tmp[27] = src_tmp[23];
                    }
                    ;
                }
                ;
                {
                    {
                        dst_tmp[28] = src_tmp[24];
                    }
                    {
                        dst_tmp[29] = src_tmp[25];
                    }
                }
                ;
                {
                    dst_tmp[30] = src_tmp[26];
                }
                ;
                {
                    dst_tmp[31] = src_tmp[27];
                }
                ;
                {
                    {
                        dst_tmp[32] = src_tmp[28];
                    }
                    ;
                    {
                        dst_tmp[33] = src_tmp[29];
                    }
                    ;
                }
                ;
            }
            ;
        }
        ;
        {
            dst_tmp[34] = src_tmp[30];
        }
        ;
        {
            dst_tmp[35] = src_tmp[31];
        }
        ;
        dst_tmp += 32;
    }
    src += src_stride;
    dst += dst_stride;
}
}
