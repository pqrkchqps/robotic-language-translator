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
#include "scanner_tests.h"

static ScannerTestSuite suite_ScannerTestSuite;

static CxxTest::List Tests_ScannerTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_ScannerTestSuite( "scanner_tests.h", 49, "ScannerTestSuite", suite_ScannerTestSuite, Tests_ScannerTestSuite );

static class TestDescription_ScannerTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 58, "test_setup_code" ) {}
 void runTest() { suite_ScannerTestSuite.test_setup_code(); }
} testDescription_ScannerTestSuite_test_setup_code;

static class TestDescription_ScannerTestSuite_test_TokenMaker_name : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_name() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 62, "test_TokenMaker_name" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_name(); }
} testDescription_ScannerTestSuite_test_TokenMaker_name;

static class TestDescription_ScannerTestSuite_test_TokenMaker_name_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_name_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 66, "test_TokenMaker_name_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_name_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_name_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_leftAngle : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_leftAngle() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 75, "test_TokenMaker_leftAngle" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_leftAngle(); }
} testDescription_ScannerTestSuite_test_TokenMaker_leftAngle;

static class TestDescription_ScannerTestSuite_test_scan_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_empty() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 183, "test_scan_empty" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty(); }
} testDescription_ScannerTestSuite_test_scan_empty;

static class TestDescription_ScannerTestSuite_test_scan_empty_comment : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_empty_comment() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 190, "test_scan_empty_comment" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty_comment(); }
} testDescription_ScannerTestSuite_test_scan_empty_comment;

static class TestDescription_ScannerTestSuite_test_scan_lexicalErrors : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_lexicalErrors() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 199, "test_scan_lexicalErrors" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_lexicalErrors(); }
} testDescription_ScannerTestSuite_test_scan_lexicalErrors;

static class TestDescription_ScannerTestSuite_test_scan_nums_vars : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_nums_vars() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 220, "test_scan_nums_vars" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_nums_vars(); }
} testDescription_ScannerTestSuite_test_scan_nums_vars;

static class TestDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 234, "test_scan_bad_syntax_good_tokens" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_bad_syntax_good_tokens(); }
} testDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens;

static class TestDescription_ScannerTestSuite_test_scan_sample_abstar : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_sample_abstar() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 277, "test_scan_sample_abstar" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_sample_abstar(); }
} testDescription_ScannerTestSuite_test_scan_sample_abstar;

#include <cxxtest/Root.cpp>
