#ifndef CORE_VERTEX_ARRAY_HPP
#define CORE_VERTEX_ARRAY_HPP

#include <memory>

#include <GL/glew.h>

#include "Core/IndexBuffer.hpp"
#include "Core/VertexBuffer.hpp"

namespace Core {
/**
 * I dislike the way `VertexBuffer` and `IndexBuffer` are handled here. This
 * breaks RAII principles
 * TODO: Maybe find an alternative solution
 */
class VertexArray {
public:
    VertexArray();
    VertexArray(const VertexArray &) = delete;

    ~VertexArray();

    VertexArray &operator=(const VertexArray &) = delete;

    void Bind() const;
    void Unbind() const;

    void AddVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer);
    void SetIndexBuffer(std::unique_ptr<IndexBuffer> indexBuffer);

    void DrawTriangles() const;

private:
    GLuint m_ArrayId;

    std::vector<std::unique_ptr<VertexBuffer>> m_VertexBuffers;
    std::unique_ptr<IndexBuffer> m_IndexBuffer;
};
} // namespace Core
#endif
