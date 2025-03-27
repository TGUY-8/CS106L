#include "class.h"


Player::Player(std::string id)
: id{id}, health{DEFAULT_HEALTH} {}

Player::Player()
: id{"Kevin"}, health{DEFAULT_HEALTH} {}

void Player::relife(){
    std::cout << "Back to life!" << std::endl;
    this -> health = DEFAULT_HEALTH / 2;
}


const std::string Player::Get_id(){
    return this->id;
}

const int Player::check_health(){
    return this->health;
}

void Player::rename(){
    std::string& name = this->id;
    name.clear();
    std::cin >> name;
}

void Player::hit(const int damage){
    if (damage <= this->health) this->health -= damage;
    else {
    std::cout << "You are Dead..." << std::endl;
    relife();
    }
}





