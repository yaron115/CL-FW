#ifndef CLFW_KBD_H
#define CLFW_KBD_H

#include "../Classes/ControllerStatus.h"
#include "../Classes/Coordinates.h"
#include "../Classes/Modes.h"
#include "../Classes/Pinout.h"
#include "../Logic/DAC.h"
#include "Keyboard.h"

class KBDMode {
public:

    KBDMode(SOCD leftX, SOCD leftY, bool useUpPriority) {
        leftXSOCD = leftX;
        leftYSOCD = leftY;

        prioritizeUp = useUpPriority;

        current_Keymap.up          = 'o';
        current_Keymap.down        = 's';
        current_Keymap.left        = 'a';
        current_Keymap.right       = 'd';
        current_Keymap.modX        = 'w';
        current_Keymap.modY        = ',';
        current_Keymap.start       = KEY_LEFT_SHIFT;
        current_Keymap.select      = 'h';
       // current_Keymap.home        = 'i';
        current_Keymap.a           = 'l';
        current_Keymap.b           = 'u';
        current_Keymap.x           = 'i';
        current_Keymap.y           = 'm';
        current_Keymap.l1          = 'n';
        current_Keymap.r1          = 'k';
        current_Keymap.l2          = KEY_RETURN;
        current_Keymap.r2          = 'j';
        current_Keymap.lightshield = ' ';
        current_Keymap.midshield   = KEY_BACKSPACE;
        current_Keymap.cUp         = '[';
       // current_Keymap.cDown       = 'BS';
        current_Keymap.cLeft       = 'v';
        current_Keymap.cRight      = ']';
    }

    void updateOutput(inputStatus *inputs) {
        digitalHandler(inputs, leftXSOCD, leftYSOCD, prioritizeUp);
    }

    bool prioritizeUp;

    pinout current_Keymap;
    SOCD leftXSOCD, leftYSOCD;
};

#endif