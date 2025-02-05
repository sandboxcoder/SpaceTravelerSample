export module universe;
import std;

import :Planet;

struct ComparePlanetsRadius {
  bool operator()(const std::shared_ptr<IPlanet>& l, const std::shared_ptr<IPlanet>& r) {
    return l->getRadius() > r->getRadius();
  }
};

// C++ 20 method to declare the compartor
auto comparePlanets = [](const std::shared_ptr<IPlanet>& l, const std::shared_ptr<IPlanet>& r) {
  return l->getRadius() > r->getRadius();
  };

export class Galaxy {
public:
  Galaxy(std::string name)
    : _name(name)
  {
  }

  void addPlanet(std::shared_ptr<IPlanet> planet)
  {
    _planetSet.insert(planet);
  }

  /// <summary>
  /// Prints all planets to console.
  /// </summary>
  void print()
  {
    for (auto &planet : _planetSet)
    {
      std::cout << planet->getRadius() << std::endl;
    }
  }

  size_t getRange()
  {
    return std::ranges::distance(_planetSet.begin(), _planetSet.end());
  }

  /// <summary>
  /// Asks this galaxy does its' name contains the substring.
  /// </summary>
  /// <param name="substring"></param>
  /// <returns></returns>
  bool containsSubstring(std::string substring)
  {
    return _name.contains(substring); // Added C++ 23
  }

private:
  std::string _name;
  std::set<std::shared_ptr<IPlanet>, decltype(comparePlanets)> _planetSet; // C++ 20 approach see: https://stackoverflow.com/questions/2620862/using-custom-stdset-comparator
};
