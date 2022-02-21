#include "lib/the_synth/synth.h"

synth bernard;

void setup() {
  bernard.begin();

  bernard.setupVoice(0,SINE,60,ENVELOPE0,90,64);
  bernard.setupVoice(1,SINE,62,ENVELOPE1,90,64);
  bernard.setupVoice(2,SINE,64,ENVELOPE2,90,64);
  bernard.setupVoice(3,SINE,67,ENVELOPE0,90,64);
}

void loop() {
  bernard.trigger(0);
  delay(1000);
  bernard.trigger(1);
  delay(1000);
  bernard.trigger(2);
  delay(1000);
  bernard.trigger(3);
  delay(1000);
}
