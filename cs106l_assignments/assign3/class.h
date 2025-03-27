#pragma once

#include <iostream>


#define DEFAULT_HEALTH 20

class Player{
    private:
    std::string id;
    size_t health;

    void relife();

    public:
    Player(std::string id);
    Player();
    const std::string Get_id();
    const int check_health();
    void rename();
    void hit(const int damage);
};