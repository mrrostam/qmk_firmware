#include <stdio.h>

#include "action_layer.h"
#include "oled_driver.h"

#include "../layers.h"
#include "mrrostam.h"

static void internal_oled_render_separator(void) {
    oled_write_ln("_____", false);
}

static void internal_oled_render_space(void) {
    oled_write_ln("     ", false);
}

static void internal_oled_render_default_layer_state(void) {
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
        default:
            oled_write("[NOP]", true);
            break;
    }
}

static void internal_oled_render_active_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write("[TYP]", false);
            break;
        case _NAV:
            oled_write("[NAV]", true);
            break;
        case _SYM:
            oled_write("[SYM]", true);
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
    internal_oled_render_default_layer_state();
    internal_oled_render_active_layer_state();
    internal_oled_render_separator();
    oled_write_ln(mr_wpm_get(), false);
    internal_oled_render_separator();
    oled_write_ln(mr_keylog_info_get(), false);
    oled_write_ln(mr_keylog_log_get(),  false);
  } else {
    oled_write(mr_pomodoro_state_get(), mr_pomodoro_is_resting());
    internal_oled_render_separator();
    oled_write("[TIM]", false);
    oled_write(mr_pomodoro_timer_get(), mr_pomodoro_is_resting());
    internal_oled_render_space();
    oled_write("[PC] ", false);
    oled_write_ln(mr_pomodoro_counter_get(), false);
  }
    return false;
}
