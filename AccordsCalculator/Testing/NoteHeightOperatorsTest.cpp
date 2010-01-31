#include "StdAfx.h"
#include "NoteHeightOperatorsTest.h"


using namespace LibMusic;

//////////////////////////////////////////////////
//              INITIALIZATION                  //
//////////////////////////////////////////////////
NoteHeightOperatorsTest::NoteHeightOperatorsTest(void)
{
}

NoteHeightOperatorsTest::~NoteHeightOperatorsTest(void)
{
}




//////////////////////////////////////////////////
//              TESTS                           //
//////////////////////////////////////////////////
void NoteHeightOperatorsTest::TestConstructors()
{
    {
        NoteHeight note = NoteHeight::CreateC();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::c;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateD();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::d;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateE();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::e;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateF();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::f;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateG();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::g;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateA();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::a;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateH();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::h;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }


    {
        NoteHeight note = NoteHeight::CreateC_dies();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::c_dies;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateD_dies();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::d_dies;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateF_dies();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::f_dies;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateG_dies();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::g_dies;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateA_dies();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::a_dies;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateD_bemol();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::d_bemol;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateE_bemol();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::e_bemol;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateG_bemol();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::g_bemol;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateA_bemol();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::a_bemol;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

    {
        NoteHeight note = NoteHeight::CreateH_bemol();

        std::wstring receivedName = note.GetNoteName();
        std::wstring expectedName = NoteHeightNames::h_bemol;

        CPPUNIT_ASSERT(receivedName == expectedName);
    }

}

void NoteHeightOperatorsTest::TestOperators()
{
    NoteHeight note = NoteHeight::CreateC();

    {
        ++note;
        CPPUNIT_ASSERT(note.GetNoteName() == NoteHeightNames::c_dies);
    }
    
    {
        note++;
        CPPUNIT_ASSERT(note.GetNoteName() == NoteHeightNames::d);
    }

    {
        --note;
        CPPUNIT_ASSERT(note.GetNoteName() == NoteHeightNames::d_bemol);
    }

    {
        note--;
        CPPUNIT_ASSERT(note.GetNoteName() == NoteHeightNames::c);
    }


    {
        note -= 1;
        CPPUNIT_ASSERT(NoteHeightNames::h == note.GetNoteName());
    }

    {
        note = note - 1;
        CPPUNIT_ASSERT(NoteHeightNames::h_bemol == note.GetNoteName());
    }

    {
        note = note + 0;
        CPPUNIT_ASSERT(NoteHeightNames::a_dies == note.GetNoteName());
    }

    {
        note = note + 7;
        CPPUNIT_ASSERT(NoteHeightNames::f == note.GetNoteName());
    }

}


