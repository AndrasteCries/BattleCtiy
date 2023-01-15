#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int g_windowHeight = 480;
int g_windowWidth = 640;

void glWidowSizeCallback(GLFWwindow* pWindow, int width, int height);

void glKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int node);

int main(void) {

    /* Initialize the library */
    if (!glfwInit()) {
        std::cout << "GLFW TROUBLE" << std::endl;
        int a;
        std::cin >> a;
        return -1;
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pWindow = glfwCreateWindow(g_windowWidth, g_windowHeight, "Battle City", nullptr, nullptr);
    if (!pWindow){
        std::cout << "WINDOW TROUBLE" << std::endl;
        glfwTerminate();
        int a;
        std::cin >> a;
        return -1;
    }

    glfwSetWindowSizeCallback(pWindow, glWidowSizeCallback);
    glfwSetKeyCallback(pWindow, glKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);

    if (!gladLoadGL()) {
        std::cout << "GLAD TROUBLE" << std::endl;
        int a;
        std::cin >> a;
        return -1;
    }

    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    

	glClearColor(0, 1, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow)){
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void glWidowSizeCallback(GLFWwindow* pWindow, int width, int height) {

    g_windowHeight = height;
    g_windowWidth = width;
    glViewport(0, 0, g_windowWidth, g_windowHeight);    

}

void glKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int node) {
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, true);
    }
    else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        g_windowHeight += 100;
        g_windowWidth += 100;
        glWidowSizeCallback(pWindow, g_windowHeight, g_windowWidth);
        std::cout << "hey!" << std::endl;
    }

}