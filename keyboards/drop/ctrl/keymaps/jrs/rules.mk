# project specific files
SRC += config_led.c

#For platform and packs
ARM_ATSAM = SAMD51J18A
MCU = cortex-m4

# Build Options
#   comment out to disable the options.
#
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
#SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
#MIDI_ENABLE = no            # MIDI support
#UNICODE_ENABLE = no         # Unicode

# RGBLIGHT_ENABLE = no				# Not for MD boards. This is here in case you forget.
COMMAND_ENABLE = no 				# Commands for debug and configuration
# BOOTMAGIC_ENABLE = full			# Virtual DIP switch configuration
# BOOTMAGIC_ENABLE = lite
# AUTO_SHIFT_ENABLE = yes      	# Auto Shift
NKRO_ENABLE = yes           	# USB Nkey Rollover
DYNAMIC_MACRO_ENABLE = yes		# Dynamic macro recording and play
MOUSEKEY_ENABLE = yes			# Enable mouse control keycodes. Increases firmware size.
TAP_DANCE_ENABLE = yes			# Enable tap dance keys
CONSOLE_ENABLE = yes			# Enable debugging console. Increases firmware size.

TERMINAL_ENABLE = yes
EXTRAKEY_ENABLE = yes			# Audio control and System control
# RAW_ENABLE = yes				# Raw HID has not yet been implemented for this keyboard
# COMBO_ENABLE					# Key combo feature
# LEADER_ENABLE					# Enable leader key chording

# Custom RGB matrix handling
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = custom

RGB_MATRIX_CUSTOM_USER = yes