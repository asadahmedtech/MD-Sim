#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

#include "atom.hpp"
#include "utils.hpp"
/**
 * \brief   Inititalizes the propoerties of the system.
 * \details System
 */
class System {
  private:
    std::vector<Atom> atoms;
    int number_of_atoms;
    double temperature, mass;

    constexpr static double boltzmann_constant = 1.3806503e-23;

    Utils utils;

  public:
  
    System(const int &N, const double &T, const double &M);
    void Initialize();
    void PrintState();
    bool ValidateVelocity();
};



#endif