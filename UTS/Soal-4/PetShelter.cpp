#include "PetShelter.hpp"
#include <iostream>
#include <string>

template class PetShelter<Pet>;

template <typename T>
PetShelter<T>::PetShelter(std::string shelterName) : shelterName(shelterName), dogCapacity(8), catCapacity(12), petCount(0), currentDogs(0), currentCats(0) {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        pets[i] = nullptr;
    }
}

template <typename T>
PetShelter<T>::PetShelter(std::string shelterName, int dogCapacity, int catCapacity) : shelterName(shelterName), dogCapacity(dogCapacity), catCapacity(catCapacity), petCount(0), currentDogs(0), currentCats(0) {
    if (dogCapacity + catCapacity > MAX_SHELTER_CAPACITY) {
        std::cout << "The total capacity you construct is " << dogCapacity + catCapacity << ", meanwhile the shelter capacity is 20" << std::endl;
    }
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        pets[i] = nullptr;
    }
}

template <typename T>
PetShelter<T>::~PetShelter() {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        delete pets[i];
        pets[i] = nullptr;
    }
}

template <typename T>
std::string PetShelter<T>::getShelterName() const {
    return shelterName;
}

template <typename T>
void PetShelter<T>::addPet(const std::string &petName, int age, bool isDog, const std::string &extraInfo) {
    if (petCount >= MAX_SHELTER_CAPACITY) {
        std::cout << "Error: Shelter is at full capacity!" << std::endl;
        return;
    }
    if (isDog && currentDogs >= dogCapacity) {
        std::cout << "Error: No space for more dogs!" << std::endl;
        return;
    }
    if (!isDog && currentCats >= catCapacity) {
        std::cout << "Error: No space for more cats!" << std::endl;
        return;
    }

    int idx = -1;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] == nullptr) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        return;
    }

    Pet* x = nullptr;
    if (isDog) {
        x = new Dog(petName, age, extraInfo);
        x->setId("D" + std::to_string(++currentDogs));
    } else {
        x = new Cat(petName, age, extraInfo);
        x->setId("C" + std::to_string(++currentCats));
    }
    pets[idx] = x;
    petCount++;
    std::cout << "Success: " << petName << " has been added as a " << (isDog ? "Dog" : "Cat") << "! Pet ID: " << x->getId() << std::endl;
}

template <typename T>
T* PetShelter<T>::findPet(const std::string& petID) const {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] != nullptr && pets[i]->getId() == petID) {
            pets[i]->displayInfo();
            return dynamic_cast<T*>(pets[i]);
        }
    }
    std::cout << "Pet ID is invalid!" << std::endl;
    return nullptr;
}

template <typename T>
void PetShelter<T>::listAllPets() const {
    if (petCount == 0) {
        std::cout << "No pets in the shelter yet!" << std::endl;
        return;
    }
    int num = 1;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] != nullptr) {
            std::cout << num++ << ". ";
            pets[i]->displayInfo();
        }
    }
}

template <typename T>
int PetShelter<T>::calculateCost() const {
    return currentDogs * 75 + currentCats * 60;
}

template <typename T>
void PetShelter<T>::removePet(const std::string& petID) {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] != nullptr && pets[i]->getId() == petID) {
            std::string petName = pets[i]->getName();
            if (dynamic_cast<Dog*>(pets[i])) {
            currentDogs--;
            } else if (dynamic_cast<Cat*>(pets[i])) {
            currentCats--;
            }
            delete pets[i];
            pets[i] = nullptr;
            petCount--;
            std::cout << petName << " has been removed from the shelter." << std::endl;
            return;
        }
    }
    std::cout << "Pet ID is invalid!" << std::endl;
}