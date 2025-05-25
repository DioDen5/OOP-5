#include "Player.h"

Player::Player(string nickname, int health, int armor)
    : nickname(nickname), health(health), armor(armor) {}

void Player::Action() {
    cout << nickname << " is ready for action." << endl;
}

void Player::ShowInfo() {
    cout << "Player: " << nickname << ", HP=" << health << ", Armor=" << armor << endl;
}

Terrorist::Terrorist(string nickname, int health, int armor)
    : Player(nickname, health, armor) {}

void Terrorist::Action() {
    cout << nickname << " plants the bomb and shoots." << endl;
}

CounterTerrorist::CounterTerrorist(string nickname, int health, int armor)
    : Player(nickname, health, armor) {}

void CounterTerrorist::Action() {
    cout << nickname << " defuses the bomb and returns fire." << endl;
}

void CounterTerrorist::Defuse(int seconds) {
    cout << nickname << " defuses in " << seconds << "s." << endl;
}

void CounterTerrorist::Defuse(int seconds, bool hasKit) {
    if (hasKit) seconds /= 2;
    cout << nickname << " defuses in " << seconds << "s" << (hasKit ? " (with kit)." : ".") << endl;
}

Leader::Leader(string nickname, string strategy, int health, int armor)
    : Terrorist(nickname, health, armor), strategy(strategy) {}

void Leader::Action() {
    cout << nickname << " commands: " << strategy << "." << endl;
}

Sniper::Sniper(string nickname, int zoom, int health, int armor)
    : Terrorist(nickname, health, armor), zoom(zoom) {}

void Sniper::Action() {
    cout << nickname << " takes a scoped shot (zoom=" << zoom << "x)." << endl;
}

MultiRole::MultiRole(string nickname)
    : Player(nickname, 120, 100), Terrorist(nickname), CounterTerrorist(nickname) {
    cout << "MultiRole constructor: " << nickname << endl;
}

MultiRole::~MultiRole() {
    cout << "MultiRole destructor: " << nickname << endl;
}

void MultiRole::Action() {
    cout << nickname << " performs multi-role operations." << endl;
}
