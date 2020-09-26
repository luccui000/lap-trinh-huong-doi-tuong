#include <iostream>
#include <string>

class Date {
private:
	int m_Day, m_Month, m_Year;
public:
	Date() { }
	Date(int d, int m, int y)
		: m_Day(d), m_Month(m), m_Year(y)
	{ }
	void getDate() {
		std::cout << m_Day << "/" << m_Month << "/" << m_Year << std::endl;
	}
};

class ColMbr {
private:
	unsigned m_IdNbr = 0;
	std::string m_Name;
public:
	ColMbr() { } 
	ColMbr(unsigned int id, std::string name) 
		:m_IdNbr(id), m_Name(name)
	{ }
	void setName(const std::string& name) {
		m_Name = name;
	}
	virtual void display() const {
		std::cout << "ID Number: " << m_IdNbr << std::endl;
		std::cout << "Name: " << m_Name << std::endl;
	}
	virtual void addClass(unsigned cred, unsigned quad) {

	}
	~ColMbr() { }
};

class Student : public ColMbr {
private:
	unsigned m_CredHrs;
	unsigned m_QualPts;
	std::string m_DegSought;
	enum DEG { AA,  AS, AAS, UNSPECIFIED};
public:
	Student() 
		: m_CredHrs(0), m_QualPts(0), m_DegSought("Unspecified") 
	{ }
	Student(unsigned id, std::string name) 
		: ColMbr(id, name), m_CredHrs(0), m_QualPts(0), m_DegSought("Unspecified") 
	{ }
	Student(unsigned id, std::string name, unsigned cred, unsigned qua, std::string deg) 
		: ColMbr(id, name), m_CredHrs(cred), m_QualPts(qua), m_DegSought(deg) { }
	void setDegree(std::string deg) {
		m_DegSought = deg;
	}
	void addClass(unsigned cred, unsigned quad) {
		m_CredHrs = cred;
		m_QualPts = quad;
	}
	double getGPA() {
		if (m_CredHrs == 0) return 0;
		return m_QualPts * 1.0 / m_CredHrs;
	}
	void display() {
		ColMbr::display();
		std::cout << "GPA: " << getGPA() << std::endl;
		std::cout << "Degree Sought: " << m_DegSought << std::endl;
	}
};

class Alumni : public ColMbr {
private:
	Date m_DateGrad;
	std::string m_Degree;
public:
	Alumni() { }
	Alumni(unsigned id, std::string name, int d, int m, int y, std::string deg) 
		:ColMbr(id, name), m_DateGrad(d, m, y), m_Degree(deg)
	{ }
	void display() {
		ColMbr::display();
		std::cout << "Date Graduated: ";
		m_DateGrad.getDate();
		std::cout << "\nDegree: " << m_Degree << std::endl;
	}
	void addClass() {

	}
};
int main() {
	ColMbr* cMbr[4];
	int i;
	cMbr[0] = new Student(12345, "Steven DiFranco", 15, 33, "AA");    
	cMbr[1] = new Alumni(98765, "Don Green", 12, 15, 1978, "AAS");     
	cMbr[2] = new Alumni(24680, "Henry Thoreau", 5, 22, 1846, "AA");    
	cMbr[3] = new Student(13579, "Millenia Bes");
	std::cout << "All college members:\n";       
	for(i = 0; i < 4; ++i) {
		cMbr[i]->display();        // no need to check type field or cast       
		std::cout << std::endl;    
	} 
	cMbr[3]->addClass(3, 12);    
	cMbr[3]->display();
	std::cin.get();
}
