#include "DoubleCell.h"
#include <stdexcept>

// Default constructor
DoubleCell::DoubleCell() : StoredValue(0.0){} //El constructor default inicia con valor 0.0 en StoredValue

// Constructor with value
DoubleCell::DoubleCell(double value) : StoredValue(value) {} //Constructor que recibe un valor tipo double

// Copy constructor
DoubleCell::DoubleCell(const DoubleCell &other) : StoredValue(other.StoredValue) {}

//Reference  constructor
DoubleCell::DoubleCell(DoubleCell &&other) noexcept : StoredValue(other.StoredValue) {
    other.StoredValue = 0.0;
}

// Destructor
//No hace falta destructor en el cpp

// Assignment operator by copy
DoubleCell &DoubleCell::operator=(const DoubleCell &other) {
    if (this != &other) {
        StoredValue = other.StoredValue;
    }
    return *this;
}//Toda esta funcion revisa si el valor es igual al other, para que si no lo es, asignarle al StoredValue el valor de other

// Assignment operator by reference
DoubleCell &DoubleCell::operator=(DoubleCell &&other) noexcept {
    if (this != &other) {
        StoredValue = other.StoredValue;
        other.StoredValue = 0.0;
    }
    return *this;
}//Toda esta funcion revisa si el valor es igual al other, para que si no lo es, asignarle al StoredValue el valor de other, ademas de asignarle el valor 0.0 al valor other (lo pone default)

// Assignment operator for double
DoubleCell &DoubleCell::operator=(double value){
            StoredValue = value;
            return *this;
}//En esta funcion se le asigna el valor double al StoredValue, y regresa el valor de this

// Arithmetic operators

//DoubleCell adding
DoubleCell DoubleCell::operator+(const DoubleCell &other) const {
    return DoubleCell(StoredValue + other.StoredValue);
}//suma el doublecell con el other
//primitive double adding
DoubleCell DoubleCell::operator+(double value) const {
    return DoubleCell(StoredValue + value);
}//suma el doublecell con el valor tipo double

//DoubleCell subtracting
DoubleCell DoubleCell::operator-(const DoubleCell &other) const {
    return DoubleCell(StoredValue - other.StoredValue);
}//resta al doublecell el other
//primitive double subtracting
DoubleCell DoubleCell::operator-(double value) const {
    return DoubleCell(StoredValue - value);
}//resta al doublecell el valor tipo double

//DoubleCell multiplication
DoubleCell DoubleCell::operator*(const DoubleCell& other) const {
    return DoubleCell(StoredValue * other.StoredValue);
}//multiplica el doublecell con el other
//primitive double multiplication
DoubleCell DoubleCell::operator*(double value) const {
    return DoubleCell(StoredValue * value);
}//multiplica el doublecell con el valor tipo double

//DoubleCell division
DoubleCell DoubleCell::operator/(const DoubleCell &other) const {
    if(other.StoredValue == 0.0) {
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(StoredValue / other.StoredValue);
}//divide el doublecell entre el other
//Primitive double division
DoubleCell DoubleCell::operator/(double value) const {
    if(value == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return DoubleCell(StoredValue / value);
}//divide el doublecell entre el valor tipo double

// Setters
void DoubleCell::SetValue(double value) {
            StoredValue = value;
} //asigna el valor tipo double al StoredValue

// Getters
double DoubleCell::GetValue() const {
    return StoredValue;
} //retorna el StoredValue
