#include QMK_KEYBOARD_H

#include <stdio.h>
#include <string.h>

#define WORK_TIME ((uint32_t)25 * 60 * 1000)
#define REST_TIME ((uint32_t)5 * 60 * 1000)

typedef enum pomo_state {
    _STOPPED,
    _WORK,
    _REST,
} pomo_state;


static bool is_running = false;
static pomo_state state = _STOPPED;
static uint8_t pomo_counter = 0;

static uint32_t pomo_timer = 0;
static uint32_t current_timer = 0;
static uint32_t total_timer = 0;

static char timer_str[15] = {};
static char counter_str[15] = {};


const char* mr_pomodoro_state_get(void) {
    switch (state) {
        case _STOPPED: return "[STP]";
        case _REST: return "[RST]";
        case _WORK: return "[WRK]";
        default: return "[UNK]";
    }
}

bool mr_pomodoro_is_resting(void) {
    return state == _REST;
}

void mr_pomodoro_toggle(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    if (is_running) {
        is_running = false;
        state = _STOPPED;
    } else {
        is_running = true;
        state = _WORK;
        total_timer = WORK_TIME;
        pomo_timer = timer_read32();
    }
}

void mr_pomodoro_timer_set(uint32_t timer) {
    if (is_running) {
        current_timer = timer_elapsed32(timer);
        if (current_timer > total_timer) {
            if (state == _WORK) {
                state = _REST;
                total_timer = REST_TIME;
            } else if (state == _REST) {
                state = _WORK;
                total_timer = WORK_TIME;
                pomo_counter++;
            }

            if (pomo_counter > 4) {
                is_running = false;
                pomo_counter = 0;
                state = _STOPPED;
            }

            pomo_timer = timer_read32();
        }
    }
}

const char* mr_pomodoro_timer_get(void) {
    if (is_running) {
        mr_pomodoro_timer_set(pomo_timer);
        uint32_t remaining = total_timer - current_timer;
        uint32_t minutes = remaining / 60000;
        uint32_t seconds = (remaining % 60000) / 1000;
        snprintf(timer_str, sizeof(timer_str), "%02ld:%02ld", minutes, seconds);
    } else {
        snprintf(timer_str, sizeof(timer_str), "%02d:%02d", 0, 0);
    }
    return timer_str;
}

const char* mr_pomodoro_counter_get(void) {
    snprintf(counter_str, sizeof(counter_str), " %02d", pomo_counter);
    return counter_str;
}
