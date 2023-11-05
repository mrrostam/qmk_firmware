AUDIO_ENABLE = no           # Audio output
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
COMMAND_ENABLE = no         # Commands for debug and configuration
CONSOLE_ENABLE = no         # Console for debug
EXTRAKEY_ENABLE = no        # Audio control and System control
LTO_ENABLE = yes
MOUSEKEY_ENABLE = no        # Mouse keys
NKRO_ENABLE = no
OLED_ENABLE= yes     # OLED display
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
WPM_ENABLE              = yes   # WPM Calculation

CFLAGS                 += -flto
EXTRAFLAGS             += -flto

# SRC += ./lib/keylogger.c
