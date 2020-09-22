#include <iostream>

class Date {
private:
	int day, month, year;
public:
	Date() : day(1), month(1), year(1990) { }
	Date(int d, int m, int y) : day(d), month(m), year(y) { }
	void display(const char* x) {
		std::cout << x << ": " << day << "/" << month << "/" << year << std::endl;
	}
	bool checkDate() {
		return day <= 31 && day >= 1 || month <= 12 && month >= 1 || year > 0;
	}
	~Date() { }
};
class Employee {
private:
	char* m_Ho, *m_Ten;
	Date m_Date;
	Date m_Ngayvaolam;
public:
	Employee() : m_Ho(new char[20]), m_Ten(new char[20]), m_Date(), m_Ngayvaolam() { }
	Employee(char* h, char*t, Date d, Date d2) 
		: m_Ho(h), m_Ten(t), m_Date(d), m_Ngayvaolam(d2) { }
	void print() {
		std::cout << "Ten: " << m_Ho << " " << m_Ten << std::endl;
		m_Date.display("Ngay sinh");
		m_Ngayvaolam.display("Ngay vao lam");
	}
	~Employee() {
		free(m_Ho);
		free(m_Ten);
	}
};
int main() {
	Date birth(7, 24, 1949);
	Date hire(3, 12, 1988);

	Employee manager((char*)"Bob", (char*)"Blue", birth, hire);
	manager.print();
	std::cin.get();
}
