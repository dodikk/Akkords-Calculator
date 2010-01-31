#ifndef __NOTE_HEIGHT_NAMES_H__
#define __NOTE_HEIGHT_NAMES_H__

#include <string>

namespace LibMusic
{
    class NoteHeightNames
    {
    private:
        NoteHeightNames();
        ~NoteHeightNames();

    public:
        static const std::wstring c;
        static const std::wstring d;
        static const std::wstring e;
        static const std::wstring f;
        static const std::wstring g;
        static const std::wstring a;
        static const std::wstring h;

        static const std::wstring c_dies;
        static const std::wstring d_dies;
        static const std::wstring f_dies;
        static const std::wstring g_dies;
        static const std::wstring a_dies;


        static const std::wstring d_bemol;
        static const std::wstring e_bemol;
        static const std::wstring g_bemol;
        static const std::wstring a_bemol;
        static const std::wstring h_bemol; //b

    public:
        static const std::wstring dies ;
        static const std::wstring bemol;
        static const std::wstring bekar;

    public:
        static const std::wstring doubleDies ;
        static const std::wstring doubleBemol;

    private:
        static const std::wstring delimiter;
    };
}

#endif

