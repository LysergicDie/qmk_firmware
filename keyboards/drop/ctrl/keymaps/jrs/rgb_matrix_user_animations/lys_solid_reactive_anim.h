// Indigo, Dark Red when pressed, esc = opposite
// TODO: maybe set up a similar one to this but with main/off colors set by config alias
//       - so this page would have an rgbmap of COLOR_1 and COLOR_2 and the config would set those colors
#include "user_rgblight_list.h"

#ifndef DISABLE_RGB_MATRIX_CUSTOM_LYS_SOLID_REACTIVE
RGB_MATRIX_EFFECT(LYS_SOLID_REACTIVE)
#	 ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

const uint8_t PROGMEM lys_solid_reactive_rgbmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
        DRK_RED, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_,          INDIGO_, INDIGO_, INDIGO_, \
        INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, \
        INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, \
        INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, \
        INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_,                            INDIGO_, \
        INDIGO_, INDIGO_, INDIGO_,                   INDIGO_,                            INDIGO_, INDIGO_, INDIGO_, INDIGO_,          INDIGO_, INDIGO_, INDIGO_, \

        INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, \
        INDIGO_, INDIGO_, INDIGO_, INDIGO_, \
        INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, INDIGO_, \
        INDIGO_, INDIGO_, INDIGO_, INDIGO_
    },
    [1] = {
        INDIGO_, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED,          DRK_RED, DRK_RED, DRK_RED, \
        DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, \
        DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, \
        DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, \
        DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED, DRK_RED,                            DRK_RED, \
        DRK_RED, DRK_RED, DRK_RED,                   DRK_RED,                            DRK_RED, DRK_RED, DRK_RED, DRK_RED,          DRK_RED, DRK_RED, DRK_RED, \
    },
};
/*
[RGB] = LAYOUT(
    ESC: 0,   F1: 1,    F2: 2,    F3: 3,    F4: 4,    F5: 5,    F6: 6,    F7: 7,    F8: 8,    F9: 9,    F10: 10,  F11: 11,  F12: 12,            PSCR: 13, SLCK: 14, PAUS: 15, \
    GRV: 16,  1: 17,    2: 18,    3: 19,    4: 20,    5: 21,    6: 22,    7: 23,    8: 24,    9: 25,    0: 26,    MINS: 27, EQL: 28,  BSPC: 29, INS: 30,  HOME: 31, PGUP: 32, \
    TAB: 33,  Q: 34,    W: 35,    E: 36,    R: 37,    T: 38,    Y: 39,    U: 40,    I: 41,    O: 42,    P: 43,    LBRC: 44, RBRC: 45, BSLS: 46, DEL: 47,  END: 48,  PGDN: 49, \
    CAPS: 50, A: 51,    S: 52,    D: 53,    F: 54,    G: 55,    H: 56,    J: 57,    K: 58,    L: 59,    SCLN: 60, QUOT: 61, ENT: 62, \
    LSFT: 63, Z: 64,    X: 65,    C: 66,    V: 67,    B: 68,    N: 69,    M: 70,    COMM: 71, DOT: 72,  SLSH: 73, RSFT: 74,                               UP: 75, \
    LCTL: 76, LGUI: 77, LALT: 78,                   SPC: 79,                                  RALT: 80, Fn: 81,   APP: 82,  RCTL: 83,           LEFT: 84, DOWN: 85, RGHT: 86, \
    
    // Underglow:
    // Bottom right to left:
         87,      88,      89,      90,      91,      92,      93,      94,      95,      96,      97,      98, \
    // Bottom left to top:
         99,     100,     101,     102, \
    // Top left to right:
        103,     104,     105,     106,     107,     108,     109,     110,     111,     112,     113,     114, \
    // Top right to bottom:
        115,     116,     117,     118 \
),
Visual Key Layout:
    @------------------------------------------------------------------------------------------------------@
    |      |   *   |   *   |   *   |   *   |   *   |   *   |   *   |   *   |   *   |   *   |   *   |       |
    |    @--------------------------------------------------------------------------------------------@    |
    | *  |#----#----#----#----#----#----#-#----#----#----#----#-#----#----#----#----#|#----#----#----#|  * |
    |    || ec |||||| f1 | f2 | f3 | f4 ||| f5 | f6 | f7 | f8 ||| f9 | 10 | 11 | 12 ||| ps | sl | pa ||    |
    | _  |#----#----#----#----#----#----#-#----#----#----#----#-#----#----#----#----#|#----#----#----#|  _ |
    |    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    |
    |    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    |
    | *  |#----#----#----#----#----#----#----#----#----#----#----#----#----#--------#|#----#----#----#|  * |
    |    ||  ` |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |  bksp  ||| in | hm | pu ||    |
    | _  |#----#----#----#----#----#----#----#----#----#----#----#----#----#--------#|#----#----#----#|  _ |
    |    |#------#----#----#----#----#----#----#----#----#----#----#----#----#------#|#----#----#----#|    |
    |    ||  tb  |  q |  w |  e |  r |  t |  y |  u |  i |  o |  p |  [ |  ] |   \  ||| dl | nd | pd ||    |
    | *  |#------#----#----#----#----#----#----#----#----#----#----#----#----#------#|#----#----#----#|  * |
    |    |#--------#----#----#----#----#----#----#----#----#----#----#----#---------#||||||||||||||||||    |
    | _  ||  caps  |  a |  s |  d |  f |  g |  h |  j |  k |  l |  ; |  ' |   ent   |||||||||||||||||||  _ |
    |    |#--------#----#----#----#----#----#----#----#----#----#----#----#---------#||||||||||||||||||    |
    |    |#----------#----#----#----#----#----#----#----#----#----#----#------------#||||||#----#||||||    |
    | *  ||   shft   |  z |  x |  c |  v |  b |  n |  m |  , |  . |  / |    shft    |||||||| ua |||||||  * |
    |    |#----------#----#----#----#----#----#----#----#----#----#----#------------#||||||#----#||||||    |
    | _  |#-----#-----#-----#-------------------------------#-----#-----#-----#-----#|#----#----#----#|  _ |
    |    || ctl | win | alt |              spc              | alt | fun | mnu | ctl ||| la | da | ra ||    |
    |    |#-----#-----#-----#-------------------------------#-----#-----#-----#-----#|#----#----#----#|    |
    | *  @--------------------------------------------------------------------------------------------@  * |
    |      |   *   |   *   |   *   |   *   |   *   |   *   |   *   |   *   |   *   |   *   |   *   |       |
    @------------------------------------------------------------------------------------------------------@

Visual RGB Matrix Layout:
    @------------------------------------------------------------------------------------------------------@
    |      |  104  |  105  |  106  |  107  |  108  |  109  |  110  |  111  |  112  |  113  |  114  |       |
    |    @--------------------------------------------------------------------------------------------@    |
    |103 |#----#----#----#----#----#----#-#----#----#----#----#-#----#----#----#----#|#----#----#----#| 115|
    |    || 00 |||||| 01 | 02 | 03 | 04 ||| 05 | 06 | 07 | 08 ||| 09 | 10 | 11 | 12 ||| 13 | 14 | 15 ||    |
    | _  |#----#----#----#----#----#----#-#----#----#----#----#-#----#----#----#----#|#----#----#----#|  _ |
    |    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    |
    |    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||    |
    |102 |#----#----#----#----#----#----#----#----#----#----#----#----#----#--------#|#----#----#----#| 116|
    |    || 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 |   29   ||| 30 | 31 | 32 ||    |
    | _  |#----#----#----#----#----#----#----#----#----#----#----#----#----#--------#|#----#----#----#|  _ |
    |    |#------#----#----#----#----#----#----#----#----#----#----#----#----#------#|#----#----#----#|    |
    |    ||  33  | 34 | 35 | 36 | 37 | 38 | 39 | 40 | 41 | 42 | 43 | 44 | 45 |  46  ||| 47 | 48 | 49 ||    |
    |101 |#------#----#----#----#----#----#----#----#----#----#----#----#----#------#|#----#----#----#| 117|
    |    |#--------#----#----#----#----#----#----#----#----#----#----#----#---------#||||||||||||||||||    |
    | _  ||   50   | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 58 | 59 | 60 | 61 |    62   |||||||||||||||||||  _ |
    |    |#--------#----#----#----#----#----#----#----#----#----#----#----#---------#||||||||||||||||||    |
    |    |#----------#----#----#----#----#----#----#----#----#----#----#------------#||||||#----#||||||    |
    |100 ||    63    | 64 | 65 | 66 | 67 | 68 | 69 | 70 | 71 | 72 | 73 |     74     |||||||| 75 ||||||| 118|
    |    |#----------#----#----#----#----#----#----#----#----#----#----#------------#||||||#----#||||||    |
    | _  |#-----#-----#-----#-------------------------------#-----#-----#-----#-----#|#----#----#----#|  _ |
    |    ||  76 |  77 |  78 |               79              |  80 |  81 |  82 |  83 ||| 84 | 85 | 86 ||    |
    |    |#-----#-----#-----#-------------------------------#-----#-----#-----#-----#|#----#----#----#|    |
    | 99 @--------------------------------------------------------------------------------------------@  87|
    |      |   98  |   97  |   96  |   95  |   94  |   93  |   92  |   91  |   90  |   89  |   88  |       |
    @------------------------------------------------------------------------------------------------------@
*/

typedef HSV (*reactive_f)(HSV hsv, uint16_t offset);

bool LYS_SOLID_REACTIVE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed, 1);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        RGB rgb = {
            .r = pgm_read_byte(&lys_solid_reactive_rgbmap[0][i][0]),
            .g = pgm_read_byte(&lys_solid_reactive_rgbmap[0][i][1]),
            .b = pgm_read_byte(&lys_solid_reactive_rgbmap[0][i][2]),
        };
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        
        uint16_t tick = max_tick;
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                RGB rgb = {
                    .r = pgm_read_byte(&lys_solid_reactive_rgbmap[1][i][0]),
                    .g = pgm_read_byte(&lys_solid_reactive_rgbmap[1][i][1]),
                    .b = pgm_read_byte(&lys_solid_reactive_rgbmap[1][i][2]),
                };
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                break;
            }
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#	 endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#endif     // DISABLE_RGB_MATRIX_CUSTOM_LYS_SOLID_REACTIVE