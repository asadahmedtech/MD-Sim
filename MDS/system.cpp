#include "system.hpp"
#include "atom.hpp"
#include "utils.hpp"

System::System(const int &N, const double &T, const double &M){

    atoms = std::vector<Atom>(N);
    number_of_atoms = N;
    temperature = T;
    mass = M;

    Initialize();
}

void System::Initialize(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);

    std::normal_distribution<double> distribution = utils.RandomGenerator();

    double factor =  sqrt(boltzmann_constant * temperature / mass);

    // Iterate till desired Temperature is attained in the system.
    do{
        //Generate random velocity from normalized distribution using box-muller method and multulply by the factor
        for(int atomIdx=0; atomIdx<number_of_atoms; atomIdx++){
            atoms[atomIdx].SetVel(factor * distribution(generator), factor * distribution(generator), factor * distribution(generator));
            // atoms[atomIdx].SetVel(factor * utils.Distribution(), factor * utils.Distribution(), factor * utils.Distribution());
        }
        
        //Set center of mass velocity to zero
        double sumVx = 0.0, sumVy = 0.0, sumVz = 0.0;
        for(auto &atom: atoms){
            sumVx += atom.vel_[0];
            sumVy += atom.vel_[1];
            sumVz += atom.vel_[2];
        }

        for(auto &atom: atoms){
            atom.vel_[0] -= sumVx/number_of_atoms;
            atom.vel_[1] -= sumVx/number_of_atoms;
            atom.vel_[2] -= sumVx/number_of_atoms;
        }
    }while(!ValidateVelocity());

    if(ValidateVelocity()){
        std::cout<<"Velocity Generated and Validated"<<std::endl;
    }else{
        std::cout<<"Velocity Generation failed"<<std::endl;
    }

    return;
}

bool System::ValidateVelocity(){
    double vrms = 0.0;
    for(auto &atom : atoms){
        vrms += pow(atom.vel_[0], 2) + pow(atom.vel_[1], 2) + pow(atom.vel_[2], 2); 
    }
    double TempFactor = 3*number_of_atoms*boltzmann_constant*temperature/mass;
    std::cout<<"Vrms : "<<sqrt(vrms)<<'\t'<<"RHS : "<<sqrt(TempFactor)<<'\t'<<"Error : "<<abs((TempFactor-vrms)/TempFactor)<<std::endl;

    // Validation Check should be less than 1% error
    if(abs((vrms-TempFactor)/vrms)<0.01)
        return true;

    return false;
}

void System::PrintState(){
    std::cout<<"Number of Atoms : "<<number_of_atoms<<"\t"<<"Temperature : "<<temperature<<std::endl;
    std::cout<<"Configuration of atoms"<<std::endl;
    for(auto &atom : atoms){
        std::cout<<atom<<std::endl;
    }
}