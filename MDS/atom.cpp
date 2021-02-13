#include "atom.hpp"

Atom::Atom(){
    pos_ = std::vector<double>(3);
    vel_ = std::vector<double>(3);
    return;
}

void Atom::SetVel(const double &Vx, const double &Vy, const double &Vz){
    vel_[0] = Vx;
    vel_[1] = Vy;
    vel_[2] = Vz;

    return;
}

std::ostream & operator << (std::ostream &os, const Atom& atom){
    for(int dim=0;dim<3;dim++){
        os << atom.pos_[dim] << "\t" << atom.vel_[dim];
    }
    os << std::endl;

    return os;
}
