#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef enum {
    UndefinedPixelChannel = 0,
    RedPixelChannel = 0,
    CyanPixelChannel = 0,
    GrayPixelChannel = 0,
    LPixelChannel = 0,
    LabelPixelChannel = 0,
    YPixelChannel = 0,
    aPixelChannel = 1,
    GreenPixelChannel = 1,
    MagentaPixelChannel = 1,
    CbPixelChannel = 1,
    bPixelChannel = 2,
    BluePixelChannel = 2,
    YellowPixelChannel = 2,
    CrPixelChannel = 2,
    BlackPixelChannel = 3,
    AlphaPixelChannel = 4,
    IndexPixelChannel = 5,
    ReadMaskPixelChannel = 6,
    WriteMaskPixelChannel = 7,
    MetaPixelChannel = 8,
    CompositeMaskPixelChannel = 9,
    MetaPixelChannels = 10,
    IntensityPixelChannel = 64,
    CompositePixelChannel = 64,
    SyncPixelChannel = 64 + 1
} PixelChannel;

typedef enum {
    UndefinedPixelTrait = 0,
    CopyPixelTrait = 1,
    UpdatePixelTrait = 2,
    BlendPixelTrait = 4
} PixelTrait;

typedef struct _PixelChannelMap {
    PixelChannel channel;
    PixelTrait traits;
    ssize_t offset;
} PixelChannelMap;

extern PixelChannelMap *channel_map;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward stepping by 1 (original pattern, unrolled by factor of 2 for variation in access rhythm)
    for (i = 0; i <= 64; i += 2) {
        channel_map[i].channel = (PixelChannel)i;
        if (i + 1 <= 64) {
            channel_map[i + 1].channel = (PixelChannel)(i + 1);
        }
    }
}
