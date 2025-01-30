export module universe:Planet;

import std;
import <cassert>;

export class IPlanet
{
public:
  virtual float getGravity() const = 0;
  virtual bool hasAtmosphere() const = 0;
  virtual float getRadius() const = 0;
};

class Planet : public IPlanet
{
public:
  Planet(float radius, float gravity, bool hasAtmosphere)
    : _radius(radius)
    , _gravity(gravity)
    , _hasAtmosphere(hasAtmosphere)
  {
    assert(radius > 0.0f);
    _radius = std::max(_radius, 0.01f); // We do not allow zero or negative radius
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

export class PlanetGenerator
{
public:
  static std::shared_ptr<IPlanet> createPlanet(float radius, float gravity, bool hasAtmosphere)
  {
    return std::make_shared<Planet>(radius, gravity, hasAtmosphere);
  }
};