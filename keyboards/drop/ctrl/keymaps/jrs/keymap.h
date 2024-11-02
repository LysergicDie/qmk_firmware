#include QMK_KEYBOARD_H

// Standard CTRL

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL   (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT    (get_mods() & MOD_MASK_ALT)

// Layers

enum layout_names {
    _KEYS=0,
    _GAME,
    _MOUS,
    _NPAD,
    _FN,
};

// RGB

extern rgb_config_t rgb_matrix_config;
bool disable_layer_color; // CONFIGURABLE - SET TO FALSE TO DISABLE LAYER-SPECIFIC RGB CHANGES

// Tap Dance

enum td_keycodes {
    TD_LALT_T_UNDS_CAPS,
    TD_APP_GAME_LAYER,
    TD_RCTL_MOUS_LAYER,
    TD_GRV_NPAD_LAYER,
};
#define TD_CAPS TD(TD_LALT_T_UNDS_CAPS)
#define TD_GAME TD(TD_APP_GAME_LAYER)
#define TD_MOUS TD(TD_RCTL_MOUS_LAYER)
#define TD_NPAD TD(TD_GRV_NPAD_LAYER)

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
} td_state_t;

typedef struct{
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Multi-purpose switch for tap dance effects
td_state_t current(qk_tap_dance_state_t *state);

void caps_finished(qk_tap_dance_state_t *state, void *user_data);
void caps_reset(qk_tap_dance_state_t *state, void *user_data);