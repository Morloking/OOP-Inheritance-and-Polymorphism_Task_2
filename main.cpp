#include <iostream>
#include <string>

class Figure {
public:
	std::string getName() const { return nameF; }
	
	virtual std::string getLengths() const = 0;
	virtual std::string getCorners() const = 0;

	virtual ~Figure() {};
protected:
	Figure(std::string name) :
		nameF(name) {
	}
private:
	std::string nameF{ "Фигура" };
};

class Triangle :
	public Figure {
public:
	Triangle(int l1, int l2, int l3, int c1, int c2, int c3) :       //публичный конструктор для создания объектов обычного треугольника (вызывает протектед конструктор, но с именем треуг)
		Triangle(l1, l2, l3, c1, c2, c3, "Треугольник") {
	}
	std::string getLengths() const override { return "a = " + std::to_string(len1) + " b = " + std::to_string(len2) + " c = " + std::to_string(len3); }
	std::string getCorners() const override { return "A = " + std::to_string(cor1) + " B = " + std::to_string(cor2) + " C = " + std::to_string(cor3); }
protected:
	Triangle(int l1, int l2, int l3, int c1, int c2, int c3, const std::string name) :
		Figure(name) {
		len1 = l1; len2 = l2; len3 = l3;
		cor1 = c1; cor2 = c2; cor3 = c3;
	};

	
protected:
	int len1{ 0 }, len2{ 0 }, len3{ 0 };
	int cor1{ 0 }, cor2{ 0 }, cor3{ 0 };
};

class Quadrangle :
	public Figure {
public:
	Quadrangle(int l1, int l2, int l3, int l4, int c1, int c2, int c3, int c4) :
		Quadrangle(l1, l2, l3, l4, c1, c2, c3, c4, "Четырёхугольник") {
	}
	std::string getLengths() const override { return "a = " + std::to_string(len1) + " b = " + std::to_string(len2) + " c = " + std::to_string(len3) + " d = " + std::to_string(len4); }
	std::string getCorners() const override { return "A = " + std::to_string(cor1) + " B = " + std::to_string(cor2) + " C = " + std::to_string(cor3) + " D = " + std::to_string(cor4); }

protected:
	Quadrangle(int l1, int l2, int l3, int l4, int c1, int c2, int c3, int c4, const std::string name) :
		Figure(name) {
		len1 = l1; len2 = l2; len3 = l3; len4 = l4;
		cor1 = c1; cor2 = c2; cor3 = c3; cor4 = c4;
	}

	protected:
	int len1{ 0 }, len2{ 0 }, len3{ 0 }, len4{ 0 };
	int cor1{ 0 }, cor2{ 0 }, cor3{ 0 }, cor4{ 0 };
};

class RectangularTriangle :
	public Triangle {
public:
	RectangularTriangle(int l1, int l2, int l3, int c1, int c2) :
		Triangle(l1, l2, l3, c1, c2, 90, "Прямоугольный треугольник") {
	}

};

class IsoscelesTriangle :
	public Triangle {
public:
	IsoscelesTriangle(int l1, int l2, int c1, int c2) :
		Triangle(l1, l2, l1, c1, c2, c1, "Равнобедренный треугольник") {
	}
};

class EquilateralTriangle :
	public Triangle {
public:
	EquilateralTriangle(int l1) :
		Triangle(l1, l1, l1, 60, 60, 60, "Равносторонний треугольник") {
	}
};

class Rectangle :
	public Quadrangle {
public:
	Rectangle(int l1, int l2) :
		Quadrangle(l1, l2, l1, l2, 90, 90, 90, 90, "Прямоугольник") {
	}
};

class Square :
	public Quadrangle {
public:
	Square(int l1) :
		Quadrangle(l1, l1, l1, l1, 90, 90, 90, 90, "Квадрат") {
	}
};

class Parallelogram :
	public Quadrangle {
public:
	Parallelogram(int l1, int l2, int c1, int c2) :
		Quadrangle(l1, l2, l1, l2, c1, c2, c1, c2, "Параллелограмм") {
	}
};

class Rhomb :
	public Quadrangle {
public:
	Rhomb(int l1, int c1, int c2) :
		Quadrangle(l1, l1, l1, l1, c1, c2, c1, c2, "Ромб") {
	}
};

void printInfo(Figure* fig) {
	std::cout << fig->getName() << ":\n"
		<< "Стороны: " << fig->getLengths() << "\n"
		<< "Углы: " << fig->getCorners() << "\n\n";
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");

	Triangle triangle(10, 20, 30, 50, 60, 70);
	RectangularTriangle rectTriangle(10, 20, 30, 50, 60);
	IsoscelesTriangle isosTriangle(10, 20, 50, 60);
	EquilateralTriangle eqTriangle(30);

	Quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle rectangle(10, 20);
	Square square(20);
	Parallelogram parallelogram(20, 30, 30, 40);
	Rhomb rhomb(30, 30, 40);

	printInfo(&triangle);
	printInfo(&rectTriangle);
	printInfo(&isosTriangle);
	printInfo(&eqTriangle);

	printInfo(&quad);
	printInfo(&rectangle);
	printInfo(&square);
	printInfo(&parallelogram);
	printInfo(&rhomb);

	return EXIT_SUCCESS;
}
