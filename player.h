
#ifndef _PLAYER_H
#define _PLAYER_H

#include <Tone.h>
#include <Arduino.h>

typedef bool (*StopWhen)(byte);

class Player {
  
  public:
  Player(int pin);
  void play(const char* song, StopWhen callback);
  
  private:
  Tone tone;
};

#endif 
