#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello Mujahid", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!"<<std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    float verticesPositions[] = {
           -0.8,-0.4,
            0.0,0.0,
            0.8,-0.4
    };
    unsigned int buffer;
    //Generate buffer
    glGenBuffers(1,&buffer);
    //Select buffer
    glBindBuffer(GL_ARRAY_BUFFER,buffer);
    //fill buffer with data
    glBufferData(GL_ARRAY_BUFFER,6*sizeof(float), verticesPositions,GL_STATIC_DRAW);

    //vertex attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float)*2,(const void*)0);
    /* Loop until the user closes the window */
    while (true)//!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /*
        glBegin(GL_TRIANGLES);
        glVertex2d(-0.1,-0.6);
        glVertex2d(0.0, 0.5);
        glVertex2d(0.1,-0.6);
        glColor3b(127.0,60.0,80.0);
        glTranslatef(0.1,0.0,0.0);
        glEnd();
        */
        //draw call
        glDrawArrays(GL_TRIANGLES,0,3);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}