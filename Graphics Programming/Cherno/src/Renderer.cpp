#include "include/Renderer.h"
#include "include/GLErrorManager.h"

void Renderer::clear() const
{
    GLCall(glClearColor(1.0f, 1.0f, 1.0f, 1.0f));
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const
{
    shader.bind();
    va.bind();
    ib.bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}
