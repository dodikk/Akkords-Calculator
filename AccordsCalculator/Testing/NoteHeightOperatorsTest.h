#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>


class NoteHeightOperatorsTest : public CppUnit::TestFixture
{
public:
    NoteHeightOperatorsTest(void);
    ~NoteHeightOperatorsTest(void);

public:
    void TestConstructors();
    void TestOperators();


public:
    CPPUNIT_TEST_SUITE(NoteHeightOperatorsTest);
    CPPUNIT_TEST(TestConstructors);
    CPPUNIT_TEST(TestOperators);
    CPPUNIT_TEST_SUITE_END();
};
