#include "utils.hpp"

Utils::Utils(){
    static std::mt19937 rng(std::random_device{}()); 
    static std::uniform_real_distribution<> runif(0.0, 1.0);
}

std::normal_distribution<double> Utils::RandomGenerator(){
    std::normal_distribution<double> distribution (0.0,1.0);
    return distribution;
}

double Utils::Distribution(){

    constexpr double epsilon = std::numeric_limits<double>::epsilon();
    constexpr double two_pi = 2.0 * M_PI;

    double u1, u2;
    do
    {
        u1 = runif(rng);
        u2 = runif(rng);
    }
    while (u1 <= epsilon);

    auto z  = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);

    return z;
}