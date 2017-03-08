// remember to update credentials.h so the device can connect to your network!

#include <EVShield.h>
#include <EVs_UIModule.h>

void setup1() {
    // ev and uim have already been instantiated, you can just use them now.
    ev.ledSetRGB(0, 0, 0); // ev = EVShield
    ev.bank_a.motorRunRotations(SH_Motor_1, SH_Direction_Forward, SH_Speed_Slow,
                                2, SH_Completion_Wait_For, SH_Next_Action_Float);
    uim.println("setup1"); // uim = UI Module
}

void loop1() {
    // reset to browser when GO is pressed
    if (ev.getButtonState(BTN_GO)) ESP.reset();
    
    // your creative code here
}
