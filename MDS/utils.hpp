#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <random>

/**
 * \brief   Utils object for helper functions
 * \details Describes the propoerties of each atom with its position and velocity.
 */

class Utils {
  public:    
    
    Utils();
    std::normal_distribution<double> RandomGenerator();
};

#endif