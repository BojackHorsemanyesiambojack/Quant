#pragma once
#include <iostream>
#include "ErrorMessages.h"

class QuantumEntity {
protected:

	double mass;
	double charge;
	double actualVelocity;
	
public:
	QuantumEntity(double mass, double charge) : mass(mass), charge(charge){}
	virtual ~QuantumEntity() {};
	double getMass()const { return mass; }
	double getCharge()const { return charge; }

	double accelerate(double electricCampEnergy) const {
		if (mass == 0) {
			throw new std::invalid_argument(ErrorMessages::MASS_ZERO);
		}
		return std::sqrt((2 * electricCampEnergy) / mass);
	}

	double desacelerate(double stopingValue) const {
		
	}

	virtual void describeAttributes() const {
		std::cout << "Quantum Entity Attributes:" << std::endl;
		std::cout << "Mass = " << mass << " kg" << std::endl;
		std::cout << "Charge = " << charge << " C" << std::endl;
	}
};