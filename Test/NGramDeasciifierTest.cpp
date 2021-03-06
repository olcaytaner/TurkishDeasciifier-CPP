//
// Created by Olcay Taner YILDIZ on 4.01.2021.
//

#include <FsmMorphologicalAnalyzer.h>
#include "catch.hpp"
#include "../NGramDeasciifier.h"
#include "../SimpleAsciifier.h"
#include <NoSmoothing.h>
#include <Corpus.h>

TEST_CASE("NGramDeasciifierTest-testDeasciify") {
    FsmMorphologicalAnalyzer fsm = FsmMorphologicalAnalyzer();
    auto* nGram = new NGram<string>("ngram.txt");
    NoSmoothing<string> noSmoothing;
    noSmoothing.setProbabilities(*nGram);
    NGramDeasciifier nGramDeasciifier = NGramDeasciifier(fsm, *nGram, true);
    SimpleAsciifier simpleAsciifier = SimpleAsciifier();
    Corpus corpus = Corpus("corpus.txt");
    for (int i = 0; i < corpus.sentenceCount(); i++){
        Sentence* sentence = corpus.getSentence(i);
        for (int j = 1; j < sentence->wordCount(); j++){
            if (fsm.morphologicalAnalysis(sentence->getWord(j)->getName()).size() > 0){
                string asciified = simpleAsciifier.asciify(sentence->getWord(j));
                if (asciified != sentence->getWord(j)->getName()){
                    Sentence* deasciified = nGramDeasciifier.deasciify(new Sentence(sentence->getWord(j - 1)->getName() + " " + sentence->getWord(j)->getName()));
                    REQUIRE(sentence->getWord(j)->getName() == deasciified->getWord(1)->getName());
                }
            }
        }
    }
}

TEST_CASE("NGramDeasciifierTest-testDeasciify2") {
    FsmMorphologicalAnalyzer fsm = FsmMorphologicalAnalyzer();
    auto* nGram = new NGram<string>("ngram.txt");
    NoSmoothing<string> noSmoothing;
    noSmoothing.setProbabilities(*nGram);
    NGramDeasciifier nGramDeasciifier = NGramDeasciifier(fsm, *nGram, false);
    REQUIRE("noter hakkında" == nGramDeasciifier.deasciify(new Sentence("noter hakkinda"))->to_string());
    REQUIRE("sandık medrese" == nGramDeasciifier.deasciify(new Sentence("sandik medrese"))->to_string());
    REQUIRE("kuran'ı karşılıklı" == nGramDeasciifier.deasciify(new Sentence("kuran'ı karsilikli"))->to_string());
}