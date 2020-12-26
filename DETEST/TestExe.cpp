#include "doctest.h"

#include "ExeTests.h"

TEST_SUITE ( "Executor" ) {
    TEST_CASE ("ADD") {
                CHECK (ExecutorTestADD() == true);
    }

    TEST_CASE ("LW") {
                CHECK (ExecutorTestLW() == true);
    }

    TEST_CASE ("SW") {
                CHECK (ExecutorTestSW() == true);
    }

    TEST_CASE ("BEQ") {
                CHECK (ExecutorTestBEQ() == true);
    }

    TEST_CASE ("LUI") {
                CHECK (ExecutorTestLUI() == true);

    }
    TEST_CASE ("JAL") {
                CHECK (ExecutorTestJAL() == true);

    }

}