#include "player.h"

extern void play_rtttl(Tone* tone1, const char *p);

Player::Player(int pin) {
  tone.begin(pin);
}
  
void Player::play(const char* song) {
  play_rtttl(&tone, song);
}
