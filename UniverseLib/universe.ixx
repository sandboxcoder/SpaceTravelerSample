export module universe;
import std;

import :Planet;

struct ComparePlanetsRadius {
  bool operator()(const std::shared_ptr<IPlanet>& l, const std::shared_ptr<IPlanet>& r) {
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

  void addPlanet(std::shared_ptr<IPlanet> planet)
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
  std::vector<std::shared_ptr<IPlanet>> _planets;
  std::priority_queue<std::shared_ptr<IPlanet>, std::vector<std::shared_ptr<IPlanet>>, ComparePlanetsRadius> _pq;
  int _size;
  std::string _name;
};
