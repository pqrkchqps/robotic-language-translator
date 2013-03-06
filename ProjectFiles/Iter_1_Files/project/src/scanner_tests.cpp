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
CxxTest::StaticSuiteDescription suiteDescription_ScannerTestSuite( "scanner_tests.h", 13, "ScannerTestSuite", suite_ScannerTestSuite, Tests_ScannerTestSuite );

static class TestDescription_ScannerTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 22, "test_setup_code" ) {}
 void runTest() { suite_ScannerTestSuite.test_setup_code(); }
} testDescription_ScannerTestSuite_test_setup_code;

static class TestDescription_ScannerTestSuite_test_TokenMaker_name : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_name() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 27, "test_TokenMaker_name" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_name(); }
} testDescription_ScannerTestSuite_test_TokenMaker_name;

static class TestDescription_ScannerTestSuite_test_TokenMaker_name_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_name_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 32, "test_TokenMaker_name_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_name_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_name_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_platform : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_platform() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 42, "test_TokenMaker_platform" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_platform(); }
} testDescription_ScannerTestSuite_test_TokenMaker_platform;

static class TestDescription_ScannerTestSuite_test_TokenMaker_platform_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_platform_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 46, "test_TokenMaker_platform_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_platform_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_platform_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_initial : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_initial() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 57, "test_TokenMaker_initial" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_initial(); }
} testDescription_ScannerTestSuite_test_TokenMaker_initial;

static class TestDescription_ScannerTestSuite_test_TokenMaker_initial_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_initial_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 61, "test_TokenMaker_initial_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_initial_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_initial_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_state : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_state() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 72, "test_TokenMaker_state" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_state(); }
} testDescription_ScannerTestSuite_test_TokenMaker_state;

static class TestDescription_ScannerTestSuite_test_TokenMaker_state_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_state_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 76, "test_TokenMaker_state_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_state_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_state_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_goto : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_goto() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 87, "test_TokenMaker_goto" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_goto(); }
} testDescription_ScannerTestSuite_test_TokenMaker_goto;

static class TestDescription_ScannerTestSuite_test_TokenMaker_goto_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_goto_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 91, "test_TokenMaker_goto_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_goto_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_goto_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_when : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_when() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 102, "test_TokenMaker_when" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_when(); }
} testDescription_ScannerTestSuite_test_TokenMaker_when;

static class TestDescription_ScannerTestSuite_test_TokenMaker_when_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_when_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 106, "test_TokenMaker_when_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_when_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_when_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_performing : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_performing() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 117, "test_TokenMaker_performing" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_performing(); }
} testDescription_ScannerTestSuite_test_TokenMaker_performing;

static class TestDescription_ScannerTestSuite_test_TokenMaker_performing_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_performing_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 121, "test_TokenMaker_performing_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_performing_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_performing_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_exit : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_exit() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 131, "test_TokenMaker_exit" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_exit(); }
} testDescription_ScannerTestSuite_test_TokenMaker_exit;

static class TestDescription_ScannerTestSuite_test_TokenMaker_exit_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_exit_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 135, "test_TokenMaker_exit_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_exit_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_exit_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_int : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_int() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 145, "test_TokenMaker_int" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_int(); }
} testDescription_ScannerTestSuite_test_TokenMaker_int;

static class TestDescription_ScannerTestSuite_test_TokenMaker_boolean : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_boolean() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 175, "test_TokenMaker_boolean" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_boolean(); }
} testDescription_ScannerTestSuite_test_TokenMaker_boolean;

static class TestDescription_ScannerTestSuite_test_TokenMaker_boolean_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_boolean_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 179, "test_TokenMaker_boolean_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_boolean_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_boolean_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_string : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_string() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 190, "test_TokenMaker_string" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_string(); }
} testDescription_ScannerTestSuite_test_TokenMaker_string;

static class TestDescription_ScannerTestSuite_test_TokenMaker_string_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_string_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 194, "test_TokenMaker_string_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_string_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_string_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_char : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_char() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 205, "test_TokenMaker_char" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_char(); }
} testDescription_ScannerTestSuite_test_TokenMaker_char;

static class TestDescription_ScannerTestSuite_test_TokenMaker_char_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_char_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 209, "test_TokenMaker_char_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_char_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_char_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_true : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_true() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 220, "test_TokenMaker_true" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_true(); }
} testDescription_ScannerTestSuite_test_TokenMaker_true;

static class TestDescription_ScannerTestSuite_test_TokenMaker_true_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_true_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 224, "test_TokenMaker_true_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_true_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_true_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_false : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_false() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 235, "test_TokenMaker_false" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_false(); }
} testDescription_ScannerTestSuite_test_TokenMaker_false;

static class TestDescription_ScannerTestSuite_test_TokenMaker_false_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_false_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 239, "test_TokenMaker_false_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_false_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_false_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_intConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_intConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 250, "test_TokenMaker_intConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_intConst(); }
} testDescription_ScannerTestSuite_test_TokenMaker_intConst;

static class TestDescription_ScannerTestSuite_test_TokenMaker_intConst_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_intConst_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 254, "test_TokenMaker_intConst_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_intConst_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_intConst_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_floatConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_floatConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 265, "test_TokenMaker_floatConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_floatConst(); }
} testDescription_ScannerTestSuite_test_TokenMaker_floatConst;

static class TestDescription_ScannerTestSuite_test_TokenMaker_floatConst_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_floatConst_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 269, "test_TokenMaker_floatConst_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_floatConst_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_floatConst_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_stringConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_stringConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 279, "test_TokenMaker_stringConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_stringConst(); }
} testDescription_ScannerTestSuite_test_TokenMaker_stringConst;

static class TestDescription_ScannerTestSuite_test_TokenMaker_stringConst_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_stringConst_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 283, "test_TokenMaker_stringConst_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_stringConst_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_stringConst_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_charConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_charConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 293, "test_TokenMaker_charConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_charConst(); }
} testDescription_ScannerTestSuite_test_TokenMaker_charConst;

static class TestDescription_ScannerTestSuite_test_TokenMaker_charConst_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_charConst_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 297, "test_TokenMaker_charConst_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_charConst_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_charConst_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_variableName : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_variableName() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 307, "test_TokenMaker_variableName" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_variableName(); }
} testDescription_ScannerTestSuite_test_TokenMaker_variableName;

static class TestDescription_ScannerTestSuite_test_TokenMaker_variableName_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_variableName_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 311, "test_TokenMaker_variableName_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_variableName_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_variableName_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_leftParen : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_leftParen() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 321, "test_TokenMaker_leftParen" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_leftParen(); }
} testDescription_ScannerTestSuite_test_TokenMaker_leftParen;

static class TestDescription_ScannerTestSuite_test_TokenMaker_leftParen_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_leftParen_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 325, "test_TokenMaker_leftParen_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_leftParen_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_leftParen_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_rightParen : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_rightParen() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 335, "test_TokenMaker_rightParen" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_rightParen(); }
} testDescription_ScannerTestSuite_test_TokenMaker_rightParen;

static class TestDescription_ScannerTestSuite_test_TokenMaker_rightParen_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_rightParen_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 339, "test_TokenMaker_rightParen_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_rightParen_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_rightParen_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_leftCurly : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_leftCurly() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 350, "test_TokenMaker_leftCurly" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_leftCurly(); }
} testDescription_ScannerTestSuite_test_TokenMaker_leftCurly;

static class TestDescription_ScannerTestSuite_test_TokenMaker_leftCurly_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_leftCurly_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 354, "test_TokenMaker_leftCurly_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_leftCurly_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_leftCurly_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_rightCurly : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_rightCurly() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 364, "test_TokenMaker_rightCurly" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_rightCurly(); }
} testDescription_ScannerTestSuite_test_TokenMaker_rightCurly;

static class TestDescription_ScannerTestSuite_test_TokenMaker_rightCurly_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_rightCurly_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 368, "test_TokenMaker_rightCurly_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_rightCurly_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_rightCurly_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_leftAngle : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_leftAngle() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 379, "test_TokenMaker_leftAngle" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_leftAngle(); }
} testDescription_ScannerTestSuite_test_TokenMaker_leftAngle;

static class TestDescription_ScannerTestSuite_test_TokenMaker_leftAngle_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_leftAngle_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 383, "test_TokenMaker_leftAngle_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_leftAngle_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_leftAngle_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_rightAngle : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_rightAngle() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 393, "test_TokenMaker_rightAngle" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_rightAngle(); }
} testDescription_ScannerTestSuite_test_TokenMaker_rightAngle;

static class TestDescription_ScannerTestSuite_test_TokenMaker_rightAngle_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_rightAngle_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 397, "test_TokenMaker_rightAngle_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_rightAngle_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_rightAngle_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_colon : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_colon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 408, "test_TokenMaker_colon" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_colon(); }
} testDescription_ScannerTestSuite_test_TokenMaker_colon;

static class TestDescription_ScannerTestSuite_test_TokenMaker_colon_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_colon_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 412, "test_TokenMaker_colon_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_colon_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_colon_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_comma : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_comma() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 423, "test_TokenMaker_comma" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_comma(); }
} testDescription_ScannerTestSuite_test_TokenMaker_comma;

static class TestDescription_ScannerTestSuite_test_TokenMaker_comma_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_comma_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 427, "test_TokenMaker_comma_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_comma_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_comma_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_semiColon : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_semiColon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 438, "test_TokenMaker_semiColon" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_semiColon(); }
} testDescription_ScannerTestSuite_test_TokenMaker_semiColon;

static class TestDescription_ScannerTestSuite_test_TokenMaker_semiColon_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_semiColon_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 442, "test_TokenMaker_semiColon_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_semiColon_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_semiColon_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_assign : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_assign() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 453, "test_TokenMaker_assign" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_assign(); }
} testDescription_ScannerTestSuite_test_TokenMaker_assign;

static class TestDescription_ScannerTestSuite_test_TokenMaker_assign_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_assign_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 457, "test_TokenMaker_assign_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_assign_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_assign_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_plusSign : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_plusSign() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 467, "test_TokenMaker_plusSign" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_plusSign(); }
} testDescription_ScannerTestSuite_test_TokenMaker_plusSign;

static class TestDescription_ScannerTestSuite_test_TokenMaker_plusSign_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_plusSign_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 471, "test_TokenMaker_plusSign_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_plusSign_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_plusSign_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_star : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_star() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 482, "test_TokenMaker_star" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_star(); }
} testDescription_ScannerTestSuite_test_TokenMaker_star;

static class TestDescription_ScannerTestSuite_test_TokenMaker_star_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_star_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 486, "test_TokenMaker_star_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_star_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_star_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_dash : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_dash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 497, "test_TokenMaker_dash" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_dash(); }
} testDescription_ScannerTestSuite_test_TokenMaker_dash;

static class TestDescription_ScannerTestSuite_test_TokenMaker_dash_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_dash_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 501, "test_TokenMaker_dash_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_dash_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_dash_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_forwardSlash : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_forwardSlash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 512, "test_TokenMaker_forwardSlash" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_forwardSlash(); }
} testDescription_ScannerTestSuite_test_TokenMaker_forwardSlash;

static class TestDescription_ScannerTestSuite_test_TokenMaker_forwardSlash_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_forwardSlash_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 516, "test_TokenMaker_forwardSlash_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_forwardSlash_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_forwardSlash_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_equalsEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_equalsEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 527, "test_TokenMaker_equalsEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_equalsEquals(); }
} testDescription_ScannerTestSuite_test_TokenMaker_equalsEquals;

static class TestDescription_ScannerTestSuite_test_TokenMaker_equalsEquals_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_equalsEquals_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 531, "test_TokenMaker_equalsEquals_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_equalsEquals_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_equalsEquals_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_lessThanEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_lessThanEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 542, "test_TokenMaker_lessThanEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_lessThanEquals(); }
} testDescription_ScannerTestSuite_test_TokenMaker_lessThanEquals;

static class TestDescription_ScannerTestSuite_test_TokenMaker_lessThanEquals_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_lessThanEquals_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 547, "test_TokenMaker_lessThanEquals_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_lessThanEquals_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_lessThanEquals_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_greaterThanEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_greaterThanEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 557, "test_TokenMaker_greaterThanEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_greaterThanEquals(); }
} testDescription_ScannerTestSuite_test_TokenMaker_greaterThanEquals;

static class TestDescription_ScannerTestSuite_test_TokenMaker_greaterThanEquals_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_greaterThanEquals_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 562, "test_TokenMaker_greaterThanEquals_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_greaterThanEquals_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_greaterThanEquals_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_notEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_notEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 573, "test_TokenMaker_notEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_notEquals(); }
} testDescription_ScannerTestSuite_test_TokenMaker_notEquals;

static class TestDescription_ScannerTestSuite_test_TokenMaker_notEquals_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_notEquals_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 578, "test_TokenMaker_notEquals_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_notEquals_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_notEquals_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_endOfFile : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_endOfFile() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 588, "test_TokenMaker_endOfFile" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_endOfFile(); }
} testDescription_ScannerTestSuite_test_TokenMaker_endOfFile;

static class TestDescription_ScannerTestSuite_test_TokenMaker_endOfFile_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_endOfFile_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 593, "test_TokenMaker_endOfFile_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_endOfFile_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_endOfFile_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_TokenMaker_lexicalError_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_TokenMaker_lexicalError_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 603, "test_TokenMaker_lexicalError_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_TokenMaker_lexicalError_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_TokenMaker_lexicalError_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_scan_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_empty() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 714, "test_scan_empty" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty(); }
} testDescription_ScannerTestSuite_test_scan_empty;

static class TestDescription_ScannerTestSuite_test_scan_empty_comment : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_empty_comment() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 721, "test_scan_empty_comment" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty_comment(); }
} testDescription_ScannerTestSuite_test_scan_empty_comment;

static class TestDescription_ScannerTestSuite_test_scan_lexicalErrors : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_lexicalErrors() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 730, "test_scan_lexicalErrors" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_lexicalErrors(); }
} testDescription_ScannerTestSuite_test_scan_lexicalErrors;

static class TestDescription_ScannerTestSuite_test_scan_nums_vars : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_nums_vars() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 751, "test_scan_nums_vars" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_nums_vars(); }
} testDescription_ScannerTestSuite_test_scan_nums_vars;

static class TestDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 763, "test_scan_bad_syntax_good_tokens" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_bad_syntax_good_tokens(); }
} testDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens;

static class TestDescription_ScannerTestSuite_test_scan_sample_abstar : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_sample_abstar() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 804, "test_scan_sample_abstar" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_sample_abstar(); }
} testDescription_ScannerTestSuite_test_scan_sample_abstar;

#include <cxxtest/Root.cpp>
