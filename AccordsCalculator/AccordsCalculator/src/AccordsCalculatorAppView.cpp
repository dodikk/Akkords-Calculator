#include "stdafx.h"
#include "AccordsCalculatorAppView.h"



using namespace Wt;
using namespace WebUi;
using namespace LibMusic;

#define TR(TEXT) WString::tr(TEXT)

AccordsCalculatorAppView::AccordsCalculatorAppView(const WEnvironment& env)
: WApplication(env)
{
    messageResourceBundle().use("../../resources/text");
    messageResourceBundle().use("../../resources/simple_chords");
    messageResourceBundle().use("../../resources/sept_chords");

    setTitle( TR("app-title") );

    InitializeMainLayout();
    InitializeMiddleArea();
    InitializeWidgets();
}

void AccordsCalculatorAppView::InitializeMainLayout()
{
    mainContainer_ = new WContainerWidget();
    mainContainer_->resize(WLength::Auto, 400);
    layout_ = new WBorderLayout();
    mainContainer_->setLayout(layout_);

    root()->addWidget(mainContainer_);
}

void AccordsCalculatorAppView::InitializeMiddleArea()
{
    middleContainer_ = new WContainerWidget();
    layout_->addWidget(middleContainer_, WBorderLayout::Center);
    middleContainer_->resize(WLength::Auto, 400);
}

void AccordsCalculatorAppView::InitializeWidgets()
{
    InitializeLogo();
    InitializeNotePicker();
    InitializeAlterationSelector();


    InitializeChordBuilderTabs();
    InitializeSimpleChordsTab();
    InitializeSeptChordsTab();


    InitializeLaunchButton();
    InitializeResultTable();
}



/////////////////////////////////////////////////////////////////
//                   WIDGETS SETUP                             //
/////////////////////////////////////////////////////////////////
void AccordsCalculatorAppView::InitializeLogo()
{
    greeting_ = new WText(TR("hdr-greeting"));
    layout_->addWidget(greeting_, WBorderLayout::North);
}


void AccordsCalculatorAppView::InitializeNotePicker()
{
    lblNoteBase_ = new WText(TR("note_picker-caption"), middleContainer_);
    middleContainer_->addWidget(new WBreak());

    cbNoteBase_ = new WComboBox(middleContainer_);
    middleContainer_->addWidget(new WBreak());
}


void AccordsCalculatorAppView::InitializeAlterationSelector()
{
    gbAlteration_ = new WGroupBox(TR("alteration-signs"), middleContainer_);
    rbNone_  = new WRadioButton(TR("alt-none") , gbAlteration_);
    gbAlteration_->addWidget(new WBreak());

    rbDies_  = new WRadioButton(TR("alt-dies") , gbAlteration_);
    gbAlteration_->addWidget(new WBreak());

    rbBemol_ = new WRadioButton(TR("alt-bemol"), gbAlteration_);
    gbAlteration_->addWidget(new WBreak());



    alterationGroup_ = new WButtonGroup(middleContainer_);
    alterationGroup_->addButton(rbNone_ );
    alterationGroup_->addButton(rbDies_ );
    alterationGroup_->addButton(rbBemol_);

    alterationGroup_->setCheckedButton(rbNone_);
}

void AccordsCalculatorAppView::InitializeChordBuilderTabs()
{
    tabThreeSoundChord_ = new WContainerWidget();
    tabSeptAkkord_      = new WContainerWidget();

    twChordsDescriber_  = new WTabWidget(middleContainer_);
    twChordsDescriber_->addTab(tabThreeSoundChord_, TR("simple-chords"));
    twChordsDescriber_->addTab(tabSeptAkkord_     , TR("sept-chords"));
}

void AccordsCalculatorAppView::InitializeLaunchButton()
{
    btnCalculate_ = new WPushButton(TR("btnLaunch-caption"), middleContainer_);
}

void AccordsCalculatorAppView::InitializeResultTable()
{
    resultTable_ = new Ext::TableView();
    middleContainer_->addWidget(resultTable_);

    resultModel_ = new WStringListModel();
    resultTable_->setModel(resultModel_);
}

/////////////////////////////////////////////////////////////////
//                   CHORDS BUILDER TABS SETUP                 //
/////////////////////////////////////////////////////////////////
void AccordsCalculatorAppView::InitializeSimpleChordsTab()
{
    gbSimpleChords_ = new WGroupBox(TR("simple-chords"), tabThreeSoundChord_);
    rbMajor_    = new WRadioButton(TR("major-chord")   , gbSimpleChords_);
    gbSimpleChords_->addWidget(new WBreak());

    rbMinor_    = new WRadioButton(TR("minor-chord")  , gbSimpleChords_);
    gbSimpleChords_->addWidget(new WBreak());

    rbEnlarged_ = new WRadioButton(TR("enlarged-chord"), gbSimpleChords_);
    gbSimpleChords_->addWidget(new WBreak());

    rbShrinked_ = new WRadioButton(TR("shrinked-chord") , gbSimpleChords_);
    gbSimpleChords_->addWidget(new WBreak());

    simpleChordsGroup_ = new WButtonGroup(gbSimpleChords_);
    simpleChordsGroup_->addButton(rbMajor_   );
    simpleChordsGroup_->addButton(rbMinor_   );
    simpleChordsGroup_->addButton(rbEnlarged_);
    simpleChordsGroup_->addButton(rbShrinked_);
    simpleChordsGroup_->setCheckedButton(rbMajor_);
}

void AccordsCalculatorAppView::InitializeSeptChordsTab()
{
    gbSeptChords_ = new WGroupBox(TR("sept-chords"), tabSeptAkkord_);
    septChordsLayout_ = new WTable(gbSeptChords_);    
    

    rbSmallMajorSept_   = new WRadioButton(TR("small-major-sept")   , septChordsLayout_->elementAt(0, 0));
    rbLargeMajorSept_   = new WRadioButton(TR("large-major-sepr")   , septChordsLayout_->elementAt(0, 1));
    rbSmallMinorSept_   = new WRadioButton(TR("small-minor-sept")   , septChordsLayout_->elementAt(1, 0));
    rbLargeMinorSept_   = new WRadioButton(TR("large-minor-sept")   , septChordsLayout_->elementAt(1, 1));
    rbHalfShrinkedSept_ = new WRadioButton(TR("half-shrinked-sept") , septChordsLayout_->elementAt(2, 0));
    rbShrinkedSept_     = new WRadioButton(TR("shrinked-sept")      , septChordsLayout_->elementAt(2, 1));
    rbEnlargedSept_     = new WRadioButton(TR("enlarged-sept")      , septChordsLayout_->elementAt(3, 0));

    const int colWidth = 200;
    septChordsLayout_->columnAt(0)->setWidth(colWidth);
    septChordsLayout_->columnAt(1)->setWidth(colWidth);

                        
    septChordsGroup_ = new WButtonGroup(gbSeptChords_);
    septChordsGroup_->addButton(rbSmallMajorSept_  );
    septChordsGroup_->addButton(rbLargeMajorSept_  );
    septChordsGroup_->addButton(rbSmallMinorSept_  );
    septChordsGroup_->addButton(rbLargeMinorSept_  );
    septChordsGroup_->addButton(rbHalfShrinkedSept_);
    septChordsGroup_->addButton(rbShrinkedSept_    );
    septChordsGroup_->addButton(rbEnlargedSept_    );

    septChordsGroup_->setCheckedButton(rbSmallMajorSept_);
}

