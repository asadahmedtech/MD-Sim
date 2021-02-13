#include "system.hpp"

using namespace std;

int main(){
    double Temperature = 298;
    double Mass = 10;
    int NumberOfParticles = 10;

    System system(NumberOfParticles, Temperature, Mass);
    system.PrintState();

    return 0;
}