#include "MIDIUSB.h"

const int NPots = 8;
int potPin[NPots] = {A0, A1, A2, A3, A6, A7, A8, A9};

int potCState[NPots] = {0};
int potPState[NPots] = {0};
int potVar = 0;

int midiCState[NPots] = {0};
int midiPState[NPots] = {0};

int TIMEOUT = 300;
int varThreshold = 10;
boolean potMoving = true; 
unsigned long PTime[NPots] = {0};
unsigned long timer[NPots] = {0};

byte midiCh = 1;
byte cc = 71;

void loop() {
  potentiometers();
}

void setup(){
}

void potentiometers() {

  for (int i = 0; i < NPots; i++) {

    potCState[i] = analogRead(potPin[i]);
    midiCState[i] = map(potCState[i], 0, 1023, 127, 0);
    potVar = abs(potCState[i] - potPState[i]);

    if (potVar > varThreshold) {
      PTime[i] = millis();
    }

    timer[i] = millis() - PTime[i];

    if (timer[i] < TIMEOUT) {
      potMoving = true;
    }
    else {
      potMoving = false;
    }

    if (potMoving == true) {
      if (midiPState[i] != midiCState[i]) {
        controlChange(midiCh, cc + i, midiCState[i]);
        MidiUSB.flush();

        potPState[i] = potCState[i];
        midiPState[i] = midiCState[i];
      }
    }
  }

}

void controlChange(byte channel, byte control, byte value) {
midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
MidiUSB.sendMIDI(event);
}
