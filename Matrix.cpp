#include "Matrix.hpp"
#include <iostream>

using namespace std;
using namespace zich;

//comparison operators
bool Matrix::operator < (const Matrix& other) const{
    return true;
}

bool Matrix::operator > (const Matrix& other) const{
    return true;
}

bool Matrix::operator >= (const Matrix& other) const{
    return true;
}

bool Matrix::operator <= (const Matrix& other) const{
    return true;
}

bool Matrix::operator == (const Matrix& other) const{
    return true;
}

bool Matrix::operator != (const Matrix& other) const{
    return true;
}

//Arithmetic operators
Matrix Matrix::operator + (const Matrix& other) const {
    return Matrix(this->vector_matrix , this->row , this->col);
}
    
Matrix Matrix::operator += (const Matrix& other) const {
    return Matrix(this->vector_matrix , this->row , this->col);
}
    
Matrix Matrix::operator - (const Matrix& other) const {
    return Matrix(this->vector_matrix , this->row , this->col);
}
    
Matrix Matrix::operator -= (const Matrix& other) const {
    return Matrix(this->vector_matrix , this->row , this->col);
}

//unary operators
Matrix Matrix::operator + () const{
    return Matrix(this->vector_matrix , this->row , this->col);
}
    
Matrix Matrix::operator - () const{
    return Matrix(this->vector_matrix , this->row , this->col);
}

//increment operators
Matrix& Matrix::operator ++ (){
    return *this;
}
    
Matrix& Matrix::operator -- (){
    return *this;
}

//friend operators
Matrix zich::operator *=(Matrix& other , double scale){
    return Matrix(other.vector_matrix , other.row , other.col);
}
Matrix zich::operator * (double scale , const Matrix& other){
    return Matrix(other.vector_matrix , other.row , other.col);
}

ostream& zich::operator << (ostream& output, const Matrix& output_matrix){
    return output;
}

istream& zich::operator >> (istream& input , Matrix& input_matrix){
    return input;
}
            
