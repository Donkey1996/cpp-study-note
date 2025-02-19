#include "blood_type.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

Human::Human(BloodType bloodType) { this->bloodType = bloodType; }
Human::Human() { this->bloodType = getRandomBloodType(); }

Human Human::reproduce(Human &partner) {
  Human child(bloodType);
  return child;
}
Population::Population(int size) {
  this->size = size;
  for (auto i = 0; i < size; i++) {
    population.emplace_back(Human());
  }
}
void Population::addHuman(Human human) {
  size += 1;
  population.emplace_back(human);
}

std::map<BloodType, int> Population::getPopulationMap() {
  std::map<BloodType, int> populationMap = {{BloodType::A, 0},
                                            {BloodType::B, 0},
                                            {BloodType::AB, 0},
                                            {BloodType::O, 0}};
  for (auto human : population) {
    auto key = human.bloodType;
    if (populationMap.find(key) != populationMap.end()) {
      populationMap[key] += 1;
    } else {
      continue;
    }
  }
  return populationMap;
}

Human getRandomHumanFromPopulation(Population population) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<size_t> dist(0,
                                             population.population.size() - 1);

  size_t randomIndex = dist(gen);
  Human randomHuman = population.population[randomIndex];
  return randomHuman;
}

void simulate(Population &population1, Population &population2, int epoch) {
  for (int i = 0; i < epoch; i++) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    int randInt = dist(gen);
    Human human1 = getRandomHumanFromPopulation(population1);
    Human human2 = getRandomHumanFromPopulation(population2);
    Human child = human1.reproduce(human2);
    if (randInt == 0) {
      population1.addHuman(child);
    } else {
      population2.addHuman(child);
    }
  }
}

int main() {

  // This is a simulation to see if a population's blood type distribution
  // change after generations Assume initial distribution is uniform.

  Population males(10000);
  Population females(10000);
  int epoch = 10000;
  simulate(males, females, epoch);

  std::map<BloodType, int> malePopulationMap = males.getPopulationMap();
  for (const auto &[key, value] :
       malePopulationMap) // better way to iterate through a std map
  {
    cout << key << ": " << value << endl;
  }

  return 0;
}