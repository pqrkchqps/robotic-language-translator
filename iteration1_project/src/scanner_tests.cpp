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
CxxTest::StaticSuiteDescription suiteDescription_ScannerTestSuite( "scanner_tests.h", 20, "ScannerTestSuite", suite_ScannerTestSuite, Tests_ScannerTestSuite );

static class TestDescription_ScannerTestSuite_test_setup_code : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_setup_code() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 31, "test_setup_code" ) {}
 void runTest() { suite_ScannerTestSuite.test_setup_code(); }
} testDescription_ScannerTestSuite_test_setup_code;

static class TestDescription_ScannerTestSuite_test_terminal_name : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_name() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 37, "test_terminal_name" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_name(); }
} testDescription_ScannerTestSuite_test_terminal_name;

static class TestDescription_ScannerTestSuite_test_terminal_name_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_name_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 43, "test_terminal_name_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_name_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_name_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_platform : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_platform() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 57, "test_terminal_platform" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_platform(); }
} testDescription_ScannerTestSuite_test_terminal_platform;

static class TestDescription_ScannerTestSuite_test_terminal_platform_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_platform_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 61, "test_terminal_platform_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_platform_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_platform_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_initial : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_initial() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 76, "test_terminal_initial" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_initial(); }
} testDescription_ScannerTestSuite_test_terminal_initial;

static class TestDescription_ScannerTestSuite_test_terminal_initial_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_initial_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 80, "test_terminal_initial_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_initial_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_initial_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_state : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_state() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 95, "test_terminal_state" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_state(); }
} testDescription_ScannerTestSuite_test_terminal_state;

static class TestDescription_ScannerTestSuite_test_terminal_state_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_state_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 99, "test_terminal_state_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_state_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_state_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_goto : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_goto() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 114, "test_terminal_goto" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_goto(); }
} testDescription_ScannerTestSuite_test_terminal_goto;

static class TestDescription_ScannerTestSuite_test_terminal_goto_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_goto_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 118, "test_terminal_goto_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_goto_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_goto_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_when : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_when() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 133, "test_terminal_when" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_when(); }
} testDescription_ScannerTestSuite_test_terminal_when;

static class TestDescription_ScannerTestSuite_test_terminal_when_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_when_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 137, "test_terminal_when_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_when_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_when_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_performing : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_performing() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 152, "test_terminal_performing" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_performing(); }
} testDescription_ScannerTestSuite_test_terminal_performing;

static class TestDescription_ScannerTestSuite_test_terminal_performing_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_performing_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 156, "test_terminal_performing_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_performing_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_performing_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_exit : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_exit() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 170, "test_terminal_exit" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_exit(); }
} testDescription_ScannerTestSuite_test_terminal_exit;

static class TestDescription_ScannerTestSuite_test_terminal_exit_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_exit_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 174, "test_terminal_exit_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_exit_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_exit_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_int : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_int() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 188, "test_terminal_int" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_int(); }
} testDescription_ScannerTestSuite_test_terminal_int;

static class TestDescription_ScannerTestSuite_test_terminal_boolean : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_boolean() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 226, "test_terminal_boolean" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_boolean(); }
} testDescription_ScannerTestSuite_test_terminal_boolean;

static class TestDescription_ScannerTestSuite_test_terminal_boolean_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_boolean_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 230, "test_terminal_boolean_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_boolean_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_boolean_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_string : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_string() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 245, "test_terminal_string" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_string(); }
} testDescription_ScannerTestSuite_test_terminal_string;

static class TestDescription_ScannerTestSuite_test_terminal_string_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_string_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 249, "test_terminal_string_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_string_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_string_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_char : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_char() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 264, "test_terminal_char" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_char(); }
} testDescription_ScannerTestSuite_test_terminal_char;

static class TestDescription_ScannerTestSuite_test_terminal_char_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_char_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 268, "test_terminal_char_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_char_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_char_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_true : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_true() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 283, "test_terminal_true" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_true(); }
} testDescription_ScannerTestSuite_test_terminal_true;

static class TestDescription_ScannerTestSuite_test_terminal_true_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_true_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 287, "test_terminal_true_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_true_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_true_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_false : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_false() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 302, "test_terminal_false" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_false(); }
} testDescription_ScannerTestSuite_test_terminal_false;

static class TestDescription_ScannerTestSuite_test_terminal_false_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_false_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 306, "test_terminal_false_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_false_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_false_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_intConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_intConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 321, "test_terminal_intConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_intConst(); }
} testDescription_ScannerTestSuite_test_terminal_intConst;

static class TestDescription_ScannerTestSuite_test_terminal_intConst_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_intConst_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 325, "test_terminal_intConst_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_intConst_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_intConst_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_floatConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_floatConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 340, "test_terminal_floatConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_floatConst(); }
} testDescription_ScannerTestSuite_test_terminal_floatConst;

static class TestDescription_ScannerTestSuite_test_terminal_floatConst_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_floatConst_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 344, "test_terminal_floatConst_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_floatConst_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_floatConst_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_stringConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_stringConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 358, "test_terminal_stringConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_stringConst(); }
} testDescription_ScannerTestSuite_test_terminal_stringConst;

static class TestDescription_ScannerTestSuite_test_terminal_stringConst_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_stringConst_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 362, "test_terminal_stringConst_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_stringConst_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_stringConst_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_charConst : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_charConst() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 376, "test_terminal_charConst" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_charConst(); }
} testDescription_ScannerTestSuite_test_terminal_charConst;

static class TestDescription_ScannerTestSuite_test_terminal_charConst_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_charConst_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 380, "test_terminal_charConst_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_charConst_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_charConst_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_variableName : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_variableName() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 394, "test_terminal_variableName" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_variableName(); }
} testDescription_ScannerTestSuite_test_terminal_variableName;

static class TestDescription_ScannerTestSuite_test_terminal_variableName_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_variableName_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 398, "test_terminal_variableName_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_variableName_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_variableName_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_leftParen : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_leftParen() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 412, "test_terminal_leftParen" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftParen(); }
} testDescription_ScannerTestSuite_test_terminal_leftParen;

static class TestDescription_ScannerTestSuite_test_terminal_leftParen_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_leftParen_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 416, "test_terminal_leftParen_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftParen_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_leftParen_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_rightParen : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_rightParen() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 430, "test_terminal_rightParen" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightParen(); }
} testDescription_ScannerTestSuite_test_terminal_rightParen;

static class TestDescription_ScannerTestSuite_test_terminal_rightParen_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_rightParen_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 434, "test_terminal_rightParen_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightParen_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_rightParen_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_leftCurly : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_leftCurly() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 449, "test_terminal_leftCurly" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftCurly(); }
} testDescription_ScannerTestSuite_test_terminal_leftCurly;

static class TestDescription_ScannerTestSuite_test_terminal_leftCurly_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_leftCurly_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 453, "test_terminal_leftCurly_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftCurly_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_leftCurly_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_rightCurly : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_rightCurly() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 467, "test_terminal_rightCurly" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightCurly(); }
} testDescription_ScannerTestSuite_test_terminal_rightCurly;

static class TestDescription_ScannerTestSuite_test_terminal_rightCurly_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_rightCurly_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 471, "test_terminal_rightCurly_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightCurly_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_rightCurly_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_leftAngle : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_leftAngle() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 486, "test_terminal_leftAngle" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftAngle(); }
} testDescription_ScannerTestSuite_test_terminal_leftAngle;

static class TestDescription_ScannerTestSuite_test_terminal_leftAngle_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_leftAngle_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 490, "test_terminal_leftAngle_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_leftAngle_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_leftAngle_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_rightAngle : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_rightAngle() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 504, "test_terminal_rightAngle" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightAngle(); }
} testDescription_ScannerTestSuite_test_terminal_rightAngle;

static class TestDescription_ScannerTestSuite_test_terminal_rightAngle_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_rightAngle_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 508, "test_terminal_rightAngle_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_rightAngle_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_rightAngle_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_colon : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_colon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 523, "test_terminal_colon" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_colon(); }
} testDescription_ScannerTestSuite_test_terminal_colon;

static class TestDescription_ScannerTestSuite_test_terminal_colon_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_colon_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 527, "test_terminal_colon_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_colon_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_colon_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_comma : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_comma() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 542, "test_terminal_comma" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_comma(); }
} testDescription_ScannerTestSuite_test_terminal_comma;

static class TestDescription_ScannerTestSuite_test_terminal_comma_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_comma_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 546, "test_terminal_comma_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_comma_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_comma_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_semiColon : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_semiColon() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 561, "test_terminal_semiColon" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_semiColon(); }
} testDescription_ScannerTestSuite_test_terminal_semiColon;

static class TestDescription_ScannerTestSuite_test_terminal_semiColon_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_semiColon_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 566, "test_terminal_semiColon_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_semiColon_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_semiColon_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_assign : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_assign() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 581, "test_terminal_assign" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_assign(); }
} testDescription_ScannerTestSuite_test_terminal_assign;

static class TestDescription_ScannerTestSuite_test_terminal_assign_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_assign_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 585, "test_terminal_assign_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_assign_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_assign_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_plusSign : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_plusSign() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 599, "test_terminal_plusSign" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_plusSign(); }
} testDescription_ScannerTestSuite_test_terminal_plusSign;

static class TestDescription_ScannerTestSuite_test_terminal_plusSign_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_plusSign_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 603, "test_terminal_plusSign_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_plusSign_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_plusSign_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_star : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_star() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 618, "test_terminal_star" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_star(); }
} testDescription_ScannerTestSuite_test_terminal_star;

static class TestDescription_ScannerTestSuite_test_terminal_star_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_star_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 622, "test_terminal_star_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_star_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_star_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_dash : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_dash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 637, "test_terminal_dash" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_dash(); }
} testDescription_ScannerTestSuite_test_terminal_dash;

static class TestDescription_ScannerTestSuite_test_terminal_dash_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_dash_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 641, "test_terminal_dash_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_dash_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_dash_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_forwardSlash : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_forwardSlash() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 656, "test_terminal_forwardSlash" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_forwardSlash(); }
} testDescription_ScannerTestSuite_test_terminal_forwardSlash;

static class TestDescription_ScannerTestSuite_test_terminal_forwardSlash_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_forwardSlash_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 660, "test_terminal_forwardSlash_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_forwardSlash_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_forwardSlash_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_equalsEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_equalsEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 675, "test_terminal_equalsEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_equalsEquals(); }
} testDescription_ScannerTestSuite_test_terminal_equalsEquals;

static class TestDescription_ScannerTestSuite_test_terminal_equalsEquals_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_equalsEquals_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 679, "test_terminal_equalsEquals_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_equalsEquals_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_equalsEquals_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_lessThanEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_lessThanEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 694, "test_terminal_lessThanEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_lessThanEquals(); }
} testDescription_ScannerTestSuite_test_terminal_lessThanEquals;

static class TestDescription_ScannerTestSuite_test_terminal_lessThanEquals_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_lessThanEquals_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 699, "test_terminal_lessThanEquals_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_lessThanEquals_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_lessThanEquals_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_greaterThanEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_greaterThanEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 713, "test_terminal_greaterThanEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_greaterThanEquals(); }
} testDescription_ScannerTestSuite_test_terminal_greaterThanEquals;

static class TestDescription_ScannerTestSuite_test_terminal_greaterThanEquals_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_greaterThanEquals_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 718, "test_terminal_greaterThanEquals_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_greaterThanEquals_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_greaterThanEquals_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_notEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_notEquals() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 733, "test_terminal_notEquals" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_notEquals(); }
} testDescription_ScannerTestSuite_test_terminal_notEquals;

static class TestDescription_ScannerTestSuite_test_terminal_notEquals_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_notEquals_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 738, "test_terminal_notEquals_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_notEquals_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_notEquals_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_endOfFile : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_endOfFile() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 752, "test_terminal_endOfFile" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_endOfFile(); }
} testDescription_ScannerTestSuite_test_terminal_endOfFile;

static class TestDescription_ScannerTestSuite_test_terminal_endOfFile_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_endOfFile_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 757, "test_terminal_endOfFile_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_endOfFile_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_endOfFile_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_terminal_lexicalError : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_lexicalError() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 770, "test_terminal_lexicalError" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_lexicalError(); }
} testDescription_ScannerTestSuite_test_terminal_lexicalError;

static class TestDescription_ScannerTestSuite_test_terminal_lexicalError_bad_lexeme : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_terminal_lexicalError_bad_lexeme() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 775, "test_terminal_lexicalError_bad_lexeme" ) {}
 void runTest() { suite_ScannerTestSuite.test_terminal_lexicalError_bad_lexeme(); }
} testDescription_ScannerTestSuite_test_terminal_lexicalError_bad_lexeme;

static class TestDescription_ScannerTestSuite_test_scan_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_empty() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 889, "test_scan_empty" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty(); }
} testDescription_ScannerTestSuite_test_scan_empty;

static class TestDescription_ScannerTestSuite_test_scan_empty_comment : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_empty_comment() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 896, "test_scan_empty_comment" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_empty_comment(); }
} testDescription_ScannerTestSuite_test_scan_empty_comment;

static class TestDescription_ScannerTestSuite_test_scan_lexicalErrors : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_lexicalErrors() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 905, "test_scan_lexicalErrors" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_lexicalErrors(); }
} testDescription_ScannerTestSuite_test_scan_lexicalErrors;

static class TestDescription_ScannerTestSuite_test_scan_nums_vars : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_nums_vars() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 926, "test_scan_nums_vars" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_nums_vars(); }
} testDescription_ScannerTestSuite_test_scan_nums_vars;

static class TestDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 938, "test_scan_bad_syntax_good_tokens" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_bad_syntax_good_tokens(); }
} testDescription_ScannerTestSuite_test_scan_bad_syntax_good_tokens;

static class TestDescription_ScannerTestSuite_test_scan_sample_abstar : public CxxTest::RealTestDescription {
public:
 TestDescription_ScannerTestSuite_test_scan_sample_abstar() : CxxTest::RealTestDescription( Tests_ScannerTestSuite, suiteDescription_ScannerTestSuite, 979, "test_scan_sample_abstar" ) {}
 void runTest() { suite_ScannerTestSuite.test_scan_sample_abstar(); }
} testDescription_ScannerTestSuite_test_scan_sample_abstar;

#include <cxxtest/Root.cpp>
