#include <iostream>
#include "ProgramBuild.h"

int main() {
    ProgramBuild program;
    if (!program.initProgram()) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}