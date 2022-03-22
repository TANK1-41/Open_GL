//
// Created by William Aey on 3/22/2022.
//

#pragma once
namespace test{
class TestCreateSquare: public Test{
public:
    TestCreateSquare(Renderer* ren);
    virtual ~TestCreateSquare();
    void OnRender() override;
    void OnImGuiRender();

    VertexArray va;
    VertexBuffer vb;
    VertexBufferLayout layout;
    IndexBuffer ib;
    Shader shader;
private:
    Renderer* rend;
    float positions[16]{
            //first triangle
            -50.f, -50.f, 0.0f, 0.0f,//0
            50.f, -50.f, 1.0f, 0.0f,//1
            50.f, 50.f, 1.0f, 1.0f,//2
            //second triangle

            -50.f, 50.f, 0.0f, 1.0f//3
    };
    unsigned int indices[6]{
            0, 1, 2,//first triangle
            2, 3, 0 //second triangle
    };
    glm::mat4 proj ;
    //camera view
    glm::mat4 view ;
    //model matrix translation used in game loop
    glm::vec3 translationA{200,200,0};
    glm::vec3 translationB{400,200,0};
};

}