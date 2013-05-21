/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#define _CXXTEST_ABORT_TEST_ON_FAIL
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "codeGen_tests.h"

static CodeGenTestSuite suite_CodeGenTestSuite;

static CxxTest::List Tests_CodeGenTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_CodeGenTestSuite( "codeGen_tests.h", 17, "CodeGenTestSuite", suite_CodeGenTestSuite, Tests_CodeGenTestSuite );

static class TestDescription_CodeGenTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_CodeGenTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 21, "test_setup_code" ) {}
 void runTest() { suite_CodeGenTestSuite.test_setup_code(); }
} testDescription_CodeGenTestSuite_test_setup_code;

static class TestDescription_CodeGenTestSuite_test_codeGen_squareMapper : public CxxTest::RealTestDescription {
public:
 TestDescription_CodeGenTestSuite_test_codeGen_squareMapper() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 75, "test_codeGen_squareMapper" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_squareMapper(); }
} testDescription_CodeGenTestSuite_test_codeGen_squareMapper;

static class TestDescription_CodeGenTestSuite_test_codeGen_abstar : public CxxTest::RealTestDescription {
public:
 TestDescription_CodeGenTestSuite_test_codeGen_abstar() : CxxTest::RealTestDescription( Tests_CodeGenTestSuite, suiteDescription_CodeGenTestSuite, 78, "test_codeGen_abstar" ) {}
 void runTest() { suite_CodeGenTestSuite.test_codeGen_abstar(); }
} testDescription_CodeGenTestSuite_test_codeGen_abstar;

#include <cxxtest/Root.cpp>
