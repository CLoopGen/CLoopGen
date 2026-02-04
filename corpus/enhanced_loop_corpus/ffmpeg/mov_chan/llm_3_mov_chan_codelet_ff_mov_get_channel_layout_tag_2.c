#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum MovChannelLayoutTag {
    MOV_CH_LAYOUT_USE_DESCRIPTIONS = (0 << 16) | 0,
    MOV_CH_LAYOUT_USE_BITMAP = (1 << 16) | 0,
    MOV_CH_LAYOUT_DISCRETEINORDER = (147 << 16) | 0,
    MOV_CH_LAYOUT_MONO = (100 << 16) | 1,
    MOV_CH_LAYOUT_STEREO = (101 << 16) | 2,
    MOV_CH_LAYOUT_STEREOHEADPHONES = (102 << 16) | 2,
    MOV_CH_LAYOUT_MATRIXSTEREO = (103 << 16) | 2,
    MOV_CH_LAYOUT_MIDSIDE = (104 << 16) | 2,
    MOV_CH_LAYOUT_XY = (105 << 16) | 2,
    MOV_CH_LAYOUT_BINAURAL = (106 << 16) | 2,
    MOV_CH_LAYOUT_AMBISONIC_B_FORMAT = (107 << 16) | 4,
    MOV_CH_LAYOUT_QUADRAPHONIC = (108 << 16) | 4,
    MOV_CH_LAYOUT_PENTAGONAL = (109 << 16) | 5,
    MOV_CH_LAYOUT_HEXAGONAL = (110 << 16) | 6,
    MOV_CH_LAYOUT_OCTAGONAL = (111 << 16) | 8,
    MOV_CH_LAYOUT_CUBE = (112 << 16) | 8,
    MOV_CH_LAYOUT_MPEG_3_0_A = (113 << 16) | 3,
    MOV_CH_LAYOUT_MPEG_3_0_B = (114 << 16) | 3,
    MOV_CH_LAYOUT_MPEG_4_0_A = (115 << 16) | 4,
    MOV_CH_LAYOUT_MPEG_4_0_B = (116 << 16) | 4,
    MOV_CH_LAYOUT_MPEG_5_0_A = (117 << 16) | 5,
    MOV_CH_LAYOUT_MPEG_5_0_B = (118 << 16) | 5,
    MOV_CH_LAYOUT_MPEG_5_0_C = (119 << 16) | 5,
    MOV_CH_LAYOUT_MPEG_5_0_D = (120 << 16) | 5,
    MOV_CH_LAYOUT_MPEG_5_1_A = (121 << 16) | 6,
    MOV_CH_LAYOUT_MPEG_5_1_B = (122 << 16) | 6,
    MOV_CH_LAYOUT_MPEG_5_1_C = (123 << 16) | 6,
    MOV_CH_LAYOUT_MPEG_5_1_D = (124 << 16) | 6,
    MOV_CH_LAYOUT_MPEG_6_1_A = (125 << 16) | 7,
    MOV_CH_LAYOUT_MPEG_7_1_A = (126 << 16) | 8,
    MOV_CH_LAYOUT_MPEG_7_1_B = (127 << 16) | 8,
    MOV_CH_LAYOUT_MPEG_7_1_C = (128 << 16) | 8,
    MOV_CH_LAYOUT_EMAGIC_DEFAULT_7_1 = (129 << 16) | 8,
    MOV_CH_LAYOUT_SMPTE_DTV = (130 << 16) | 8,
    MOV_CH_LAYOUT_ITU_2_1 = (131 << 16) | 3,
    MOV_CH_LAYOUT_ITU_2_2 = (132 << 16) | 4,
    MOV_CH_LAYOUT_DVD_4 = (133 << 16) | 3,
    MOV_CH_LAYOUT_DVD_5 = (134 << 16) | 4,
    MOV_CH_LAYOUT_DVD_6 = (135 << 16) | 5,
    MOV_CH_LAYOUT_DVD_10 = (136 << 16) | 4,
    MOV_CH_LAYOUT_DVD_11 = (137 << 16) | 5,
    MOV_CH_LAYOUT_DVD_18 = (138 << 16) | 5,
    MOV_CH_LAYOUT_AUDIOUNIT_6_0 = (139 << 16) | 6,
    MOV_CH_LAYOUT_AUDIOUNIT_7_0 = (140 << 16) | 7,
    MOV_CH_LAYOUT_AUDIOUNIT_7_0_FRONT = (148 << 16) | 7,
    MOV_CH_LAYOUT_AAC_6_0 = (141 << 16) | 6,
    MOV_CH_LAYOUT_AAC_6_1 = (142 << 16) | 7,
    MOV_CH_LAYOUT_AAC_7_0 = (143 << 16) | 7,
    MOV_CH_LAYOUT_AAC_OCTAGONAL = (144 << 16) | 8,
    MOV_CH_LAYOUT_TMH_10_2_STD = (145 << 16) | 16,
    MOV_CH_LAYOUT_TMH_10_2_FULL = (146 << 16) | 21,
    MOV_CH_LAYOUT_AC3_1_0_1 = (149 << 16) | 2,
    MOV_CH_LAYOUT_AC3_3_0 = (150 << 16) | 3,
    MOV_CH_LAYOUT_AC3_3_1 = (151 << 16) | 4,
    MOV_CH_LAYOUT_AC3_3_0_1 = (152 << 16) | 4,
    MOV_CH_LAYOUT_AC3_2_1_1 = (153 << 16) | 4,
    MOV_CH_LAYOUT_AC3_3_1_1 = (154 << 16) | 5,
    MOV_CH_LAYOUT_EAC3_6_0_A = (155 << 16) | 6,
    MOV_CH_LAYOUT_EAC3_7_0_A = (156 << 16) | 7,
    MOV_CH_LAYOUT_EAC3_6_1_A = (157 << 16) | 7,
    MOV_CH_LAYOUT_EAC3_6_1_B = (158 << 16) | 7,
    MOV_CH_LAYOUT_EAC3_6_1_C = (159 << 16) | 7,
    MOV_CH_LAYOUT_EAC3_7_1_A = (160 << 16) | 8,
    MOV_CH_LAYOUT_EAC3_7_1_B = (161 << 16) | 8,
    MOV_CH_LAYOUT_EAC3_7_1_C = (162 << 16) | 8,
    MOV_CH_LAYOUT_EAC3_7_1_D = (163 << 16) | 8,
    MOV_CH_LAYOUT_EAC3_7_1_E = (164 << 16) | 8,
    MOV_CH_LAYOUT_EAC3_7_1_F = (165 << 16) | 8,
    MOV_CH_LAYOUT_EAC3_7_1_G = (166 << 16) | 8,
    MOV_CH_LAYOUT_EAC3_7_1_H = (167 << 16) | 8,
    MOV_CH_LAYOUT_DTS_3_1 = (168 << 16) | 4,
    MOV_CH_LAYOUT_DTS_4_1 = (169 << 16) | 5,
    MOV_CH_LAYOUT_DTS_6_0_A = (170 << 16) | 6,
    MOV_CH_LAYOUT_DTS_6_0_B = (171 << 16) | 6,
    MOV_CH_LAYOUT_DTS_6_0_C = (172 << 16) | 6,
    MOV_CH_LAYOUT_DTS_6_1_A = (173 << 16) | 7,
    MOV_CH_LAYOUT_DTS_6_1_B = (174 << 16) | 7,
    MOV_CH_LAYOUT_DTS_6_1_C = (175 << 16) | 7,
    MOV_CH_LAYOUT_DTS_6_1_D = (182 << 16) | 7,
    MOV_CH_LAYOUT_DTS_7_0 = (176 << 16) | 7,
    MOV_CH_LAYOUT_DTS_7_1 = (177 << 16) | 8,
    MOV_CH_LAYOUT_DTS_8_0_A = (178 << 16) | 8,
    MOV_CH_LAYOUT_DTS_8_0_B = (179 << 16) | 8,
    MOV_CH_LAYOUT_DTS_8_1_A = (180 << 16) | 9,
    MOV_CH_LAYOUT_DTS_8_1_B = (181 << 16) | 9
};


struct MovChannelLayoutMap {
    uint32_t tag;
    uint64_t layout;
};


extern uint64_t channel_layout;
extern int i;
extern int j;
extern  enum MovChannelLayoutTag *layouts;
extern int channels;
extern  struct MovChannelLayoutMap *layout_map;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access over layout_map with reversed iteration and indirect indexing
    int stride = 2; // Simulate non-unit stride access for layout_map
    uint32_t target_channel_count = channels & 65535;

    for (i = 0; layouts[i] != 0; i++) {
        if ((layouts[i] & 65535) != target_channel_count)
            continue;

        // Traverse layout_map with reverse, strided access
        j = 0;
        int map_size = 0;
        while (layout_map[map_size].tag != 0) map_size++; // Compute size once

        for (j = ((map_size - 1) / stride) * stride; j >= 0; j -= stride) {
            if (layout_map[j].tag == layouts[i] && layout_map[j].layout == channel_layout)
                goto exit_loop_2;
        }

        // Check last element if stride skips index 0
        if ((map_size - 1) % stride != 0 && layout_map[0].tag == layouts[i] && layout_map[0].layout == channel_layout)
            break;
    }
    return;

exit_loop_2:
    return;
}
