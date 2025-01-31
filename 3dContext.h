#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#define NUM_VAOS 1

namespace TDC{
	float cameraX, cameraY, cameraZ;
	GLuint mvLoc, projLoc, vLoc, tfLoc;
	glm::mat4 pMat, vMat, mMat, mvMat, tMat, rMat;
	int windowHeigth, windowWidth;
	float aspect;

	int tdcEvents(GLuint *VAO, GLFWwindow* window, GLuint program) {
		getActualFrameSize(window);
		updateUniformVariables(program);
	}

	void updateUniformVariables(GLuint program) {
		mvLoc = glGetUniformLocation(program, "mv_matrix");
		projLoc = glGetUniformLocation(program, "proj_matrix");
		vLoc = glGetUniformLocation(program, "v_matrix");
		tfLoc = glGetUniformLocation(program, "tf");
	}

	void getActualFrameSize(GLFWwindow* window) {
		glfwGetFramebufferSize(window, &windowWidth, &windowHeigth);
		aspect = float(windowWidth) / float(windowHeigth);
	}
}