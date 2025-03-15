#include "FirePokemon.hpp"
#include "WaterPokemon.hpp"
#include "GrassPokemon.hpp"


int main() {
    FirePokemon* f1 = new FirePokemon("Charmander");
    new (f1) FirePokemon(*f1);
    WaterPokemon* w1 = new WaterPokemon("Squirtle", 100, 20, 10);
    w1->heal(10);
    new WaterPokemon("Magikarp");
    *w1 = *w1;
    w1->attack(*f1);
    w1->attack(*f1);
    delete f1;
    delete w1;
    return 0;
}