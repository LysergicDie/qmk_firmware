#include "keymap.h"
#include "rgb_matrix_user_animations/user_rgblight_list.h"

// functional keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_KEYS] = LAYOUT(
         KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,            KC_PSCR, KC_SLCK, KC_PAUS, \
        TD_NPAD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,    KC_INS, KC_HOME, KC_PGUP, \
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END, KC_PGDN, \
        TD_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT, \
        KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,                                KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_FN), TD_GAME, TD_MOUS,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT,                              _______, \
        _______, XXXXXXX, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    [_MOUS] = LAYOUT(
        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, KC_BTN4, KC_BTN3, KC_BTN5, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              KC_MS_U, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            KC_MS_L, KC_MS_D, KC_MS_R \
    ),
    [_NPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, XXXXXXX, KC_PSLS,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______,   KC_P4,   KC_P5,   KC_P6, KC_LOCK, KC_PENT, \
        _______, _______, _______, _______, _______, _______, _______, _______,   KC_P1,   KC_P2,   KC_P3, _______,                              _______, \
        _______, _______, _______,                   KC_PAST,                              KC_P0, KC_PDOT, _______, _______,            _______, _______, _______ \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    */ // Keep _FN as top layer
    [_FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE,   KC_MPLY, KC_MPRV, _______, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______,   _______, KC_MNXT, _______, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_ON,   NK_OFF,  _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
};

// led maps for unique layer colors
#ifdef _______
#undef _______
#define _______ _BLANK_

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
/*
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
    [RGB] = {
        ESC: 0,   F1: 1,    F2: 2,    F3: 3,    F4: 4,    F5: 5,    F6: 6,    F7: 7,    F8: 8,    F9: 9,    F10: 10,  F11: 11,  F12: 12,            PSCR: 13, SLCK: 14, PAUS: 15,
        GRV: 16,  1: 17,    2: 18,    3: 19,    4: 20,    5: 21,    6: 22,    7: 23,    8: 24,    9: 25,    0: 26,    MINS: 27, EQL: 28,  BSPC: 29, INS: 30,  HOME: 31, PGUP: 32,
        TAB: 33,  Q: 34,    W: 35,    E: 36,    R: 37,    T: 38,    Y: 39,    U: 40,    I: 41,    O: 42,    P: 43,    LBRC: 44, RBRC: 45, BSLS: 46, DEL: 47,  END: 48,  PGDN: 49,
        CAPS: 50, A: 51,    S: 52,    D: 53,    F: 54,    G: 55,    H: 56,    J: 57,    K: 58,    L: 59,    SCLN: 60, QUOT: 61, ENT: 62,
        LSFT: 63, Z: 64,    X: 65,    C: 66,    V: 67,    B: 68,    N: 69,    M: 70,    COMM: 71, DOT: 72,  SLSH: 73, RSFT: 74,                               UP: 75,
        LCTL: 76, LGUI: 77, LALT: 78,                   SPC: 79,                                  RALT: 80, Fn: 81,   APP: 82,  RCTL: 83,           LEFT: 84, DOWN: 85, RGHT: 86,
        
        // Underglow:
        // Bottom right to left:
             87,      88,      89,      90,      91,      92,      93,      94,      95,      96,      97,      98, \
        // Bottom left to top:
             99,     100,     101,     102, \
        // Top left to right:
            103,     104,     105,     106,     107,     108,     109,     110,     111,     112,     113,     114, \
        // Top right to bottom:
            115,     116,     117,     118
    },
    [_TEMPLATE] = {
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______, \
        // Underglow:
        // Bottom right to left:
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        // Bottom left to top:
        _______, _______, _______, _______, \
        // Top left to right:
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        // Top right to bottom:
        _______, _______, _______, _______
    },
*/
    [_KEYS] = { // Blank, keep whatever matrix animation selected
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______, \
        // Underglow:
        // Bottom right to left:
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        // Bottom left to top:
        _______, _______, _______, _______, \
        // Top left to right:
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        // Top right to bottom:
        _______, _______, _______, _______
    },
    [_GAME] = {
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, __OFF__, _______,                   _______,                            _______, _______, PURPLE_, _______,            _______, _______, _______, \
        // Underglow:
        // Bottom right to left:
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        // Bottom left to top:
        _______, _______, _______, _______, \
        // Top left to right:
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        // Top right to bottom:
        _______, _______, _______, _______
    },
    [_MOUS] = {
        __OFF__, GOLDROD, GOLDROD, GOLDROD, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__,          __OFF__, __OFF__, __OFF__, \
        __OFF__, AQUA_LK, AQUA_LK, AQUA_LK, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, AQUA_LK, AQUA_LK, AQUA_LK, \
        __OFF__, AQUA_LK, GOLDROD, AQUA_LK, GOLDROD, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, AQUA_LK, AQUA_LK, AQUA_LK, \
        __OFF__, GOLDROD, GOLDROD, GOLDROD, GOLDROD, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, \
        __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__, __OFF__,                            GOLDROD, \
        __OFF__, __OFF__, __OFF__,                   __OFF__,                            __OFF__, __OFF__, __OFF__, PURPLE_,          GOLDROD, GOLDROD, GOLDROD, \
        // Underglow:
        // Bottom right to left:
        _______, GOLDROD, _______, GOLDROD, _______, GOLDROD, _______, GOLDROD, _______, GOLDROD, _______, GOLDROD, \
        // Bottom left to top:
        _______, GOLDROD, _______, GOLDROD, \
        // Top left to right:
        _______, GOLDROD, _______, GOLDROD, _______, GOLDROD, _______, GOLDROD, _______, GOLDROD, _______, GOLDROD, \
        // Top right to bottom:
        _______, GOLDROD, _______, GOLDROD
    },
    [_NPAD] = {
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        PURPLE_, _______, _______, _______, _______, _______, _______, __OFF__, __OFF__, __OFF__, DRK_RED, INDIGO_, INDIGO_, INDIGO_,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, __OFF__, DRK_RED, DRK_RED, DRK_RED, __OFF__, __OFF__, DRK_RED,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, __OFF__, DRK_RED, DRK_RED, DRK_RED, __OFF__, INDIGO_, \
        _______, _______, _______, _______, _______, _______, _______, __OFF__, DRK_RED, DRK_RED, DRK_RED, INDIGO_,                              _______, \
        _______, _______, _______,                   DRK_RED,                            DRK_RED, DRK_RED, _______, _______,            _______, _______, _______, \
        // Underglow:
        // Bottom right to left:
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        // Bottom left to top:
        _______, _______, _______, _______, \
        // Top left to right:
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        // Top right to bottom:
        _______, _______, _______, _______
    },
    [_FN] = {
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, PURPLE_, _______, _______,            _______, _______, _______, \
        // Underglow:
        // Bottom right to left:
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        // Bottom left to top:
        _______, _______, _______, _______, \
        // Top left to right:
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        // Top right to bottom:
        _______, _______, _______, _______
    },
};

#undef _______
#define _______ KC_TRNS
#endif

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

void set_layer_color(int layer) {
    if (layer == 0) { return; }
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        RGB rgb = {
            .r = pgm_read_byte(&ledmap[layer][i][0]),
            .g = pgm_read_byte(&ledmap[layer][i][1]),
            .b = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if ((rgb.r == 1) && (rgb.g == 1) && (rgb.b == 1)) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else if (rgb.r || rgb.g || rgb.b) {
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        } // case _______ happens here, leaves that light alone
    }
}

void rgb_matrix_indicators_user(void) {
    // disable indicator lights when layer colors disabled or rgb off
    if (disable_layer_color ||
        rgb_matrix_get_flags() == LED_FLAG_NONE) {
            return;
        }
    // set layer-specific colors
    set_layer_color(get_highest_layer(layer_state));

    // actual indicator lights
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(50, RGB_DARK_RED);
        rgb_matrix_set_color(51, RGB_DARK_RED);
        rgb_matrix_set_color(99, RGB_DARK_RED);
    }
    if (host_keyboard_led_state().scroll_lock) {
        rgb_matrix_set_color(14, RGB_DARK_RED);
        rgb_matrix_set_color(87, RGB_DARK_RED);
    }
}

// Tap Dance Functions

// Switch for interpreting TD inputs
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP; // no state->interrupted so that quick use will still be recognized as hold
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else return TD_UNKNOWN;
}

// TD_LALT_T_UNDS_CAPS functions

// instance of td_tap_t for the caps tap dance
static td_tap_t caps_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    caps_tap_state.state = cur_dance(state);
    switch (caps_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code16(KC_UNDS); break;
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_HOLD:
            register_code(KC_LALT); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
            register_code(KC_CAPS); break;
        default:
            register_code(KC_NO); break;
    }
}

void caps_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (caps_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code16(KC_UNDS); break;
        case TD_SINGLE_HOLD:
        case TD_DOUBLE_HOLD:
            unregister_code(KC_LALT); break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code(KC_CAPS); break;
        default:
            unregister_code(KC_NO); break;
    }
}

// All tap dance actions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LALT_T_UNDS_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_finished, caps_reset), // ALIAS TD_CAPS
    [TD_APP_GAME_LAYER] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_APP, _GAME),                    // ALIAS TD_GAME
    [TD_RCTL_MOUS_LAYER] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RCTL, _MOUS),                  // ALIAS TD_MOUS
    [TD_GRV_NPAD_LAYER] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_GRV, _NPAD),                    // ALIAS TD_NPAD
};