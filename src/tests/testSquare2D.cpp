//
// Created by William Aey on 3/21/2022.
//

#include "testSquare2D.h"
#include "Renderer.h"
#include "imgui/imgui.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace test {


    TestSquares2D::TestSquares2D()
        : m_Proj(glm::ortho(0.f, 960.f, 0.f, 540.f, -1.0f, 1.0f)),m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0,0,0))),
          m_TranslationA(200,200,0), m_TranslationB(400,200,0)
    {

        float positions[] = {
                //first triangle
                -50.f, -50.f, 0.0f, 0.0f,//0
                50.f, -50.f, 1.0f, 0.0f,//1
                50.f, 50.f, 1.0f, 1.0f,//2
                //second triangle

                -50.f, 50.f, 0.0f, 1.0f//3

        };

        unsigned int indices[]{
                0, 1, 2,//first triangle
                2, 3, 0 //second triangle
        };

        //enables blending for textures
        GLCall(glEnable(GL_BLEND));
        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

        //heaps allocates
        m_Shader = std::make_unique<Shader>("res/shaders/color.shader");
        m_VAO = std::make_unique<VertexArray>();
        m_IBO = std::make_unique<IndexBuffer>(indices, 6);
        m_VBO = std::make_unique<VertexBuffer>(positions, 4 * 4 * sizeof(float));

        //vertex buffer layout
        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        m_VAO->AddBuffer(*m_VBO, layout);



        m_Shader->Bind();
        m_Shader->SetUniform4f("u_Color", 0.0f, 0.5f, 0.5f, 1.0f);
    }

    TestSquares2D::~TestSquares2D()
    {
    }

    void TestSquares2D::OnUpdate(float deltaTime)
    {
    }

    void TestSquares2D::OnRender()
    {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
        Renderer renderer;
        m_Shader->Bind();
        {
            //model matrixA
            glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationA);
            glm::mat4 mvp = m_Proj * m_View * model;
            m_Shader->SetUniformMat4f("u_MVP", mvp);
            renderer.draw(*m_VAO, *m_IBO,*m_Shader);
        }

        {
            //model matrixB
            glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationB);
            glm::mat4 mvp = m_Proj * m_View * model;
            m_Shader->SetUniformMat4f("u_MVP", mvp);
            renderer.draw(*m_VAO, *m_IBO, *m_Shader);
        }


    }

    void TestSquares2D::OnImGuiRender()
    {
        ImGui::Text("Test colored square 2D");
        ImGui::SliderFloat3("translationA", &m_TranslationA.x, 0.0f, 960.f);
        ImGui::SliderFloat3("translationB", &m_TranslationB.x, 0.0f, 960.f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    }
}// namespace test