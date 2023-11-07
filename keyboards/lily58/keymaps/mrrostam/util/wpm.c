#include <stdio.h>

#include "wpm.h"

static char wpm_str[12];

const char *mr_wpm_get(void) {
    sprintf(wpm_str, "[WPM]\n%03d ", get_current_wpm());
    return wpm_str;
}
