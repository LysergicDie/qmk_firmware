#pragma once

// #define IS_COMMAND() (get_mods() == MOD_MASK_SHIFT)      // Key combination that allows the use of magic commands (useful for debugging)

// #define NO_DEBUG                    // Disable debugging
// #define NO_PRINT                    // Disable printing/debugging using hid_listen
// #define NO_ACTION_LAYER             // Disable layers
// #define NO_ACTION_TAPPING           // Disable tap dance and other tapping features
// #define NO_ACTION_ONESHOT           // Disable one-shot modifiers
// #define NO_ACTION_MACRO             // Disable old style macro handling: MACRO() & action_get_macro
#define TERMINAL_HELP
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_WHEEL_DELAY 0
// #define FORCE_NKRO                  // NKRO by default requires to be turned on, this forces it on during keyboard startup regardless of EEPROM setting. NKRO can still be turned off but will be turned on again if the keyboard reboots.
// #define QMK_KEYS_PER_SCAN 4         // Allows sending more than one key per scan. By default, only one key event gets sent via process_record() per scan. This has little impact on most typing, but if you're doing a lot of chords, or your scan rate is slow to begin with, you can have some delay in processing key events. Each press and release is a separate event. For a keyboard with 1ms or so scan times, even a very fast typist isn't going to produce the 500 keystrokes a second needed to actually get more than a few ms of delay from this. But if you're doing chording on something with 3-4ms scan times? You probably want this.
// #define STRICT_LAYER_RELEASE        // Force a key release to be evaluated using the current layer stack instead of remembering which layer it came from (used for advanced cases)
// #define LOCKING_SUPPORT_ENABLE      // Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
// #define LOCKING_RESYNC_ENABLE       // Tries to keep switch state consistent with keyboard LED state
#define TAPPING_TERM 150            // How long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold too
// #define TAPPING_TERM_PER_KEY        // Enables handling for per key TAPPING_TERM settings
// #define RETRO_TAPPING               // Tap anyway, even after TAPPING_TERM, if there was no other key interruption between press and release
#define TAPPING_TOGGLE 2            // How many taps before triggering the toggle
// #define PERMISSIVE_HOLD             // Makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the TAPPING_TERM. See Permissive Hold for details
// #define IGNORE_MOD_TAP_INTERRUPT    // Makes it possible to do rolling combos (zx) with keys that convert to other keys on hold, by enforcing the TAPPING_TERM for both keys. See Mod tap interrupt for details
// #define TAPPING_FORCE_HOLD          // Makes it possible to use a dual role key as modifier shortly after having been tapped. See Hold after tap. Breaks any Tap Toggle functionality (TT or the One Shot Tap Toggle)
// #define LEADER_TIMEOUT 300          // How long before the leader key times out. If you're having issues finishing the sequence before it times out, you may need to increase the timeout setting. Or you may want to enable the LEADER_PER_KEY_TIMING option, which resets the timeout after each key is tapped.
// #define LEADER_PER_KEY_TIMING       // Sets the timer for leader key chords to run on each key press rather than overall
// #define LEADER_KEY_STRICT_KEY_PROCESSING    // Disables keycode filtering for Mod-Tap and Layer-Tap keycodes. Eg, if you enable this, you would need to specify MT(MOD_CTL, KC_A) if you want to use KC_A.
// #define ONESHOT_TIMEOUT 300         // How long before oneshot times out
// #define ONESHOT_TAP_TOGGLE 2        // How many taps before oneshot toggle is triggered
// #define COMBO_COUNT 2               // Set this to the number of combos that you're using in the Combo feature.
// #define COMBO_TERM 200              // How long for the Combo keys to be detected. Defaults to TAPPING_TERM if not defined.
// #define TAP_CODE_DELAY 100          // Sets the delay between register_code and unregister_code, if you're having issues with it registering properly (common on VUSB boards). The value is in milliseconds.
// #define TAP_HOLD_CAPS_DELAY 80      // Sets the delay for Tap Hold keys (LT, MT) when using KC_CAPSLOCK keycode, as this has some special handling on MacOS.  The value is in milliseconds, and defaults to 80 ms if not defined. For macOS, you may want to set this to 200 or higher.

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES         // reacts to keypresses
// #define RGB_MATRIX_KEYRELEASES        // reacts to keyreleases (instead of keypresses)
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CUSTOM_LYS_SOLID_REACTIVE // Sets the default mode, if none has been set
#define RGB_MATRIX_STARTUP_VAL 63    // Sets the default hsv.v - brightness

// This list in in the correct mode order. Next mode is the following line, previous mode is previous line. Loops around.
// #define DISABLE_RGB_MATRIX_SOLID_COLOR                   // Static single hue, no speed support
#define DISABLE_RGB_MATRIX_ALPHAS_MODS                   // Static dual hue, speed is hue for secondary hue
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN              // Static gradient top to bottom, speed controls how much gradient changes
#define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT           // Static gradient left to right, speed controls how much gradient changes
#define DISABLE_RGB_MATRIX_BREATHING                     // Single hue brightness cycling animation
#define DISABLE_RGB_MATRIX_BAND_SAT                      // Single hue band fading saturation scrolling left to right
#define DISABLE_RGB_MATRIX_BAND_VAL                      // Single hue band fading brightness scrolling left to right
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT             // Single hue 3 blade spinning pinwheel fades saturation
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL             // Single hue 3 blade spinning pinwheel fades brightness
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT               // Single hue spinning spiral fades saturation
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL               // Single hue spinning spiral fades brightness
#define DISABLE_RGB_MATRIX_CYCLE_ALL                     // Full keyboard solid hue cycling through full gradient
#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT              // Full gradient scrolling left to right
#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN                 // Full gradient scrolling top to bottom
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN                  // Full gradient scrolling out to in
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL             // Full dual gradients scrolling out to in
#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON        // Full gradent Chevron shapped scrolling left to right
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL                // Full gradient spinning pinwheel around center of keyboard
#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL                  // Full gradient spinning spiral around center of keyboard
#define DISABLE_RGB_MATRIX_DUAL_BEACON                   // Full gradient spinning around center of keyboard
#define DISABLE_RGB_MATRIX_RAINBOW_BEACON                // Full tighter gradient spinning around center of keyboard
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS             // Full dual gradients spinning two halfs of keyboard
// #define DISABLE_RGB_MATRIX_RAINDROPS                     // Randomly changes a single key's hue
// #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS           // Randomly changes a single key's hue and saturation
#define DISABLE_RGB_MATRIX_HUE_BREATHING                 // Hue shifts up a slight amount at the same time, then shifts back
#define DISABLE_RGB_MATRIX_HUE_PENDULUM                  // Hue shifts up a slight amount in a wave to the right, then back to the left
#define DISABLE_RGB_MATRIX_HUE_WAVE                      // Hue shifts up a slight amount and then back down in a wave to the right
// =================================================== Requires RGB_MATRIX_FRAMEBUFFER_EFFECTS =============================================================
// #define DISABLE_RGB_MATRIX_TYPING_HEATMAP                // How hot is your WPM!
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 60   // Heatmap fadeaway timing - higher stays longer
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN                  // That famous computer simulation
// =================================================== RGB_MATRIX_KEYPRESSES OR RGB_MATRIX_KEYRELEASES =====================================================
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE                // Static single hue, pulses keys hit to shifted hue then fades to current hue
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE         // Pulses keys hit to hue & value then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE           // Hue & value pulse near a single key hit then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE      // Hue & value pulse near multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS          // Hue & value pulse the same column and row of a single key hit then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS     // Hue & value pulse the same column and row of multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS          // Hue & value pulse away on the same column and row of single key hit then fades value out
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS     // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SPLASH                        // Full gradient & value pulse away from a single key hit then fades value out
#define DISABLE_RGB_MATRIX_MULTISPLASH                   // Full gradient & value pulse away from multiple key hits then fades value out
#define DISABLE_RGB_MATRIX_SOLID_SPLASH                  // Hue & value pulse away from a single key hit then fades value out
#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH             // Hue & value pulse away from multiple key hits then fades value out

// lysergic_die custom rgb_matrix_effects settings
// #define RGB_MATRIX_SOLID_RAINDROPS_FADE_DELAY_MS 10     // sets delay for raindrop fade
// #define RGB_MATRIX_SOLID_RAINDROPS_DROP_DELAY_BASE 2550 // sets slowest speed in ms

#define DISABLE_RGB_MATRIX_CUSTOM_SOLID_RAINDROPS       // Different raindrop effect - DO NOT ENABLE!
// #define DISABLE_RGB_MATRIX_CUSTOM_LYS_SOLID_REACTIVE    // Indigo, Dark Red when pressed, esc = opposite
#define DISABLE_RGB_MATRIX_CUSTOM_CARBON_SOLID_COLORS   // Solid colors to match YMDK Carbon Keycaps