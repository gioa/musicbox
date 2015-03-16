
#ifndef _PLAYER_H
#define _PLAYER_H

#include <Tone.h>

typedef bool (*StopWhen)();

class Player {
  
  public:
  Player(int pin);
  void play(const char* song, StopWhen callback);
  
  private:
  Tone tone;
};

#endif 
