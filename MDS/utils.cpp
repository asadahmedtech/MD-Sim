#include "utils.hpp"

Utils::Utils(){}
std::normal_distribution<double> Utils::RandomGenerator(){
    std::normal_distribution<double> distribution (0.0,1.0);
    return distribution;
}