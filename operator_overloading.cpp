#include <iostream>

struct Vector2 {
    float x, y;
    Vector2(float x, float y): x(x), y(y) {}
    Vector2 Add(const Vector2& other) const {
        return Vector2(x+other.x, y+ other.y); 
    }

    Vector2 operator+(const Vector2& other) const {
        return Add(other);
    }

    Vector2 Multiply(const Vector2& other) const {
        return Vector2(x * other.x, y * other.y); 
    }

    Vector2 operator*(const Vector2& other) const {
        return Multiply(other); 
    }


};

std::ostream& operator<<(std::ostream& stream, Vector2& other) { 
    stream << "x: " << other.x << ", " << "y: " <<other.y;
    return stream;
}

int main() {
    Vector2 position(0.1f, 0.2f);
    Vector2 speed(0.1f , 0.2f);
    Vector2 powerup (0.5f, 1.1f);

    Vector2 res = position.Add(speed.Multiply(powerup));
    Vector2 res2 = position + speed * powerup;
    //std::cout << res.x << res.y << std::endl;
    //std::cout << res2.x << res2.y << std::endl;
    std::cout << res << std::endl;
    std::cout << res2 << std::endl;


}
