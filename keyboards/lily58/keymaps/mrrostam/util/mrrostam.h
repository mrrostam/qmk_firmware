#include "action.h"
#include "oled_driver.h"

void mr_keylog_set(uint16_t keycode, keyrecord_t *record);
const char *mr_keylog_info_get(void);
const char *mr_keylog_log_get(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation);
void mr_oled_render_layer_state(void);
void mr_oled_render_wpm(void);

const char *mr_wpm_get(void);
