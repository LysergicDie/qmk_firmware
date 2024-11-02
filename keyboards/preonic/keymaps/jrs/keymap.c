/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* LysergicDie 2022-04-16
 * Single layer MIDI keymap for Preonic
 * - also see changes in rules.mk and config.h that help make this work
 */

// oct and trns limits ?
// figure out channels ?
// handle the other notes and manage index, note queues
// TODO: possibly add layers for more options + layers for typing etc.
//       - set up alternate functions for some keys (using laltl/ralt as lmod/rmod)
//       - move VEL to alt layer, add notes for main

#include QMK_KEYBOARD_H
#include "muse.h"

#include "qmk_midi.h"

extern MidiDevice midi_device;

static uint8_t l_note = 0;
static uint8_t l_index = 0;
static uint8_t l_oct = 2;
static int8_t l_trns = 0;
static uint8_t l_vel = 104;
static uint8_t l_ch = 1;

// static uint8_t r_note [4] = { 0, 0, 0, 0 };
// static uint8_t r_index = 0;
// static uint8_t r_oct = 4;
// static int8_t r_trns = 0;
// static uint8_t r_vel = 104;
// static uint8_t r_ch = 2;

static uint8_t lysergic_midi_compute_note(uint16_t kc, uint8_t oct, int8_t trns) {
  return (12 * oct) + (kc - MIDI_TONE_MIN) + trns;
}

enum lysergic_layers {
  _MIDI
};

enum lysergic_keycodes {
  L_OCTD = MI_OCTD, R_OCTD = MI_OCT_0,            // Octave Down
  L_OCTU = MI_OCTU, R_OCTU = MI_OCT_1,            // Octave Up
  L_TRNSU = MI_TRNSU, R_TRNSU = MI_TRNS_0,        // Transpose Up
  L_TRNSD = MI_TRNSD,                             // Transpose Down
  L_BENDD = MI_BENDD, R_BENDD = SAFE_RANGE,       // Pitchbend Down
  L_BENDU = MI_BENDU, R_BENDU = SAFE_RANGE + 1,   // Pitchbend Up

  L_VEL_1 = MI_VEL_0, R_VEL_1 = MI_VEL_5,         // Velocity 1 =  26
  L_VEL_2 = MI_VEL_1, R_VEL_2 = MI_VEL_6,         // Velocity 2 =  52
  L_VEL_3 = MI_VEL_2, R_VEL_3 = MI_VEL_7,         // Velocity 3 =  78
  L_VEL_4 = MI_VEL_3, R_VEL_4 = MI_VEL_8,         // Velocity 4 = 104
  L_VEL_5 = MI_VEL_4, R_VEL_5 = MI_VEL_9,         // Velocity 5 = 127

  MI_RST = SAFE_RANGE + 2                         // MIDI Reset
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 2 INST MIDI (2 instrument layout):
 *              - L INST -           - L MOD - R MOD -           - R INST -
 *   _______________||_______________   _|__   __|_   _______________||_______________
 *  /                                \ /    \ /    \ /                                \
 * ,-----------------------------------------------------------------------------------.
 * | RVe1 | RVe2 | RVe3 | RVe4 | RVe5 | lalt | ralt | RVe1 | RVe2 | RVe3 | RVe4 | RVe5 |
 * |------=------=------=------=------|------|------|------=------=------=------=------|
 * |  Ds1 |  E1  |  F1  |  Fs1 |  G1  | locu | rocu |  Ds3 |  E3  |  F3  |  Fs3 |  G3  |
 * |------+------+------+------+------|------|------|------+------+------+------+------|
 * |  As  |  B   |  C1  |  Cs1 |  D1  | locd | rocd |  As2 |  B2  |  C3  |  Cs3 |  D3  |
 * |------+------+------+------+------|------|------|------+------+------+------+------|
 * |  F   |  Fs  |  G   |  Gs  |  A   | lbdu | rbdu |  F2  |  Fs2 |  G2  |  Gs2 |  A2  |
 * |------+------+------+------+------|------|------|------+------+------+------+------|
 * |  C   |  Cs  |  D   |  Ds  |  E   | lbdd | rbdd |  C2  |  Cs2 |  D2  |  Ds2 |  E2  |
 * `-----------------------------------------------------------------------------------'
 */
/*[_MIDI] = LAYOUT_preonic_grid(
  L_VEL_1, L_VEL_2, L_VEL_3, L_VEL_4, L_VEL_5, L_TRNSU, R_TRNSU, R_VEL_1, R_VEL_2, R_VEL_3, R_VEL_4, R_VEL_5,
  MI_Ds_1,  MI_E_1,  MI_F_1, MI_Fs_1,  MI_G_1,  L_OCTU,  R_OCTU, MI_Ds_3,  MI_E_3,  MI_F_3, MI_Fs_3,  MI_G_3,
    MI_As,    MI_B,  MI_C_1, MI_Cs_1,  MI_D_1,  L_OCTD,  R_OCTD, MI_As_2,  MI_B_2,  MI_C_3, MI_Cs_3,  MI_D_3,
     MI_F,   MI_Fs,    MI_G,   MI_Gs,    MI_A, L_BENDU, R_BENDU,  MI_F_2, MI_Fs_2,  MI_G_2, MI_Gs_2,  MI_A_2,
     MI_C,   MI_Cs,    MI_D,   MI_Ds,    MI_E, L_BENDD, R_BENDD,  MI_C_2, MI_Cs_2,  MI_D_2, MI_Ds_2,  MI_E_2
),*/
/* 1 INST MIDI (1 instrument layout):
 * ,-----------------------------------------------------------------------------------.
 * | Vel1 | Vel2 | Vel3 | Vel4 | Vel5 |  RST | OctD | OctU | NotD | NotU | BndD | BndU |
 * |------=------=------=------=------=------=------=------=------=------=------=------|
 * |  Ds2 |  E2  |  F2  |  Fs2 |  G2  |  Gs2 |  A2  |  As2 |  B2  |  C3  |  Cs3 |  D3  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  As  |  B   |  C2  |  Cs2 |  D2  |  Ds2 |  E2  |  F2  |  Fs2 |  G2  |  Gs2 |  A2  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F   |  Fs  |  G   |  Gs  |  A   |  As  |  B   |  C2  |  Cs2 |  D2  |  Ds2 |  E2  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  C   |  Cs  |  D   |  Ds  |  E   |  F   |  Fs  |  G   |  Gs  |  A   |  As  |  B   |
 * `-----------------------------------------------------------------------------------'
 */
[_MIDI] = LAYOUT_preonic_grid(
  L_VEL_1, L_VEL_2, L_VEL_3, L_VEL_4, L_VEL_5,  MI_RST,  L_OCTD,  L_OCTU, L_TRNSD, L_TRNSU, L_BENDD, L_BENDU,
  MI_Ds_1,  MI_E_1,  MI_F_1, MI_Fs_1,  MI_G_1, MI_Gs_1,  MI_A_1, MI_As_1,  MI_B_1,  MI_C_2, MI_Cs_2,  MI_D_2,
    MI_As,    MI_B,  MI_C_1, MI_Cs_1,  MI_D_1, MI_Ds_1,  MI_E_1,  MI_F_1, MI_Fs_1,  MI_G_1, MI_Gs_1,  MI_A_1,
     MI_F,   MI_Fs,    MI_G,   MI_Gs,    MI_A,   MI_As,    MI_B,  MI_C_1, MI_Cs_1,  MI_D_1, MI_Ds_1,  MI_E_1,
     MI_C,   MI_Cs,    MI_D,   MI_Ds,    MI_E,    MI_F,   MI_Fs,    MI_G,   MI_Gs,    MI_A,   MI_As,    MI_B
),
};

// Key overrides for 'alt layer'
//const key_override_t

bool process_record_user(uint16_t kc, keyrecord_t * record) {
  switch (kc) {

    // LEFT INSTRUMENT:
    // Notes
    case MI_C ... MI_D_2 : //MI_G_1 :
            if (record->event.pressed) {
                l_note = lysergic_midi_compute_note(kc, l_oct, l_trns);
                midi_send_noteon(&midi_device, l_ch, l_note, l_vel);
            } else {
                uint8_t temp_note = lysergic_midi_compute_note(kc, l_oct, l_trns);
                midi_send_noteoff(&midi_device, l_ch, temp_note, l_vel);
            }
            return false;

    // Octaves
    case L_OCTD :
        if (record->event.pressed) {
            if (l_oct > 0) {
                l_oct--;
            } else {
                l_oct = (MIDI_OCTAVE_MAX - MIDI_OCTAVE_MIN);
            }
        }
        return false;
    case L_OCTU :
        if (record->event.pressed) {
            if (l_oct < (MIDI_OCTAVE_MAX - MIDI_OCTAVE_MIN)) {
                l_oct++;
            } else {
                l_oct = 0;
            }
        }
        return false;

    // Transpose
    case L_TRNSD :
        if (record->event.pressed) {
            if (l_trns > (MIDI_TRANSPOSE_MIN - MI_TRNS_0)) {
                l_trns--;
            } else {
                l_trns = 6;
            }
        }
        return false;
    case L_TRNSU :
        if (record->event.pressed) {
            if (l_trns < (MIDI_TRANSPOSE_MAX - MI_TRNS_0)) {
                l_trns++;
            } else {
                l_trns = -6;
            }
        }
        return false;

    // Pitchbend
    case L_BENDD :
        if (record->event.pressed) {
            midi_send_pitchbend(&midi_device, l_ch, -0x2000);
        } else {
            midi_send_pitchbend(&midi_device, l_ch, 0);
        }
        return false;
    case L_BENDU :
        if (record->event.pressed) {
            midi_send_pitchbend(&midi_device, l_ch, 0x1fff);
        } else {
            midi_send_pitchbend(&midi_device, l_ch, 0);
        }
        return false;

    // Velocity
    case L_VEL_1 ... L_VEL_5 :
        if (record->event.pressed) {
            l_vel = ((kc - L_VEL_1) * 24) + 7;
        }
        return false;

    // // RIGHT INSTRUMENT
    // // Notes
    // case MI_C_2 ... MI_G_3 :
    //         if (record->event.pressed) {
    //             if (r_index < 4) {
    //                 uint8_t r_ch = 2;
    //                 r_note[r_index] = lysergic_midi_compute_note(kc, r_oct, r_trns);
    //                 midi_send_noteon(&midi_device, r_ch, r_note[r_index], r_vel);
    //             }
    //         } else {
    //                 uint8_t r_ch = 2;
    //                 uint8_t temp_note = lysergic_midi_compute_note(kc, r_oct, r_trns);
    //                 midi_send_noteoff(&midi_device, r_ch, temp_note, r_vel);
    //         }
    //         return false;

    // // Octaves
    // case R_OCTD :
    //     if (record->event.pressed) {
    //         if (r_oct > 0) {
    //             r_oct--;
    //         } else {
    //             r_oct = (MIDI_OCTAVE_MAX - MIDI_OCTAVE_MIN);
    //         }
    //     }
    //     return false;
    // case R_OCTU :
    //     if (record->event.pressed) {
    //         if (r_oct < (MIDI_OCTAVE_MAX - MIDI_OCTAVE_MIN)) {
    //             r_oct++;
    //         } else {
    //             r_oct = 0;
    //         }
    //     }
    //     return false;

    // // Transpose
    // case R_TRNSU :
    //     if (record->event.pressed) {
    //         if (r_trns < (MIDI_TRANSPOSE_MAX - MI_TRNS_0)) {
    //             r_trns++;
    //         } else {
    //             r_trns = -6;
    //         }
    //     }
    //     return false;

    // // Pitchbend
    // case R_BENDD :
    //     if (record->event.pressed) {
    //         midi_send_pitchbend(&midi_device, r_ch, -0x2000);
    //     } else {
    //         midi_send_pitchbend(&midi_device, r_ch, 0);
    //     }
    //     return false;
    // case R_BENDU :
    //     if (record->event.pressed) {
    //         midi_send_pitchbend(&midi_device, r_ch, 0x1fff);
    //     } else {
    //         midi_send_pitchbend(&midi_device, r_ch, 0);
    //     }
    //     return false;

    // // Velocity
    // case R_VEL_1 ... R_VEL_5 :
    //     if (record->event.pressed) {
    //         r_vel = ((kc - R_VEL_1) * 24) + 7;
    //     }
    //     return false;

    case MI_RST :
        if (record->event.pressed) {
            l_note  = 0;
            l_index = 0;
            l_oct = 2;
            l_trns = 0;
            l_vel = 104;
            l_ch = 1;
        }

    default :
      return true;
  }
}

void keyboard_post_init_user(void) {

    //debug_enable=true;

    // Set underglow to solid red
    rgblight_enable_noeeprom();
    rgblight_sethsv_red();
    rgblight_mode_noeeprom(0);

    // Turn MIDI on
    midi_on();
}
