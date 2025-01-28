#pragma once
#include <iostream>
#include "Electron.h"
#include "Proton.h"
#include <vector>

using namespace std;

class Atom {
private:
	int atomicNumber;
	vector<Electron> electrons;
	vector<Proton> protons;
public:
	Atom(int atomicNumber) : atomicNumber(atomicNumber) {
		for (int i = 0; i < atomicNumber; i++) {
			electrons.push_back(Electron());
			protons.push_back(Proton());
		}
	}
};