#include "lib/the_synth/synth.h"

#define KB_SAMPLES 100
#define PINOUT_AUDIO_OUT CHA
#define PINOUT_POT_ATK A0
#define PINOUT_POT_REL A1
#define PINOUT_POT_WAV A2
#define PINOUT_KB_IN A3

synth bernard;

void setup() {
	// i/o instellen
	pinMode(PINOUT_AUDIO_OUT, OUTPUT);
	pinMode(PINOUT_POT_ATK, INPUT);
	pinMode(PINOUT_POT_WAV, INPUT);
	pinMode(PINOUT_POT_REL, INPUT);
	pinMode(PINOUT_KB_IN, INPUT);

	// the_synth initialiseren
	bernard.begin(PINOUT_AUDIO_OUT);

	// gekopiëerd van een stukje voorbeeldcode, alleen de golfvorm maakt hier uit
	bernard.setupVoice(0,SINE,60,ENVELOPE0,90,64);
	bernard.setupVoice(1,TRIANGLE,62,ENVELOPE1,90,64);
	bernard.setupVoice(2,SAW,64,ENVELOPE2,90,64);
	bernard.setupVoice(3,SQUARE,67,ENVELOPE0,90,64);
}

void loop() {
	// lees potmeters uit
	unsigned int pot_rel = analogRead(PINOUT_POT_REL);
	unsigned int pot_atk = analogRead(PINOUT_POT_ATK);
	unsigned int pot_wav = analogRead(PINOUT_POT_WAV);

	// neem een gemiddelde meting van de keyboard ingangsspanning
	double average = 0.0;
	for (int i = 0; i < KB_SAMPLES; i++)
		average += ((double) analogRead(PINOUT_KB_IN)) / KB_SAMPLES;

	// geplukte getallen om de klank aan te passen
	unsigned char env = pot_rel / (1024/4);
	unsigned char mod = 572 + pot_atk / 100;
	unsigned char wave = pot_wav / (1024/4);

	// synth kiezen / klank bijwerken
	bernard.setEnvelope(wave, env);
	// synth triggeren
	bernard.mTrigger(wave, 116 - average / 10);
	delay(500 - pot_atk / 5);
}
