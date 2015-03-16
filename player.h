
#ifndef _PLAYER_H
#define _PLAYER_H

#include "Tone.h"

class Player {
  
  public:
  Player(int pin);
  void play(const char* song);
  
  private:
  Tone tone;
};

#endif 
