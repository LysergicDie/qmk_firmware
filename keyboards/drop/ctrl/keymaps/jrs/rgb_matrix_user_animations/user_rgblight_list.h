// 08-08-2021 lysergic_die
// Defines rgb color presets used in custom matrix animations
#pragma once

#define _BLANK_ {0, 0, 0}
#define __OFF__ {1, 1, 1}

/*              RGB COLORS             */
#define RGB_CARBON_CREAM 0xFF, 0xFF, 0xC0
#define RGB_CARBON_GRAY 0x8C, 0x8C, 0x8C
#define RGB_CARBON_ORANGE 0xFF, 0x2D, 0x00
#define RGB_AQUA_LIKE 0x0F, 0xFA, 0xD3
#define RGB_INDIGO 0x50, 0x14, 0xFF 
#define RGB_DARK_RED 0xA5, 0x05, 0x05

// 7-char aliases for ledmaps
#define C_CREAM {RGB_CARBON_CREAM}
#define C__GRAY {RGB_CARBON_GRAY}
#define C_ORANG {RGB_CARBON_ORANGE}
#define AQUA_LK {RGB_AQUA_LIKE}
#define INDIGO_ {RGB_INDIGO}
#define DRK_RED {RGB_DARK_RED}

	// for rgblight_list colors
	#define PURPLE_ {RGB_PURPLE}
	#define GOLDROD {RGB_GOLDENROD}

/* TODO         HSV COLORS             */
//#define HSV_CARBON_CREAM 
//#define HSV_CARBON_GRAY 0, 0, 140
//#define HSV_CARBON_ORANGE 8, 255, 255
//#define HSV_AQUA_LIKE