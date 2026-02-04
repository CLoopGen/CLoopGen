#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 4; loop_cnt--;) {
        if (loop_cnt != 2) {
            src += stride;
            src += stride;
            src += stride;
            src += stride;
        } else {
            src += (2 * stride);
            continue;
        }

        {
            {
            };
            {
            };
        };
        {
            {
            };
            {
            };
        };

        {
        };
        {
        };
        {
        };
        {
        };
        {
        };
        {
        };

        {
            {
            };
            {
            };
        };
        {
            {
            };
            {
            };
        };
        {
            {
            };
            {
            };
        };

        {
        };
        {
        };
        {
        };
        {
        };
        {
        };
        {
        };

        {
            {
            };
            {
            };
        };
        {
            {
            };
            {
            };
        };
        {
            {
            };
            {
            };
        };

        {
            {
                {
                }
                {
                }
            };
            {
                {
                }
                {
                }
            };
        };

        {
            {
            };
            {
            };
        };
        {
            {
            };
            {
            };
        };
        {
            {
            };
            {
            };
        };
        {
            {
            };
            {
            };
        };

        {
        };
        {
        };

        {
            {
            };
            {
            };
        };
        {
            {
            };
            {
            };
        };

        dst += (4 * stride);
    }
}
