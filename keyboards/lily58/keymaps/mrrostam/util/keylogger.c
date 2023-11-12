#include <stdio.h>

#include "mrrostam.h"

static const char KEYCODE_TO_NAME[] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'N', 'E', 'B', 'T', 'S', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', 'C'
};

static const uint16_t KEYCODE_TO_NAME_LEN = sizeof(KEYCODE_TO_NAME) / sizeof(KEYCODE_TO_NAME[0]);

static char info_str[15] = {};
static char log_str[5] = {};
static int  log_str_idx = 0;

void mr_keylog_set(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if (keycode < KEYCODE_TO_NAME_LEN) {
        name = KEYCODE_TO_NAME[keycode];
    }

    snprintf(
        info_str,
        sizeof(info_str),
        "r:%d\nc:%d\n%2d", record->event.key.row, record->event.key.col, keycode % 10000);

    if (log_str_idx == sizeof(log_str) - 1) {
        log_str_idx = 0;
        for (int i = 0; i < sizeof(log_str) - 1; i++) {
            log_str[i] = ' ';
        }
    }

    log_str[log_str_idx] = name;
    log_str_idx++;
}

const char *mr_keylog_info_get(void) {
  return info_str;
}

const char *mr_keylog_log_get(void) {
  return log_str;
}
