AUDIO_ENABLE = no           # Audio output
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
COMMAND_ENABLE = no         # Commands for debug and configuration
CONSOLE_ENABLE = no         # Console for debug
EXTRAKEY_ENABLE = no        # Audio control and System control
MOUSEKEY_ENABLE = no        # Mouse keys
NKRO_ENABLE = no			# NKRO mode enable
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing

CAPS_WORD_ENABLE = yes	  	# Enable caps word
OLED_ENABLE = yes     		# OLED display
WPM_ENABLE = yes   			# WPM Calculation

LTO_ENABLE = yes

SRC += ./keymaps/mrrostam/util/keylogger.c \
       ./keymaps/mrrostam/util/oled.c \
       ./keymaps/mrrostam/util/wpm.c \
       ./keymaps/mrrostam/util/pomodoro.c
