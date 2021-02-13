#include "system.hpp"

using namespace std;

int main(){
    double Temperature = 298;
    double Mass = 39.948;
    int NumberOfParticles = 1000;

    System system(NumberOfParticles, Temperature, Mass);
    // system.PrintState();

    return 0;
}