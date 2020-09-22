#include <iostream>
#include <math.h>

class Rectangle {
private:
	unsigned int len, wid;
public:
	Rectangle() : len(10), wid(10) {}
	Rectangle(unsigned int w, unsigned int l) : len(l), wid(w) { }
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
					if(j == 0 || j == len - 1) 
						std::cout << x << " ";
					else 
						std::cout << "  ";
				}
			}
			std::cout << std::endl;
		}
	}
};
int main() {
	Rectangle a(10, 20);
	a.display();
	a.draw('*');
	std::cin.get();
}