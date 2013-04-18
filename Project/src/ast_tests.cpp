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
CxxTest::StaticSuiteDescription suiteDescription_AstTestSuite( "ast_tests.h", 14, "AstTestSuite", suite_AstTestSuite, Tests_AstTestSuite );

static class TestDescription_AstTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 21, "test_setup_code" ) {}
 void runTest() { suite_AstTestSuite.test_setup_code(); }
} testDescription_AstTestSuite_test_setup_code;

static class TestDescription_AstTestSuite_testParseExpresion : public CxxTest::RealTestDescription {
public:
 TestDescription_AstTestSuite_testParseExpresion() : CxxTest::RealTestDescription( Tests_AstTestSuite, suiteDescription_AstTestSuite, 45, "testParseExpresion" ) {}
 void runTest() { suite_AstTestSuite.testParseExpresion(); }
} testDescription_AstTestSuite_testParseExpresion;

#include <cxxtest/Root.cpp>
