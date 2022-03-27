//
// Created by William Aey on 3/21/2022.
//

#pragma once
#include "tests.h"
#include "texture.h"
#include "vertexBufferLayout.h"
#include "vertexBuffer.h"
#include "memory.h"
namespace test {
    class TestSquares2D : public Test {
    public:
        TestSquares2D();
        ~TestSquares2D() override;

        void OnUpdate(float deltaTime) override;
        void OnRender() override;
        void OnImGuiRender() override;

    private:
        std::unique_ptr<VertexArray> m_VAO;
        std::unique_ptr<VertexBuffer> m_VBO;
        std::unique_ptr<IndexBuffer> m_IBO;
        std::unique_ptr<Shader> m_Shader;
        //math for aspect ratio m_Proj
        //camera view matrix
        glm::mat4 m_Proj,m_View;
        //model matrix translation used in game loop
        glm::vec3 m_TranslationA, m_TranslationB;

    };
}// namespace test