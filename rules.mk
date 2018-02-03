RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = yes
TAP_DANCE_ENABLE = yes

PS2_MOUSE_ENABLE = yes
PS2_USE_INT = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

include $(TMK_DIR)/protocol.mk
