#include <iostream>

class Point3d {
private:
    int m_x {};
    int m_y {};
    int m_z {};

public:
    // Public member function that allows to set values for m_x, m_y, and m_z.
    void setValues(int x, int y, int z) {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    // Public member function that prints the Point in the following format: <m_x, m_y, m_z>
    void print() const {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">";
    }

    // Public member function that compares two objects of the class Point3d
    bool isEqual (Point3d& newPoint) const {
        return (m_x == newPoint.m_x) && (m_y == newPoint.m_y) && (m_z == newPoint.m_z);
    }
};

int main()
{
	Point3d point1{};
	point1.setValues(1, 2, 3);
    point1.print();
    std::cout << '\n';

	Point3d point2{};
	point2.setValues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

	return 0;
}
