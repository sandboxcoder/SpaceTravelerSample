module;
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <queue>

export module universe;

export class IPlanet
{
public:
  virtual float getGravity() const = 0;
  virtual bool hasAtmosphere() const = 0;
  virtual float getRadius() const = 0;
};

export class Planet : public IPlanet
{
public:
  Planet(float radius, float gravity, bool hasAtmosphere)
    : _radius(radius)
    , _gravity(gravity)
    , _hasAtmosphere(hasAtmosphere)
  {

  }

  virtual float getGravity() const override
  {
    return _gravity;
  }
  virtual bool hasAtmosphere() const override { return _hasAtmosphere; }
  virtual float getRadius() const override {
    return _radius;
  }

private:
  float _radius;
  bool _hasAtmosphere;
  float _gravity;
};

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
