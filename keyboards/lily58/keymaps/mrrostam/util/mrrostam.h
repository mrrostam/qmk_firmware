#ifndef MRROSTAM_H
#define MRROSTAM_H

#include "action.h"

const char *mr_keylog_info_get(void);
const char *mr_keylog_log_get(void);
void mr_keylog_set(uint16_t keycode, keyrecord_t *record);

void mr_oled_render_layer_state(void);
void mr_oled_render_wpm(void);

const char *mr_wpm_get(void);

bool mr_pomodoro_is_resting(void);
const char* mr_pomodoro_counter_get(void);
const char* mr_pomodoro_state_get(void);
const char* mr_pomodoro_timer_get(void);
void mr_pomodoro_timer_set(uint32_t timer);
void mr_pomodoro_toggle(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data);

void mr_typo_set(uint16_t keycode, keyrecord_t *record);
const char *mr_typo_info_get(void);

#endif
