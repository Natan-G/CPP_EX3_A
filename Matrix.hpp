#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace zich{

    class Matrix{
        
        vector <double> vector_matrix;
        int row;
        int col;

        public:

            //constructor
            Matrix(vector<double> vector_matrix,int row,int col) : vector_matrix(vector_matrix),row(row) , col(col){} 

            //deconstructor
            ~Matrix(){}

            int getRow() const{
                return this->row;
            }

            int getCol() const{
                return this->col;
            }

            vector <double>& get_vector_matrix(){
                return this->vector_matrix;
            }


            //comparison operators
            bool operator < (const Matrix& other) const;
            bool operator > (const Matrix& other) const;
            bool operator >= (const Matrix& other) const;
            bool operator <= (const Matrix& other) const;
            bool operator == (const Matrix& other) const;
            bool operator != (const Matrix& other) const;

            //Arithmetic operators
            Matrix operator + (const Matrix& other)const;
            Matrix operator += (const Matrix& other) const;
            Matrix operator - (const Matrix& other) const;
            Matrix operator -= (const Matrix& other) const;            

            //unary operators
            Matrix operator + () const;
            Matrix operator - () const;

            //increment operators
            Matrix& operator ++ ();
            Matrix& operator -- ();


            //friend operators
            friend Matrix operator *= (Matrix& other , double scale);
            friend Matrix operator * (double scale , const Matrix& other);
            friend ostream& operator << (std::ostream& output, const Matrix& output_matrix);
            friend istream& operator >> (std::istream& input , Matrix& input_matrix);
            




    };



}