#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>
using std::string;

enum BloodType { A, B, AB, O };
enum Sex { Male, Female };
std::map<std::tuple<BloodType, BloodType>, std::vector<BloodType>>
    bloodTypeInheritance = {
        {{BloodType::O, BloodType::O}, {BloodType::O}},
        {{BloodType::O, BloodType::A}, {BloodType::O, BloodType::A}},
        {{BloodType::O, BloodType::B}, {BloodType::O, BloodType::B}},
        {{BloodType::O, BloodType::AB}, {BloodType::A, BloodType::B}},
        {{BloodType::A, BloodType::A}, {BloodType::O, BloodType::A}},
        {{BloodType::A, BloodType::B},
         {BloodType::O, BloodType::A, BloodType::B, BloodType::AB}},
        {{BloodType::A, BloodType::AB},
         {BloodType::A, BloodType::B, BloodType::AB}},
        {{BloodType::B, BloodType::B}, {BloodType::O, BloodType::B}},
        {{BloodType::B, BloodType::AB},
         {BloodType::A, BloodType::B, BloodType::AB}},
        {{BloodType::AB, BloodType::AB},
         {BloodType::A, BloodType::B, BloodType::AB}}};
std::array<BloodType, 4> bloodTypes = {BloodType::A, BloodType::B, BloodType::O,
                                       BloodType::AB};

BloodType getRandomBloodType(const std::vector<BloodType> &possibleBloodTypes) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<size_t> dist(0, possibleBloodTypes.size() - 1);
  return possibleBloodTypes[dist(gen)];
}

BloodType getRandomBloodType() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 3);
  return bloodTypes[dist(gen)];
}

class Human {
public:
  BloodType bloodType;
  // constructor
  Human(BloodType bloodType);
  Human();
  Human reproduce(Human &partner);
};

class Population {
public:
  int size;
  std::vector<Human> population;
  void addHuman(Human newHuman);
  Population(int populationSize);
  std::map<BloodType, int> getPopulationMap();
};