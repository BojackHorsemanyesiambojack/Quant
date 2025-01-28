#pragma once
#include <iostream>
#include "QuantumEntity.h"

class Electron : public QuantumEntity
{
public:
	Electron() : QuantumEntity(9.10938356e-31, 1.60217662e-19){}
};

