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
            -0.5f,-0.5f, 0.0f,0.0f, //0
            0.5f,-0.5f,1.0f,0.0f,//1
            0.5f,0.5f, 1.0f,1.0f,//2
            //second triangle

            -0.5f,0.5f, 0.0f,1.0f//3
    };
    unsigned int indices[6]{
            0, 1, 2,//first triangle
            2, 3, 0 //second triangle
    };
};

}