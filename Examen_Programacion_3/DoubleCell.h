#ifndef DOUBLE_CELL_H
#define DOUBLE_CELL_H

class DoubleCell {
public:
    // Default constructor
    DoubleCell(); //un constructor vacio default

    // Constructor with value
    explicit DoubleCell(double value); //un constructor con un valor tipo double

    // Copy constructor
    DoubleCell(const DoubleCell &other); //un constructor copia un other

    //Reference constructor
    DoubleCell(DoubleCell &&other) noexcept; //un constructor referencia un other

    // Destructor
    ~DoubleCell() = default; //el destructor le da valor default

    // Assignment operator by copy
    DoubleCell &operator=(const DoubleCell &other); //operador "=" por copia para DoubleCell

    // Assignment operator by reference
    DoubleCell &operator=(DoubleCell &&other) noexcept; //operador "=" por referencia para DoubleCell

    // Assignment operator for double
    DoubleCell &operator=(double value); //operador "=" para valores double

    // Arithmetic operators

    //constructores para operador "+" (o sumas)
    DoubleCell operator+(const DoubleCell &other) const;
    DoubleCell operator+(const double other) const;

    //constructores para operador "-" (o restas)
    DoubleCell operator-(const DoubleCell &other) const;
    DoubleCell operator-(const double other) const;

    //constructores para operador "*" (o multiplicaciones)
    DoubleCell operator*(const DoubleCell &other) const;
    DoubleCell operator*(const double other) const;

    //constructores para operador "/" (o divisiones)
    DoubleCell operator/(const DoubleCell &other) const;
    DoubleCell operator/(const double other) const;

    // Setters
       void SetValue(double value); //una funcion setValue que recibe como parametro un valor tipo double

    // Getters
       double GetValue() const; //un arreglo de constantes tipo double llamado "getValue"


private:
    double StoredValue; //un valor double llamado "StoredValue"
};

#endif  // DOUBLE_CELL_H
