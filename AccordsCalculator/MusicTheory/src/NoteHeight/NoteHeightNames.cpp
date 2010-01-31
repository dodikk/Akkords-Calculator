#include "stdafx.h"
#include "NoteHeightNames.h"

using namespace LibMusic;

////////////////////////////////////////////////////////////
//                BASIC NOTE NAMES                        //
////////////////////////////////////////////////////////////
//TODO : add localization
const std::wstring NoteHeightNames::dies        = L"dies"       ;
const std::wstring NoteHeightNames::bemol       = L"bemol"      ;
const std::wstring NoteHeightNames::bekar       = L"bekar"      ;
const std::wstring NoteHeightNames::doubleDies  = L"doubleDies" ;
const std::wstring NoteHeightNames::doubleBemol = L"doubleBemol";
const std::wstring NoteHeightNames::delimiter   = L"_"          ;


const std::wstring NoteHeightNames::c = L"c";
const std::wstring NoteHeightNames::d = L"d";
const std::wstring NoteHeightNames::e = L"e";
const std::wstring NoteHeightNames::f = L"f";
const std::wstring NoteHeightNames::g = L"g";
const std::wstring NoteHeightNames::a = L"a";
const std::wstring NoteHeightNames::h = L"h";




////////////////////////////////////////////////////////////
//              DERIVED NOTE NAMES                        //
////////////////////////////////////////////////////////////
const std::wstring NoteHeightNames::c_dies = NoteHeightNames::c + NoteHeightNames::delimiter + NoteHeightNames::dies;
const std::wstring NoteHeightNames::d_dies = NoteHeightNames::d + NoteHeightNames::delimiter + NoteHeightNames::dies;
const std::wstring NoteHeightNames::f_dies = NoteHeightNames::f + NoteHeightNames::delimiter + NoteHeightNames::dies;
const std::wstring NoteHeightNames::g_dies = NoteHeightNames::g + NoteHeightNames::delimiter + NoteHeightNames::dies;
const std::wstring NoteHeightNames::a_dies = NoteHeightNames::a + NoteHeightNames::delimiter + NoteHeightNames::dies;




const std::wstring NoteHeightNames::d_bemol = NoteHeightNames::d + NoteHeightNames::delimiter + NoteHeightNames::bemol;
const std::wstring NoteHeightNames::e_bemol = NoteHeightNames::e + NoteHeightNames::delimiter + NoteHeightNames::bemol;
const std::wstring NoteHeightNames::g_bemol = NoteHeightNames::g + NoteHeightNames::delimiter + NoteHeightNames::bemol;
const std::wstring NoteHeightNames::a_bemol = NoteHeightNames::a + NoteHeightNames::delimiter + NoteHeightNames::bemol;
const std::wstring NoteHeightNames::h_bemol = L"b";


