//
// Created by William Aey on 3/22/2022.
//
#include "tests.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "Renderer.h"
#include "testCreateSquare.h"
test::TestCreateSquare::TestCreateSquare(Renderer* ren)
    :rend(ren),
      va(),
      vb(positions,4*4* sizeof(float)),
      layout(),
      ib(indices,6),
      shader("res/shaders/basic.shader")
{

    layout.Push<float>(2);
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    shader.Bind();
    shader.SetUniform4f("u_Color", 0.0f, 0.3f, 0.8f, 1.0f);
    shader.Unbind();
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
}

test::TestCreateSquare::~TestCreateSquare()
{
}
void test::TestCreateSquare::OnRender()
{
    shader.Bind();
    shader.SetUniform4i("u_Texture",0);
    shader.SetUniform4f("u_Color", 0.5f, 0.3f, 0.8f, 1.0f);
    rend->draw(va, ib, shader);
    shader.Unbind();
}
void test::TestCreateSquare::OnImGuiRender()
{

}
