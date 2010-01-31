#ifndef Interval_h__
#define Interval_h__

namespace LibMusic
{
    class Interval
    {
    private:
        Interval(size_t notesCount, size_t halfTonesCount);

    public:
        static Interval CreatePrimoPure     ();
        static Interval CreateSecundaSmall  ();
        static Interval CreateSecundaLarge  ();
        static Interval CreateTerciaSmall   ();
        static Interval CreateTerciaLarge   ();
        static Interval CreateKvartaPure    ();
        static Interval CreateKvartaEnlarged();
        static Interval CreateKvintaShrinked();
        static Interval CreateKvintaPure    ();
        static Interval CreateSekstaSmall   ();
        static Interval CreateSekstaLarge   ();
        static Interval CreateSeptimaSmall  ();
        static Interval CreateSeptimaLarge  ();
        static Interval CreateOktavaPure    ();

    public:
        size_t GetNotesCount()     const;
        size_t GetHalfTonesCount() const;

    private:
        size_t notesCount_    ;
        size_t halfTonesCount_;
    };
}

#endif // Interval_h__

