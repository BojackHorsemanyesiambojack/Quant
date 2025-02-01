#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define NUM_VAOS 1

namespace TDC {
    float cameraX = 0.0f, cameraY = 0.0f, cameraZ = 5.0f;
    GLuint mvLoc, projLoc, vLoc, tfLoc;
    glm::mat4 pMat, vMat, mMat, mvMat, tMat, rMat;
    int windowHeight, windowWidth;
    float aspect;

    void getActualFrameSize(GLFWwindow* window) {
        glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
        aspect = static_cast<float>(windowWidth) / static_cast<float>(windowHeight);

        pMat = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 100.0f);
    }

    void updateUniformVariables(GLuint program) {
        mvLoc = glGetUniformLocation(program, "mv_matrix");
        projLoc = glGetUniformLocation(program, "proj_matrix");
        vLoc = glGetUniformLocation(program, "v_matrix");
        tfLoc = glGetUniformLocation(program, "tf");

        glUniformMatrix4fv(projLoc, 1, GL_FALSE, &pMat[0][0]);
    }

    void tdcEvents(GLuint* VAO, GLFWwindow* window, GLuint program) {
        getActualFrameSize(window);
        updateUniformVariables(program);
    }
}
