#include <stdio.h>

#include "action_layer.h"

#include "../layers.h"
#include "mrrostam.h"

void internal_oled_render_separator(void) {
    oled_write_ln("_____", false);
}

void internal_oled_render_space(void) {
    oled_write_ln("     ", false);
}

void my_oled_render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
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
    my_oled_render_layer_state();
    internal_oled_render_separator();
    oled_write_ln(mr_keylog_info_get(), false);
    internal_oled_render_space();
    oled_write_ln(mr_keylog_log_get(),  false);
    internal_oled_render_separator();
    oled_write_ln(mr_wpm_get(), false);
  } else {
    // oled_write_ln(read_host_led_state(), false);
    // oled_render_separator();
    // oled_write_ln(read_mode_icon(true), false);
    // oled_render_separator();
    // oled_write_ln(read_mode_icon(false), false);
  }
    return false;
}
// #include QMK_KEYBOARD_H

// #include "layers.h"
// #include <stdio.h>
// #include "host.h"

// char host_led_state_str[24];
// char wpm_str[12];

// #ifdef OLED_ENABLE
// /* char hsv_str[18]; */
// /* char mod_str[12]; */
// /* char keylog_str[24] = {}; */
// /* uint16_t wpm_graph_timer = 0; */
// /* static uint32_t oled_timer = 0; */


// // When you add source files to SRC in rules.mk, you can use functions.
// const char *read_layer_state(void);
// const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// // const char *read_host_led_state(void);
// // void set_timelog(void);
// // const char *read_timelog(void);

// void my_oled_render_layer_state(void) {
//     switch (get_highest_layer(layer_state)) {
//         case _QWERTY:
//             oled_write("[QWR]", false);
//             break;
//         case _GAMING:
//             oled_write("[GME]", false);
//             break;
//         case _COLEMAK:
//             oled_write("[CLM]", false);
//             break;
//         case _MAC:
//             oled_write("[MAC]", false);
//             break;
//         case _LOWER:
//             oled_write("[LWR]", true);
//             break;
//         case _RAISE:
//             oled_write("[RSE]", true);
//             break;
//         case _ADJUST:
//             oled_write("[ADJ]", true);
//             break;
//         default:
//             oled_write("[NOP]", true);
//             break;
//     }
// }

// void oled_render_wpm(void) {
//     sprintf(
//         wpm_str,
//          "[WPM]\n%03d ",
//          get_current_wpm());
//     oled_write(wpm_str, false);
// }

// const char *read_host_led_state(void)
// {
//   led_t led_state = host_keyboard_led_state();
//   snprintf(
//     host_led_state_str,
//     sizeof(host_led_state_str),
//     "N:%s\nC:%s\nS:%s",
//            led_state.num_lock ? "on" : "- ",
//            led_state.caps_lock ? "on" : "- ",
//            led_state.scroll_lock ? "on" : "- ");

//   return host_led_state_str;
// }

