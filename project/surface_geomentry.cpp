#include<iostream>
#include<vector>



struct Point3 {
    float x;
    float y;
    float z;

    Point3(int a, int b, int c): x(a), y(b), z(c) {};
};

typedef Point3 Vector3 ;

class Triangle {
public:
    Triangle(const Point3& p0, const Point3& p1, const Point3& p2);
    const Point3& vertex(int i) const;
private:
    Point3 m_vertex[3];
};


// This is a bit unoptimized we have a optimized version of this class IndexedTriangleList
// Note here we are not storing the triangle because this structure of data lets us
// iterate all the vertex easily
class TriangleList{
public:
    std::vector<Point3> m_vertexArray;

    Triangle triangle(int t) const {
        return Triangle(
            m_vertexArray[3*t],
            m_vertexArray[3*t + 1],
            m_vertexArray[3*t +2]);
    }

    int size() const {
        return m_vertexArray.size() / 3;
    }
};


// This is a optimized triangle soup aka triangle list
// its similar to a hash map, where points are stored seprately 
// and a index array store the actual point and refers to the index, in the point 
// array
class IndexedTriangleList {
public:
    std::vector<Point3> m_vertexArray;
    std::vector<int> m_indexArray;
    Triangle triangle(int t) const {
        return Triangle(
            m_vertexArray[m_indexArray[t * 3]],
            m_vertexArray[m_indexArray[t * 3 + 1]],
            m_vertexArray[m_indexArray[t * 3 + 2]]
        );
    }

    int size() const {
        return m_indexArray.size() / 3;
    }

};

class Ray {
public:
    // starting point
    Point3 origin;

    // unit vector
    Vector3 direction;
};

int main() {
    // here the mesh size for 4 tirangels is 3(floats)*4bytes* 3(point) * 4 (tringles) = 144 
    // 144 bytes is requred for a tetrahedron 
    // 36MB for 1 million triangles
    TriangleList mesh;
    IndexedTriangleList indexed_mesh;

    std::vector<Point3>& V(mesh.m_vertexArray);
    std::vector<Point3>& V1(indexed_mesh.m_vertexArray);
    std::vector<int> i(indexed_mesh.m_indexArray);

    V.insert(V.end(), {Point3(1,0,0), Point3(0,1,0), Point3(0,0,1)});
    V.insert(V.end(), {Point3(1,0,0), Point3(0,0,1), Point3(0,0,0)});
    V.insert(V.end(), {Point3(0,0,0), Point3(0,1,0), Point3(1,0,0)});
    V.insert(V.end(), {Point3(0,1,0), Point3(0,1,0), Point3(0,0,1)});
    
    V1.insert(V1.end(), {Point3(1,0,0), Point3(0,1,0), Point3(0,0,1), Point3(0,0,0)});
    i.insert(i.end(), {0, 1, 2});
    i.insert(i.end(), {0, 2, 3});
    i.insert(i.end(), {3, 1, 0});
    i.insert(i.end(), {1, 3, 2});


}
