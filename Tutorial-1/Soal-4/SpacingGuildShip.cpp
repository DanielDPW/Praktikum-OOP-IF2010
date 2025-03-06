#include "SpacingGuildShip.hpp"
using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;	

SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), guildNavigatorCount(3), serialNum(producedShips + 1) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = 50;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(producedShips + 1) {
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& other) : maxPassengerCap(other.maxPassengerCap), guildNavigatorCount(other.guildNavigatorCount), serialNum(producedShips + 1) {
    this->passengerCount = other.passengerCount;
    this->operatingGuildNavigator = other.operatingGuildNavigator;
    this->spiceStock = other.spiceStock;
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip() {

}

int SpacingGuildShip::getShipSerialNum() const {
    return serialNum;
}

int SpacingGuildShip::getPassengerCount() const {
    return passengerCount;
}

void SpacingGuildShip::travel(float distance) {
    if(operatingGuildNavigator > 0) {
        totalGuildTravel += distance / (E * E * operatingGuildNavigator);
        this->operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers) {
    this->passengerCount = (passengerCount + addedPassengers <= maxPassengerCap) ? passengerCount + addedPassengers : maxPassengerCap;
}

void SpacingGuildShip::dropOff(int droppedPassenger) {
    this->passengerCount = (passengerCount - droppedPassenger > 0) ? passengerCount - droppedPassenger : 0;
}

void SpacingGuildShip::refreshNavigator(int n) {
    if (spiceStock - n * GUILD_NAVIGATOR_SPICE_DOSE >= 0) {
        this->operatingGuildNavigator += n;
        this->spiceStock -= n * GUILD_NAVIGATOR_SPICE_DOSE;
    } else {
        this->operatingGuildNavigator += spiceStock / GUILD_NAVIGATOR_SPICE_DOSE;
        this->spiceStock = spiceStock % GUILD_NAVIGATOR_SPICE_DOSE;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice) {
    this->spiceStock += addedSpice;
}