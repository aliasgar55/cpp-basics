#include<iostream>
#include<vector>

class Vertex {
    public:
        int x, y, z;
        Vertex(int x, int y, int z):x(x), y(y), z(z) {
        }
        Vertex(const Vertex& vertex): x(vertex.x), y(vertex.y), z(vertex.z)
        {
            std::cout << "Copied!!"<< std::endl;
        }

};
int main() {
    // This is unoptimized code
    std::cout << "unoptimized code" << std::endl;
    std::vector<Vertex> vertices(3, Vertex(1, 2, 3));
    vertices.push_back({1, 2, 3});
    vertices.push_back({1, 2, 3});
    vertices.push_back({2, 2, 3});

    // this is optimized code
    std::cout << "optimized code" << std::endl;
    std::vector<Vertex> vertices1;
    vertices1.reserve(3);
    vertices1.emplace_back(1, 2, 3);
    vertices1.emplace_back(1, 2, 3);
    vertices1.emplace_back(1, 2, 3);
}


