/**
 * sm64bljtrainer-N64 - main_menu.c
 *
 * Copyright 2023, Coby Walters
 *
 * This source code is licensed under the MIT-style license found in the
 * LICENSE.txt file in the root directory of this source tree.
 */

#include "main_menu.h"

static const char *options[] = {
    "BLJ practice",
    "About",
    "Help",
};

static int menu_selection = 0;
static int menu_options = sizeof(options)/sizeof(char*);

void main_menu_tick(game_state_t* game_state, const gamepad_state_t *const gamepad) {
    if (gamepad->A) {
        if (menu_selection == 0) {
            *game_state = PRACTICE_TOOL;
        } else if (menu_selection == 1) {
            *game_state = ABOUT_SCREEN;
        } else if (menu_selection == 2) {
            *game_state = HELP_MENU;
        }
    } else if (gamepad->up) {
        menu_selection = (menu_selection - 1 + menu_options) % menu_options;
    } else if (gamepad->down) {
        menu_selection = (menu_selection + 1) % menu_options;
    }
}

void main_menu_draw() {

    /* Draw title */
    text_set_font(FONT_BOLD);
    text_draw(32, 24, "sm64 blj rhythm trainer", ALIGN_LEFT);

    /* Draw menu options*/
    text_set_font(FONT_MEDIUM);
    for (int i = 0; i < menu_options; i++) {
        int x = 42;
        if (i == menu_selection) {
            text_draw(x - 10, 44 + i*11, ">", ALIGN_LEFT);
        }
        text_draw(x, 44 + i*11, options[i], ALIGN_LEFT);
    }
}