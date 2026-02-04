#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t gt16x16_cnst[64] __attribute__((aligned(64)));
extern int16_t *coeffs;
extern int16_t i;
extern int16_t j;
extern int16_t k;
extern int16_t *buf_ptr;
extern int16_t *src;
extern  int16_t *filter;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 2; i--;) {
    {
        {
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
        }
        ;
        {
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
        }
        ;
    }
    ;
    {
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
    }
    ;
    {
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
            {
            }
            ;
            {
            }
            ;
        }
        ;
    }
    ;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    {
        {
        }
        ;
        {
        }
        ;
    }
    ;
    {
        int16_t *ptr0, *ptr1;
        ptr0 = (buf_ptr + 112);
        ptr1 = (buf_ptr + 128);
        k = -1;
        for (j = 0; j < 4; j++) {
            {
            }
            filter += 16;
            {
            }
            ;
            {
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
            }
            ;
            {
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
            }
            ;
            k *= -1;
            buf_ptr += 16;
        }
    }
    ;
    src += 128;
    buf_ptr = coeffs + 8;
    filter = &gt16x16_cnst[0];
}

}
