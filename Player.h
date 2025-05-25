#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

class Player {
protected:
    string nickname;
    int health;
    int armor;

public:
    Player(string nickname = "Unknown", int health = 100, int armor = 0);
    virtual void Action();
    void ShowInfo();
    virtual ~Player() {}
};

class Terrorist : public Player {
public:
    Terrorist(string nickname, int health = 100, int armor = 50);
    void Action() override;

    template<typename T>
void ThrowGrenade(T value) {
        if constexpr (is_same<T, int>::value) {
            cout << nickname << " throws " << value << " grenades." << endl;
        } else if constexpr (is_same<T, double>::value) {
            cout << nickname << " throws a grenade with " << value << "% accuracy." << endl;
        } else {
            cout << nickname << " cannot throw grenades of type: " << typeid(T).name() << endl;
        }
    }
};

class CounterTerrorist : public Player {
public:
    CounterTerrorist(string nickname, int health = 100, int armor = 70);
    void Action() override;
    void Defuse(int seconds);
    void Defuse(int seconds, bool hasKit);
};

class Leader : public Terrorist {
private:
    string strategy;
public:
    Leader(string nickname, string strategy, int health = 100, int armor = 50);
    void Action() override;
};

class Sniper : public Terrorist {
private:
    int zoom;
public:
    Sniper(string nickname, int zoom = 8, int health = 90, int armor = 80);
    void Action() override;
};

#endif
