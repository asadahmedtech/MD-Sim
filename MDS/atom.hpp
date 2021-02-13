#ifndef ATOM_HPP
#define ATOM_HPP

#include <iostream>
#include <vector>

/**
 * \brief   Atom object for molecular dynamics simulation
 * \details Describes the propoerties of each atom with its position and velocity.
 */

class Atom {
  public:    
    std::vector<double> pos_, vel_;

    Atom();
    void SetVel(const double&, const double&, const double&);
    friend std::ostream & operator << (std::ostream &out, const Atom &atom); 
};

#endif