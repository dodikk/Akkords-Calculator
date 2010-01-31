#include "stdafx.h"
#include "NoteHeight.h"

using namespace LibMusic;


const uint MAX_NOTE_HEIGHT = INT_MAX - (INT_MAX % 12);


wstring_vt NoteHeight::ascendingNames_ ;
wstring_vt NoteHeight::descendingNames_;


/////////////////////////////////////////////////
//            BUILDER                          //
/////////////////////////////////////////////////
NoteHeight NoteHeight::CreateC()
{
    return NoteHeight(NoteHeightValues::c, true);
}


NoteHeight NoteHeight::CreateD()
{
    return NoteHeight(NoteHeightValues::d, true);
}


NoteHeight NoteHeight::CreateE()
{
    return NoteHeight(NoteHeightValues::e, true);
}


NoteHeight NoteHeight::CreateF()
{
    return NoteHeight(NoteHeightValues::f, true);
}


NoteHeight NoteHeight::CreateG()
{
    return NoteHeight(NoteHeightValues::g, true);
}


NoteHeight NoteHeight::CreateA()
{
    return NoteHeight(NoteHeightValues::a, true);
}


NoteHeight NoteHeight::CreateH()
{
    return NoteHeight(NoteHeightValues::h, true);
}



NoteHeight NoteHeight::CreateC_dies()
{
    return NoteHeight(NoteHeightValues::c_dies, true);
}


NoteHeight NoteHeight::CreateD_dies()
{
    return NoteHeight(NoteHeightValues::d_dies, true);
}


NoteHeight NoteHeight::CreateF_dies()
{
    return NoteHeight(NoteHeightValues::f_dies, true);
}


NoteHeight NoteHeight::CreateG_dies()
{
    return NoteHeight(NoteHeightValues::g_dies, true);
}


NoteHeight NoteHeight::CreateA_dies()
{
    return NoteHeight(NoteHeightValues::a_dies, true);
}


           
NoteHeight NoteHeight::CreateD_bemol()
{
    return NoteHeight(NoteHeightValues::d_bemol, false);
}


NoteHeight NoteHeight::CreateE_bemol()
{
    return NoteHeight(NoteHeightValues::e_bemol, false);
}


NoteHeight NoteHeight::CreateG_bemol()
{
    return NoteHeight(NoteHeightValues::g_bemol, false);
}


NoteHeight NoteHeight::CreateA_bemol()
{
    return NoteHeight(NoteHeightValues::a_bemol, false);
}


NoteHeight NoteHeight::CreateH_bemol()
{
    return NoteHeight(NoteHeightValues::h_bemol, false);
}





/////////////////////////////////////////////////
//            CONSTRUCTION                     //
/////////////////////////////////////////////////
NoteHeight::NoteHeight(RawNoteHeight value /*= 0*/, bool isAscending /*= false*/) :
    value_(value), 
    isAscending_(isAscending)
{
    InitializeHeaders();
}



/////////////////////////////////////////////////
//            HEADERS                          //
/////////////////////////////////////////////////
void NoteHeight::InitializeHeaders()
{
    InitializeAscendingHeaders();
    InitializeDescendingHeaders();
}

void NoteHeight::InitializeAscendingHeaders()
{
    if (ascendingNames_.empty())
    {
        ascendingNames_.push_back(NoteHeightNames::c     );
        ascendingNames_.push_back(NoteHeightNames::c_dies);
        ascendingNames_.push_back(NoteHeightNames::d     );
        ascendingNames_.push_back(NoteHeightNames::d_dies);
        ascendingNames_.push_back(NoteHeightNames::e     );
        ascendingNames_.push_back(NoteHeightNames::f     );
        ascendingNames_.push_back(NoteHeightNames::f_dies);
        ascendingNames_.push_back(NoteHeightNames::g     );
        ascendingNames_.push_back(NoteHeightNames::g_dies);
        ascendingNames_.push_back(NoteHeightNames::a     );
        ascendingNames_.push_back(NoteHeightNames::a_dies);
        ascendingNames_.push_back(NoteHeightNames::h     );
    }
}

void NoteHeight::InitializeDescendingHeaders()
{
    if (descendingNames_.empty())
    {
        descendingNames_.push_back(NoteHeightNames::c      );
        descendingNames_.push_back(NoteHeightNames::d_bemol);
        descendingNames_.push_back(NoteHeightNames::d      );
        descendingNames_.push_back(NoteHeightNames::e_bemol);
        descendingNames_.push_back(NoteHeightNames::e      );
        descendingNames_.push_back(NoteHeightNames::f      );
        descendingNames_.push_back(NoteHeightNames::g_bemol);
        descendingNames_.push_back(NoteHeightNames::g      );
        descendingNames_.push_back(NoteHeightNames::a_bemol);
        descendingNames_.push_back(NoteHeightNames::a      );
        descendingNames_.push_back(NoteHeightNames::h_bemol);
        descendingNames_.push_back(NoteHeightNames::h      );
    }
}



/////////////////////////////////////////////////
//            GETTERS                          //
/////////////////////////////////////////////////
RawNoteHeight NoteHeight::GetRawHeight() const
{
    return value_;
}

bool NoteHeight::IsAscending() const
{
    return isAscending_;
}

const std::wstring& NoteHeight::GetNoteName() const
{
    RawNoteHeight normValue = NormalizeValue(value_);

    if (isAscending_)
    {
        return ascendingNames_.at(normValue);
    }
    else
    {
        return descendingNames_.at(normValue);
    }
}




/////////////////////////////////////////////////
//              UTILITIES                      //
/////////////////////////////////////////////////
RawNoteHeight NoteHeight::NormalizeValue(RawNoteHeight value) const
{
    RawNoteHeight result = value % ascendingNames_.size();
    return result;
}




/////////////////////////////////////////////////
//              OPERATORS OVERLOAD             //
/////////////////////////////////////////////////
NoteHeight& NoteHeight::operator+=(RawNoteHeight diff)
{
    if (value_ + diff <= MAX_NOTE_HEIGHT)
    {
        value_ += diff;
    }
    else
    {
        value_ = (value_ + diff - MAX_NOTE_HEIGHT);
    }

    isAscending_ = true;

    return (*this);
}

NoteHeight& NoteHeight::operator-=(RawNoteHeight diff)
{
    if (value_ >= diff)
    {
        value_ -= diff;
    }
    else
    {
        RawNoteHeight rest = diff - value_;
        value_ = MAX_NOTE_HEIGHT - rest;
    }

    isAscending_ = false;

    return (*this);
}




NoteHeight& NoteHeight::operator++() //prefix
{
    (*this) += 1;
    return (*this);
}  

NoteHeight NoteHeight::operator++(int) //postfix
{
    NoteHeight result = (*this);
    (*this) += 1;

    return result;
}
 

NoteHeight& NoteHeight::operator--()//prefix 
{
    (*this) -= 1;
    return (*this);
}
NoteHeight NoteHeight::operator--(int) //postfix
{
    NoteHeight result = (*this);
    (*this) -= 1;

    return result;
}
 


NoteHeight LibMusic::operator+(const NoteHeight& left, RawNoteHeight right)
{
    NoteHeight result = left;
    result += right;

    return result;
}

NoteHeight LibMusic::operator-(const NoteHeight& left, RawNoteHeight right)
{
    NoteHeight result = left;
    result -= right;

    return result;
}


NoteHeightDistance LibMusic::operator-(
    const NoteHeight& left, 
    const NoteHeight& right)
{
    NoteHeightDistance result = left.GetRawHeight() - right.GetRawHeight();
    return result;
}
