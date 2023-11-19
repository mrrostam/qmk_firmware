#include <stdio.h>

#include "mrrostam.h"

static uint16_t last_input = 0;
static char info_str[15] = {};
static int typos[60] = {0};

extern const char KEYCODE_TO_NAME[];
extern const uint16_t KEYCODE_TO_NAME_LEN;

void mr_typo_set(uint16_t keycode, keyrecord_t *record) {
    if (keycode > KEYCODE_TO_NAME_LEN) {
        return;
    }

    if (KEYCODE_TO_NAME[keycode] == 'B') {
        typos[last_input]+=1;
    } else {
        last_input = keycode;
    }

}

const char *mr_typo_info_get(void) {
    snprintf(
        info_str,
        sizeof(info_str),
        "%c:%d\n", KEYCODE_TO_NAME[last_input], typos[last_input]);
    return info_str;
}
