#include <UnitTest++/UnitTest++.h>
#include <iostream>
#include <string>
#include <UnitTest++/TestReporterStdout.h>
#include "RouteCipher.h"

auto RunSuite (const char* SuiteName)
{ 
    UnitTest::TestReporterStdout reporter;
    UnitTest::TestRunner runner(reporter);
        return runner.RunTestsIf(UnitTest::Test::GetTestList(),
                                SuiteName,
                                UnitTest::True(),0);
}

std::string t;
SUITE(encrypt){
    TEST(test1){
        t = "PIXEL"; 
        CHECK_EQUAL(RouteCipher(3).encrypt(t), "PLIEX");
    }
    TEST(test5){
        t = "PI XEL"; 
        CHECK_THROW(RouteCipher(3).encrypt(RouteCipher(3).getValidText(t)), cipher_error);
    }
    TEST(test2){
        t = "??PIXEL??"; 
        CHECK_THROW(RouteCipher(3).encrypt(RouteCipher(3).getValidText(t)), cipher_error);
    }
    TEST(test3){
        t = "pixel"; 
        CHECK_EQUAL(RouteCipher(3).encrypt(t), "pliex");
    }
    TEST(test4){
        t = " "; 
        CHECK_THROW(RouteCipher(3).encrypt(RouteCipher(3).getValidText(t)), cipher_error);
    }    
}
SUITE(decrypt){
    TEST(t_1){
        t = "PLIEX"; 
        CHECK_EQUAL(RouteCipher(3).decrypt(t), "PIXEL");
    }
    TEST(t_2){
        t = "PL IEX"; 
        CHECK_THROW(RouteCipher(3).decrypt(RouteCipher(3).getValidText(t)), cipher_error);
    }
    TEST(t_3){
        t = "232PLIEX||||"; 
        CHECK_THROW(RouteCipher(3).decrypt(RouteCipher(3).getValidText(t)), cipher_error);
    }
    TEST(t_4){
        t = " ";
        CHECK_THROW(RouteCipher(3).decrypt(RouteCipher(3).getValidText(t)), cipher_error);
    }
    TEST(t_5){
        t = "88+55+100"; 
        CHECK_THROW(RouteCipher(3).decrypt(RouteCipher(3).getValidText(t)), cipher_error);
    }    
}
SUITE(KeyTest) {
    TEST(InvalidKey) {
    CHECK_THROW(RouteCipher(0), std::invalid_argument);
    }
    TEST(NonKey) {
    CHECK_THROW(RouteCipher(-1), std::invalid_argument);
    
}
}

SUITE(KeyLengthTest) {
    TEST(KeyGreaterThanTextLength) {
        CHECK_THROW(RouteCipher(10).getValidText("abc"), cipher_error);
    }
}
int main() {
    return UnitTest::RunAllTests();
}  
