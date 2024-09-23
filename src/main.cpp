import universe;

#include <iostream>

int main()
{
  Galaxy galaxy(3);
  galaxy.addPlanet(std::make_shared<Planet>(5.0f, 9.8f, true));
  galaxy.addPlanet(std::make_shared<Planet>(7.0f, 2.8f, true));
  galaxy.addPlanet(std::make_shared<Planet>(2.0f, 1.8f, true));
  galaxy.addPlanet(std::make_shared<Planet>(9.0f, 0.8f, true));
  galaxy.addPlanet(std::make_shared<Planet>(3.0f, 0.8f, true));
  galaxy.printKthLargestPlanets();
  std::cout << "Range:" << galaxy.getRange() << std::endl;
  return 0;
}