#include "lib/the_synth/synth.h"

#define PINOUT_AUDIO_OUT CHA
#define PINOUT_POT_ATK A0
#define PINOUT_POT_REL A1
#define PINOUT_POT_WAV A2
#define PINOUT_KB_IN A3

synth bernard;

const static unsigned int notes[] = {
	751, // f3
	751, // f#3
	744, // g3
	743, // g#3
	736, // a3
	733, // a#3
	730, // b3
	725, // c4
	720, // c#4
	660, // d4
	655, // d#4
	650, // e4
	642, // f4
	635, // f#4
	626, // g4
	610, // g#4
	602, // a4
	595, // a#4
	580, // b4
	550, // c5
};

void setup() {
  pinMode(PINOUT_AUDIO_OUT, OUTPUT);
  bernard.begin(PINOUT_AUDIO_OUT);

  pinMode(PINOUT_POT_ATK, INPUT);
  pinMode(PINOUT_POT_WAV, INPUT);
  pinMode(PINOUT_POT_REL, INPUT);
  pinMode(PINOUT_KB_IN, INPUT);

  bernard.setupVoice(0,SINE,60,ENVELOPE0,90,64);
  bernard.setupVoice(1,TRIANGLE,62,ENVELOPE1,90,64);
  bernard.setupVoice(2,SAW,64,ENVELOPE2,90,64);
  bernard.setupVoice(3,SQUARE,67,ENVELOPE0,90,64);

	Serial.begin(9600);
}

void loop() {
  int samples = 100;
  double average = 0.0;
  for (int i = 0; i < samples; i++) {
    average += ((double) analogRead(PINOUT_KB_IN)) / samples;
  }

  unsigned int pot_rel = analogRead(PINOUT_POT_REL);
  unsigned int pot_atk = analogRead(PINOUT_POT_ATK);
  unsigned int pot_wav = analogRead(PINOUT_POT_WAV);
  unsigned int kb_in = analogRead(PINOUT_KB_IN);
	unsigned char env = pot_rel / (1024/4);
	unsigned char mod = 572 + pot_atk / 100;
	unsigned char wave = pot_wav / (1024/4);
	bernard.setEnvelope(wave, env);
	bernard.mTrigger(wave, 116 - average / 10);
	delay(500 - pot_atk / 5);
}
