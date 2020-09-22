#include <iostream>
#include <math.h>

class Rectangle {
private:
	unsigned int len, wid;
	static int thisMany;
	char* fillString;
public:
	Rectangle() : len(10), wid(10) {
		fillString = (char*)"";
		const_cast<int&>(thisMany)++;
	}
	Rectangle(unsigned int w, unsigned int l, char *x) : len(l), wid(w), fillString(x) {
		const_cast<int&>(thisMany)++;
	}
	// Thiet lap  chieu rong 
	void setWidth(unsigned int x) {
		this->wid = x;
	}
	// Thiet lap chieu dai
	void setLength(unsigned int l) {
		this->len = l;
	}
	// Lay chieu rong
	unsigned int getWidth() {
		return this->wid;
	}
	// Lay chieu dai
	unsigned int getLength() {
		return this->len;
	}
	char* fill() {
		return fillString;
	}
	// Tinh chu vi 
	unsigned int perimeter() {
		return (wid + len) * 2;
	}
	// Tinh dien tich 
	unsigned int area() {
		return wid * len;
	}
	// Tinh duong cheo
	float diagonal() {
		return sqrt(wid * wid + len * len);
	}
	// Hien thi
	void display() {
		std::cout << "[" << len << " x " << wid << "]\n";
	}
	// Kiem tra co phai la hinh vuong hay khong
	bool isSquare() {
		return len == wid;
	}
	// Ve 
	void draw(char x) {
		std::cout << "\n+++++++++++ Ve +++++++++++\n\n";
		for (int i = 0; i < wid; i++) {
			for (int j = 0; j < len; j++) {
				if (i == 0 || i == wid - 1) {
					std::cout << x << " ";
				}
				else {
					if (j == 0 || j == len - 1)
						std::cout << x << " ";
					else
						std::cout << "  ";
				}
			}
			std::cout << std::endl;
		}
	}
	static int recCounter() {
		return thisMany;
	}
	~Rectangle() {
		const_cast<int&>(thisMany)--;
		std::cout << "Rectangle con lai " << thisMany << std::endl;
	}
};
int Rectangle::thisMany = 0;

int main() {
	Rectangle a(10, 20, (char*)"Hello");
	a.display();
	a.draw('*');

	std::cout << Rectangle::recCounter() << std::endl;
	std::cin.get();
}
