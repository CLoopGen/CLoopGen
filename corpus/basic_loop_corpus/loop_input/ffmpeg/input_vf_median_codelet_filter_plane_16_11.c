#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
uint16_t *ccoarse;
uint16_t *cfine;
int radiusV;
uint16_t *srcp;

void init_vars() {
    // Set parameters to control data size and ensure no out-of-bounds access
    width = 1 << 18;  // ~256K elements, adjust for ~0.01s runtime
    radiusV = 3;      // Small positive value

    // Allocate srcp: contains 16-bit values we will shift by (16+1)/2 = 8 bits
    srcp = (uint16_t*)calloc(width, sizeof(uint16_t));
    
    // Each element in srcp should have valid high and low 8-bit parts
    for (int i = 0; i < width; i++) {
        srcp[i] = (rand() & 0xFFFF);  // full 16-bit random value
    }

    // Compute required sizes for ccoarse and cfine based on access patterns

    // For ccoarse: index = (1<<8)*i + ((srcp[i])>>8)
    // i in [0, width), so max i = width - 1
    // ((srcp[i])>>8) in [0, 255]
    // So max index = (1<<8)*(width-1) + 255 = 256*(width-1)+255
    size_t ccoarse_size = (1 << 8) * width + 256;  // slightly overallocate
    ccoarse = (uint16_t*)calloc(ccoarse_size, sizeof(uint16_t));

    // For cfine: index = (1<<8) * (width * ((srcp[i])>>8) + i) + ((srcp[i]) & 255)
    // Let high = (srcp[i] >> 8) -> [0,255]
    // Then inner term: width * high + i -> max when high=255, i=width-1
    //   => width*255 + (width-1) = 256*width - 1
    // Multiply by 256: 256*(256*width - 1) = 65536*width - 256
    // Add offset up to 255 -> max index = 65536*width - 1
    size_t cfine_size = (1ULL << 16) * width;  // 65536 * width
    cfine = (uint16_t*)calloc(cfine_size, sizeof(uint16_t));
}

// Ensure all extern symbols are properly defined at file scope
int width;
uint16_t *ccoarse;
uint16_t *cfine;
int radiusV;
uint16_t *srcp;