#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace zich;


Matrix generate_class_positive_matrix(int row , int col , double start_value){
    vector <double> vec;
    
    for(int i=0 ; i< (row*col) ; i++){
        vec.push_back(start_value);
        start_value+=1;
    }
    return Matrix(vec , row , col);
}

Matrix generate_class_negetive_matrix(int row , int col , double start_value){
    vector <double> vec;
    
    for(int i=0 ; i< (row*col) ; i++){
        vec.push_back(start_value);
        start_value-=1;
    }
    return Matrix(vec , row , col);
}

TEST_CASE("check constructor"){
    vector <double> vec;

    //check n=m and even or odd , check n!=m even or odd 
    CHECK_NOTHROW(Matrix(vec , 4 , 4));
    CHECK_NOTHROW(Matrix(vec , 5 , 5));
    CHECK_NOTHROW(Matrix(vec , 3 , 5));
    CHECK_NOTHROW(Matrix(vec , 5 , 3));
    CHECK_NOTHROW(Matrix(vec , 3 , 4));
    CHECK_NOTHROW(Matrix(vec , 4 , 3));
}

TEST_CASE("comparison operators"){

    SUBCASE("< operator"){

        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 0);
        Matrix matrix_b = generate_class_positive_matrix(3 , 3 , 1);
        Matrix matrix_c = generate_class_positive_matrix(3 , 4 , 1);

        CHECK_THROWS(bool ans = (matrix_a < matrix_c)); 
        
        CHECK_EQ(matrix_a < matrix_b , true);
        matrix_a.get_vector_matrix().at(8)=77;
        CHECK_EQ(matrix_a < matrix_b , false);
    }

    SUBCASE("> operator"){
        
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 1);
        Matrix matrix_b = generate_class_positive_matrix(3 , 3 , 0);
        Matrix matrix_c = generate_class_positive_matrix(3 , 4 , 1);

        CHECK_THROWS(bool ans = (matrix_a < matrix_c)); 

        CHECK_EQ(matrix_a > matrix_b , true);
        matrix_a.get_vector_matrix().at(8)=0;
        CHECK_EQ(matrix_a > matrix_b , false); 
    }


    SUBCASE("<= operator"){
        
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 0);
        Matrix matrix_b = generate_class_positive_matrix(3 , 3 , 1);
        Matrix matrix_c = generate_class_positive_matrix(3 , 4 , 1);


        CHECK_THROWS(bool ans = (matrix_a < matrix_c));      

        CHECK_EQ(matrix_a <= matrix_b , true);

        matrix_a.get_vector_matrix().at(0)=1;
        CHECK_EQ(matrix_a <= matrix_b , true);
        matrix_a.get_vector_matrix().at(8)=77;
        CHECK_EQ (matrix_a <= matrix_b , false);
    }
    
     SUBCASE(">= operator"){
        
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 1);
        Matrix matrix_b = generate_class_positive_matrix(3 , 3 , 0);
        Matrix matrix_c = generate_class_positive_matrix(3 , 4 , 1);

        CHECK_THROWS(bool ans = (matrix_a >= matrix_c));
        
        CHECK_EQ(matrix_a >= matrix_b , true);

        matrix_b.get_vector_matrix().at(0) =1;
        CHECK_EQ(matrix_a >= matrix_b , true);

        matrix_a.get_vector_matrix().at(8) = -1;
        CHECK_EQ (matrix_a >= matrix_b , false);
    }

    SUBCASE("operator =="){
        
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 0);
        Matrix matrix_b = generate_class_positive_matrix(3 , 3 , 0);
        Matrix matrix_c = generate_class_positive_matrix(3 , 4 , 1);

        CHECK_THROWS(bool ans = (matrix_a == matrix_c));

        CHECK_EQ(matrix_a == matrix_b , true);
        matrix_a.get_vector_matrix().at(8) = -1;
        CHECK_EQ (matrix_a >= matrix_b , false);       
    }

    
    SUBCASE("operator !="){
        
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 1);
        Matrix matrix_b = generate_class_positive_matrix(3 , 3 , 0);
        Matrix matrix_c = generate_class_positive_matrix(3 , 4 , 1);

        CHECK_THROWS(bool ans = (matrix_a != matrix_c));
        
        CHECK_EQ(matrix_a != matrix_b , true);
        
        matrix_a.get_vector_matrix().at(0) = 0;
        CHECK_EQ(matrix_a != matrix_b , false);
    }
}

TEST_CASE("Arithmetic operators"){

    SUBCASE("operator +"){
    
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 1.1);
        Matrix matrix_b = generate_class_negetive_matrix(3 , 3 , -1.1);
        Matrix matrix_c = generate_class_positive_matrix(3 , 4 , 1);
      
        CHECK_THROWS(matrix_a + matrix_c);

        Matrix matrix_ans = matrix_a+matrix_b;

        //check that all indexs=0 and index of matrix a = index of matrix b
        for(size_t i=0 ; i<matrix_a.get_vector_matrix().size() ; i++){
            CHECK(matrix_a.get_vector_matrix().at(i) != matrix_b.get_vector_matrix().at(i));
            CHECK(matrix_ans.get_vector_matrix().at(i)==0);
        }
    }

    SUBCASE("operator -"){
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 1.1);
        Matrix matrix_b = generate_class_positive_matrix(3 , 3 , 1.1);
        Matrix matrix_c = generate_class_positive_matrix(3 , 4 , 1);
        
        CHECK_THROWS(matrix_a + matrix_c);

        Matrix matrix_ans = matrix_a - matrix_b;

        for(size_t i =0 ; i<matrix_ans.get_vector_matrix().size() ; i++){
            CHECK(matrix_a.get_vector_matrix().at(i) == matrix_b.get_vector_matrix().at(i));
            CHECK(matrix_ans.get_vector_matrix().at(i)==0);
        }
    }

    SUBCASE("operator +="){

        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 1.1);
        Matrix matrix_b = generate_class_negetive_matrix(3 , 3 , -1.1);
        Matrix matrix_c = generate_class_positive_matrix(3 , 4 , 1);
      
        CHECK_THROWS(matrix_a + matrix_c);
        
        matrix_a += matrix_b;
        double start=1.1;

        for(size_t i=0 ; i<matrix_a.get_vector_matrix().size() ; i++){
            CHECK(matrix_a.get_vector_matrix().at(i) != start);//check that a change
            CHECK(matrix_a.get_vector_matrix().at(i)==0);//check that index of  matrix a is 0
            start+=1;
        }

    }

    SUBCASE("operator -="){
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 1.1);
        Matrix matrix_b = generate_class_positive_matrix(3 , 3 , 1.1);
        Matrix matrix_c = generate_class_positive_matrix(3 , 4 , 1);
        
        CHECK_THROWS(matrix_a + matrix_c);

        matrix_a -= matrix_b;
        double start = 1.1;

        for(size_t i =0 ; i<matrix_a.get_vector_matrix().size() ; i++){
            CHECK(matrix_a.get_vector_matrix().at(i) != 1.1);//check that a change
            CHECK(matrix_a.get_vector_matrix().at(i)==0);//check that index of  matrix a is 0
            start+=1;
        }
    }
}

TEST_CASE("unary operators"){

    SUBCASE("operator +"){
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 1.1);
        Matrix same_a = +matrix_a;
        
        for(size_t i=0 ; i < same_a.get_vector_matrix().size() ; i++){
            CHECK(same_a.get_vector_matrix().at(i) == matrix_a.get_vector_matrix().at(i));
        }
    }

    SUBCASE("operator -"){
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 1.1);
        Matrix same_a = -matrix_a;
        
        //check that - operator are correct and dosent change matrix_a!!!!!
        for(size_t i=0 ; i < same_a.get_vector_matrix().size() ; i++){
            CHECK(same_a.get_vector_matrix().at(i) == -(matrix_a.get_vector_matrix().at(i)));
            
        }
    }    
}

TEST_CASE("increment operators"){
    //check that operator++ correct and matrix_a has change!!!
    SUBCASE("operator ++"){
        Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 0);
        ++matrix_a;
        double start=0 ;
        for(size_t i=0 ; i < matrix_a.get_vector_matrix().size() ; i++ ){
            CHECK(matrix_a.get_vector_matrix().at(i)==start);
            start+=1;
        }
    }

    //check that operator-- correct and matrix_a has change!!!
    SUBCASE("operator --"){
        Matrix matrix_a = generate_class_negetive_matrix(3 , 3 , 0);
        --matrix_a;
        double start=0 ;
        for(size_t i=0 ; i < matrix_a.get_vector_matrix().size() ; i++ ){
            CHECK(matrix_a.get_vector_matrix().at(i)==start);
            start-=1;
        }
    }
}

TEST_CASE("operator *"){
    Matrix matrix_a = generate_class_positive_matrix(3 , 3 , 1.2);
    Matrix matrix_b = 2.1 * matrix_a;
    //check that have the same row and cols
    bool flag = (matrix_a.getRow() == matrix_b.getRow() && matrix_a.getCol() == matrix_b.getCol());
    CHECK(flag==true);

    for(size_t i=0 ; i < matrix_b.get_vector_matrix().size() ; i++){
        CHECK (matrix_b.get_vector_matrix().at(i) == (matrix_a.get_vector_matrix().at(i)*2.1));
    }

}