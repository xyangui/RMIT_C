//
//  main.cpp
//  RMIT_C++
//
//  Created by Jason on 2019/5/3.
//  Copyright © 2019年 Jason. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//test

//Q1——选最后一个
#define GRADE_hd 80
#define GRADE_max 100
std::string gradeToString(int grade){
    if(grade >= GRADE_hd && grade < GRADE_max){
        return std::string("HD");
    } else if(grade < GRADE_hd && grade > GRADE_hd){
        return std::string("Invalid");
    }
    return std::string("Invalid");
}


//Q2——选1，2，4，5，7
void foo1(char value){
    value = value + 1;
}
void foo2(double value){
    value = value + 1;
}
//void foo3(std::string value){
//    value = value + 1;
//}
void foo4(int* value){
    int val = *value;
    value = value + 1;
     int val2 = *value;
     int val3 = *value;
}
void foo5(char* value){
    char val = *value;
    value = value + 1;
    char val2 = *value;
    char val3 = *value;
}
//void foo6(const int value){
//    value = value + 1;
//}
void foo7(int value){
    value = value + 1;
}


//Q4—— Integer Overeflow/Underflow         Read beyond ....
//int sum(int* array, int length){
//    int total = 0;
//    for(int i = 0; i < length; ++i){
//        sum += array[i];
//    }
//    return total;
//}


//Q5
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


//Q8
#define LENGTH 10


//Q9
namespace name{
    std::string foo9(){
        return std::string("namespace name, function foo()");
    }
    std::string bar9(){
        return std::string("namespace name, function bar()");
    }
}
std::string foo9(){
    return std::string("function foo()");
}
std::string bar9(){
    return std::string("function bar()");
}


//Q10
int stringLength(char* string){
    int length = 0;
    int i = 0;
    while (string[i]) {
        length++;
        i++;
    }
    return length;
}


//Q11
void question11(double* arrA, double* arrB, int length){
  
    int j = length / 2;
    int i = 0;
    double tmp;
    while (i < j) {
        tmp = arrA[i];
        arrA[i] = arrA[length -1 - i];
        arrA[length -1 - i] = tmp;
        i++;
    }
    
    i = 0;
    while (i < length) {
        arrB[i] = arrA[i];
        i++;
    }
}
void question11_2(double* arrA, double* arrB, int length){
    
    int j = length / 2;
    for(int i = 0; i < length / 2; i++){
        double tmp =  arrA[i];
        arrA[i] = arrA[length -1 - i];
        arrA[length -1 - i] = tmp;
    }
    for(int i = 0; i < length; i++){
        arrB[i] = arrA[i];
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //Q1
    int grade = 90;
    std::string str = gradeToString(grade);
    
    //Q2
    char val = 'a';
    foo1(val);
    char val2 = val;
    
    //指向数组的指针
    int iArray[4] = {11, 22, 33, 44};
    int *p = iArray;
    foo4(p);
    int iArray1 = *p;
    int iArray2 = *(p + 1);
    int iArray3 = *(iArray + 1);
    
    char cArray[4] = {'a', 'b', 'c', 'd'};
    foo5(cArray);//
    
    //Q3——var1 = 100；var2 = -1；var3 = var1地址
    double var1 = 0;
    double var2 = -1;
    double* var3 = &var1;
    double& var4 = var2;
    *var3 = 100;
    
    //Q5——？？
    int a = 2;
    int b = 3;
    swap(&a, &b);
    
    //Q6——选第一个
    
    //Q7——？？？
    
    //Q8
    double var11 = 1.0f;//stack
    double* var22 = new double(-1.0f);//heap
    double* var33 = new double(var11);//heap
    double& var44 = var11;//stack
    double* array = new double[LENGTH];//heap
    
    //Q9——选第一项
    std::cout<< name::foo9() << std::endl;
    std::cout<< foo9() << std::endl;
    cout<< name::foo9() << endl;
    
    //Q10
    char* pStr = {"abc"};
    int q10 = stringLength(pStr);
    char* pStr2 = "abcde";
    int q11 = stringLength(pStr2);
    
    //Q11
    double arrA[5] = {1, 2, 3, 4, 5};
    double arrB[5] = {100, 90, 80, 70, 60};
//    question11(arrA, arrB, 5);
//    question11(arrA, arrB, 0);
//    question11(arrA, arrB, 3);
    question11_2(arrA, arrB, 5);
    question11_2(arrA, arrB, 0);
    question11_2(arrA, arrB, 3);
    
    double arrA1[6] = {1, 2, 3, 4, 5, 6};
    double arrB1[6] = {100, 90, 80, 70, 60, 50};
//    question11(arrA1, arrB1, 6);
//    question11(arrA1, arrB1, 0);
//    question11(arrA1, arrB1, 4);
    question11_2(arrA1, arrB1, 6);
    question11_2(arrA1, arrB1, 0);
    question11_2(arrA1, arrB1, 4);
    
    //Q12
    //arrA: 10 9 8 7 6 5 4 3 2 1
    //arrB: 10 9 8 7 6 5 4 3 2 1
    
    //arrA: 10 9 8 7 6 5 4 3 2 1
    //arrB: 10 9 8 7 6 5 4 3 2 1
    
    //arrA: 6 7 8 9 10 5 4 3 2 1
    //arrB: 6 7 8 9 10 5 4 3 2 1
    
    return 0;
}

