module;
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <queue>

export module universe;

import :Planet;

struct ComparePlanetsRadius {
  bool operator()(const std::shared_ptr<Planet>& l, const std::shared_ptr<Planet>& r) {
    return l->getRadius() > r->getRadius();
  }
};

export class Galaxy {
public:
  Galaxy(int queueSize, std::string name)
    : _size(queueSize)
    , _name(name)
  {
  }

  void addPlanet(std::shared_ptr<Planet> planet)
  {
    _planets.push_back(planet);
    _pq.push(planet);
    if (_pq.size() > _size)
    {
      _pq.pop();
    }
  }

  /// <summary>
  /// Destructive operation that will clear the internal queue.
  /// </summary>
  void printKthLargestPlanets()
  {
    while(!_pq.empty()) {
      std::cout << _pq.top()->getRadius() << std::endl;
      _pq.pop();
    }
  }

  size_t getRange()
  {
    size_t d = std::ranges::distance(_planets.begin(), _planets.end());
    return d;
  }

  bool containsSubstring(std::string substring)
  {
    return _name.contains(substring);
  }

private:
  std::vector<std::shared_ptr<Planet>> _planets;
  std::priority_queue<std::shared_ptr<Planet>, std::vector<std::shared_ptr<Planet>>, ComparePlanetsRadius> _pq;
  int _size;
  std::string _name;
};
