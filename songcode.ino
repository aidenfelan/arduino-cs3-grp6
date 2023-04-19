#include "pitches.h"

// The melody of the "Up" theme song (Married Life)
int melody[] = {
  NOTE_G4, -1, NOTE_G4, NOTE_DS5, NOTE_G5, NOTE_AS4, NOTE_G4, NOTE_FS5,
  NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_AS5, NOTE_G5, NOTE_FS5,
  NOTE_DS5, NOTE_CS5, -1, NOTE_G4, NOTE_DS5, NOTE_G5, NOTE_AS4, NOTE_G4,
  NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_G5, NOTE_AS5, NOTE_G5,
  NOTE_FS5, NOTE_DS5, NOTE_CS5, -1
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  8, 8, 8, 8, 4, 4, 4, 8,
  4, 4, 8, 8, 8, 4, 4, 4,
  2, 8, 8, 8, 4, 4, 4, 8,
  4, 4, 8, 8, 8, 4, 4, 4,
  2, 8
};

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(8);
  }

  delay(2000); // Add a pause between repetitions of the melody
}
