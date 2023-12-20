// FabricMethod.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Product {
public:
    virtual ~Product() = default;
    virtual std::string getDescription() const = 0;
};

class ConcreteProductA : public Product {
public:
    std::string getDescription() const override {
        return "Concrete Product A";
    }
};

class ConcreteProductB : public Product {
public:
    std::string getDescription() const override {
        return "Concrete Product B";
    }
};

class Creator {
public:
    virtual ~Creator() = default;
    virtual Product* createProduct() const = 0;
};

class ConcreteCreatorA : public Creator {
public:
    Product* createProduct() const override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* createProduct() const override {
        return new ConcreteProductB();
    }
};

int main() {
  
    Creator* creatorA = new ConcreteCreatorA();
    Product* productA = creatorA->createProduct();
    std::cout << "Product A: " << productA->getDescription() << std::endl;

    Creator* creatorB = new ConcreteCreatorB();
    Product* productB = creatorB->createProduct();
    std::cout << "Product B: " << productB->getDescription() << std::endl;

    
    delete creatorA;
    delete productA;
    delete creatorB;
    delete productB;

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
