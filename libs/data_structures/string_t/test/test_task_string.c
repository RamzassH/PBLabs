#include "test_task_string.h"
#include "../tasks/task_manager.h"


//////////////////////////////////////////////////TASK1\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//удалить из строки все пробельные символы

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

//////////////////////////////////////////////////TASK2\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Преобразовать строку, оставляя только один символ
//в каждой последовательности подряд идущих одинаковых символов.
//Сократить количество пробелов между словами данного предложения
//до одного

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

//////////////////////////////////////////////////TASK3\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//преобразовать строку таким образом, чтобы цифры
//каждого слова были перенесены в начало слова
//и изменить порядок следования цифр в слове на обратный,
//а буквы – в конец слова,
//без изменения порядка следования.

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

/////////////////////////////////////////////////////TASK4\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Преобразовать строку, заменяя каждую цифру
// соответствующим ей числом пробелов.

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

/////////////////////////////////////////////////////TASK5\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Заменить все вхождения слова 𝑤1 на слово 𝑤2.

void test_task5_default_case()
{
    char s1[] = "hello world";
    replace(s1, "world", "hello");

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

/////////////////////////////////////////////////////TASK6\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Определить, упорядочены ли лексикографически слова данного предложения.

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

/////////////////////////////////////////////////////TASK7\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Вывести слова данной строки в обратном порядке по одному в строке экрана.

void test_task7_default_case() {
    char testString[] = "hello world";
    bagOfWords_t sobaka;
    get_bag_of_words(&sobaka, testString);
}
void task7() {
//    test_task7_default_case();
}

/////////////////////////////////////////////////////TASK8\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//В данной строке соседние слова разделены запятыми.
//Определить количество слов-палиндромов.

void test_task8() {
    char testString[] = "abdba";
    word_descriptor_t testWord;
    get_word(testString, &testWord);
    assert(is_palindromic_word(testWord) == 1);
}

void task8() {
    test_task8();
}

/////////////////////////////////////////////////////TASK9\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Даны две строки. Получить строку, в которой чередуются слова первой
///и второй строки. Если в одной из строк число слов больше,
//чем в другой, то оставшиеся слова этой строки
//должны быть дописаны в строку-результат. В качестве
//разделителя между словами используйте пробел


void test_task9_default_case() {
    char testString1[] = "hello I'm";
    char testString2[] = "world here";
    char testString3[21];

    split_strings(testString1, testString2, testString3);

    char expectedString1[] = "hello world I'm here";
    ASSERT_STRING(expectedString1, testString3);
}

void test_task9_is_first_word_less () {
    char testString1[] = "hello";
    char testString2[] = "world here";
    char testString3[17];

    split_strings(testString1, testString2, testString3);

    char expectedString1[] = "hello world here";
    ASSERT_STRING(expectedString1, testString3);
}
void test_task9_is_second_word_less () {
    char testString1[] = "hello here";
    char testString2[] = "I'm";
    char testString3[17];

    split_strings(testString1, testString2, testString3);

    char expectedString1[] = "hello I'm here";
    ASSERT_STRING(expectedString1, testString3);
}

void task9() {
    test_task9_default_case();
    test_task9_is_first_word_less();
    test_task9_is_second_word_less();
}

/////////////////////////////////////////////////////TASK10\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Преобразовать строку, изменив порядок следования слов в строке на обратный.

void test_task10_default_case() {
    char testString[] = "world hello allo darova";
    char expectedString[] = "darova allo hello world";

    reverse_string_order(testString);

    ASSERT_STRING(expectedString, testString);
}

void task10() {
    test_task10_default_case();
}

/////////////////////////////////////////////////////TASK11\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Вывести слово данной строки, предшествующее первому из слов, содержащих
//букву "а".

void test_task11_default_case() {
    char s1[] = "allo hello privet";

    print_word_before_word_with_a(s1);
}

void test_task11_default_case2() {
    char s1[] = "hello allo privet";

    print_word_before_word_with_a(s1);
}

void test_task11_default_case3() {
    char s1[] = "hello privet";

    print_word_before_word_with_a(s1);
}

void task11() {
//    test_task11_default_case();
//    test_task11_default_case2();
//    test_task11_default_case3();
}

/////////////////////////////////////////////////////TASK12\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Даны две строки. Определить последнее из слов первой строки, которое есть
//во второй строке.

void test_task12_last_of_first_in_second_default_case() {
    char testString1[] = "hello world";
    char testString2[] = "hello world";

    word_descriptor_t res = last_of_first_in_second(testString1, testString2);
    char result[5];
    word_descriptor_to_string(res, result);

    char expected_string[] = "world";
    ASSERT_STRING(expected_string, result);
}

void test_task12_last_of_first_in_second_not_same_strings() {
    char testString1[] = "hello world";
    char testString2[] = "hola world";

    word_descriptor_t res = last_of_first_in_second(testString1, testString2);
    char result[5];
    word_descriptor_to_string(res, result);

    char expected_string[] = "world";
    ASSERT_STRING(expected_string, result);
}

void task12() {
    test_task12_last_of_first_in_second_default_case();
    test_task12_last_of_first_in_second_not_same_strings();
}

/////////////////////////////////////////////////////TASK13\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Определить, есть ли в данной строке одинаковые слова

void test_task13_default_case() {
    char testString1[] = "hello world hello";

    assert(is_string_contains_same_words(testString1) == 1);
}

void test_task13_non_contains_unique_word() {
    char testString1[] = "hola amigos";

    assert(is_string_contains_same_words(testString1) == 0);
}

void test_task13_empty_string() {
    char testString1[] = "    ";

    assert(is_string_contains_same_words(testString1) == 0);
}

void task13() {
    test_task13_default_case();
    test_task13_non_contains_unique_word();
    test_task13_empty_string();
}

////////////////////////////////////////////////////////TASK14\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Определить, есть ли в данной строке пара слов, составленных из одинаковых
//букв.

void test_task14_default_case() {
    char testString1[] = "hello world olleh";

    assert(is_word_contains_same_letters_words_pair(testString1) == 1);
}

void test_task14_without_same_words() {
    char testString1[] = "hello world";

    assert(is_word_contains_same_letters_words_pair(testString1) == 0);
}

void test_task14_without_empty_string() {
    char testString1[] = "     ";

    assert(is_word_contains_same_letters_words_pair(testString1) == 0);
}

void task14() {
//    test_task14_default_case();
//    test_task14_without_same_words();
//    test_task14_without_empty_string();
}

///////////////////////////////////////////////////////////TASK15\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Получить строку из слов данной строки, которые отличны от последнего слова

void test_task15_default_case() {
    char testString[] = "hello world there is war world";
    char expectedString[] = "hello there is war";

    get_string_without_last_word_like(testString);

    ASSERT_STRING(expectedString, testString);
}

void task15() {
    test_task15_default_case();
}

///////////////////////////////////////////////////////////TASK16\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Даны две строки. Определить последнее из слов первой строки, которое
//есть во второй строке.

void test_task16_last_of_first_in_second_default_case() {
    char testString1[] = "hello world";
    char testString2[] = "hello world";

    word_descriptor_t res = last_of_first_in_second(testString1, testString2);
    char result[5];
    word_descriptor_to_string(res, result);

    char expected_string[] = "world";
    ASSERT_STRING(expected_string, result);
}

void test_task16_last_of_first_in_second_not_same_strings() {
    char testString1[] = "hello world";
    char testString2[] = "hola world";

    word_descriptor_t res = last_of_first_in_second(testString1, testString2);
    char result[5];
    word_descriptor_to_string(res, result);

    char expected_string[] = "world";
    ASSERT_STRING(expected_string, result);
}

void task16() {
    test_task16_last_of_first_in_second_default_case();
    test_task16_last_of_first_in_second_not_same_strings();
}

///////////////////////////////////////////////////////////TASK17\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Удалить из данной строки слова-палиндромы.

void test_task17_default_case() {
    char testString1[] = "hello abcba world rar";
    char expectedString[] = "hello world";

    delete_palindromic_words(testString1);

    ASSERT_STRING(expectedString, testString1);
};

void test_task17_without_palindromic() {
    char testString1[] = "hello world";
    char expectedString[] = "hello world";

    delete_palindromic_words(testString1);

    ASSERT_STRING(expectedString, testString1);
}


void task17() {
    test_task17_default_case();
    test_task17_without_palindromic();
}

///////////////////////////////////////////////////////////TASK18\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Даны две строки. Пусть 𝑛1 – число слов в первой строке,
//а 𝑛2 – во второй. Требуется дополнить строку,
//содержащую меньшее количество слов, последними
//словами строки, в которой содержится большее количество слов.

void test_task18_default_case() {
    char testString1[] = "allo privet";
    char testString2[] = "allo privet dela kak";

    add_words_to_less_string(testString1, testString2);

    char expectedString[] = "allo privet kak dela";
    ASSERT_STRING(expectedString, testString1);
}

void test_task18_same_strings() {
    char testString1[] = "allo privet";
    char testString2[] = "allo privet";

    add_words_to_less_string(testString1, testString2);

    char expectedString[] = "allo privet";
    ASSERT_STRING(expectedString, testString1);
}

void task18() {
    test_task18_default_case();
    test_task18_same_strings();
}

///////////////////////////////////////////////////////////TASK19\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//Определить, входит ли в данную строку каждая буква данного слова.

void test_task19_default_case() {
    char testString1[] = "hello world";
    char testString2[] = "dell";

    word_descriptor_t word;
    get_word(testString2, &word);

    assert(is_string_contains_every_symbol(testString1, &word) == 1);
}

void test_task19_is_non_contain_symbol() {
    char testString1[] = "hello world";
    char testString2[] = "dall";

    word_descriptor_t word;
    get_word(testString2, &word);

    assert(is_string_contains_every_symbol(testString1, &word) == 0);
}

void task19() {
    test_task19_default_case();
    test_task19_is_non_contain_symbol();
}

///////////////////////////////////////////////////////////END\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void test_task() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();
    task11();
    task12();
    task13();
    task14();
    task15();
    task16();
    task17();
    task18();
    task19();
}