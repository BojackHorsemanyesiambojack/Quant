#include <iostream>
#include <memory>
#include "Glfw.h"

#define NUM_VAOS 1

class ProgramBuild {
public:
    static bool initProgram() {
        try {
            GLuint VAOs[NUM_VAOS];
            auto program = initGlfw(VAOs);
            std::cout << "[INFO] Program initialized successfully. Starting main loop..." << std::endl;
            getMainLoop(program->getWindow(), program->getProgram());
            std::cout << "[INFO] Program finished." << std::endl;
            glfwTerminate();
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "[ERROR] Initialization failed: " << e.what() << std::endl;
            glfwTerminate();
            return false;
        }
    }

private:
    static void getMainLoop(GLFWwindow* window, GLuint program) {
        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glUseProgram(program);
            glDrawArrays(GL_POINTS, 0, 100);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    static std::unique_ptr<ProgramKit> initGlfw(GLuint* VAOs) {
        if (!glfwInit()) throw std::runtime_error("GLFW initialization failed.");

        GLFWwindow* window = GlfwUtils::createWindow("Quantic Simulator", 800, 600);
        if (!window) throw std::runtime_error("Failed to create GLFW window.");

        GlfwUtils::putOpenGlContext(window);

        GLuint shaderProgram = GlfwUtils::buildProgramShader();
        GlfwUtils::initVertexArrays(VAOs, NUM_VAOS);

        return std::make_unique<ProgramKit>(window, shaderProgram);
    }
};