#pragma once
#include <iostream>
#include "QuantumEntity.h"

class Proton : public QuantumEntity {
public:
	Proton() : QuantumEntity(1.6726219e-27, 1.60217662e-19) {};
};