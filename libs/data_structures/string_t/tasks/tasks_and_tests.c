#include "task_manager.h"

void remove_non_letters(char *s) {
    char *endSource = get_end_of_string(s);
    char *destination = copy_if(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_task1_default_case() {
    char testString1[] = "H E L L O";
    char expectedResult[] = "HELLO";

    remove_non_letters(testString1);

    ASSERT_STRING(expectedResult, testString1);
}

void test_task1_escapes() {
    char testString1[] = "H\tE\tL\tL\tO";
    char expectedResult[] = "HELLO";

    remove_non_letters(testString1);

    ASSERT_STRING(expectedResult, testString1);
}

void test_task1_more_then_one_space() {
    char testString1[] = "HELLO_     WORL    D";
    char expectedResult[] = "HELLO_WORLD";

    remove_non_letters(testString1);

    ASSERT_STRING(expectedResult, testString1);
}

void task1() {
    test_task1_default_case();
    test_task1_escapes();
    test_task1_more_then_one_space();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void remove_adjacent_equal_letters(char *s) {
    if (*s == '\0') {
        return;
    }

    char *currentLetter = s;
    while (*s != '\0') {
        if (*currentLetter != *s){
            *(++currentLetter) = *s;
        }
        s++;
    }

    *(++currentLetter) = '\0';
}

void remove_extra_spaces(char *s) {
    if (*s == '\0') {
        return;
    }

    char *posToWrite = s;
    s++;
    while (*s !='\0') {
        if (isspace(*posToWrite) && isspace(*s)){
            *posToWrite = ' ';
        }
        else{
            *(++posToWrite) = *s;
        }
        s++;
    }
    *(++posToWrite) = '\0';
}


void test_task2_default_case() {
    char testString[] = "aaaallllloooo";
    char expectedString[] = "alo";

    remove_adjacent_equal_letters(testString);

    ASSERT_STRING(expectedString, testString);
}

void test_task2_default_case2() {
    char testString[] = "a     l     o";
    char expectedString[] = "a l o";

    remove_extra_spaces(testString);

    ASSERT_STRING(expectedString, testString);
}

void task2() {
    test_task2_default_case();
    test_task2_default_case2();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct{
    char *begin;
    char *end;
} word_descriptor_t;

int true() {
    return 1;
}

int get_word(char *beginSearch, word_descriptor_t *word) {
    (word)->begin = find_non_space(beginSearch);
    if (*(word)->begin == '\0') {
        return 0;
    }

    (word)->end = find_space((word)->begin);

    return 1;
}

int get_word_reverse(char *rbegin, char *rend, word_descriptor_t *word) {
    (word)->end = find_non_space_reverse(rbegin, rend);
    if((word)->begin == rend) {
        return 0;
    }

    (word)->begin = find_space_reverse((word)->end, rend) + 1;

    return 1;
}

void digit_to_start(word_descriptor_t word) {
    char *endStringBuffer = copy((word).begin, (word).end, _stringBuffer);
    char *recPosition = copy_if(_stringBuffer - 1,
                                        endStringBuffer,
                                        (word).begin, isdigit);

    copy_if(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void replace_words_and_digits(char *stringBegin) {
    word_descriptor_t word;
    char *beginSearch = stringBegin;
    while(get_word(beginSearch, &word)) {
        digit_to_start(word);
        beginSearch = (word).end;
    };
}

void test_task3_default_case() {
    char testString1[] = "allo123";
    char expectedString[] = "123allo";

    replace_words_and_digits(testString1);

    ASSERT_STRING(expectedString, testString1);
}

void test_task3_few_words() {
    char testString1[] = "allo123 hello wor321ld";
    char expectedString[] = "123allo hello 321world";

    replace_words_and_digits(testString1);

    ASSERT_STRING(expectedString, testString1);

}

void task3() {
    test_task3_default_case();
    test_task3_few_words();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char digits_to_spaces(char *stringBegin) {
    char *endSource = get_end_of_string(stringBegin);
    char *endStringBuffer = copy(stringBegin, endSource, _stringBuffer);
    *endStringBuffer = '\0';

    char *startStringBuffer = _stringBuffer;
    while (*startStringBuffer != *endStringBuffer) {
        if (isalpha(*startStringBuffer)) {
            *(stringBegin++) = *startStringBuffer;
        } else if (isdigit(*startStringBuffer)) {
            unsigned char digitValue = *startStringBuffer - '0';
            while (digitValue--) {
                *(stringBegin++) = ' ';
            }
        }
        startStringBuffer++;
    }
    *stringBegin = '\0';
}

void test_task4_default_case() {
    char testString1[] = "2allo2da2darova";
    char expectedString[] = "  allo  da  darova";

    digits_to_spaces(testString1);

    ASSERT_STRING(expectedString, testString1);
}

void test_task4_only_spaces() {
    char testString1[] = "5";
    char expectedString[] = "     ";

    digits_to_spaces(testString1);

    ASSERT_STRING(expectedString, testString1);
}

void task4() {
    test_task4_default_case();
    test_task4_only_spaces();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//int areWordsEqual(word_descriptor_t w1,word_descriptor_t w2) {
//    while ((w1).begin != (w2).end && (w2).begin != (w2).end && *(w1).begin != *(w2).begin) {
//        (w1).begin++;
//        (w2).begin++;
//    }
//
//    return (*(w1).begin == ' ' || *(w1).begin == '\0') && (*(w2).begin == ' ' || *(w2).begin == '\0');
//}

int wordsAreEqual(word_descriptor_t w1, word_descriptor_t w2) {
    while (*(w2).begin == *(w1).begin && (w1).begin != w1.end && (w2).begin != w2.end) {
        (w1).begin++;
        (w2).begin++;
    }

    return ((*(w1).begin == ' ' || *(w1).begin == '\0') && (*(w2).begin == ' ' || *(w2).begin == '\0'));
}

void replace(char *source, char *wordToReplace, char *newWord) {
    size_t wordToReplaceSize = strlen(wordToReplace);
    size_t newWordSize = strlen(newWord);

    word_descriptor_t wordToReplace_t = {wordToReplace, wordToReplace + wordToReplaceSize};
    word_descriptor_t newWord_t = {newWord, newWord + newWordSize};

    char *readPtr;
    char *recPtr;
    if (wordToReplaceSize >= newWordSize) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, get_end_of_string(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    word_descriptor_t word;
    while (get_word(readPtr, &word) && *recPtr != '\0') {
        if (wordsAreEqual(word, wordToReplace_t)) {
            recPtr = copy(newWord_t.begin, newWord_t.end, recPtr);
        } else {
            recPtr = copy(word.begin, word.end, recPtr);
        }

        if (*recPtr != '\0') {
            *recPtr = ' ';
        }

        ++recPtr;
        readPtr = word.end;
    }

    *(--recPtr) = '\0';
}

void test_task5_default_case()
{
    char s1[] = "hello world";
    replace(s1, "world", "hello");

    puts(s1);
    ASSERT_STRING("hello hello", s1);
}

void test_task5_replace_all() {
    char testString1[] = "hello hello hello";
    replace(testString1, "hello", "darova");

    ASSERT_STRING("darova darova darova", testString1);
}

void task5() {
    test_task5_default_case();
    test_task5_replace_all();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int word_cmp(word_descriptor_t w1, word_descriptor_t w2) {
    while (*(w1).begin == *(w2).begin && *(w1).begin != '\0') {
        (w1).begin++;
        (w2).begin++;
    }
    if (*(w2).begin == '\0') {
        return -1;
    }

    return *(w1).begin - *(w2).begin;
}

int is_string_lexicographically_correct(char *stringToCheck) {
    char *begin = stringToCheck;

    word_descriptor_t currentWord;
    word_descriptor_t nextWord;

    if (!get_word(begin, &currentWord)) {
        return 1;
    }

    begin = (currentWord).end;
    while (get_word(begin, &nextWord)) {
        begin = (currentWord).end;

        if ((word_cmp(currentWord, nextWord) > 0)) {
            return 0;
        }

        (currentWord).begin = (nextWord).begin;
        (currentWord).end = (nextWord).end;
    }

    return 1;
}

void test_task6_default_case() {
    char testString[] = "abc abc";
    assert(is_string_lexicographically_correct(testString) == 1);
}

void test_task6_mono_symbols() {
    char testString[] = "a b c d e";
    assert(is_string_lexicographically_correct(testString) == 1);
}

void test_task6_one_word() {
    char read[] = "abc";
    assert(is_string_lexicographically_correct(read) == 1);
}



void task6() {
    test_task6_default_case();
    test_task6_mono_symbols();
    test_task6_one_word();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct {
    word_descriptor_t words[MAX_N_WORDS_IN_STRING];
    size_t size;
}bagOfWords_t;

int count_words(char *s) {
    word_descriptor_t word;
    int counter = 0;
    char *begin = s;
    while (get_word(begin, &word)) {
        begin = (word).end;
        ++counter;
    }

    return counter;
}

void get_bag_of_words(bagOfWords_t *bag, char *s) {
    int nWords = count_words(s);
    word_descriptor_t word_array[nWords];
    (bag)->size = count_words(s);
    char *begin = get_end_of_string(s);

    for (register size_t i = 0; i < (bag)->size; ++i) {
        word_descriptor_t word;
        get_word_reverse(begin - 1, s, &word);
        (bag)->words[i] = word;
        begin = (word).begin;
        for (; (word).end > (word).begin - 1; word.begin++){
            printf("%c", *word.begin);
        }
        printf("\n");
    }
}

void test_task7_default_case() {
    char testString[] = "hello world allah acbar";
    bagOfWords_t sobaka;
    get_bag_of_words(&sobaka, testString);
}
void task7() {
    test_task7_default_case();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int is_palindromic_word(word_descriptor_t w)
{
    char *leftPos = w.begin;
    char *rightPos = w.end - 1;
    for (; leftPos - rightPos > 0; ++leftPos, ++rightPos) {
        if (*leftPos != *rightPos) {
            return 0;
        }
    }

    return 1;
}

void test_task8() {
    char testString[] = "abdba";
    word_descriptor_t testWord;
    get_word(testString, &testWord);
    assert(is_palindromic_word(testWord) == 1);
}

void task8() {
    test_task8();
}
