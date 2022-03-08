#include "task_manager.h"

//////////////////////////////////////////////////TASK1\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//удалить из строки все пробельные символы

void remove_non_letters(char *s) {
    char *endSource = get_end_of_string(s);
    char *destination = copy_if(s, endSource, s, isgraph);
    *destination = '\0';
}

//////////////////////////////////////////////////TASK2\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Преобразовать строку, оставляя только один символ
//в каждой последовательности подряд идущих одинаковых символов.
//Сократить количество пробелов между словами данного предложения
//до одного

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
        } else {
            *(++posToWrite) = *s;
        }
        s++;
    }

    *(++posToWrite) = '\0';
}
//////////////////////////////////////////////////TASK3\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//преобразовать строку таким образом, чтобы цифры
//каждого слова были перенесены в начало слова
//и изменить порядок следования цифр в слове на обратный,
//а буквы – в конец слова,
//без изменения порядка следования.

int get_word(char *beginSearch, word_descriptor_t *word) {
    (word)->begin = find_non_space(beginSearch);
    if (*(word)->begin == '\0') {
        return 0;
    }

    (word)->end = find_space((word)->begin);

    return 1;
}

int get_word_reverse(char *rbegin, char *rend, word_descriptor_t *word) {
    (word)->end = find_non_space_reverse(rbegin, rend) - 1;
    if((word)->end == rend) {
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

/////////////////////////////////////////////////////TASK4\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Преобразовать строку, заменяя каждую цифру
// соответствующим ей числом пробелов.

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

/////////////////////////////////////////////////////TASK5\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Заменить все вхождения слова 𝑤1 на слово 𝑤2.

int are_words_equal(word_descriptor_t w1, word_descriptor_t w2) {
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

    char *readPtr, *recPtr;
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
        if (are_words_equal(word, wordToReplace_t)) {
            recPtr = copy((newWord_t).begin, (newWord_t).end, recPtr);
        } else {
            recPtr = copy((word).begin, (word).end, recPtr);
        }

        if (*recPtr != '\0') {
            *recPtr = ' ';
        }

        ++recPtr;
        readPtr = (word).end;
    }

    *(--recPtr) = '\0';
}

/////////////////////////////////////////////////////TASK6\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Определить, упорядочены ли лексикографически слова данного предложения.

int word_cmp(word_descriptor_t w1, word_descriptor_t w2) {
    while (*(w1).begin == *(w2).begin && *(w1).begin != '\0') {
        (w1).begin++;
        (w2).begin++;
    }
    if (*(w2).begin == '\0') {
        return 0;
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

/////////////////////////////////////////////////////TASK7\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Вывести слова данной строки в обратном порядке по одному в строке экрана.

int getWordRevers(char *rbegin, char *rend, word_descriptor_t *word) {
    char* word_end = find_non_space_reverse(rbegin, rend);

    if (word_end == rend)
        return 0;

    char* word_begin = find_space_reverse(word_end, rend);

    word->begin = word_begin + 1;
    word->end = word_end + 1;

    return 1;
}

void get_bag_of_words(bagOfWords_t *bag, char *s) {
    (bag)->size = 0;
    word_descriptor_t word;

    while (get_word(s, &word)) {
        (bag)->words[(bag)->size++] = word;
        s = word.end;
//        print_word((word.begin), (word).end);
    }
}

/////////////////////////////////////////////////////TASK8\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//В данной строке соседние слова разделены запятыми.
//Определить количество слов-палиндромов.

int is_palindromic_word(word_descriptor_t w)
{
    char *leftPos = w.begin;
    char *rightPos = w.end - 1;
    while (rightPos - leftPos > 0) {
        if (*leftPos != *rightPos) {
            return 0;
        }
        ++leftPos;
        --rightPos;
    }

    return 1;
}

/////////////////////////////////////////////////////TASK9\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Даны две строки. Получить строку, в которой чередуются слова первой
///и второй строки. Если в одной из строк число слов больше,
//чем в другой, то оставшиеся слова этой строки
//должны быть дописаны в строку-результат. В качестве
//разделителя между словами используйте пробел

char *copy_if_found(char *begin, char *end, char *beginSearch) {
    beginSearch = copy(begin, end, beginSearch);
    *(beginSearch) = ' ';
    ++beginSearch;

    return beginSearch;
}

void split_strings(char *s1, char *s2, char *stringToSplit) {
    word_descriptor_t word1, word2;
    int isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2, *beginSearch3 = stringToSplit;


    while ((isW1Found = get_word(beginSearch1, &word1),
            isW2Found = get_word(beginSearch2, &word2),
            isW1Found || isW2Found)) {

        if (isW1Found) {
            beginSearch3 = copy_if_found(word1.begin, word1.end, beginSearch3);
            beginSearch1 = word1.end;
        }

        if (isW2Found) {
            beginSearch3 = copy_if_found(word2.begin, word2.end, beginSearch3);
            beginSearch2 = word2.end;
        }
    }
    *(beginSearch3 - 1) = '\0';
}

/////////////////////////////////////////////////////TASK10\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Преобразовать строку, изменив порядок следования слов в строке на обратный.

int is_non_space(char s) {
    return !isspace(s);
}

void reverse_string_order(char*stringToReverse) {
    copy(stringToReverse, get_end_of_string(stringToReverse), _stringBuffer);

    bagOfWords_t bag;
    get_bag_of_words(&bag, _stringBuffer);

    char *beginCopy = stringToReverse;
    while ((bag).size--) {
        beginCopy = copy((bag).words[(bag).size].begin, (bag).words[(bag).size].end , beginCopy);
        *beginCopy = ' ';
        beginCopy++;
    }

    *(beginCopy - 1) = '\0';
}

/////////////////////////////////////////////////////TASK11\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Вывести слово данной строки, предшествующее первому из слов, содержащих
//букву "а".

void print_word_before_word_with_a(char *s) {
    if (find (s, get_end_of_string(s), 'a') == get_end_of_string(s)) {
        printf("string not contains A\n");
    }

    word_descriptor_t currentWord;
    get_word(s, &currentWord);
    if (find(currentWord.begin, currentWord.end, 'a') != currentWord.end) {
        printf("first word contains A\n");
        return;
    }

    word_descriptor_t nextWord;

    while(get_word(currentWord.end, &nextWord)) {
        if (find(nextWord.begin, nextWord.end, 'a') != nextWord.end) {
            print_word(currentWord.begin, currentWord.end);
            printf("\n");
            return;
        }
        else {
            currentWord.begin = nextWord.begin;
            currentWord.end = nextWord.end;
        }
    }
}

/////////////////////////////////////////////////////TASK12\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Даны две строки. Определить последнее из слов первой строки, которое есть
//во второй строке.

void word_descriptor_to_string(word_descriptor_t word, char *destination) {
    char *end = copy((word).begin, (word).end, destination);
    *end = '\0';
}

word_descriptor_t last_of_first_in_second(char *s1, char *s2) {
    bagOfWords_t bag1;
    get_bag_of_words(&bag1, s1);

    bagOfWords_t bag2;
    get_bag_of_words(&bag2, s2);

    word_descriptor_t word;
    for (register size_t i = 0; i < (bag1).size; ++i) {
        for (register size_t J = 0; J < (bag2).size; ++J) {
            if (strcmp((bag1).words[i].begin, (bag2).words[i].begin) == 0) {
                (word).begin = (bag1).words[i].begin, (word).end = (bag1).words[i].end;
            }
        }
    }
    return word;
}

/////////////////////////////////////////////////////TASK13\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Определить, есть ли в данной строке одинаковые слова

int is_string_contains_same_words(char *s1) {
    bagOfWords_t bag;
    get_bag_of_words(&bag, s1);

    word_descriptor_t *currentWord = (bag).words;
    word_descriptor_t *endWord = (bag).words + (bag).size - 1;

    while (currentWord < endWord) {
        word_descriptor_t *w = currentWord + 1;
        while (w <= endWord) {
            if (word_cmp(*currentWord, *w) == 0) {
                return 1;
            }
            w++;
        }
        currentWord++;
    }

    return 0;
}

////////////////////////////////////////////////////////TASK14\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Определить, есть ли в данной строке пара слов, составленных из одинаковых
//букв.

int compare_char(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;

    if (arg1 < arg2){
        return -1;
    } else if (arg1 > arg2) {
        return 1;
    } else {
        return 0;
    }
}

void letters_sort(word_descriptor_t* word) {
    size_t nLetters = (word)->end - (word)->begin;
    qsort((word)->begin, nLetters, sizeof(char), compare_char);
}

int is_word_contains_same_letters_words_pair(char *s) {
    copy(s, get_end_of_string(s), _stringBuffer);

    word_descriptor_t wordToSort;
    char *bufferPtr = _stringBuffer;

    while (get_word(bufferPtr, &wordToSort)) {
        letters_sort(&wordToSort);
        bufferPtr = (wordToSort).end;
    }

    bagOfWords_t bag;
    get_bag_of_words(&bag, _stringBuffer);
    size_t bagSize = (bag).size;

    for (register size_t i = 0; i < bagSize; ++i) {
        for (register size_t j = 0; j < bagSize; ++j) {
            if (i != j && word_cmp((bag).words[i], (bag).words[j]) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

///////////////////////////////////////////////////////////TASK15\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Получить строку из слов данной строки, которые отличны от последнего слова

void get_string_without_last_word_like(char *defString) {
    word_descriptor_t currentWord, lastWord;

    char *endBuff = copy(defString, get_end_of_string(defString), _stringBuffer);
    *endBuff = '\0';

    if (!getWordRevers(endBuff - 1, _stringBuffer - 1, &lastWord)) {
        return;
    }

    char *beginBufferPtr = _stringBuffer;
    char *endStringPtr = defString;

    while (get_word(beginBufferPtr, &currentWord)) {
        if (!are_words_equal(lastWord, currentWord)) {
            endStringPtr = copy(currentWord.begin, currentWord.end, endStringPtr);
            *endStringPtr = ' ';
            endStringPtr++;
        }

        beginBufferPtr = currentWord.end;
    }

    *(endStringPtr - 1) = '\0';
}

///////////////////////////////////////////////////////////TASK16\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Даны две строки. Определить последнее из слов первой строки, которое
//есть во второй строке.

word_descriptor_t last_of_first_in_second_search(char *s1, char *s2) {
    bagOfWords_t bag1;
    get_bag_of_words(&bag1, s1);

    bagOfWords_t bag2;
    get_bag_of_words(&bag2, s2);

    word_descriptor_t word;
    for (register size_t i = 0; i < (bag1).size; ++i) {
        for (register size_t J = 0; J < (bag2).size; ++J) {
            if (strcmp((bag1).words[i].begin, (bag2).words[i].begin) == 0) {
                (word).begin = (bag1).words[i].begin, (word).end = (bag1).words[i].end;
            }
        }
    }
    return word;
}

///////////////////////////////////////////////////////////TASK17\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Удалить из данной строки слова-палиндромы.

int is_non_palindromic(word_descriptor_t word) {
    return is_palindromic_word(word);
}

void delete_palindromic_words(char *s) {
    bagOfWords_t bag;
    get_bag_of_words(&bag, s);

    char *beginCopyPtr = s;
    word_descriptor_t word;
    get_word(beginCopyPtr, &word);

    while ((bag).size--) {

        if (!is_palindromic_word(word)) {
            beginCopyPtr = copy((word).begin, (word).end, beginCopyPtr);
            *beginCopyPtr = ' ';
            ++beginCopyPtr;
        }

        get_word((word).end, &word);
    }
    *(beginCopyPtr - 1) = '\0';
}

///////////////////////////////////////////////////////////TASK18\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Даны две строки. Пусть 𝑛1 – число слов в первой строке,
//а 𝑛2 – во второй. Требуется дополнить строку,
//содержащую меньшее количество слов, последними
//словами строки, в которой содержится большее количество слов.

void add_words_to_less_string_(bagOfWords_t *greaterString, bagOfWords_t *lessString) {

    size_t difference = (greaterString)->size - (lessString)->size;
    char *endOfLessString = (lessString)->words[(lessString)->size - 1].end;
    *endOfLessString = ' ';
    endOfLessString++;
    char *endOfGreaterString = (greaterString)->words[(greaterString)->size - 1].end;

    size_t wordNum = (greaterString)->size - 1;
    word_descriptor_t wordToCopy;
    while (difference--) {
        get_word_reverse(endOfGreaterString, (greaterString)->words[0].begin, &wordToCopy);
        endOfGreaterString = (greaterString)->words[--wordNum].end;

        endOfLessString = copy_if((wordToCopy).begin - 1, (wordToCopy).end + (*(wordToCopy).end != '\0'),
                                  endOfLessString, (int (*)(int)) is_non_space);
        *endOfLessString = ' ';
        endOfLessString++;
    }
    *(endOfLessString - 1) = '\0';
}

void add_words_to_less_string(char *s1, char *s2) {
    bagOfWords_t bag1;
    get_bag_of_words(&bag1, s1);

    bagOfWords_t bag2;
    get_bag_of_words(&bag2, s2);

    if ((bag1).size > (bag2).size) {
        add_words_to_less_string_((&bag1), (&bag2));
    } else if ((bag1).size < (bag2).size) {
        add_words_to_less_string_((&bag2), (&bag1));
    }
}

///////////////////////////////////////////////////////////TASK19\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Определить, входит ли в данную строку каждая буква данного слова.

int is_string_contains_every_symbol(char *s1, word_descriptor_t *word) {
    char *endStringPtr = get_end_of_string(s1) - 1;
    while ((word)->begin < (word)->end) {
        if(*find(s1, endStringPtr, *(word)->begin) != *(word)->begin) {
            return 0;
        }
        ++(word)->begin;
    }
    return 1;
}

///////////////////////////////////////////////////////////END\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\