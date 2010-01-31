#include "StdAfx.h"
#include "AccordsCalculatorApp.h"

using namespace Wt;
using namespace WebUi;
using namespace LibMusic;

const RawNoteHeight AccordsCalculatorApp::notes_[] = 
{
    NoteHeightValues::c,
    NoteHeightValues::d,
    NoteHeightValues::e,
    NoteHeightValues::f,
    NoteHeightValues::g,
    NoteHeightValues::a,
    NoteHeightValues::h
};



const int AccordsCalculatorApp::eIndex_ = 2;
const int AccordsCalculatorApp::fIndex_ = 3;
const int AccordsCalculatorApp::hIndex_ = 6;
const int AccordsCalculatorApp::cIndex_ = 0;

/////////////////////////////////////////////////////////////////////
//                  INITIALIZATION                                 //
/////////////////////////////////////////////////////////////////////
AccordsCalculatorApp::AccordsCalculatorApp(const Wt::WEnvironment& env) :
    ParentClass(env)
{
    SetupEvents();
    SetupWidgets();
}

void AccordsCalculatorApp::SetupEvents()
{
    cbNoteBase_->activated().connect(this, &AccordsCalculatorApp::OnCbNoteBase_valueChanged);
    btnCalculate_->clicked().connect(this, &AccordsCalculatorApp::OnBtnCalculate_pressed   );
}


void AccordsCalculatorApp::SetupWidgets()
{
    InitializeNotesComboBox();
    OnCbNoteBase_valueChanged(cIndex_);
}


/////////////////////////////////////////////////////////////////////
//                  WIDGETS CONTENT SETUP                          //
/////////////////////////////////////////////////////////////////////
void AccordsCalculatorApp::InitializeNotesComboBox()
{
    cbNoteBase_->addItem(NoteHeightNames::c);
    cbNoteBase_->addItem(NoteHeightNames::d);
    cbNoteBase_->addItem(NoteHeightNames::e);
    cbNoteBase_->addItem(NoteHeightNames::f);
    cbNoteBase_->addItem(NoteHeightNames::g);
    cbNoteBase_->addItem(NoteHeightNames::a);
    cbNoteBase_->addItem(NoteHeightNames::h);
}





/////////////////////////////////////////////////////////////////////
//                  EVENT HANDLERS                                 //
/////////////////////////////////////////////////////////////////////
void AccordsCalculatorApp::OnCbNoteBase_valueChanged(int index)
{
    int checkedButtonId = alterationGroup_->checkedId();

    int diesId  = alterationGroup_->id(rbDies_ );
    int bemolId = alterationGroup_->id(rbBemol_);
    int noneId  = alterationGroup_->id(rbNone_ );


    switch (index)
    {
    case (eIndex_):
    case (hIndex_):
        {
            rbDies_ ->setDisabled(true );
            rbBemol_->setDisabled(false);
            rbNone_ ->setDisabled(false);

            if (checkedButtonId == diesId)
            {
                alterationGroup_->setSelectedButtonIndex(noneId);
            }

            break;
        }

    case (cIndex_):
    case (fIndex_):
        {
            rbDies_ ->setDisabled(false);
            rbBemol_->setDisabled(true );
            rbNone_ ->setDisabled(false);

            if (checkedButtonId == bemolId)
            {
                alterationGroup_->setSelectedButtonIndex(noneId);
            }

            break;
        }
    default:
        {
            rbDies_ ->setDisabled(false);
            rbBemol_->setDisabled(false);
            rbNone_ ->setDisabled(false);
        }
    };
}


void AccordsCalculatorApp::OnBtnCalculate_pressed()
{
    Akkord result;
    DoBuildAkkord(result);
    DrawAkkord(result);
}

///////////////////////////////////////////////////
//          FACTORIES                            //
///////////////////////////////////////////////////
AccordsCalculatorApp::AkkordBuildCallback AccordsCalculatorApp::GetBuildCallback() const
{
    int activeTabIndex = twChordsDescriber_->currentIndex();

    enum TabIndexValues
    {
        tiSimple = 0,
        tiSept   = 1,
    };

    switch (activeTabIndex)
    {
    case (tiSimple) :
        {
            return GetSimpleBuildCallback();
            break;
        }
    case (tiSept):
        {
            return GetSeptBuildCallback();
            break;
        }
    };

    throw std::runtime_error("<AccordsCalculatorApp::GetBuildCallback> : unexpected tab value");
}

AccordsCalculatorApp::AkkordBuildCallback AccordsCalculatorApp::GetSimpleBuildCallback() const
{
    typedef std::vector<AkkordBuildCallback> AkkordBuildCallbacks;

    static AkkordBuildCallbacks callbacks;
    if (callbacks.empty())
    {
        callbacks.push_back(&AkkordsBuilder::BuildMajor);
        callbacks.push_back(&AkkordsBuilder::BuildMinor);
        callbacks.push_back(&AkkordsBuilder::BuildEnlarged);
        callbacks.push_back(&AkkordsBuilder::BuildShrinked);
    }

    int callbackIndex = simpleChordsGroup_->checkedId();
    return callbacks.at(callbackIndex);
}

AccordsCalculatorApp::AkkordBuildCallback AccordsCalculatorApp::GetSeptBuildCallback() const
{
    typedef std::vector<AkkordBuildCallback> AkkordBuildCallbacks;

    static AkkordBuildCallbacks callbacks;
    if (callbacks.empty())
    {
        callbacks.push_back(&SeptAkkordsBuilder::BuildSmallMajorSept  );
        callbacks.push_back(&SeptAkkordsBuilder::BuildBigMajorSept    );
        callbacks.push_back(&SeptAkkordsBuilder::BuildSmallMinorSept  );
        callbacks.push_back(&SeptAkkordsBuilder::BuildBigMinorSept    );
        callbacks.push_back(&SeptAkkordsBuilder::BuildHalfShrinkedSept);
        callbacks.push_back(&SeptAkkordsBuilder::BuildShrinkedSept    );
        callbacks.push_back(&SeptAkkordsBuilder::BuildEnlargedSept    );
    }

    int callbackIndex = septChordsGroup_->checkedId();
    return callbacks.at(callbackIndex);
}

const NoteHeight& AccordsCalculatorApp::BuildBaseNote() const
{
    static NoteHeight_vt baseNotes;

    if (baseNotes.empty())
    {
        baseNotes.push_back(NoteHeight::CreateC());
        baseNotes.push_back(NoteHeight::CreateD());
        baseNotes.push_back(NoteHeight::CreateE());
        baseNotes.push_back(NoteHeight::CreateF());
        baseNotes.push_back(NoteHeight::CreateG());
        baseNotes.push_back(NoteHeight::CreateA());
        baseNotes.push_back(NoteHeight::CreateH());
    }

    int noteIndex = cbNoteBase_->currentIndex();
    return baseNotes.at(noteIndex);
}

AlterationSign AccordsCalculatorApp::GetAlterationSign() const
{
    static AlterationSign altSigns[] = 
    {
        LibMusic::None,
        LibMusic::Dies,
        LibMusic::Bemol
    };

    int altIndex = alterationGroup_->checkedId();
    return altSigns[altIndex];
}



//////////////////////////////////////////////////////
//               UTILS                              //
//////////////////////////////////////////////////////
NoteHeight AccordsCalculatorApp::ApplyAlteration(
    const NoteHeight& note, 
    AlterationSign alt) const
{
    int iAlt = static_cast<int>(alt);

    if (iAlt > 0)
    {
        return note + iAlt;
    }
    else if (iAlt < 0)
    {
        return note - abs(iAlt);
    }
    else
    {
        return note;
    }

    throw std::runtime_error("<AccordsCalculatorApp::ApplyAlteration> : unexpected alt sign");
}

void AccordsCalculatorApp::DoBuildAkkord(Akkord& result) const
{
    AkkordBuildCallback callback = GetBuildCallback();

    const NoteHeight& baseNote = BuildBaseNote();
    AlterationSign altSign = GetAlterationSign();

    NoteHeight firstNoteOfChord = ApplyAlteration(baseNote, altSign);
    callback(firstNoteOfChord, result);
}



void AccordsCalculatorApp::DrawAkkord(const Akkord& akkord)
{
    std::vector<WString> rawResult;

    size_t akkordSize = akkord.size();
    for (size_t i = 0; i < akkordSize; ++i)
    {
        std::wstring noteName = akkord[i].GetNoteName();
        rawResult.push_back(noteName);
    }

    resultModel_->setStringList(rawResult);
    resultTable_->refresh();
}

