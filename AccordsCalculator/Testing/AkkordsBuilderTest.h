#pragma once


#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>


class AkkordsBuilderTest : public CppUnit::TestFixture
{
public:
    AkkordsBuilderTest(void);
    ~AkkordsBuilderTest(void);

public:
    void TestMajor();
    void TestMinor();
    void TestEnlarged();
    void TestShrinked();

public:
    CPPUNIT_TEST_SUITE(AkkordsBuilderTest);
    CPPUNIT_TEST(TestMajor);
    CPPUNIT_TEST(TestMinor);
    CPPUNIT_TEST(TestEnlarged);
    CPPUNIT_TEST(TestShrinked);
    CPPUNIT_TEST_SUITE_END();
};
