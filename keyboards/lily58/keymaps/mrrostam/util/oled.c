#include <stdio.h>

#include "action_layer.h"

#include "../layers.h"
#include "mrrostam.h"

static void internal_oled_render_separator(void) {
    oled_write_ln("_____", false);
}

static void internal_oled_render_space(void) {
    oled_write_ln("     ", false);
}

static void internal_oled_render_layer_state(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("[QWR]", false);
            break;
        case _GAMING:
            oled_write("[GME]", false);
            break;
        case _COLEMAK:
            oled_write("[CLM]", false);
            break;
        case _MAC:
            oled_write("[MAC]", false);
            break;
        case _LOWER:
            oled_write("[LWR]", true);
            break;
        case _RAISE:
            oled_write("[RSE]", true);
            break;
        case _ADJUST:
            oled_write("[ADJ]", true);
            break;
        default:
            oled_write("[NOP]", true);
            break;
    }
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    internal_oled_render_layer_state();
    internal_oled_render_separator();
    oled_write_ln(mr_wpm_get(), false);
    internal_oled_render_separator();
    oled_write_ln(mr_keylog_info_get(), false);
    internal_oled_render_space();
    oled_write_ln(mr_keylog_log_get(),  false);
  } else {
    oled_write_ln(mr_pomodoro_state_get(), false);
    internal_oled_render_separator();
    oled_write_ln("[TIM]", false);
    oled_write_ln(mr_pomodoro_timer_get(), false);
    internal_oled_render_space();
    oled_write_ln("[PC]", false);
    oled_write_ln(mr_pomodoro_counter_get(), false);
  }
    return false;
}
