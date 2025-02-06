import universe;

int main()
{
  Galaxy galaxy("Milky Way");
  galaxy.addPlanet(PlanetGenerator::createPlanet(5.0f, 9.8f, true));
  galaxy.addPlanet(PlanetGenerator::createPlanet(7.0f, 2.8f, true));
  galaxy.addPlanet(PlanetGenerator::createPlanet(2.0f, 1.8f, true));
  galaxy.addPlanet(PlanetGenerator::createPlanet(9.0f, 0.8f, true));
  galaxy.addPlanet(PlanetGenerator::createPlanet(3.0f, 0.8f, true));
  galaxy.addPlanet(PlanetGenerator::createPlanet(1.0f, 0.8f, true));

  galaxy.print();

  std::cout << "Range:" << galaxy.getRange() << " size: " << galaxy.getSize() << std::endl;
  std::cout << "Galaxy name contains " << galaxy.containsSubstring("Milk") << std::endl;


  return 0;
}