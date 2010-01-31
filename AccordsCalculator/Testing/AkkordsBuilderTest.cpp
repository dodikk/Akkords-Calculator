#include "StdAfx.h"
#include "AkkordsBuilderTest.h"


using namespace LibMusic;


//////////////////////////////////////////////////
//              INITIALIZATION                  //
//////////////////////////////////////////////////
AkkordsBuilderTest::AkkordsBuilderTest(void)
{
}

AkkordsBuilderTest::~AkkordsBuilderTest(void)
{
}




//////////////////////////////////////////////////
//              TESTS                           //
//////////////////////////////////////////////////
void AkkordsBuilderTest::TestMajor()
{
    Akkord result;

    {
        AkkordsBuilder::BuildMajor(NoteHeight::CreateC(), result);

        CPPUNIT_ASSERT(NoteHeightNames::c == result.at(0).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::e == result.at(1).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::g == result.at(2).GetNoteName());
    }

    {
        AkkordsBuilder::BuildMajor(NoteHeight::CreateC_dies(), result);

        CPPUNIT_ASSERT(NoteHeightNames::c_dies  == result.at(0).GetNoteName());
        // e _dies == f
        CPPUNIT_ASSERT(NoteHeightNames::f       == result.at(1).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::g_dies  == result.at(2).GetNoteName());
    }

    {
        AkkordsBuilder::BuildMajor(NoteHeight::CreateD(), result);

        CPPUNIT_ASSERT(NoteHeightNames::d      == result.at(0).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::f_dies == result.at(1).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::a      == result.at(2).GetNoteName());
    }

}


void AkkordsBuilderTest::TestMinor()
{
    Akkord result;

    {
        AkkordsBuilder::BuildMinor(NoteHeight::CreateC(), result);

        CPPUNIT_ASSERT(NoteHeightNames::c       == result.at(0).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::e_bemol == result.at(1).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::g       == result.at(2).GetNoteName());
    }

    {
        AkkordsBuilder::BuildMinor(NoteHeight::CreateC_dies(), result);

        CPPUNIT_ASSERT(NoteHeightNames::c_dies == result.at(0).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::e      == result.at(1).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::g_dies == result.at(2).GetNoteName());
    }

    {
        AkkordsBuilder::BuildMinor(NoteHeight::CreateD(), result);

        CPPUNIT_ASSERT(NoteHeightNames::d == result.at(0).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::f == result.at(1).GetNoteName());
        CPPUNIT_ASSERT(NoteHeightNames::a == result.at(2).GetNoteName());
    }
}


void AkkordsBuilderTest::TestEnlarged()
{
    CPPUNIT_ASSERT_MESSAGE("Not implemented", false);
}


void AkkordsBuilderTest::TestShrinked()
{
    CPPUNIT_ASSERT_MESSAGE("Not implemented", false);
}


