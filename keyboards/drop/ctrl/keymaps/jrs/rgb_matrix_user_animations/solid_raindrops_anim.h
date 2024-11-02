// Modified from qmk-firmware/quantum/rgb_matrix_animations/raindrops_anim.h and typing_heatmap_anim.h
// TODO change colors, maybe use h+s from config?
// TODO restart and rename - DELETE THIS FILE
#ifndef DISABLE_RGB_MATRIX_CUSTOM_SOLID_RAINDROPS
RGB_MATRIX_EFFECT(SOLID_RAINDROPS)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#        ifndef RGB_MATRIX_SOLID_RAINDROPS_FADE_DELAY_MS
#            define RGB_MATRIX_SOLID_RAINDROPS_FADE_DELAY_MS 10
#        endif

#        define RGB_MATRIX_SOLID_RAINDROPS_DROP_DELAY_BASE 2550

static void raindrop(int i, effect_params_t* params) {
    if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;

    uint8_t row = i % MATRIX_ROWS;
    uint8_t col = i / MATRIX_ROWS;
    g_rgb_frame_buffer[row][col] = 230;
}

// Keep track of last drops and fade_drops
static uint16_t drops_timer;
static uint16_t fade_drops_timer;
// Whether the next update will drop and fade drops
static bool drops;
static bool fade_drops;

bool SOLID_RAINDROPS(effect_params_t* params) {
    uint8_t led_min = RGB_MATRIX_LED_PROCESS_LIMIT * params->iter;
    uint8_t led_max = led_min + RGB_MATRIX_LED_PROCESS_LIMIT;
    if (led_max > sizeof(g_rgb_frame_buffer)) led_max = sizeof(g_rgb_frame_buffer);

    uint16_t drop_delay = RGB_MATRIX_SOLID_RAINDROPS_DROP_DELAY_BASE - (rgb_matrix_get_speed() * 10);
    // update timers when animation starts - see typing_heatmap_anim.h
    if (params->iter == 0) {
        drops = timer_elapsed(drops_timer) >= drop_delay && drop_delay > 0;
        fade_drops = timer_elapsed(fade_drops_timer) >= RGB_MATRIX_SOLID_RAINDROPS_FADE_DELAY_MS;
        if (drops) {
            drops_timer = timer_read();
        }
        if (fade_drops) {
            fade_drops_timer = timer_read();
        }
    }

    if (drops) {
        raindrop(rand() % led_max, params);
    }

    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        uint8_t row = i % MATRIX_ROWS;
        uint8_t col = i / MATRIX_ROWS;
        uint8_t val = g_rgb_frame_buffer[row][col];
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;

        if (i < led_max) {
            uint8_t led = g_led_config.matrix_co[row][col];
            rgb_matrix_set_color(led, f * 85, f * (25 + val), f * 255);
        } else {
            rgb_matrix_set_color(i, f * 85, f * 25, f * 255);
        }
        if (fade_drops) {
            g_rgb_frame_buffer[row][col] = qsub8(val, 1);
        }
    }

    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_CUSTOM_SOLID_RAINDROPS