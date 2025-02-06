export module universe;
import std;

import :Planet;

// Returns true if the leftmost planet has the greatest radius
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

  /// <summary>
  /// Returns the range from the beginning of the set to the end.
  /// This function isn't built to be "practical". Added to demonstrate
  /// std::ranges::distance.
  /// </summary>
  /// <returns></returns>
  size_t getRange()
  {
    return std::ranges::distance(_planetSet.begin(), _planetSet.end());
  }

  /// <summary>
  /// Returns the size of this galaxy
  /// </summary>
  /// <returns></returns>
  size_t getSize()
  {
    return _planetSet.size();
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
