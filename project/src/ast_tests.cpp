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
#include "ast_tests.h"

static AstTestSuite suite_AstTestSuite;

static CxxTest::List Tests_AstTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_AstTestSuite( "ast_tests.h", 15, "AstTestSuite", suite_AstTestSuite, Tests_AstTestSuite );

static class TestDescription_AstTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 22, "test_setup_code" ) {}
 void runTest() { suite_AstTestSuite.test_setup_code(); }
} testDescription_AstTestSuite_test_setup_code;

static class TestDescription_AstTestSuite_test_ast_squareMapper : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_ast_squareMapper() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 37, "test_ast_squareMapper" ) {}
 void runTest() { suite_AstTestSuite.test_ast_squareMapper(); }
} testDescription_AstTestSuite_test_ast_squareMapper;

#include <cxxtest/Root.cpp>
