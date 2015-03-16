#include "player.h"

extern void play_rtttl(Tone* tone1, const char *p, StopWhen callback);

Player::Player(int pin) {
  tone.begin(pin);
}
  
void Player::play(const char* song, StopWhen callback) {
  play_rtttl(&tone, song, callback);
}
